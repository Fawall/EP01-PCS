#include "Catraca.h"
#include "Usuario.h"
#include "Data.h"

Catraca::Catraca(GerenciadorDeUsuario* g) {
    this->g = g;
}

bool Catraca::entrar(int id, Data* d) {

    bool verifica = g->getUsuario(id)->entrar(d);

    if(g->getUsuario(id) != nullptr && verifica != false){
        return true;
    }
    return false;
    
}

bool Catraca::sair(int id, Data* d) {

    bool verifica = g->getUsuario(id)->sair(d);
    
    if(g->getUsuario(id) != nullptr && verifica == true){
        return true;
    }
    else{
        return false;
   
    }
}

Catraca::~Catraca() { }