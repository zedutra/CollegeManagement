#include "../../include/dto/TeacherDTO.h"
#include <string>
#include <iostream>
using namespace std;

TeacherDTO::TeacherDTO() : Person(), id(""), salario() {}

TeacherDTO::TeacherDTO(const string& name, int age, const string& phone, const string& id, const int& salario):Person(name, age, phone), id(id), salario(salario) {}

const string& TeacherDTO::getID() const { return id; }
void TeacherDTO::setID(const string& id) { this->id = id; }

const int& TeacherDTO::getSalario() const{
    return salario;
}

void TeacherDTO::setSalario(const int& salario){
    this->salario = salario;
}

const vector<string>& TeacherDTO::getDisciplinas() const{
    return disciplinas;
}

void TeacherDTO::addDisciplina(const std::string& disciplina) {
    disciplinas.push_back(disciplina);
}

void TeacherDTO::clearDisciplinas() {
    disciplinas.clear();
}

std::ostream& operator<<(std::ostream& out, const TeacherDTO& teacherDTO){
    out << "ID: " << teacherDTO.getID() << endl;
    out << "Name: " << teacherDTO.getName() << endl;
    out << "Age: " << teacherDTO.getAge() << endl;
    out << "Phone: " << teacherDTO.getPhone() << endl;
    out << "Salary: " << teacherDTO.getSalario() << endl;
    return out;
}

