#include <iostream>
#include "Catraca.h"
#include "Data.h"
#include "GerenciadorDeUsuario.h"
#include "Registro.h"
#include "Usuario.h"

using namespace std;

void menu()
{
    Data *d;
    GerenciadorDeUsuario *u = new GerenciadorDeUsuario(10);
    Catraca *catracaEntrar = new Catraca(u);
    Catraca *catracaSair = new Catraca(u);

    int id = 0;
    int hora = 0; 
    int minuto = 0;
    int segundo = 0;
    int dia = 0;
    int mes = 0;
    int ano = 0;

    int escolha;
    do
    {
        cout << "Acesso ao predio" << endl;
        cout << "1) Entrada" << endl;
        cout << "2) Saida" << endl;
        cout << "3) Registro manual" << endl;
        cout << "4) Cadastro de usuario" << endl;
        cout << "5) Relatorio" << endl;
        cout << "0) Sair" << endl;

        cout << "Escolha uma opcao: ";
        // cin >> escolha;
        escolha = 1;

        switch (escolha)
        {
        case 1:
            id = 1;
            hora = 2;
            minuto = 0;
            segundo = 30;
            dia = 11;
            mes = 9;
            ano = 2004;

            // cout << "Catraca: 0" << endl;
            // cout << "Id: ";
            // cin >> id;
            // cout << "Hora: ";
            // cin >> hora;
            // cout << "Minuto: " ;
            // cin >> minuto;
            // cout << "Segundo: ";
            // cin >> segundo;
            // cout << "Dia: ";
            // cin >> dia;
            // cout << "Mes: ";
            // cin >> mes;
            // cout << "Ano: ";
            // cin >> ano;

            d = new Data(hora, minuto, segundo, dia, mes, ano);

            catracaEntrar->entrar(id, d);
            cout << endl;

            break;
        case 2:
            id = 1;
            hora = 1;
            minuto = 0;
            segundo = 30;
            dia = 11;
            mes = 9;
            ano = 2004;

            // cout << "Catraca: 0" << endl;
            // cout << "Id: ";
            // cin >> id;
            // cout << "Hora: ";
            // cin >> hora;
            // cout << "Minuto: " ;
            // cin >> minuto;
            // cout << "Segundo: ";
            // cin >> segundo;
            // cout << "Dia: ";
            // cin >> dia;
            // cout << "Mes: ";
            // cin >> mes;
            // cout << "Ano: ";
            // cin >> ano;

            d = new Data(hora, minuto, segundo, dia, mes, ano);

            catracaSair->sair(id, d);
            cout << endl;

            break;

        case 4:
            id = 1;
            string nome = "Maria";

            Usuario *user = new Usuario(id, nome, 10);

            u->adicionar(user);
            cout << endl;
            break;
        }

    } while (escolha != 0);
}
