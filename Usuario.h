#ifndef USUARIO_H
#define USUARIO_H

#include <iostream>
#include "Data.h"
#include "Registro.h"

using namespace std;

class Usuario
{
protected:
    int id;
    int maximo;
    string nome;
    Registro **registros;
    int quantidade = 0;
    int diferenca = 0 ;

public:
    Usuario(int id, string nome, int maximo);
    virtual ~Usuario();

    string getNome();
    int getId();

    bool entrar(Data *d);
    bool sair(Data *d);

    bool registrarEntradaManual(Data *d);
    bool registrarSaidaManual(Data *d);

    int getHorasTrabalhadas(int mes, int ano);
    Registro **getRegistros();
    int getQuantidade();
};

#endif