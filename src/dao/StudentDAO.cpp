#include "../../include/dao/StudentDAO.h"

std::shared_ptr<StudentDTO> StudentDAO::getById(const std::string &id) const
{
    auto it = College::getStudents().find(id);
    if (it != College::getStudents().end())
    {
        // Verificar se e possível fazer a conversao para StudentDTO
        std::shared_ptr<StudentDTO> studentDto = std::dynamic_pointer_cast<StudentDTO>(it->second);
        if (studentDto)
        {
            return studentDto;
        }
    }
    return nullptr; // Retornar nullptr se o aluno nao for encontrado ou nao for um StudentDTO
}

void StudentDAO::add(const StudentDTO &student)
{
    students[student.getRA()] = make_shared<StudentDTO>(student);
    College college;
    college.addStudent(student.getRA(), students[student.getRA()]);
    std::cout << "Adicionando " << student.getName() << " ao sistema..." << std::endl;
}

void StudentDAO::remove(const std::string& ra) {
    auto it = students.find(ra);
    if (it != students.end()) {
        students.erase(it);
    }
}

void StudentDAO::update(const StudentDTO &student)
{
    for (auto &s : students)
    {
        if (s.second->getRA() == student.getRA()) // Acessando o segundo elemento do pair, que e um shared_ptr para StudentDTO
        {
            *(s.second) = student; // Atualizando o StudentDTO apontado pelo shared_ptr
            return;
        }
    }
}

vector<shared_ptr<StudentDTO>> StudentDAO::getAll() const
{
    const map<string, shared_ptr<StudentDTO>>& students_map = College::getStudents();
    vector<shared_ptr<StudentDTO>> students_vector;
    for (const auto& student : students_map)
    {
        shared_ptr<StudentDTO> studentDTO = dynamic_pointer_cast<StudentDTO>(student.second);
        if (studentDTO)
        {
            students_vector.push_back(studentDTO);
        }
    }
    return students_vector;
}

void StudentDAO::readStudent(const StudentDTO& studentDTO){
    cout << studentDTO;
};
