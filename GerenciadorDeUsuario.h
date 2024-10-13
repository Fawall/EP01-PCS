#ifndef GERENCIADORDEUSUARIO_H
#define GERENCIADORDEUSUARIO_H

#include "Usuario.h"
#include "Registro.h"

class GerenciadorDeUsuario
{

protected:
    int maximo;
    Usuario **usuarios;
    int quantidade;

public:
    GerenciadorDeUsuario(int maximo);
    virtual ~GerenciadorDeUsuario();

    bool adicionar(Usuario* u);
    Usuario* getUsuario(int id);
    Usuario** getUsuarios();
    
    int getQuantidade();
   
};


#endif