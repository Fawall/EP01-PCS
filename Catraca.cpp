#include "Catraca.h"
#include "Usuario.h"
#include "Data.h"

Catraca::Catraca(GerenciadorDeUsuario* g) {
    this->g = g;
}

bool Catraca::entrar(int id, Data* d) {
    // int id = g->getUsuario(id)->getId();
    // string nome = g->getUsuario(id)->getNome();

    // Usuario* usuario = new Usuario(id, nome, 10);

    // bool verificaUsuario = usuario->entrar(d);


    bool verifica = g->getUsuario(id)->entrar(d);

    if(g->getUsuario(id) != nullptr && verifica != false){
        g->getUsuario(id)->entrar(d); 
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