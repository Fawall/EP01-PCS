#ifndef REGISTRO_H
#define REGISTRO_H

#include "Data.h"

class Registro {

private:
    Data* data;
    bool entrada;
    bool manual;

public:
    Registro(Data* d, bool entrada, bool manual);
    virtual ~Registro();

    Data* getData();
    bool isEntrada();
    bool isManual();
};



#endif