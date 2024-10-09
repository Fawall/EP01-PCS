#include "Repository/Headers/Data.h"
#include <ctime>
#include <iostream>

using namespace std;

void teste() {

    time_t t;
    time(&t); //pegar o tempo desde 70 (atual)

    tm *d1 = new tm(); //criei um obj data

    d1->tm_hour = 10;
    d1->tm_min = 0;
    d1->tm_sec = 0;
    d1->tm_isdst = 0;
    d1->tm_mday = 21;
    d1->tm_mon = 10 - 1;
    d1->tm_year = 2024 - 1900;

    time_t t1 = mktime(d1); //peguei o obj data e fiz virar um horario (convercao)
    
    int diferenca = (int) difftime(t,t1); //(time_t inicio, time_t fim)

    cout << diferenca << endl;

    //struct tm *tAtual; //eh necessario criar por conta do asctime
    //tAtual = localtime(&t); //converte o tempo la de 70 bonitinho
    //cout << asctime(tAtual) << endl; //converte o horario pra string
    //cout << ctime(&t) << endl;
    //cout << tAtual->tm_hour << endl; //acessar hora do meu objeto


}