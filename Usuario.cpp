#include "Usuario.h"
#include "Registro.h"
#include "Data.h"

Usuario::Usuario(int id, string nome, int maximo)
{
    this->id = id;
    this->nome = nome;
    this->maximo = maximo;
    this->registros = new Registro *[maximo];
}

string Usuario::getNome()
{
    return this->nome;
}

int Usuario::getId()
{
    return this->id;
}


bool Usuario::entrar(Data *d)
{
    if (quantidade >= maximo)
    {
        return false;
    }

    if (quantidade == 0)
    {
        registros[quantidade] = new Registro(d, true, false);
        quantidade++;
        return true;
    }

    bool ultimoRegistroEntrada = registros[quantidade - 1]->isEntrada();
    int diferenca = d->diferenca(d) - d->diferenca(registros[quantidade -1]->getData());

    if (ultimoRegistroEntrada == false || diferenca < 0)
    {
        registros[quantidade] = new Registro(d, true, false);
        quantidade++;
        return true;
    }
    registros[quantidade] = nullptr;
    return false;
}

bool Usuario::sair(Data *d)
{
    int atualQnt = getQuantidade();
    if (atualQnt >= maximo || atualQnt == 0)
    {
        return false;
    }
    
    // int ultimoRegistroData = registros[quantidade]->getData()->diferenca(registros[quantidade]->getData());
    bool ultimoRegistroEntrada = registros[atualQnt-1]->isEntrada();

    int diferenca = d->diferenca(d) - d->diferenca(registros[atualQnt-1]->getData());

    if (ultimoRegistroEntrada == true && diferenca < 0)
    {
        registros[atualQnt] = new Registro(d, false, false);
        quantidade++;
        return true;
    }

    return false;
}

bool Usuario::registrarEntradaManual(Data *d)
{
    int atualQnt = getQuantidade();

    if (atualQnt >= maximo)
    {
        return false;
    }

    if (atualQnt == 0)
    {
        registros[atualQnt] = new Registro(d, true, true);
        quantidade++;
        return true;
    }


    bool ultimoRegistroEntrada = registros[atualQnt - 1]->isEntrada();
    Data* ultimoRegistroData = registros[atualQnt - 1]->getData();

    int diferenca = d->diferenca(d) - d->diferenca(ultimoRegistroData);

    if (ultimoRegistroEntrada == false || diferenca < 0)
    {
        registros[atualQnt] = new Registro(d, true, true);
        quantidade++;
        return true;
    }
    registros[atualQnt] = nullptr;
    return false;

}

bool Usuario::registrarSaidaManual(Data *d)
{
    int atualQnt = getQuantidade();

    if (atualQnt >= maximo || atualQnt == 0)
    {
        return false;
    }
    
    // int ultimoRegistroData = registros[quantidade]->getData()->diferenca(registros[quantidade]->getData());
    bool ultimoRegistroEntrada = registros[atualQnt-1]->isEntrada();

    int diferenca = d->diferenca(d) - d->diferenca(registros[atualQnt-1]->getData());

    if (ultimoRegistroEntrada == true && diferenca < 0)
    {
        registros[atualQnt] = new Registro(d, false, false);
        quantidade++;
        return true;
    }

    return false;
}

Registro **Usuario::getRegistros()
{
    return this->registros;
}

int Usuario::getQuantidade()
{
    return this->quantidade;
}

int Usuario::getHorasTrabalhadas(int mes, int ano)
{
    // To be implemented later
    return 0;
}

Usuario::~Usuario()
{
    int atualQnt = getQuantidade();

    for (int i = 0; i <= atualQnt; i++)
    {
        delete registros[i];
    }
    delete registros;
}
