#ifndef CLASSDAO_H_
#define CLASSDAO_H_

#include <memory>
#include <vector>
#include <iostream>
#include <algorithm>
#include "AbstractDAO.h"
#include "../dto/ClassDTO.h"
#include "../controller/College.h"
//#include "../../"

using namespace std;

class ClassDAO : public AbstractDAO<ClassDTO> {

private:
    vector<shared_ptr<ClassDTO>> classes;

public:
    // Construtor que inicializa college (herdado de AbstractDAO)
    ClassDAO(shared_ptr<College> college) : AbstractDAO<ClassDTO>(college) {}

    // Adiciona uma nova turma de disciplina ao vetor correspondente
    void add(const ClassDTO& classDTO) override;

    // Outros metodos para ler, atualizar e deletar turmas de disciplina, se necessario
    static void readClass(const ClassDTO& classDTO);
    void update(const ClassDTO& classes) override;
    void remove(const string& code) override;
    std::vector<std::shared_ptr<ClassDTO>> getAll() const override;
    std::shared_ptr<ClassDTO> getById(const std::string& id) const override;
};

#endif
