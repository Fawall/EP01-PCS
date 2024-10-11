#include "Catraca.h"


Catraca::Catraca(GerenciadorDeUsuario* g) {
    this->g = g;
}

bool Catraca::entrar(int id, Data* d) {
    Usuario* usuario = g->getUsuario(id);

    if( usuario != nullptr){
        usuario->entrar(d);
        cout << "[Entrada] Catraca 0" << " abriu: id " << id << endl;
        
        return true;
    }
    return false;
    
}

bool Catraca::sair(int id, Data* d) {
    Usuario* usuario = g->getUsuario(id);

    if( usuario != nullptr){
        usuario->sair(d);
        return true;
    }
    return false;
}

Catraca::~Catraca() { }