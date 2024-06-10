/** 
 * Grupo:
 *     Jose Vitor #187174 
 *     Lucas Saad Pascholini #200881
 *     Maria Eduarda de Souza Gomes #260844
 *     Nasser Nasser Fares #196894
 *     Tammy Kojima #213792
 * **/

#ifndef COLLEGE_HPP
#define COLLEGE_HPP
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <memory>
#include "../../include/dto/StudentDTO.h"
#include "../../include/dto/TeacherDTO.h"
#include "../../include/dto/ClassDTO.h"
#include "../../include/dto/Subject.h"
using namespace std;

class College{
    public:
    //Containers para o polimorfismo - atributos
    static map<string, shared_ptr<StudentDTO>> Students;
    static map<string, shared_ptr<TeacherDTO>> Teachers;
    static vector<shared_ptr<Subject>> Subjects;
    static vector<shared_ptr<ClassDTO>> Classes;

    //Metodos getters
    //static  map<string, shared_ptr<Person>>& getStudents();
    static map<string, shared_ptr<TeacherDTO>>& getTeachers();
    static vector<shared_ptr<Subject>>& getSubjects();
    static vector<shared_ptr<ClassDTO>>& getClasses();
    static map<string, shared_ptr<StudentDTO>>& getStudents();


    //Metodo setter
    //static void setStudents(const map<string, shared_ptr<Person>>& Students);
    static void setTeachers(const map<string, shared_ptr<TeacherDTO>>& Teachers);
    static void setSubjects(const vector<shared_ptr<Subject>>& Subjects);
    static void setClasses(const vector<shared_ptr<ClassDTO>>& Classes);
    static void setStudents(const map<string, shared_ptr<StudentDTO>>& Students);

    //metodos
    static void addStudent(const string& ra, const shared_ptr<StudentDTO>& Students);
    static void addTeacher(const string& id, const shared_ptr<TeacherDTO>& Teachers);
};  

#endif