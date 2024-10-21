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

this->dataTM->tm_hour = hora;
this->dataTM->tm_min = minuto;
this->dataTM->tm_sec = segundo;
this->dataTM->tm_isdst = 0;
this->dataTM->tm_mday = dia;
this->dataTM->tm_mon = mes - 1;
this->dataTM->tm_year = ano - 1900;

}

Data::~Data(){}


<<<<<<< HEAD
int Data::diferenca(Data* d) {

    time_t t1;
    time(&t1);
    
    tm d1 = {};
 
    d1.tm_sec = d->segundo;
    d1.tm_min = d->minuto;
    d1.tm_hour = d->hora;
    d1.tm_mday = d->dia;
    d1.tm_mon = d->mes;
    d1.tm_year = d->ano;

    time_t t2 = mktime(&d1);

    return difftime(t1, t2);
=======
int Data::diferenca(Data* d) {    

    time_t data1 = mktime(dataTM);
    time_t dataUltimoRegistro = mktime(d->dataTM);

    return difftime(data1, dataUltimoRegistro);
>>>>>>> main
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