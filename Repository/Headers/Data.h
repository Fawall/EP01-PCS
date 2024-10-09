#ifndef DATA_H
#define DATA_H

class Data {

public:

    Data (int hora, int minuto, int segundo, int dia, int mes, int ano);
    virtual ~Data();

    int getHora();
    int getMinuto();
    int getSegundo();
    int getDia();
    int getMes();
    int getAno();
    int diferenca(Data* d); 

};

#endif