#include "Data.h"

set<Student *, studentComparatorAlpha1> Data :: get_students() const{return students_;}
vector<UCClass*> Data :: get_ucClasses() const{return ucClasses_;}
queue<Request*> Data :: get_requests() const{return requests_;}
vector<Request*> Data:: get_archive() const{return archive_;}

/**
 * Função lê o ficheiro "classes.csv" e cria os objetos do tipo UCClass e Lecture.
 *
 * COMPLEXIDADE: O(n).
 * @param fname string com o nome de ficheiro de input
 */

void Data :: readFile_classes(string fname){
    //variables
    string classCode, ucCode, weekday, type;
    float startHour, duration;
    vector<string> v;

    //open file
    ifstream input(fname);
    if (input.is_open()) {

        string line;
        getline(input, line); //skips first line
        while (getline(input, line)) {
            stringstream iss(line);

            //divide line in tokens;
            string token;
            while (getline(iss, token, ',')) { v.push_back(token); }

            //assign tokens to the correct variables
            classCode = v[0];
            ucCode = v[1];
            weekday = v[2];
            type = v[5];
            startHour = stof(v[3]);
            duration = stof(v[4]);
            v.clear();

            UCClass *uc = new UCClass(ucCode, classCode);
            Lecture *lecture = new Lecture(weekday, startHour, duration, type);

            string uccode = uc->get_ucCode();
            string classcode = uc->get_classCode();
            auto it = find_if(ucClasses_.begin(), ucClasses_.end(), [uccode, classcode](
                    UCClass *uc2)->bool {return (uc2->get_ucCode() == uccode && uc2->get_classCode() == classcode );}); // find(students_.begin();students_.end(),student)

            if (it != ucClasses_.end()) {
                uc = *it;
                uc->add_lecture(lecture);
            }
            else{
                uc->add_lecture(lecture);
                ucClasses_.push_back(uc);
            }

        }
    }
    else cout<<"Could not open the file\n";

}

/**
 * Função lê o ficheiro "students_classes.csv" e cria os objetos do tipo Student e UC.
 *
 * COMPLEXIDADE: O(n).
 * @param fname string com o nome de ficheiro de input
 */

void Data :: readFile_students_classes(string fname){
    //variables
    int studentCode;
    string studentName, ucCode, classCode;
    vector<string> v;

    //open file
    ifstream input(fname);
    if(input.is_open()) {
        string line;
        getline(input, line); //skips first line
        while ( getline(input, line)) {
            stringstream iss(line);

            //divide line in tokens;
            string token;
            while (getline(iss, token, ',')) { v.push_back(token); }

            studentCode = stoi(v[0]);
            studentName = v[1]; ucCode = v[2]; classCode = v[3];
            v.clear();

            Student *student = new Student(studentName, studentCode);
            UCClass *ucClass = new UCClass(ucCode, classCode);


            string uccode = ucClass->get_ucCode();
            string classcode = ucClass->get_classCode();
            //fomos buscar a info da ucclass ao container completo:
            auto itu = find_if(ucClasses_.begin(), ucClasses_.end(), [uccode, classcode](
                    UCClass *uc2)->bool {return (uc2->get_ucCode() == uccode && uc2->get_classCode() == classcode );});

            if(itu != ucClasses_.end()){
                ucClass = *itu;
            }

            //adicionar novo student ou adicionar info ao student já existente
            auto its = students_.find(student); // find(students_.begin();students_.end(),student)

            if (its!= students_.end()){
                // adicionar turmas
                student = *its; // ir buscar estudante ja inicializado
                student->add_class(ucClass);
            }
            else {
                student->add_class(ucClass);
                students_.insert(student);
            }

            //FOI AQUI QUE ALTERÁMOS
            ucClass->add_student(student);

        }
    }
    else cout<<"Could not open the file\n";
}

/**
 * Função dá output ao utilizador da informação sobre um estudante (Nome, Número de Aluno e Turmas).
 * Informa o utilizador se o estudante não existir.
 *
 * COMPLEXIDADE: O(n^2).
 * @param code int que indica o código do objeto do tipo Student cujas informaçoes vao ser impressas
 */
