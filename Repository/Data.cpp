#include <ctime>
//include de cabecalho
#include "Headers/Data.h"


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
