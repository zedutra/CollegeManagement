#!/bin/bash

# Comando de compilaçao
g++ -o meu_programa src/*.cpp src/controller/*.cpp src/dao/*.cpp src/dto/*.cpp src/menu/*.cpp src/system/*.cpp src/utils/*.cpp -I./include

# Executar o programa compilado
./meu_programa
