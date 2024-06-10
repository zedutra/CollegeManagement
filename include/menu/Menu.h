#ifndef MENU_HPP
#define MENU_HPP
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Menu{
    private:
        vector<string> options;
    public:
        //Construtor do Menu
        Menu(const vector<string>& options);

        //Metodo para adicionar novas opcoes no Menu
        void addOption(const string& option);

        //Metodo para apresentar o Menu
        void display() const;

        //Metodo de validacao e retorno de índice da opcao
        int validarOption() const;

        //validar entrada
        static bool isInteger(const std::string& str) {
        for (char c : str) {
            if (!std::isdigit(c)) {
                return false;
            }
        }
        return true;
        }

};
#endif