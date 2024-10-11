#include "GerenciadorDeUsuario.h"
#include "Registro.h"

using namespace std;

GerenciadorDeUsuario::GerenciadorDeUsuario(int maximo) {
    this->maximo = maximo;
    this->usuarios = new Usuario*[maximo];
    this->quantidade = 0;
}

GerenciadorDeUsuario::~GerenciadorDeUsuario(){
    for(int i = 0; i < quantidade; i++){
        delete usuarios[i];
    }
    delete usuarios;
}

bool GerenciadorDeUsuario::adicionar(Usuario* u) {
    if(quantidade >= maximo) {
        return false;
    }

    for(int i = 0; i < quantidade; i++) {
        if(usuarios[i]->getId() == u->getId()) {
            return false;
        }
    }

    usuarios[quantidade] = u;
    quantidade++;
    return true;
}

Usuario* GerenciadorDeUsuario::getUsuario(int id) {
    for(int i = 0; i < quantidade; i++) {
        if(usuarios[i]->getId() == id) {
            return usuarios[i];
        }
    }
    return nullptr;
}

Usuario* GerenciadorDeUsuario::getUsuarios() {
    return *usuarios;
}

int GerenciadorDeUsuario::getQuantidade() {
    return quantidade;
}
