#ifndef TEACHERDTO_HPP
#define TEACHERDTO_HPP
#include <string>
#include <vector>
#include "../../include/dto/Person.h"
using namespace std;

class TeacherDTO : public Person {
private:
    string id;
    int salario;
    vector<string> disciplinas;

public:
    TeacherDTO();
    TeacherDTO(const string& name, int age, const string& phone, const string& id, const int& salario);

    const string& getID() const;
    void setID(const string& id);

    const int& getSalario() const;
    void setSalario(const int& salario);

    void addDisciplina(const string& disciplina);
    const vector<string>& getDisciplinas() const;

    void clearDisciplinas();

    friend std::ostream& operator<<(std::ostream& out, const TeacherDTO& teacherDTO);
};

#endif