void Data::printSInfo(int code) const{
    bool flag = true;
    for(Student * stu: students_){
        if (stu->get_studentCode() == code){
            cout << "Name: " << stu->get_studentName() << endl;
            cout << "Student Code: " << stu->get_studentCode() << endl << endl << "Classes:"<< endl;
            for (UCClass *uc : stu->get_classes()){
                cout << "\t" << uc->get_ucCode() << ", " << uc->get_classCode() << ";" << endl;
            }
            flag = false;
            break;
        }
    }
    if (flag){ cout << "Student not found.";}
}

/**
 * Função procura e retorna o objeto Student com um determinado número de estudante.
 *
 * COMPLEXIDADE: O(n).
 * @param code int que indica o código do objeto do tipo Student que se pretende procurar
 */
Student* Data::findStudent(int code) const {
    bool flag = true;
    Student* s;
    for(Student * stu: students_){
        if (stu->get_studentCode() == code){
            flag = false;
            s = stu;
            break;
        }
    }
    if (flag){ cout << "Student not found." << endl;
        s =  new Student("Failure",0);
        }
    return s;
}

struct sorted_vector2{
    bool operator()(tuple<string,Lecture> t1, tuple<string,Lecture> t2){
        if (get<1>(t1).get_startHour() < get<1>(t2).get_startHour()) return true;
        return false;
    }
};
/**
 * Função dá print a um vetor de tuplos compostos por uma string e um objeto do tipo Lecture, que representa um dia da semana no horário de um estudante.
 *
 * COMPLEXIDADE: O(n).
 * @param t1 vetor de tuplos de strings e objetos do tipo Lecture que contem a informaçao que vai ser impressa (horario de um objeto do tipo Student)
 */
void cout_tt2 (vector<tuple<string,Lecture>> t1){
    for (tuple<string,Lecture> t: t1){
        cout << get<1>(t).get_startHour()<< " | " << get<1>(t).get_endHour()<< " | " << get<0>(t) << " | " << get<1>(t).get_type() << endl;
    }
}
/**
 * Função cria e dá output ao utilizador sobre o horário de uma determinada UC.
 *
 * COMPLEXIDADE: O(n^2).
 * @param uccode string que contem o codigo da UC cujo horario se pretende imprimir
 */
void Data ::uc_timetable(string uccode) const {
    vector<tuple<string,Lecture>> monday;
    vector<tuple<string,Lecture>> tuesday;
    vector<tuple<string,Lecture>> wednesday;
    vector<tuple<string,Lecture>> thursday;
    vector<tuple<string,Lecture>> friday;
    for (UCClass* uc: ucClasses_) {
        if (uccode == uc->get_ucCode()){
            for (Lecture* l: uc->get_lectures()){
                tuple<string,Lecture> par(uc->get_classCode(), *l);
                if (l->get_weekDay() == "Monday") monday.push_back(par);
                if (l->get_weekDay() == "Tuesday") tuesday.push_back(par);
                if (l->get_weekDay() == "Wednesday") wednesday.push_back(par);
                if (l->get_weekDay() == "Thursday") thursday.push_back(par);
                if (l->get_weekDay() == "Friday") friday.push_back(par);
            }
        }
    }
    sort(monday.begin(), monday.end(), sorted_vector2());
    sort(tuesday.begin(), tuesday.end(), sorted_vector2());
    sort(wednesday.begin(), wednesday.end(), sorted_vector2());
    sort(thursday.begin(), thursday.end(), sorted_vector2());
    sort(friday.begin(), friday.end(), sorted_vector2());

    cout << "MONDAY" << endl;
    cout_tt2(monday);
    cout << '\n';
    cout << "TUESDAY" << endl;
    cout_tt2(tuesday);
    cout << '\n';
    cout << "WEDNESDAY" << endl;
    cout_tt2 (wednesday);
    cout << '\n';
    cout << "THURSDAY" << endl;
    cout_tt2 (thursday);
    cout << '\n';
    cout << "FRIDAY" << endl;
    cout_tt2 (friday);
    cout << '\n';
}
/**
 * Função cria e dá output ao utilizador sobre o horário de uma determinada turma.
 *
 * COMPLEXIDADE: O(n^2).
 * @param classcode string que recebe o codigo da turma cujo horario se pretende imprimir
 */
