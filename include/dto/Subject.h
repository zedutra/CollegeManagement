#ifndef SUBJECT_H
#define SUBJECT_H

#include <string>
using namespace std;

class Subject {
private:
    string codigo;
    string nome;
    string ementa;

public:
    Subject();
    Subject(const string& codigo, const string& nome, const string& ementa);

    const string& getCode() const;
    void setCode(const string& codigo);

    const string& getName() const;
    void setName(const string& nome);

    const string& getSyllabus() const;
    void setSyllabus(const string& ementa);
};

#endif