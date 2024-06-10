#include "../../include/controller/College.h"

map<string, shared_ptr<StudentDTO>> College::Students;
map<string, shared_ptr<TeacherDTO>> College::Teachers;
vector<shared_ptr<Subject>> College::Subjects;
vector<shared_ptr<ClassDTO>> College::Classes;

//Implementar o getter
map<string, shared_ptr<TeacherDTO>>& College::getTeachers(){
    return Teachers;
}
vector<shared_ptr<Subject>>& College::getSubjects(){
    return Subjects;
}
vector<shared_ptr<ClassDTO>>& College::getClasses(){
    return Classes;
}
map<string, shared_ptr<StudentDTO>>& College::getStudents(){
    return Students;
}

//Implementar o setter
void College::setTeachers(const map<string, shared_ptr<TeacherDTO>>& Teachers){
    College::Teachers = Teachers;
}
void College::setSubjects(const vector<shared_ptr<Subject>>& Subjects){
    College::Subjects = Subjects;
}
void College::setClasses(const vector<shared_ptr<ClassDTO>>& Classes){
    College::Classes = Classes;
}
void College::setStudents(const map<string, shared_ptr<StudentDTO>>& students)
{
    Students = students;
}

//metodos
void College::addStudent(const string& ra, const shared_ptr<StudentDTO>& student)
{
    Students[ra] = student;
}
void College::addTeacher(const string& id, const shared_ptr<TeacherDTO>& teacher)
{
    Teachers[id] = teacher;
}
