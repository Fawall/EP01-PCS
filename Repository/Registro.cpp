#include "Headers/Registro.h"

Registro::Registro(Data* d, bool entrada, bool manual) {
    this->data = d;
    this->entrada = entrada;
    this->manual = manual;
}

bool Registro::isEntrada() {
    return this->entrada;
}

bool Registro::isManual() {
    return this->manual;
}

Data* Registro::getData() {
    return this->data;
}

Registro::~Registro() {
    delete this->data;
}