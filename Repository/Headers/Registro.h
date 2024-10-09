#ifndef REGISTRO_H
#define REGISTRO_H

#include "Data.h"

class Registro {

    Registro(Data* d, bool entrada, bool manual);
    virtual ~Registro();

    Data* getData();
    bool isEntrada();
    bool isManual();
};



#endif