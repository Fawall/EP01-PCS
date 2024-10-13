#include "Catraca.h"
#include "Usuario.h"
#include "Data.h"

Catraca::Catraca(GerenciadorDeUsuario* g) {
    this->g = g;
}

bool Catraca::entrar(int id, Data* d) {
    Usuario* usuario = g->getUsuario(id);

    if( usuario != nullptr){
        usuario->entrar(d);  
        return true;
    }
    return false;
    
}

bool Catraca::sair(int id, Data* d) {
   
    Usuario* usuario = g->getUsuario(id);
    bool verifica = usuario->sair(d);
    
    if(usuario != nullptr && verifica == true){
        return true;
    }
    else{
        return false;
   
    }
}

Catraca::~Catraca() { }