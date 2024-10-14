#include <ctime>
#include <iostream>
//include de cabecalho
#include "Data.h"

using namespace std;

Data::Data(int hora, int minuto, int segundo, int dia, int mes, int ano) {

this->hora = hora;
this->minuto = minuto;
this->segundo = segundo;
this->dia = dia;
this->mes = mes;
this->ano = ano;

}

Data::~Data(){}

// int Data::diferenca(Data* d) { 
// //retorna a diferenca em segundos entre a data atual e a data recebida

//     time_t t;
//     time(&t); //pegar o tempo desde 70 (atual)

//     tm *d1 = new tm(); //criei um obj data

//     d1->tm_hour = d->hora;
//     d1->tm_min = d->minuto;
//     d1->tm_sec = d->segundo;
//     d1->tm_isdst = 0;
//     d1->tm_mday = d->dia;
//     d1->tm_mon = d->mes;
//     d1->tm_year = d->ano;

//     time_t t1 = mktime(d1); //peguei o obj data e fiz virar um horario (convercao)
    
//     int diferenca = (int) difftime(t,t1); //(time_t inicio, time_t fim)

//     cout << "DIFERENCA: "<< diferenca <<endl;


//     return diferenca;

// }

int Data::diferenca(Data* d) {
    tm d1 = {};
    d1.tm_hour = this->hora;
    d1.tm_min = this->minuto;
    d1.tm_sec = this->segundo;
    d1.tm_isdst = 0;
    d1.tm_mday = this->dia;
    d1.tm_mon = this->mes - 1;
    d1.tm_year = this->ano - 1900;

    tm d2 = {};
    d2.tm_hour = d->hora;
    d2.tm_min = d->minuto;
    d2.tm_sec = d->segundo;
    d2.tm_isdst = 0;
    d2.tm_mday = d->dia;
    d2.tm_mon = d->mes - 1;
    d2.tm_year = d->ano - 1900;

    time_t t1 = mktime(&d1);
    time_t t2 = mktime(&d2);

    return difftime(t1, t2);
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