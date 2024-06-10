#ifndef STUDENTDTO_HPP
#define STUDENTDTO_HPP

#include "Person.h"
using namespace std;
#include <string>
class StudentDTO : public Person {
private:
     string ra;
     string course;

public:
    StudentDTO();
    StudentDTO(const string& name, int age, const string& phone, const string& ra, const string& course);

    const string& getRA() const;
    void setRA(const string& ra);

    const string& getCourse() const;
    void setCourse(const string& course);

    const string& getName() const;

    friend std::ostream& operator<<(std::ostream& out, const StudentDTO& studentDTO);
};

#endif