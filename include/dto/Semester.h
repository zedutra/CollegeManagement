#ifndef SEMESTRE_H
#define SEMESTRE_H

class Semester {
protected:
    int year;
    int semesterNumber;

public:
    Semester(int ano, int numeroSemestre);
    Semester();

    int getYear() const;
    void setYear(int ano);

    int getSemesterNumber() const;
    void setSemesterNumber(int numeroSemestre);
};

#endif // SEMESTRE_H