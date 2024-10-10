#ifndef CATRACA_H
#define CATRACA_H

#include "GerenciadorDeUsuario.h"

class Catraca
{

protected:
    GerenciadorDeUsuario* g;
    int id;
    Data* d;


public:
    Catraca(GerenciadorDeUsuario* g);
    virtual ~Catraca();

    bool entrar(int id, Data* d);
    bool sair(int id, Data* d);




};



#endif