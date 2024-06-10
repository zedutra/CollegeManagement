#ifndef CONTROLLER_HPP
#define CONTROLLER_HPP

#include <iostream>
#include <string>
#include <map>
#include <memory>
#include <vector>
#include <numeric>
#include "../../include/menu/Menu.h"
#include "../../include/controller/College.h"
#include "../../include/dao/StudentDAO.h"
#include "../../include/dao/TeacherDAO.h"
#include "../../include/dao/ClassDAO.h"

using namespace std;

class Controller {
    private:
    Menu mainMenu;

    public:
    //Construtor
    Controller() : mainMenu({"Estudantes", "Professores", "Disciplinas", "Turmas", "Reports", "Help", "Sair do programa"}){}
    //Metodo para iniciar
    void start();

    //Metodos para os submenus
    void showStudentsMenu();
    void showTeachersMenu();
    void showSubjectsMenu();
    void showClassMenu();
    void showReportsMenu();
    void showHelpMenu();

};


#endif
