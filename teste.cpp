#include "Data.h"
#include "Registro.h"
#include "GerenciadorDeUsuario.h"
#include "Catraca.h"

#include <ctime>
#include <iostream>

using namespace std;

void teste() {

    tm *d1 = new tm(); //criei um obj data
    tm *d2 = new tm();

    d1->tm_hour = 10;
    d1->tm_min = 0;
    d1->tm_sec = 0;
    d1->tm_isdst = 0;
    d1->tm_mday = 21;
    d1->tm_mon = 10-1;
    d1->tm_year = 2024-1900;

    d2->tm_hour = 9;
    d2->tm_min = 0;
    d2->tm_sec = 0;
    d2->tm_isdst = 0;
    d2->tm_mday = 21;
    d2->tm_mon = 10 - 1;
    d2->tm_year = 2024 - 1900;

    Data * data = new Data(d1->tm_hour,d1->tm_min,d1->tm_sec,d1->tm_yday,d1->tm_mon,d1->tm_year);
    Data* data2 = new Data(d2->tm_hour,d2->tm_min,d2->tm_sec,d2->tm_yday,d2->tm_mon,d2->tm_year);

    int diferenca = data->Data::diferenca(data);
    int diferenca2 = data->Data::diferenca(data2);
    
    time_t t = mktime(d1);
    time_t t2 = mktime(d2);

    cout << t << endl;
    cout << t2 << endl ;
    int diferenca3 = (int) difftime(t,t2);
    
    cout << "Diferenca 1" << diferenca << endl;
    cout << "Diferenca 2" << diferenca2 << endl;

    cout << "Diferenca 3" << diferenca3 << endl;
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
    Usuario* u1 = new Usuario(1,"Joao",10);
   
   
    g->adicionar(u1);
    Usuario* u2 = new Usuario(2,"Maria",10);
    g->adicionar(u2);

    g->adicionar(new Usuario(3,"Jose",10));

    cout << u1->entrar(new Data(1,1,1,1,1,2024));
    cout << u1->entrar(new Data(2,1,1,1,1,2024));
    

    cout << "Usuario: " << g->getUsuario(1)->getNome() << endl;

    cout << "Quantidade: " << g->getQuantidade() << endl;
}

void testeCatraca2(){
    GerenciadorDeUsuario *g = new GerenciadorDeUsuario(10);;
    Catraca* c = new Catraca(g);

    bool verifica;
    
    g->adicionar(new Usuario(1,"Joao",10));
    g->adicionar(new Usuario(2,"Maria",10));
    g->adicionar(new Usuario(3,"Jose",10));

    verifica = c->entrar(2,new Data(2,1,1,1,1,2024));
    
    if(verifica != true){
        cout << "Erro ao entrar" << endl;
    }else{

    cout << "Entrou" << endl;
    }

    verifica = c->sair(2,new Data(3,1,1,1,1,2024));
    
    if(verifica != true){
        cout << "Erro ao sair" << endl;
    }
    cout << "Saiu" << endl;

}

void testeCatraca(){
    GerenciadorDeUsuario *g = new GerenciadorDeUsuario(10);;
    Catraca* c = new Catraca(g);

    bool verifica;
    
    g->adicionar(new Usuario(1,"Fabio",10));

    verifica = c->entrar(2,new Data(2,1,1,1,1,2024));




}

void testeEntradasESaidas(){
    Usuario* usuario1;
    Usuario* usuario2;
    Usuario* usuario3;

    GerenciadorDeUsuario* g = new GerenciadorDeUsuario(10);
    

    usuario1 = new Usuario(1,"Joao",10);
    usuario2 = new Usuario(2,"Maria",10);
    usuario3 = new Usuario(3,"Jose",10);

    g->adicionar(usuario1);
    g->adicionar(usuario2);
    g->adicionar(usuario3);

    cout << "Quantidade de usuarios: " <<  g->getQuantidade() << endl;

    cout << "Entrada usuario 1: " << usuario1->entrar(new Data(5,12,27,5,1,2024)) << endl;
    cout << "Entrada usuario 2: " << usuario2->entrar(new Data(7,12,27,5,1,2024)) << endl;
    cout << "Entrada usuario 3: " << usuario3->entrar(new Data(8,12,27,5,1,2024)) << endl;

    cout << "Saida usuario 1: " << usuario1->sair(new Data(10,12,27,5,1,2024)) << endl;
    cout << "Saida usuario 2: " << usuario2->sair(new Data(11,12,27,5,1,2024)) << endl;
    cout << "Saida usuario 3: " << usuario3->sair(new Data(12,12,27,5,1,2024)) << endl << endl;


    cout << "TESTANDO ENTRADAS INVALIDAS" << endl;
    Usuario* usuario5  = new Usuario(5,"Fabio",10);
    g->adicionar(usuario5);

    cout << "Entrada usuario 5: " << usuario5->entrar(new Data(5,12,27,5,1,2024)) << endl;
    cout << "Repetindo entrada do usuario 5: " << usuario5->entrar(new Data(5,12,27,5,1,2024)) << endl;
    cout << "Entrada sem saida do usuario 5: " << usuario5->entrar(new Data(6,12,27,5,1,2024)) << endl;
    cout << "Entrada antes da primeira entrada do usuario 5: " << usuario5->entrar(new Data(3,12,27,5,1,2024)) << endl << endl;


    cout << "TESTANDO SAIDA INVALIDAS" << endl;
    Usuario* usuario4;
    
    usuario4 = new Usuario(4,"Fabio",10);

    cout << "Entrada usuario 4: " << usuario4->entrar(new Data(5,12,27,5,1,2024)) << endl;
    cout << "Saida antes da entrada: " << usuario4->sair(new Data(4,12,27,5,1,2024)) << endl;
    usuario4->sair(new Data(6,12,27,5,1,2024));

    cout << "Saida sem entrada: " << usuario4->sair(new Data(6,12,27,5,1,2024)) << endl;


}