void Data ::class_timetable(string classcode) const{ //alterações feitas, flag para verificar se turma existe
    bool flag = false;
    vector<tuple<string,Lecture>> monday;
    vector<tuple<string,Lecture>> tuesday;
    vector<tuple<string,Lecture>> wednesday;
    vector<tuple<string,Lecture>> thursday;
    vector<tuple<string,Lecture>> friday;
    for (UCClass* uc: ucClasses_) {
        if (classcode == uc->get_classCode()){
            flag = true;
            for (Lecture* l: uc->get_lectures()){
                tuple<string,Lecture> par(uc->get_ucCode(), *l);
                if (l->get_weekDay() == "Monday") monday.push_back(par);
                if (l->get_weekDay() == "Tuesday") tuesday.push_back(par);
                if (l->get_weekDay() == "Wednesday") wednesday.push_back(par);
                if (l->get_weekDay() == "Thursday") thursday.push_back(par);
                if (l->get_weekDay() == "Friday") friday.push_back(par);
            }
        }
    }
    if (flag) {
        sort(monday.begin(), monday.end(), sorted_vector2());
        sort(tuesday.begin(), tuesday.end(), sorted_vector2());
        sort(wednesday.begin(), wednesday.end(), sorted_vector2());
        sort(thursday.begin(), thursday.end(), sorted_vector2());
        sort(friday.begin(), friday.end(), sorted_vector2());

        cout << "MONDAY" << endl;
        cout_tt2(monday);
        cout << '\n';
        cout << "TUESDAY" << endl;
        cout_tt2(tuesday);
        cout << '\n';
        cout << "WEDNESDAY" << endl;
        cout_tt2(wednesday);
        cout << '\n';
        cout << "THURSDAY" << endl;
        cout_tt2(thursday);
        cout << '\n';
        cout << "FRIDAY" << endl;
        cout_tt2(friday);
        cout << '\n';
    }
    else {cout << "Could not find Class." << endl;}
}

/**
 * Função cria e guarda pedido de estudante (de adição, remoção ou troca de turma) na fila de pedidos.
 *
 * COMPLEXIDADE: O(n).
 * @param student pointer de objeto do tipo Student com que o pedido está relacionado
 * @param og vetor de objetos do tipo UCClass antes da alteração envolvida no pedido
 * @param final vetor de objetos do tipo UCClass apos a alteração envolvida no pedido
 */

void Data::saveRequests(Student* student, vector<UCClass*> og, vector<UCClass*> final) {
    Request *req;
    req = new Request(student, og, final);
    requests_.push(req);
}
/**
 * Função vai retirar um dos objetos do tipo Request do seu container (queue).
 *
 * COMPLEXIDADE: O(1).
 */
void Data :: data_pop(){
    requests_.pop();
}

/**
 * Função verifica a compatibilidade entre horários de duas turmas.
 *
 * COMPLEXIDADE: O(n^2).
 * @param uc1 um dos pointers para objeto do tipo UCClass presente na verificação de compatibilidade
 * @param uc2 um dos pointers para objeto do tipo UCClass presente na verificação de compatibilidade
 * @return valor booleano - true se os horarios forem compativeis de acordo com os objetos UCClass recebidos
 */
bool check_compatibility(UCClass* uc1, UCClass* uc2){
    for (Lecture* l1: uc1->get_lectures())
        for (Lecture* l2: uc2->get_lectures()){
            if (((l2->get_type() == "TP" && l1->get_type()== "TP") || (l2->get_type() == "PL" && l1->get_type()== "PL") || (l2->get_type() == "TP" && l1->get_type()== "PL") || (l2->get_type() == "PL" && l1->get_type()== "TP")) && ( (l1->get_weekDay()==l2->get_weekDay()) && (l2->get_endHour() > l1->get_startHour() || l2->get_startHour() < l1->get_endHour()))) return false;
        }
    return true;
}

