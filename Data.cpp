#include "Data.h"

set<Student *, studentComparatorAlpha1> Data :: get_students(){return students_;}
vector<UCClass*> Data :: get_ucClasses(){return ucClasses_;} //passar para set
queue<Request*> Data :: get_requests(){return requests_;}
vector<Request*> Data:: get_archive(){return archive_;}
/*
void Data :: readFile() {
    readFile_classes_per_uc();
    readFile_classes();
    readFile_students_classes();
}
*/

/**
 * Função lê o ficheiro "classes.csv" e cria os objetos do tipo UCClass e Lecture.
 *
 * COMPLEXIDADE: O(n).
 */
//adiciona os horários de cada turma
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

//cria os estudantes e adiciona as turmas (já com horários) ao estudante.
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
struct sorted_vector2{
    bool operator()(tuple<string,Lecture> t1, tuple<string,Lecture> t2){
        if (get<1>(t1).get_startHour() < get<1>(t2).get_startHour()) return true;
        return false;
    }
};
void cout_tt2 (vector<tuple<string,Lecture>> t1){
    for (tuple<string,Lecture> t: t1){
        cout << get<1>(t).get_startHour()<< " | " << get<1>(t).get_endHour()<< " | " << get<0>(t) << " | " << get<1>(t).get_type() << endl;
    }
}
void Data ::uc_timetable(string uccode) {
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
void Data ::class_timetable(string classcode) {
    vector<tuple<string,Lecture>> monday;
    vector<tuple<string,Lecture>> tuesday;
    vector<tuple<string,Lecture>> wednesday;
    vector<tuple<string,Lecture>> thursday;
    vector<tuple<string,Lecture>> friday;
    for (UCClass* uc: ucClasses_) {
        if (classcode == uc->get_classCode()){
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

//funcao recebe student code, mas tem de receber ja os vetores das classes (por isso tem de se criara os vetores na interface)
void Data::guardarPedidos(int sc, vector<UCClass*> og, vector<UCClass*> final) {
    Request *req;
    for (Student *s: students_) {
        if (sc == s->get_studentCode()){
            req = new Request(s, og, final);
        }
    }
    requests_.push(req);
}

void Data:: processRequests(){
    int count1 = 0;
    Request* req = requests_.front();
    if ((req->get_class_final()).size() == 0) { // pedido de remoção
        for (UCClass *uc: req->get_class_og()) {
            auto it = find(req->get_student()->get_classes().begin(),req->get_student()->get_classes().end(), uc);
            (req->get_student()->get_classes()).erase(it);
        }
    }

    if ((req->get_class_og()).size() == 0) { // pedido de adiçãp
        for (UCClass *uc: req->get_class_final()) {

        }
    }

}