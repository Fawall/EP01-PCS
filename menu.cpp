#include <iostream>
#include "Catraca.h"
#include "Data.h"
#include "GerenciadorDeUsuario.h"
#include "Registro.h"
#include "Usuario.h"

using namespace std;

void menu()
{

    int escolha;
    while (escolha != 0)
    {
        cout << "Acesso ao predio" << endl;
        cout << "1) Entrada" << endl;
        cout << "2) Saida" << endl;
        cout << "3) Registro manual" << endl;
        cout << "4) Cadastro de usuario" << endl;
        cout << "5) Relatorio" << endl;
        cout << "0) Sair" << endl;

        cout << "Escolha uma opcao:";
        cin >> escolha;

        switch(escolha){
            case 1:
                int id = 0;
                int hora = 0;
                int minuto = 0;
                int segundo = 0;
                int dia = 0;
                int mes = 0;
                int ano = 0;

                Data* d;
                cout << "Catraca: 0" << endl;
                cout << "Id: " << endl;
                cin >> id;
                cout << "Hora: ";
                cin >> hora;
                cout << "Minuto: " ;
                cin >> minuto;
                cout << "Segundo: ";
                cin >> segundo;
                cout << "Dia: ";
                cin >> dia;
                cout << "Mes: ";
                cin >> mes;
                cout << "Ano: ";
                cin >> ano;

                d = new Data(hora, minuto, segundo, dia, mes, ano);
                GerenciadorDeUsuario* u;
                Catraca* c = new Catraca(u);
                c->entrar(id, d);
                break;
        }

    }

}
