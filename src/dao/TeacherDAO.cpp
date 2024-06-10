#include "../../include/dao/TeacherDAO.h"

void TeacherDAO::add(const TeacherDTO &teacherDTO) {
    teachers[teacherDTO.getID()] = make_shared<TeacherDTO>(teacherDTO);
    College college;
    college.addTeacher(teacherDTO.getID(), teachers[teacherDTO.getID()]);
    std::cout << "Adicionando " << teacherDTO.getName() << " ao sistema..." << std::endl;
}

void TeacherDAO::readTeacher(const TeacherDTO& teacherDTO){
    cout << teacherDTO;
};

void TeacherDAO::update(const TeacherDTO &teacher)
{
    for (auto &t : teachers)
    {
        if (t.second->getID() == teacher.getID()) // Acessando o segundo elemento do pair, que e um shared_ptr para StudentDTO
        {
            *(t.second) = teacher; // Atualizando o StudentDTO apontado pelo shared_ptr
            return;
        }
    }
}

void TeacherDAO::remove(const string &teacherId)
{
    auto it = teachers.find(teacherId);
    if (it != teachers.end()) {
        teachers.erase(it);
    }
}

shared_ptr<TeacherDTO> TeacherDAO::getById(const string &id) const
{
    auto it = College::getTeachers().find(id);
    if (it != College::getTeachers().end())
    {
        // Verificar se e possível fazer a conversao para StudentDTO
        std::shared_ptr<TeacherDTO> teacherDto = std::dynamic_pointer_cast<TeacherDTO>(it->second);
        if (teacherDto)
        {
            return teacherDto;
        }
    }
    return nullptr; // Retornar nullptr se o aluno nao for encontrado ou nao for um StudentDTO
}

vector<shared_ptr<TeacherDTO>> TeacherDAO::getAll() const
{
    const map<string, shared_ptr<TeacherDTO>>& teachers_map = College::getTeachers();
    vector<shared_ptr<TeacherDTO>> teachers_vector;
    for (const auto& teacher : teachers_map)
    {
        shared_ptr<TeacherDTO> teacherDTO = dynamic_pointer_cast<TeacherDTO>(teacher.second);
        if (teacherDTO)
        {
            teachers_vector.push_back(teacherDTO);
        }
    }
    return teachers_vector;
}