void testeEntradaESaidaCatraca(){

    cout << "Cadastro de usuarios" << endl;
    GerenciadorDeUsuario* g = new GerenciadorDeUsuario(10);
    Usuario* u1 = new Usuario(1,"Joao",10);
    Usuario* u2 = new Usuario(2,"Maria",10);
    Usuario* u3 = new Usuario(3,"Jose",10);

    g->adicionar(u1);
    g->adicionar(u2);
    g->adicionar(u3);

    // cout << "Entrada de usuarios" << endl;
    Catraca* c = new Catraca(g);
    cout << "Usuario 1: " << c->entrar(1,new Data(2,1,1,2,1,2024))<<endl;
    cout << "Usuario 2: " << c->entrar(2,new Data(3,1,1,3,1,2024))<<endl;
    cout << "Usuario 3: " << c->entrar(3,new Data(2,1,1,4,1,2024)) << endl << endl;

    cout << "Saida de usuarios" << endl;
    cout << "Usuario 1: " << c->sair(1,new Data(4,1,1,2,1,2024))<<endl;
    cout << "Usuario 2: " << c->sair(2,new Data(5,1,1,3,1,2024))<<endl;
    cout << "Usuario 3: " << c->sair(3,new Data(6,1,1,4,1,2024))<<endl<<endl;

    cout << "Testando saidas repetidas" << endl;
    cout << "Usuario 1: " << c->sair(1,new Data(4,1,1,2,1,2024))<<endl;
    cout << "Usuario 2: " << c->sair(2,new Data(5,1,1,3,1,2024))<<endl;
    cout << "Usuario 3: " << c->sair(3,new Data(6,1,1,4,1,2024))<<endl<<endl;

    cout << "Testando se quando um usuario sai, ele consegue entrar novamente" << endl;
    cout << "Usuario 1 entrada: " << c->entrar(1,new Data(5,1,1,2,1,2024)) << endl;
    cout << "Usuario 2 saida: " << c->sair(1,new Data(6,1,1,2,1,2024)) << endl;
    cout << "Usuario 1 entrada apos a primeira saida: " << c->entrar(1,new Data(7,1,1,2,1,2024)) << endl;
    cout << "Usuario 1 saida apos a segunda entrada: " << c->sair(1, new Data(8,1,1,2,1,2024)) << endl;
    
}

void testeGetHorasTrabalhadas(){
    GerenciadorDeUsuario* g = new GerenciadorDeUsuario(10);
    Catraca* c = new Catraca(g);
    Usuario* u2 = new Usuario(2,"Maria",10);
    g->adicionar(u2);

    c->entrar(2,new Data(9,4,30,30,9,2024));
    c->sair(2, new Data(15,0,20,30,9,2024));
    
    c->entrar(2,new Data(23,0,0,30,9,2024));
    c->sair(2, new Data(8,6,0,1,10,2024));

    c->entrar(2,new Data(9,5,30,2,10,2024));
    c->sair(2, new Data(12,8,0,2,10,2024));

    c->entrar(2,new Data(13,10,0,2,10,2024));
    c->sair(2, new Data(18,10,30,2,10,2024));

    c->entrar(2,new Data(9,10,30,3,10,2024));

    cout << "Horas trabalhadas setembro: " << u2->getHorasTrabalhadas(9,2024) << endl;
    cout << "Horas Trabalhadas outubro: " << u2->getHorasTrabalhadas(10,2024);

    u2->~Usuario();
    g->~GerenciadorDeUsuario();

}

