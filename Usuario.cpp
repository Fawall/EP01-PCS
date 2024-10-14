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
    int atualQnt = getQuantidade();
    if (atualQnt >= maximo)
    {
        return false;
    }

    if (quantidade == 0)
    {
        registros[atualQnt] = new Registro(d, true, false);
        quantidade++;
        return true;
    }

    bool ultimoRegistroEntrada = registros[atualQnt - 1]->isEntrada();
    int diferenca = d->diferenca(d) - d->diferenca(registros[quantidade - 1]->getData());

    if (ultimoRegistroEntrada == false && diferenca < 0)
    {
        registros[quantidade] = new Registro(d, true, false);
        quantidade++;
        return true;
    }
    // registros[quantidade] = nullptr;
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
    bool ultimoRegistroEntrada = registros[atualQnt - 1]->isEntrada();

    int ultimaData = d->diferenca(registros[atualQnt - 1]->getData());
    int atualData = d->diferenca(d);

    int diferencaEntreDuasDatas = ultimaData - atualData;

    if (ultimoRegistroEntrada == true && diferencaEntreDuasDatas > 0)
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
    Data *ultimoRegistroData = registros[atualQnt - 1]->getData();

    int diferenca = d->diferenca(d) - d->diferenca(registros[quantidade - 1]->getData());

    if (ultimoRegistroEntrada == false && diferenca < 0)
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
    bool ultimoRegistroEntrada = registros[atualQnt - 1]->isEntrada();

    int diferenca = d->diferenca(d) - d->diferenca(registros[atualQnt - 1]->getData());

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
    int atualQnt = getQuantidade();
    int horasTrabalhadas = 0;
    Data *dataSaida;
    
    if (atualQnt == 0)
    {
        return 0;
    }


    for (int i = 0; i < atualQnt; i++)
    {
        if (registros[i]->getData()->getMes() == mes && registros[i]->getData()->getAno() == ano)
        {
            if (registros[i]->isEntrada() == true)
            {
                if (i + 1 < atualQnt && registros[i + 1] != nullptr)
                {
                    if (registros[i+1]->isEntrada() == false)
                    {
                        dataSaida = registros[i + 1]->getData();
                        int diferencaEntreSaidaEntrada = dataSaida->diferenca(registros[i]->getData());
                       
                        horasTrabalhadas += (diferencaEntreSaidaEntrada) / 3600;
                    }
                }
            }
        }
    }

    return horasTrabalhadas;
}

Usuario::~Usuario()
{
    int atualQnt = getQuantidade();
    if (registros != nullptr)
    {
        for (int i = 0; i < atualQnt; i++)
        {
            delete registros[i];
            registros[i] = nullptr;
        }
        delete[] registros;
        registros = nullptr;
    }

}
