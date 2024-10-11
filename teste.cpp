#include "Data.h"
#include "Registro.h"
#include "GerenciadorDeUsuario.h"
#include "Catraca.h"

#include <ctime>
#include <iostream>

using namespace std;

void teste() {

    tm *d1 = new tm(); //criei um obj data

    d1->tm_hour = 10;
    d1->tm_min = 0;
    d1->tm_sec = 0;
    d1->tm_isdst = 0;
    d1->tm_mday = 21;
    d1->tm_mon = 10 - 1;
    d1->tm_year = 2024 - 1900;

    Data * data = new Data(d1->tm_hour,d1->tm_min,d1->tm_sec,d1->tm_yday,d1->tm_mon,d1->tm_year);
    
    int diferenca = data->Data::diferenca(data);
    cout << diferenca << endl;

    //struct tm *tAtual; //eh necessario criar por conta do asctime
    //tAtual = localtime(&t); //converte o tempo la de 70 bonitinho
    //cout << asctime(tAtual) << endl; //converte o horario pra string
    //cout << ctime(&t) << endl;
    //cout << tAtual->tm_hour << endl; //acessar hora do meu objeto
}


void testeRegistro(){

    Registro* reg = new Registro(new Data(1,1,1,1,1,2024),true,true);

    cout << "Entrada: " << reg->isEntrada() << endl;

    Data* d = reg->getData();
    cout << "Data: " << d->getHora() << ":" << d->getMinuto() << ":" << d->getSegundo() << " " << d->getDia() << "/" << d->getMes() << "/" << d->getAno() << endl;

    delete reg;
}

void testeGerenciador(){
    GerenciadorDeUsuario* g = new GerenciadorDeUsuario(10);

    g->adicionar(new Usuario(1,"Joao",10));
    g->adicionar(new Usuario(2,"Maria",10));
    g->adicionar(new Usuario(3,"Jose",10));

    
    cout << "Usuario: " << g->getUsuario(2)->getNome() << endl;

    cout << "Quantidade: " << g->getQuantidade() << endl;
}

void testeCatraca(){
    GerenciadorDeUsuario *g = new GerenciadorDeUsuario(10);;
    Catraca* c = new Catraca(g);
    
    g->adicionar(new Usuario(1,"Joao",10));
    g->adicionar(new Usuario(2,"Maria",10));
    g->adicionar(new Usuario(3,"Jose",10));

    bool teste = c->entrar(1,new Data(1,1,1,1,1,2024));
    bool teste2 = c->entrar(1,new Data(2,1,1,1,1,2024));

    if(teste != true){
        cout << "Nao entrou" << endl;
    }
    else {
        cout << "Entrou" << endl;
    }

/*  ALGO DE ERRADO NAO ESTA CERTO    */


}


