#ifndef TEACHERDAO_H_
#define TEACHERDAO_H_

#include "AbstractDAO.h"
#include "../dto/TeacherDTO.h"
#include "../controller/College.h"
#include <iostream>
#include <vector>
#include <memory>
#include <algorithm>

using namespace std;

class TeacherDAO : public AbstractDAO<TeacherDTO, std::string> { // Adicionando std::string como tipo de identificacao
private:
    map<string,shared_ptr<TeacherDTO>> teachers;
    shared_ptr<College> college;

public:
    TeacherDAO() : AbstractDAO<TeacherDTO, std::string>(nullptr) {} // Atualizando o construtor conforme necessario
    // Metodos
    void add(const TeacherDTO& teacherDTO) override;
    void update(const TeacherDTO& teacher) override;
    std::shared_ptr<TeacherDTO> getById(const std::string& id) const override;
    std::vector<shared_ptr<TeacherDTO>> getAll() const override;
    void remove(const std::string& id) override;
    void readTeacher(const TeacherDTO& teacherDTO);
};

#endif
