cd analyzer

#CREACION DE ARCHIVOS FLEX Y BISON
flex --header-file=scanner.h -o scanner.cpp analizador.l
bison analizador.y -o parser.cpp --defines=parser.h

cd ..

#COMPILAR ARCHIVOS .CPP
g++ main.cpp ./abstract/command.cpp ./commands/*.cpp ./estructures/*.cpp ./analyzer/*.cpp ./allStructs/*.cpp ./systemsCommands/*.cpp ./users/*.cpp

./a.out
