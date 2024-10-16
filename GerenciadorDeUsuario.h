#ifndef GERENCIADORDEUSUARIO_H
#define GERENCIADORDEUSUARIO_H

#include "Usuario.h"
#include "Registro.h"

class GerenciadorDeUsuario
{

private:
    int maximo = 0;
    Usuario **usuarios;
    int quantidade = 0;

public:
    GerenciadorDeUsuario(int maximo);
    virtual ~GerenciadorDeUsuario();

    bool adicionar(Usuario* u);
    Usuario* getUsuario(int id);
    Usuario** getUsuarios();
    
    int getQuantidade();
   
};


#endif