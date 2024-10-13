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

    if( usuario != false){
        usuario->sair(d);

        cout << "[Saida] Catraca 1" << " abriu: id " << id << endl;
        return true;
    }
    cout << "NAO SAIU";
    return false;
}

Catraca::~Catraca() { }