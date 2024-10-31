#include "Catraca.h"
#include "Usuario.h"
#include "Data.h"

Catraca::Catraca(GerenciadorDeUsuario* g) {
    this->g = g;
}

bool Catraca::entrar(int id, Data* d) {

    if(g->getQuantidade() == 0)
        return false;

    bool verificaSeUsuarioExiste = g->getUsuario(id);

    if(verificaSeUsuarioExiste == true){
        if(g->getUsuario(id)->entrar(d) == true)
            return true;
        return false;
    }
    return false;
    
}

bool Catraca::sair(int id, Data* d) {
    
    if(g->getQuantidade() == 0)
        return false;

    bool verificaSeUsuarioExiste = g->getUsuario(id);
    
    if(verificaSeUsuarioExiste == true){
        if(g->getUsuario(id)->sair(d) == true)
            return true;
        return false;
    }
    
    return false;

}

Catraca::~Catraca() { }