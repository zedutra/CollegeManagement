#include "../../include/dto/Semester.h"
using namespace std;

Semester::Semester() : year(0), semesterNumber(0) {}
Semester::Semester(int ano, int numeroSemestre) : year(ano), semesterNumber(numeroSemestre) {}

int Semester::getYear() const {
    return year;
}

void Semester::setYear(int ano) {
    this->year = ano;
}

int Semester::getSemesterNumber() const {
    return semesterNumber;
}

void Semester::setSemesterNumber(int numeroSemestre) {
    this->semesterNumber = numeroSemestre;
}