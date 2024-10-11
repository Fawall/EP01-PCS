#include <ctime>
#include <iostream>
//include de cabecalho
#include "Data.h"

using namespace std;

Data::Data(int hora, int minuto, int segundo, int dia, int mes, int ano) {

this->hora = hora;
this->minuto = hora;
this->segundo = hora;
this->dia = hora;
this->mes = hora;
this->ano = ano;

}

Data::~Data(){}

int Data::diferenca(Data* d) { 
//retorna a diferenca em segundos entre a data atual e a data recebida

    tm *d1 = new tm(); //criei um obj data

    d1->tm_hour = d->hora;
    d1->tm_min = d->minuto;
    d1->tm_sec = d->segundo;
    d1->tm_isdst = 0;
    d1->tm_mday = d->dia;
    d1->tm_mon = d->mes;//-1;
    cout << "mes eh: " << d1->tm_mon << endl;
    d1->tm_year = d->ano;//-1900;

    time_t t1 = mktime(d1); //peguei o obj data e fiz virar um horario (convercao)
    
    time_t t;
    time(&t); //pegar o tempo desde 70 (atual)

    int diferenca = (int) difftime(t1,t); //(time_t inicio, time_t fim)

    return diferenca;


}



int Data::getHora() {
    return hora;
}

int Data::getMinuto() {
    return minuto;
}

int Data::getSegundo() {
    return segundo;
}

int Data::getDia() {
    return dia;
}

int Data::getMes() {
    return mes;
}

int Data::getAno() {
    return ano;
}