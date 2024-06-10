#include "../../include/controller/Controller.h"
#include <iostream>

void Controller::start()
{
    int option = 0;

    while (option != 7)
    {
        mainMenu.display();                // Exibir opcoes
        option = mainMenu.validarOption(); // Metodo de Menu

        switch (option)
        {
        case 1:
            showStudentsMenu();
            break;
        case 2:
            showTeachersMenu();
            break;
        case 3:
            showSubjectsMenu();
            break;
        case 4:
            showClassMenu();
            break;
        case 5:
            showReportsMenu();
            break;
        case 6:
            showHelpMenu();
            break;
        case 7:
            printf("Obrigado por utilizar! Encerrando...");
            break;
        default:
            option = mainMenu.validarOption(); // Chamada para validar a opcao do usuario novamente
            break;
        }
    }
}
// Meotodo para o submenu Student
void Controller::showStudentsMenu()
{
    int option;
    Menu studentsMenu({"Novo estudante", "Visualizar todos os estudantes", "Procurar estudante pelo RA", "Alterar estudante", "Remover estudante", "Voltar para o Menu Principal"});
    StudentDAO studentDAO;
    string nome, phone, ra, course;
    int age;
    shared_ptr<StudentDTO> newStudent;

    // Declaracao da variavel fora do switch
    auto it = College::Students.end();

    do
    {
        studentsMenu.display();
        option = studentsMenu.validarOption();
        switch (option)
        {
        case 1:
        {
            // Solicitar detalhes do usuario
            cin.ignore();
            cout << "Digite o nome do novo estudante: ";
            getline(cin, nome);

            cout << "Digite o telefone do novo estudante: ";
            getline(cin, phone);

            cout << "Digite o ra do novo estudante: ";
            getline(cin, ra);

            cout << "Digite o curso do novo estudante: ";
            getline(cin, course);

            string x;
                bool isValid = false;
                do {
                // Solicitar informacoes ao usuario
                cout << "Digite a idade do novo estudante: ";
                cin >> x;
                if (Menu::isInteger(x)) {
                    isValid = true;
                    age = stoi(x);
                } else {
                    std::cout << "Voce digitou uma string. Por favor, digite um numero inteiro.\n";
                }
                } while (!isValid);
            

            // Criar um objeto StudentDTO com as informacoes novas
            StudentDTO student(nome, age, phone, ra, course);
            newStudent = make_shared<StudentDTO>(student);

            // Adicionar o novo estudante ao sistema usando o DAO correspondente
            studentDAO.add(*newStudent);

            cout << "Novo estudante adicionado com sucesso!" << endl;
            break;
        }
        case 2:
            // Verificar se ha estudantes cadastrados
            cin.ignore();
            if (College::Students.empty())
            {
                cout << "Nao ha estudantes cadastrados." << endl;
            }
            else
            {
                StudentDAO studentDAO;
                for (const auto& student : College::Students)
                {
                    studentDAO.readStudent(*student.second);
                    cout << "-----------------------------" << endl;
                }
            }
            break;
        case 3:
            // Solicitar detalhes do usuario
            cin.ignore();
            cout << "Digite o RA do estudante que deseja encontrar: ";
            getline(cin, ra);

            // Verificar se o estudante existe
            it = College::Students.find(ra);
            if (it != College::Students.end())
            {
                // Imprimir informacoes do estudante
                auto student = it->second;
                cout << "Nome: " << student->getName() << endl;
                cout << "Idade: " << student->getAge() << endl;
                cout << "Telefone: " << student->getPhone() << endl;
                auto studentDTO = std::dynamic_pointer_cast<StudentDTO>(student);
                cout << "RA: " << studentDTO->getRA() << endl;
                cout << "Curso: " << studentDTO->getCourse() << endl;
            }
            else
            {
                // Estudante nao existe
                cout << "Estudante nao existente. Se desejar, cadastre-o." << endl;
            }
            break;
        case 4:
            // Solicitar o RA do estudante a ser alterado
            cin.ignore();
            cout << "Digite o RA do estudante a ser alterado: ";
            getline(cin, ra);

            // Verificar se o estudante existe
            it = College::Students.find(ra);
            if (it != College::Students.end())
            {
                // Estudante encontrado, permitir alteracoes
                cout << "Estudante encontrado. Insira as novas informacoes:" << endl;

                // Solicitar novas informacoes do estudante
                string newName, newPhone, newCourse;
                int newAge;

                cout << "Novo nome: ";
                getline(cin, newName);
                string x;
                bool isValid = false;
                do {
                // Solicitar informacoes ao usuario
                cout << "Nova idade: ";
                cin >> x;
                if (Menu::isInteger(x)) {
                    isValid = true;
                    newAge = stoi(x);
                } else {
                    std::cout << "Voce digitou uma string. Por favor, digite um numero inteiro.\n";
                }
                } while (!isValid);
            
                cin.ignore(); // Limpar o buffer de entrada
                cout << "Novo telefone: ";
                getline(cin, newPhone);
                cout << "Novo curso: ";
                getline(cin, newCourse);

                // Aplicar as alteracoes
                it->second->setName(newName);
                it->second->setAge(newAge);
                it->second->setPhone(newPhone);
                auto studentDTO = std::dynamic_pointer_cast<StudentDTO>(it->second);
                studentDTO->setCourse(newCourse);

                cout << "Estudante alterado com sucesso!" << endl;
            }
            else
            {
                cout << "Estudante com o RA fornecido nao encontrado." << endl;
            }
            break;
        case 5:
            // Solicitar o RA do estudante a ser removido
            cin.ignore();
            cout << "Digite o RA do estudante a ser removido: ";
            getline(cin, ra);

            // Verificar se o estudante existe
            it = College::Students.find(ra);
            if (it != College::Students.end())
            {
                // Permitir remocao
                College::Students.erase(it);
                cout << "Estudante removido com sucesso!" << endl;
            }
            else
            {
                cout << "Estudante com o RA fornecido nao encontrado." << endl;
            }
            break;
        case 6:
            cout << "Retornando pro Menu Principal" << endl;
            break;
        default:
            cout << "Opcao invalida. Favor escolher novamente." << endl;
            break;
        }
    } while (option != 6);
}

