#ifndef ABSTRACTDAO_HPP
#define ABSTRACTDAO_HPP

#include <memory>
#include <vector>
#include <string>
#include "../../include/controller/College.h" 

// Definicao da classe template abstrata
template <typename T, typename IdType = std::string>

class AbstractDAO {
public:
    // Construtor
    AbstractDAO(shared_ptr<College> college) : college(college) {}

    // Destrutor virtual para garantir que as classes derivadas possam ser destruídas corretamente
    virtual ~AbstractDAO() {}

    // Metodos CRUD
    virtual void add(const T& entity) = 0;   // Adicionar uma nova entidade
    virtual shared_ptr<T> getById(const IdType& id) const = 0;
    virtual vector<shared_ptr<T>> getAll() const = 0; // Obter todas as entidades
    virtual void update(const T& entity) = 0;  // Atualizar uma entidade existente
    virtual void remove(const IdType& id) = 0;  // Remover uma entidade pelo ID

protected:
    shared_ptr<College> college;

};

#endif
