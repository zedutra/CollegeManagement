#ifndef STUDENTDAO_H_
#define STUDENTDAO_H_

#include <memory>
#include <string>
#include <vector>
#include <algorithm>
#include "../dto/StudentDTO.h"
#include "../controller/College.h"
#include "AbstractDAO.h"

class StudentDAO : public AbstractDAO<StudentDTO, std::string>
{
protected:
    map<string, shared_ptr<StudentDTO>> students;
    shared_ptr<College> college;

public:
    StudentDAO() : AbstractDAO<StudentDTO, std::string>(nullptr) {} 
    void add(const StudentDTO& student) override;
    void remove(const std::string& ra) override;
    std::vector<std::shared_ptr<StudentDTO>> getAll() const override;
    std::shared_ptr<StudentDTO> getById(const std::string& id) const override;
    void update(const StudentDTO& student) override;
    static void readStudent(const StudentDTO& studentDTO);
};

#endif /* STUDENTDAO_H_ */