// Meotodo para o submenu Teacher
void Controller::showTeachersMenu()
{
    int option;
    Menu teachersMenu({"Novo professor", "Visualizar todos os professores", "Procurar professor pelo ID", "Alterar professor", "Remover professor", "Voltar para o Menu Principal"});
    shared_ptr<TeacherDTO> newTeacher; // Corrigido para TeacherDTO
    TeacherDAO teacherDAO;
    string nome, phone, id, disciplina;
    int age, salario;
    vector<string> disciplinas;
    auto it = College::Students.end();

    do
    {
        teachersMenu.display();                // Exibir opcoes
        option = teachersMenu.validarOption();
        switch (option)
        {
        case 1:
        {
            // Solicitar detalhes pro usuario
            cin.ignore();
            cout << "Digite o nome do novo professor: ";
            getline(cin, nome);

            cout << "Digite o telefone do novo professor: ";
            getline(cin, phone);

            cout << "Digite o id do novo professor: ";
            getline(cin, id);

            string x;
                bool isValid = false;
                do {
                // Solicitar informacoes ao usuario
                cout << "Digite a idade do novo professor: ";
                cin >> x;
                if (Menu::isInteger(x)) {
                    isValid = true;
                    age = stoi(x);
                } else {
                    std::cout << "Voce digitou uma string. Por favor, digite um numero inteiro.\n";
                }
                } while (!isValid);
            
            do {
                // Solicitar informacoes ao usuario
                cout << "Digite o salario do novo professor: ";
                cin >> x;
                if (Menu::isInteger(x)) {
                    isValid = true;
                    salario = stoi(x);
                } else {
                    std::cout << "Voce digitou uma string. Por favor, digite um numero inteiro.\n";
                }
                } while (!isValid);

            cin.ignore(); // Limpar o buffer do teclado

            // Solicitar as disciplinas que o professor leciona
            cout << "Digite as disciplinas que o professor leciona (digite 'fim' para encerrar):" << endl;
            while (true)
            {
                cout << "> ";
                getline(cin, disciplina);
                if (disciplina == "fim")
                {
                    break;
                }
                disciplinas.push_back(disciplina);
            }

            // Criar um objeto TeacherDTO com as infos novas
            newTeacher = make_shared<TeacherDTO>(nome, age, phone, id, salario);

            // Adicionar as disciplinas ao professor
            for (const auto &disc : disciplinas)
            {
                newTeacher->addDisciplina(disc);
            }
            teacherDAO.add(*newTeacher);

            cout << "Novo professor adicionado com sucesso!" << endl;
            break;
        }
        case 2:
        {
            // Verificar se ha professores cadastrados
            cin.ignore();
            if (College::Teachers.empty())
            {
                cout << "Nao ha professores cadastrados." << endl;
            }
            else
            {
                // Exibindo professores
                TeacherDAO teacherDAO;
                for (const auto& teacher : College::Teachers)
                {
                    teacherDAO.readTeacher(*teacher.second);
                    cout << "-----------------------------" << endl;
                }
            }
            break;
        }
        case 3:
        {
            // Solicitar detalhes pro usuario
            cin.ignore();
            cout << "Digite o ID do professor que deseja encontrar: ";
            getline(cin, id);

            // Verificar se o professor existe
            auto it = College::Teachers.find(id);
            if (it != College::Teachers.end())
            {

                // Imprimir informacoes do estudante
                auto teacher = it->second;
                cout << "Nome: " << teacher->getName() << endl;
                cout << "Idade: " << teacher->getAge() << endl;
                cout << "Telefone: " << teacher->getPhone() << endl;
                auto teacherDTO = std::dynamic_pointer_cast<TeacherDTO>(teacher);
                cout << "ID: " << teacherDTO->getID() << endl;
                cout << "Salario: " << teacherDTO->getSalario() << endl;
                cout << "Disciplinas lecionadas:" << endl;
                for (const auto &disciplina : teacherDTO->getDisciplinas())
                {
                    cout << "- " << disciplina << endl;
                }
            }
            else
            {
                // Professor nao existe
                cout << "Professor nao existente. Se desejar, cadastre-o." << endl;
            }
            break;
        }
        case 4:
        {
            // Solicitar o professor a ser alterado
            cin.ignore();
            cout << "Digite o ID do professor a ser alterado: ";
            getline(cin, id);

            // Verificar se o professor existe
            auto it = College::Teachers.find(id);
            if (it != College::Teachers.end())
            {

                // Professor encontrado, permitir alteracoes
                cout << "Professor encontrado. Insira as novas informacoes:" << endl;

                // Solicitar novos detalhes do estudante
                string newName, newPhone, newCourse;
                int newAge, newSalary;
                vector<string> newDisciplinas;

                cout << "Novo nome: ";
                getline(cin, newName);

                string x;
                bool isValid = false;
                do {
                // Solicitar informacoes ao usuario
                cout << "Nova idade: ";
                cin >> x;
                if (Menu::isInteger(x)) {
                    isValid = true;
                    newAge = stoi(x);
                } else {
                    std::cout << "Voce digitou uma string. Por favor, digite um numero inteiro.\n";
                }
                } while (!isValid);

                cin.ignore(); // Limpar o buffer de entrada
                cout << "Novo telefone: ";
                getline(cin, newPhone);

                do {
                // Solicitar informacoes ao usuario
                cout << "Novo Salario: ";
                cin >> x;
                if (Menu::isInteger(x)) {
                    isValid = true;
                    newSalary = stoi(x);
                } else {
                    std::cout << "Voce digitou uma string. Por favor, digite um numero inteiro.\n";
                }
                } while (!isValid);

                // Solicitar as novas disciplinas que o professor leciona
                cout << "Digite as novas disciplinas que o professor leciona (digite 'fim' para encerrar):" << endl;
                string disciplina;
                while (true)
                {
                    cout << "> ";
                    getline(cin, disciplina);
                    if (disciplina == "fim")
                    {
                        break;
                    }
                    newDisciplinas.push_back(disciplina);
                }

                // Aplicar as alteracoes
                it->second->setName(newName);
                it->second->setAge(newAge);
                it->second->setPhone(newPhone);
                auto teacherDTO = std::dynamic_pointer_cast<TeacherDTO>(it->second);
                teacherDTO->setSalario(newSalary);
                // Limpar as disciplinas atuais e adicionar as novas
                teacherDTO->clearDisciplinas();
                for (const auto &disc : newDisciplinas)
                {
                    teacherDTO->addDisciplina(disc);
                }

                cout << "Professor alterado com sucesso!" << endl;
            }
            else
            {
                cout << "Professor com o ID fornecido nao encontrado." << endl;
            }
            break;
        }
        case 5:
        {
            // Solicitar o ID do professor a ser removido
            cin.ignore();
            cout << "Digite o ID do professor a ser removido: ";
            getline(cin, id);

            // Verificar se o professor existe
            auto it = College::Teachers.find(id);
            if (it != College::Teachers.end())
            {
                // Remover o professor do mapa de professores
                College::Teachers.erase(it);
                cout << "Professor removido com sucesso!" << endl;
            }
            else
            {
                cout << "Professor com o ID fornecido nao encontrado." << endl;
            }
            break;
        }
        case 6:
        {
            cout << "Retornando para o Menu Principal" << endl;
            break;
        }
        default:
        {
            cout << "Opcao invalida. Favor escolher novamente." << endl;
            break;
        }
        }
    } while (option != 6);
}

