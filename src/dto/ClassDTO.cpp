#include "../../include/dto/ClassDTO.h"

using namespace std;

ClassDTO::ClassDTO(): Subject(), Semester(), idProfessor(" ") {}; 

ClassDTO::ClassDTO(int ano, int numeroSemestre, const string& codigo, const string& nome, const string& ementa, 
    const string& idProfessor) : Semester(ano, numeroSemestre), Subject(codigo, nome, ementa), idProfessor(idProfessor) {};

const string& ClassDTO::getIdProfessor() const {
    return idProfessor;
}

const vector<string>& ClassDTO::getRaAlunos() const {
    return raAlunos;
}

const vector<double>& ClassDTO::getNotasAlunos() const {
    return notasAlunos;
}

const string& ClassDTO::getCode() const {
    return Subject::getCode();
}

const string& ClassDTO::getSubjectName() const {
    return Subject::getName();
}

void ClassDTO::setIdProfessor(const string& idProfessor) {
    this->idProfessor = idProfessor;
}

void ClassDTO::adicionarAluno(const string& ra) {
    raAlunos.push_back(ra);
}

void ClassDTO::adicionarNotaAluno(double nota) {
    notasAlunos.push_back(nota);
}

void ClassDTO::setAno(int ano) {
    Semester::setYear(ano);
}

void ClassDTO::setNumeroSemestre(int numeroSemestre) {
    Semester::setSemesterNumber(numeroSemestre);
}

void ClassDTO::setCodigo(const string& codigo) {
    Subject::setCode(codigo);
}

void ClassDTO::setNome(const string& nome) {
    Subject::setName(nome);
}

void ClassDTO::setEmenta(const string& ementa) {
    Subject::setSyllabus(ementa);
}

std::ostream& operator<<(std::ostream& out, const ClassDTO& classDTO) {
    out << "Code: " << classDTO.getCode() << endl;
    out << "Name: " << classDTO.getSubjectName() << std::endl;
    out << "Syllabus: " << classDTO.getSyllabus() << std::endl;
    out << "Year: " << classDTO.getYear() << std::endl;
    out << "Semester Number: " << classDTO.getSemesterNumber() << std::endl;
    out << "TeacherId: " << classDTO.getIdProfessor() << std::endl;
    out << std::endl;
    return out;
}