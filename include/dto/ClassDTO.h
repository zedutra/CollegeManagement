#ifndef CLASSDTO_H
#define CLASSDTO_H

#include "Semester.h"
#include "Subject.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class ClassDTO : public Semester, public Subject {
private:
    string idProfessor;
    vector<string> raAlunos;
    vector<double> notasAlunos;

public:
    ClassDTO();
    ClassDTO(int ano, int numeroSemestre, const string& codigo, const string& nome,
          const string& ementa, const string& idProfessor);

    const string& getIdProfessor() const;
    void setIdProfessor(const string& idProfessor);

    const vector<string>& getRaAlunos() const;
    void adicionarAluno(const string& ra);

    const vector<double>& getNotasAlunos() const;
    void adicionarNotaAluno(double nota);

    const string& getCode() const;
    const string& getSubjectName() const;

    void setAno(int ano);
    void setNumeroSemestre(int numeroSemestre);
    void setCodigo(const string& codigo);
    void setNome(const string& nome);
    void setEmenta(const string& ementa);

    friend std::ostream& operator<<(std::ostream& out, const ClassDTO& classDTO);
};

#endif // CLASSDTO_H