// Meotodo para o submenu Subjects
void Controller::showSubjectsMenu()
{
    int option;
    Menu subjectsMenu({"Nova disciplina", "Visualizar todas as disciplinas", "Procurar disciplina pelo codigo", "Alterar disciplina", "Voltar para o Menu Principal"});
    string codigo, nome, ementa;
    shared_ptr<Subject> newsubject;
    do
    {
        subjectsMenu.display();
        option = subjectsMenu.validarOption();
        switch (option)
        {
        case 1:{
            // Solicitar detalhes da nova disciplina ao usuario
            cin.ignore();
            cout << "Digite o codigo da nova disciplina: ";
            getline(cin, codigo);

            cout << "Digite o nome da nova disciplina: ";
            getline(cin, nome);

            cout << "Digite a ementa da nova disciplina: ";
            getline(cin, ementa);

            // Criar um objeto Subject com as informacoes fornecidas
            newsubject = make_shared<Subject>(codigo, nome, ementa);
            College::Subjects.push_back(newsubject);
            break;
        }
        case 2:{
            // Verificar se ha disciplinas cadastrados
            cin.ignore();
            if (College::Subjects.empty())
            {
                cout << "Nao ha disciplinas cadastrados." << endl;
            }
            else
            {
                // Exibir todas as disciplinas
                cout << "Disciplinas cadastradas:" << endl;
                for (const auto &subject : College::Subjects)
                {
                    cout << "Codigo: " << subject->getCode() << endl;
                    cout << "Nome: " << subject->getName() << endl;
                    cout << "Ementa: " << subject->getSyllabus() << endl;
                    cout << "-----------------------------" << endl;
                }
            }
            break;
        }
        case 3:{
            // Solicitar o codigo da disciplina a ser encontrada
            cin.ignore();
            cout << "Digite o codigo da disciplina que deseja encontrar: ";
            getline(cin, codigo);

            // Verificar se a disciplina existe
            auto it = find_if(College::Subjects.begin(), College::Subjects.end(), [&codigo](const shared_ptr<Subject> &subject)
                              { return subject->getCode() == codigo; });

            if (it != College::Subjects.end())
            {
                // Disciplina encontrada, imprimir informacoes
                cout << "Codigo: " << (*it)->getCode() << endl;
                cout << "Nome: " << (*it)->getName() << endl;
                cout << "Ementa: " << (*it)->getSyllabus() << endl;
            }
            else
            {
                // Disciplina nao encontrada
                cout << "Disciplina com o codigo fornecido nao encontrada." << endl;
            }
            break;
        }
        case 4:{
            // Solicitar o codigo da disciplina a ser alterada
            cin.ignore();
            cout << "Digite o codigo da disciplina que deseja alterar: ";
            getline(cin, codigo);

            // Verificar se a disciplina existe
            auto it = find_if(College::Subjects.begin(), College::Subjects.end(), [&codigo](const shared_ptr<Subject> &subject)
                              { return subject->getCode() == codigo; });

            if (it != College::Subjects.end())
            {
                // Disciplina encontrada, permitir alteracoes
                cout << "Disciplina encontrada. Insira as novas informacoes:" << endl;

                string novoNome, novaEmenta;

                cout << "Novo nome: ";
                getline(cin, novoNome);
                cout << "Nova ementa: ";
                getline(cin, novaEmenta);

                // Aplicar as alteracoes
                (*it)->setName(novoNome);
                (*it)->setSyllabus(novaEmenta);

                cout << "Disciplina alterada com sucesso!" << endl;
            }
            else
            {
                // Disciplina nao encontrada
                cout << "Disciplina com o codigo fornecido nao encontrada." << endl;
            }
            break;
        }
        case 5:{
            cout << "Retornando pro Menu Principal" << endl;
            break;
        }
        default:
            cout << "Opcao invalida. Favor escolher novamente." << endl;
            break;
        }
    } while (option != 5);
}

