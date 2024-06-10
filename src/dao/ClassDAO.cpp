#include "../../include/dao/ClassDAO.h"

void ClassDAO::add(const ClassDTO &classDTO)
{
    classes.push_back(make_shared<ClassDTO>(classDTO));
};

vector<shared_ptr<ClassDTO>> ClassDAO::getAll() const
{
    const auto& classes = College::getClasses();
    vector<shared_ptr<ClassDTO>> classes_vector;

    for (const auto& classDTO : classes)
    {
        std::shared_ptr<ClassDTO> classDto = dynamic_pointer_cast<ClassDTO>(classDTO);
        if (classDto)
        {
            classes_vector.push_back(classDto);
        }
    }

    return classes_vector;
}


shared_ptr<ClassDTO> ClassDAO::getById(const std::string &code) const
{
    const auto& classes = College::getClasses();
    for (const auto& classDTO : classes)
    {
        if (classDTO->getCode() == code)
        {
            // Verificar se e possível fazer a conversao para ClassDTO
            std::shared_ptr<ClassDTO> classDto = dynamic_pointer_cast<ClassDTO>(classDTO);
            if (classDto)
            {
                return classDto;
            }
        }
    }
    return nullptr; // Retornar nullptr se a turma nao for encontrada
}


void ClassDAO::readClass(const ClassDTO& classDTO)
{
    cout << classDTO;
}

void ClassDAO::update(const ClassDTO& classdto)
{
    string code;
    string name;
    string syllabus;
    int year;
    int semesterNumber;

    // Solicitar o codigo da classe
    cout << "Digite o codigo da classe que deseja atualizar: ";
    cin >> code;

    // Encontrar a classe com o codigo fornecido
    auto it = find_if(classes.begin(), classes.end(), [code](const std::shared_ptr<ClassDTO> &classPtr)
                      { return classPtr->getCode() == code; });

    if (it != classes.end())
    {
        // Solicitar as novas informacoes da classe
        cout << "Digite o novo nome: ";
        cin >> name;
        cout << "Digite a nova syllabus: ";
        cin >> syllabus;
        cout << "Digite o novo ano: ";
        cin >> year;
        cout << "Digite o novo numero do semestre: ";
        cin >> semesterNumber;

        // Atualizar as informacoes da classe
        (*it)->setName(name);
        (*it)->setSyllabus(syllabus);
        (*it)->setYear(year);
        (*it)->setSemesterNumber(semesterNumber);

        cout << "Classe atualizada com sucesso." << endl;
    }
    else
    {
        cout << "Classe nao encontrada." << endl;
    }
}

void ClassDAO::remove(const string& code)
{
    auto it = find_if(classes.begin(), classes.end(),
                      [code](const std::shared_ptr<ClassDTO> &classPtr)
                      { return classPtr->getCode() == code; });

    if (it != classes.end())
    {
        classes.erase(it);
        cout << "Classe deletada com sucesso." << endl;
    }
    else
    {
        cout << "Classe nao encontrada ou ja foi deletada." << endl;
    }
}

