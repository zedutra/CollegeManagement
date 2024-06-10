#include "../../include/dto/Subject.h"
using namespace std;

Subject::Subject(): codigo(" "), nome(" "), ementa(" ") {}

Subject::Subject(const  string& codigo, const string& nome, const string& ementa)
    : codigo(codigo), nome(nome), ementa(ementa) {}

const string& Subject::getCode() const {
    return codigo;
}

void Subject::setCode(const string& codigo) {
    this->codigo = codigo;
}

const string& Subject::getName() const {
    return nome;
}

void Subject::setName(const string& nome) {
    this->nome = nome;
}

const string& Subject::getSyllabus() const {
    return ementa;
}

void Subject::setSyllabus(const string& ementa) {
    this->ementa = ementa;
}