/**
 * Função processa os pedidos na fila de pedidos. Assume que o valor máximo de alunos por turma é 25. Separa os pedidos em dois tipos: pedidos de adição e de remoção. Os pedidos de trocas surgem como um pedido de adição e outro de remoção por parte de dois alunos diferentes.
 * Pedidos não aceites a priori são guardados num vetor archive_ e voltam a ser processados quando os pedidos na fila principal "terminarem".
 *
 * COMPLEXIDADE: O(n^2).
 */
void Data:: processRequests() {
    int cap = 2;
    bool flag = true;
    vector<int> aux;
    vector<int> aux2;

    while (!requests_.empty()) {
        Request *req = requests_.front();

        if ((req->get_class_final()).size() == 0) { // pedido de remoção
            for (UCClass *uc: req->get_class_og()) {
/*
                for (UCClass *uc2: ucClasses_) {  //verificar quantos alunos é que há nas outras turmas dessa cadeira
                    if (uc->get_ucCode() == uc2->get_ucCode()) aux.push_back(uc2->get_students().size());
                }

                auto itmax = max_element(aux.begin(), aux.end());
                int max = *itmax; // numero maximo de alunos nessa cadeira

                aux.clear();

                if (uc->get_students().size() - 1 < (max - 4)) {
                    archive_.push_back(req);
                    break;
                }*/
                    req->get_student()->rem(uc);
                    uc->remo(req->get_student());
                    /*
                    auto it = find(req->get_student()->get_classes().begin(), req->get_student()->get_classes().end(),
                                   uc);
                    (req->get_student()->get_classes()).erase(it); // remover class das classes do estudante
                    auto ite = find(uc->get_students().begin(), uc->get_students().end(), req->get_student());
                    uc->get_students().erase(ite); //remover student dos estudantes da uc*/
            }
        }

        if ((req->get_class_og()).size() == 0) { // pedido de adiçãp
            for (UCClass *uc: req->get_class_final()) { //iterar por todas as classes que ele pediu para adicionar

                for (UCClass *uc2: ucClasses_) {  //verificar quantos alunos é que há nas outras turmas dessa cadeira
                    if (uc->get_ucCode() == uc2->get_ucCode()) aux2.push_back(uc2->get_students().size());
                }

                // itmax = max_element(aux2.begin(), aux2.end());
                //int max = *itmax; // numero maximo de alunos nessa cadeira

                auto itmin = min_element(aux2.begin(), aux2.end());
                int min = *itmin; // numero minimo de alunos dessa cadeira

                aux2.clear();

                if (uc->get_students().size() + 1 > (min + 4) || uc->get_students().size() + 1 > cap) flag = false;
                else{
                    for (UCClass *uc2: req->get_student()->get_classes()) {
                        /* || uc->get_students().size() + 1 > (min + 4)*/
                        if (!check_compatibility(uc2, uc)) {
                            flag = false;
                            break;
                        } // pedido nao aceite, vai para arquivo
                        else {
                            flag = true;
                        }
                    }
                }

                if (flag){
                    req->get_student()->add_class(uc);
                    uc->add_student(req->get_student());// pedido aceite. uc é adicionada às ucs do aluno e aluno é adicionado à lista de ucs}
            }
                else{archive_.push_back(req);}
        }}
        data_pop();
    }
    for (Request* r: archive_){requests_.push(r);}
}

void Data:: clear_archive(){
    archive_.clear();
}

void Data:: file_writer(string fname) const{
    ofstream f (fname);
    if (f.is_open()){
        f << "StudentCode,StudentName,UcCode,ClassCode" << endl;
        for (Student* s: students_){


                for (UCClass *uc: s->get_classes()) {
                    f << s->get_studentCode() << ',' << s->get_studentName() << ',' << uc->get_ucCode() << ','
                      << uc->get_classCode() << endl;
                }

        }
    }
    else cout << "File not found" << endl;
}