#include "GerenciadorDeUsuario.h"
#include "Usuario.h"

using namespace std;

GerenciadorDeUsuario::GerenciadorDeUsuario(int maximo) {
    this->maximo = maximo;
    this->usuarios = new Usuario*[maximo];
    this->quantidade = 0;
}

GerenciadorDeUsuario::~GerenciadorDeUsuario(){
    int quantidadeGU = getQuantidade();
    
    for(int i = 0; i < quantidadeGU; i++){
        delete usuarios[i];
    }
    delete[] usuarios;
}

bool GerenciadorDeUsuario::adicionar(Usuario* u) {
    int quantidadeGU = getQuantidade();
    if(quantidadeGU >= maximo) {
        return false;
    }

    for(int i = 0; i < quantidadeGU; i++) {
        if(usuarios[i]->getId() == u->getId()) {
            return false;
        }
    }

    usuarios[quantidadeGU] = u;
    quantidade++;

    return true;
}

Usuario* GerenciadorDeUsuario::getUsuario(int id) {
    int quantidadeGU = getQuantidade();
    for(int i = 0; i < quantidadeGU; i++) {
        if(usuarios[i]->getId() == id) {
            return usuarios[i];
        }
    }
    return nullptr;
}

Usuario** GerenciadorDeUsuario::getUsuarios() {
    return usuarios;
}

int GerenciadorDeUsuario::getQuantidade() {
    return quantidade;
}
