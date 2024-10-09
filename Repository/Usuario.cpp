#include "Headers/Usuario.h"

Usuario::Usuario(int id, string nome, int maximo) {
    this->id = id;
    this->nome = nome;
    this->maximo = maximo;
    this->registros = new Registro*[maximo];
    this->quantidade = 0;
}   


string Usuario::getNome() {
    return this->nome;
}

int Usuario::getId() {
    return this->id;
}

bool Usuario::entrar(Data *d) {
    if(quantidade >= maximo) {
        return false;
    }

    int ultimoRegistroData = registros[quantidade]->getData()->diferenca(registros[quantidade]->getData());
    bool ultimoRegistroEntrada = registros[quantidade]->isEntrada();

    int diferenca = d->diferenca(d) - ultimoRegistroData ;

    if(ultimoRegistroEntrada != true || diferenca < 0) {
        registros[quantidade] = new Registro(d, true, false);
        quantidade++;
        return true;
    }
    return false;
}

bool Usuario::sair(Data *d){
    if(quantidade >= maximo) {
        return false;
    }


    int ultimoRegistroData = registros[quantidade]->getData()->diferenca(registros[quantidade]->getData());
    bool ultimoRegistroSaida = registros[quantidade]->isEntrada();

    int diferenca = d->diferenca(d) - d->diferenca(registros[quantidade]->getData()) ;

    if(ultimoRegistroSaida == true || diferenca > 0) {
        if(quantidade > 0)
            quantidade -= 1;
        registros[quantidade] = new Registro(d, false, false);
        return true;
    }
    return false;
}

bool Usuario::registrarEntradaManual(Data *d) {
    if(quantidade >= maximo) {
        return false;
    }

    int ultimoRegistroData = registros[quantidade]->getData()->diferenca(registros[quantidade]->getData());
    bool ultimoRegistroEntrada = registros[quantidade]->isEntrada();

    int diferenca = d->diferenca(d) - ultimoRegistroData;

    if(ultimoRegistroEntrada != true || diferenca < 0) {
        registros[quantidade] = new Registro(d, true, true);
        quantidade++;
        return true;
    }
    return false;
}

bool Usuario::registrarSaidaManual(Data *d) {
    if(quantidade >= maximo) {
        return false;
    }

    int ultimoRegistroData = registros[quantidade]->getData()->diferenca(registros[quantidade]->getData());
    bool ultimoRegistroSaida = registros[quantidade]->isEntrada();

    int diferenca = d->diferenca(d) - d->diferenca(registros[quantidade]->getData());

    if(ultimoRegistroSaida == true || diferenca > 0) {
        if(quantidade > 0)
            quantidade -= 1;
        registros[quantidade] = new Registro(d, false, true);
        return true;
    }
    return false;
}

Registro* *Usuario::getRegistros() {
    return  this->registros;
}

int Usuario::getQuantidade() {
    return this->quantidade;
}


Usuario::~Usuario(){    
    for(int i = quantidade; i >= 0; i--) {
        delete registros[i];
    }
    delete registros;
}