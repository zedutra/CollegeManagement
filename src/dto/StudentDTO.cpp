#include "../../include/dto/StudentDTO.h"
using namespace std;
#include <string>
#include <iostream>

StudentDTO::StudentDTO() : Person(), ra(""), course(""){};

StudentDTO::StudentDTO(const string &name, int age, const string &phone, const string &ra, const string &course)
    : Person(name, age, phone), ra(ra), course(course){};

const std::string &StudentDTO::getRA() const { return ra; }
void StudentDTO::setRA(const std::string &ra) { this->ra = ra; }

const string &StudentDTO::getCourse() const { return course; }
void StudentDTO::setCourse(const string &course) { this->course = course; }

const string& StudentDTO::getName() const {
    return Person::getName(); 
}

std::ostream& operator<<(std::ostream& out, const StudentDTO& studentDTO) {
    out << "Nome: " << studentDTO.getName() << endl;
    out << "Idade: " << studentDTO.getAge() << endl;
    out << "Telefone: " << studentDTO.getPhone() << endl;
    out << "RA: " << studentDTO.getRA() << endl;
    out << "Curso: " << studentDTO.getCourse() << endl;  
    return out;
}