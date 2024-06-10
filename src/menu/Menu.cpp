#include <iostream>
#include <string>
#include <vector>
using namespace std;
#include "../../include/menu/Menu.h"

//Construtor
Menu :: Menu(const vector<string>& options) : options(options){}

//Metodo para adicionar novas opcoes no Menu
void Menu::addOption(const string& option){
    options.push_back(option);
}

//Metodo para apresentar o Menu
void Menu::display() const{
    cout << endl;
    cout << "Menu Principal:" << endl;
    for (size_t i = 0; i < options.size(); ++i){
        cout << i+1 << ". " << options[i] << endl; 
    }
}

//Metodo de validacao e retorno de índice da opcao
int Menu::validarOption() const{
    int option;
    cout << "Escolha uma opcao: ";
    cin >> option;
    cout << endl;
    if (option < 1 || option > static_cast<int>(options.size())){
        cout << "Opcao invalida, favor escolher novamente." << endl;
        return -1; //indicar erro
    }
    return option;
}