// Meotodo para o submenu Class
void Controller::showClassMenu()
{
    int option;
    Menu classMenu({"Nova turma", "Adicionar professor a uma turma", "Adicionar estudante e nota a uma turma", "Mostrar todas as turmas", "Pesquisar turma por codigo", "Alterar turma", "Remover turma", "Voltar para o Menu Principal"});
    int numeroSemestre, ano;
    string codigo, nome, ementa, idProfessor;
    shared_ptr<ClassDTO> newClass;
    shared_ptr<Subject> newSubject;
    
    do
    {
        classMenu.display();
        option = classMenu.validarOption();
        switch(option)
        {
            case 1:{
                // Solicitar informacoes ao usuario
                string x;
                bool isValidSemestre = false;
                bool isValidAno = false;
                do {
                // Solicitar informacoes ao usuario
                cout << "Digite o ano do semestre: ";
                cin >> x;
                if (Menu::isInteger(x)) {
                    isValidAno = true;
                    ano = stoi(x);
                } else {
                    std::cout << "Voce digitou uma string. Por favor, digite um numero inteiro.\n";
                }
                } while (!isValidAno);

                do {
                // Solicitar informacoes ao usuario
                cout << "Digite o numero do semestre: ";
                cin >> x;
                if (Menu::isInteger(x)) {
                    isValidAno = true;
                    numeroSemestre = stoi(x);
                } else {
                    std::cout << "Voce digitou uma string. Por favor, digite um numero inteiro.\n";
                }
                } while (!isValidAno);
                cin.ignore(); // Limpar o buffer do newline deixado pelo cin

                cout << "Digite o codigo da disciplina: ";
                getline(cin, codigo);
                cout << "Digite o nome da disciplina: ";
                getline(cin, nome);
                cout << "Digite a ementa da disciplina: ";
                getline(cin, ementa);
                cout << "Digite o ID do professor: ";
                getline(cin, idProfessor);

                // Criar a nova turma
                newClass = make_shared<ClassDTO>(ano, numeroSemestre, codigo, nome, ementa, idProfessor);

                // Adicionar a turma a lista de turmas
                College::Classes.push_back(newClass);

                break;
            }
            case 2:{
                // Adicionar professor a uma turma
                // Solicitar informacoes ao usuario
                cin.ignore();
                cout << "Digite o codigo da turma: ";
                getline(cin, codigo); // Le o codigo da turma
                cout << "Digite o ID do professor: ";
                getline(cin, idProfessor); // Le o ID do professor

                // Verificar se a turma existe
                auto it = find_if(College::Classes.begin(), College::Classes.end(),
                    [&codigo](const shared_ptr<ClassDTO>& cls) {
                        return cls->getCode() == codigo;
                    });

                if (it != College::Classes.end()) {
                    // Turma encontrada
                    cout << "Turma encontrada, ID do professor antes de set: " << (*it)->getIdProfessor() << endl; // Debug
                    (*it)->setIdProfessor(idProfessor);
                    cout << "ID do professor depois de set: " << (*it)->getIdProfessor() << endl; // Debug
                    cout << "Professor adicionado com sucesso a turma " << codigo << endl;
                } else {
                    cout << "Turma nao encontrada!" << endl;
                }
                break;
            }
            case 3:{
                // Adicionar estudante e nota a uma turma
                string codigoTurma;
                int nota;
                string ra;

                 // Solicitar informações ao usuario
                cin.ignore(); // Limpar o buffer do newline deixado pelo cin

                cout << "Digite o codigo da turma: ";
                getline(cin, codigoTurma);

                cout << "Digite o RA do estudante: ";
                getline(cin, ra);

                cout << "Digite a nota do estudante: ";
                cin >> nota;
                cin.ignore(); // Limpar o buffer do newline deixado pelo cin

                // Encontrar a turma correspondente pelo codigo
                // Verificar se a turma existe
                auto it = find_if(College::Classes.begin(), College::Classes.end(),
                    [&codigoTurma](const shared_ptr<ClassDTO>& cls) {
                        return cls->getCode() == codigoTurma;
                    });
                

                if (it != College::Classes.end()) {
                    // Turma encontrada
                    // Agora voce pode adicionar o estudante e sua nota a essa turma
                    (*it)->adicionarAluno(ra);
                    (*it)->adicionarNotaAluno(nota);
                    cout << "Estudante e nota adicionados com sucesso a turma " << codigoTurma << endl;
                } else {
                    cout << "Turma nao encontrada!" << endl;
                }
                break;
            }
            case 4:{
                // Mostrar todas as turmas
                College college;
                cout << "Lista de turmas: " << endl;
                for (const auto& turma : College::Classes) {
                    ClassDAO::readClass(*turma); // Chamada correta da funçao readClass
                }
            }
            break;
            case 5:{
                // Pesquisar turma por codigo
                string codigoTurma;

                // Solicitar informações ao usuario
                cin.ignore();
                cout << "Digite o codigo da turma: ";
                getline(cin, codigoTurma);

                // Encontrar a turma correspondente pelo codigo
                auto it = find_if(College::Classes.begin(), College::Classes.end(),
                    [&codigoTurma](const shared_ptr<ClassDTO>& cls) {
                        return cls->getCode() == codigoTurma;
                    });

                if (it != College::Classes.end()) {
                    // Turma encontrada
                    cout << "Turma encontrada:" << endl;
                    cout << "Codigo da turma: " << (*it)->getCode() << endl;
                    cout << "Nome da disciplina: " << (*it)->getSubjectName() << endl;
                    cout << "ID do professor: " << (*it)->getIdProfessor() << endl;
                    // Adicione aqui quaisquer outras informações que deseja mostrar sobre a turma
                } else {
                    cout << "Turma nao encontrada!" << endl;
                }
                break;
            }
            case 6:{
                // Alterar turma
                string codigoTurma;
                int ano, numeroSemestre;
                string codigo, nome, ementa, idProfessor;

                // Solicitar o codigo da turma que deseja alterar
                cin.ignore();
                cout << "Digite o codigo da turma que deseja alterar: ";
                getline(cin, codigoTurma);

                // Encontrar a turma correspondente pelo codigo
                auto it = find_if(College::Classes.begin(), College::Classes.end(),
                    [&codigoTurma](const shared_ptr<ClassDTO>& cls) {
                        return cls->getCode() == codigoTurma;
                    });

                if (it != College::Classes.end()) {
                    // Turma encontrada, voce pode fazer as alterações desejadas aqui
                    // Solicitar novas informações ao usuario
                    cout << "Digite o ano do semestre: ";
                    cin >> ano;
                    cout << "Digite o numero do semestre: ";
                    cin >> numeroSemestre;
                    cin.ignore(); // Limpar o buffer do newline deixado pelo cin

                    cout << "Digite o codigo da disciplina: ";
                    getline(cin, codigo);
                    cout << "Digite o nome da disciplina: ";
                    getline(cin, nome);
                    cout << "Digite a ementa da disciplina: ";
                    getline(cin, ementa);
                    cout << "Digite o ID do professor: ";
                    getline(cin, idProfessor);

                    // Atualizar os atributos da turma (*it) com as novas informações
                    (*it)->setAno(ano);
                    (*it)->setNumeroSemestre(numeroSemestre);
                    (*it)->setCodigo(codigo);
                    (*it)->setNome(nome);
                    (*it)->setEmenta(ementa);
                    (*it)->setIdProfessor(idProfessor);

                    cout << "Turma alterada com sucesso." << endl;
                } else {
                    cout << "Turma nao encontrada!" << endl;
                }
                break;
            }
            case 7:{
                // Remover turma
                string codigoTurma;
                
                // Solicitar o codigo da turma ao usuario
                cin.ignore();
                cout << "Digite o codigo da turma que deseja remover: ";
                getline(cin, codigoTurma);
                
                // Verificar se a turma existe
                auto it = find_if(College::Classes.begin(), College::Classes.end(),
                    [&codigoTurma](const shared_ptr<ClassDTO>& cls) {
                        return cls->getCode() == codigoTurma;
                    });

                if (it != College::Classes.end()) {
                    // Turma encontrada, remover da lista
                    College::Classes.erase(it);
                    cout << "Turma removida com sucesso!" << endl;
                } else {
                    cout << "Turma nao encontrada!" << endl;
                }
                break;
            }
            case 8:
                cout << "Retornando pro Menu Principal" << endl;
                break;
            default:
                cout << "Opcao invalida. Favor escolher novamente." << endl;
                break;
        }
    } while (option != 8);
}

// Meotodo para o submenu Reports
void Controller::showReportsMenu()
{
    int option;
    Menu reportsMenu({"Historico Escolar do Estudante", "Disciplinas em que o Estudante esta Matriculado", "Estudantes Matriculados na Disciplina", "Media de Notas de uma Disciplina", "Voltar para o Menu Principal"});
    string ra;
    
    do
    {
        reportsMenu.display();
        option = reportsMenu.validarOption();
        
        switch (option)
        {
            case 1: {
                // Historico Escolar do Estudante
                cin.ignore();
                cout << "Digite o RA do estudante: ";
                getline(cin, ra);
                cout << "RA LIDO: " << ra << endl;

                // Percorrer todas as turmas
                for (const auto& turma : College::Classes) {
                    // Verificar se o estudante esta matriculado na turma
                    auto itRa = find(turma->getRaAlunos().begin(), turma->getRaAlunos().end(), ra);
                    if (itRa != turma->getRaAlunos().end()) {
                        // Estudante encontrado, encontrar o índice do RA
                        auto index = distance(turma->getRaAlunos().begin(), itRa);

                        // Obter a nota correspondente ao índice
                        double nota = turma->getNotasAlunos()[index];

                        cout << "Disciplina: " << turma->getSubjectName() << " - Nota: " << nota << endl;
                    }
                }

                break;
            }
            case 2: {
                // Historico Escolar do Estudante
                cin.ignore();
                cout << "Digite o RA do estudante: ";
                getline(cin, ra);

                // Percorrer todas as turmas
                for (const auto& turma : College::Classes) {
                    // Verificar se o estudante esta matriculado na turma
                    auto itRa = find(turma->getRaAlunos().begin(), turma->getRaAlunos().end(), ra);
                    if (itRa != turma->getRaAlunos().end()) {
                        // Estudante encontrado, encontrar o índice do RA
                        auto index = distance(turma->getRaAlunos().begin(), itRa);

                        // Obter a nota correspondente ao índice
                        double nota = turma->getNotasAlunos()[index];

                        cout << "Disciplina: " << turma->getSubjectName() << endl;
                    }
                }

                break;
            }
            case 3:{
                // Estudantes Matriculados na Disciplina
                string codigoDisciplina;
                cin.ignore();
                cout << "Digite o codigo da disciplina: ";
                getline(cin, codigoDisciplina);

                // Buscar a turma com o codigo da disciplina fornecido
                auto itTurma = find_if(College::Classes.begin(), College::Classes.end(),
                    [&codigoDisciplina](const shared_ptr<ClassDTO>& turma) {
                        return turma->getCode() == codigoDisciplina;
                    });

                if (itTurma != College::Classes.end()) {
                    // Turma encontrada, exibir os estudantes matriculados
                    cout << "Estudantes matriculados na disciplina " << codigoDisciplina << ":" << endl;
                    const vector<string>& raAlunos = (*itTurma)->getRaAlunos();
                    for (const auto& ra : raAlunos) {
                        cout << "RA: " << ra << endl;
                    }
                } else {
                    cout << "Disciplina nao encontrada!" << endl;
                }
                break;
            }
            case 4:{
                // Media de Notas de uma Disciplina
                string codigoDisciplina;
                cin.ignore();
                cout << "Digite o codigo da disciplina: ";
                getline(cin, codigoDisciplina);

                // Encontrar todas as turmas correspondentes ao codigo da disciplina
                vector<double> notas;
                int totalAlunos = 0;

                for (const auto& turma : College::Classes) {
                    if (turma->getCode() == codigoDisciplina) {
                        // Esta turma corresponde à disciplina
                        const vector<double>& notasAlunos = turma->getNotasAlunos();
                        totalAlunos += notasAlunos.size();
                        notas.insert(notas.end(), notasAlunos.begin(), notasAlunos.end());
                    }
                }

                if (totalAlunos > 0) {
                    // Calcular a media das notas
                    double somaNotas = accumulate(notas.begin(), notas.end(), 0.0);
                    double media = somaNotas / totalAlunos;

                    cout << "Media de notas da disciplina " << codigoDisciplina << ": " << media << endl;
                } else {
                    cout << "Disciplina nao encontrada ou nao possui alunos matriculados!" << endl;
                }

                break;
            }
            case 5:
                cout << "Retornando para o Menu Principal" << endl;
                break;
            default:
                cout << "Opcao invalida. Favor escolher novamente." << endl;
                break;
        }
    } while (option != 5);
}

void Controller::showHelpMenu()
{
    cout << "Este e um sistema de gerenciamento escolar que permite realizar diversas operacoes, como inserir, visualizar e atualizar informacoes sobre estudantes, professores, disciplinas, e gerar relatorios." << endl;
    // Adicionar mais informacoes de ajuda
}