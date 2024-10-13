#include <iostream>
#include "Catraca.h"
#include "Data.h"
#include "GerenciadorDeUsuario.h"
#include "Registro.h"
#include "Usuario.h"

using namespace std;

void menu()
{
    Usuario *usuario;
    Data *d;
    GerenciadorDeUsuario *g = new GerenciadorDeUsuario(10);
    Catraca *catracaEntrar = new Catraca(g);
    Catraca *catracaSair = new Catraca(g);

    bool verifica;

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
        cin >> escolha;
        // escolha = 3;

        switch (escolha)
        {
        case 1:
        {
            int catraca,id,hora,minuto,segundo,dia,mes,ano = 0;
            cout << "Catraca: ";
            cin >> catraca;
            cout << "Id: ";
            cin >> id;
            cout << "Hora: ";
            cin >> hora;
            cout << "Minuto: ";
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
            verifica = catracaEntrar->entrar(id, d);
            if (verifica != true)
            {
                cout << "[Entrada] Catraca " << catraca << " travada" << endl;
                break;
            }
            cout << "[Entrada] Catraca " << catraca << " abriu: id " << id << endl;

            cout << endl;

            break;
        }
        case 2:
        {
            int id,hora,minuto,segundo,dia,mes,ano = 0;
            cout << "Catraca: 1" << endl;
            cout << "Id: ";
            cin >> id;
            cout << "Hora: ";
            cin >> hora;
            cout << "Minuto: ";
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

            catracaSair->sair(id, d);
            cout << "[Saida] Catraca 1" << " abriu: id " << id << endl;
            cout << endl;

            break;
        }
        case 3:
        {
            cout << "Entrada (e) ou Saida (s)? ";
            char opcao;
            cin >> opcao;
            opcao = tolower(opcao);
            switch (opcao)
            {
            case 'e':
            {
                int id,hora,minuto,segundo,dia,mes,ano = 0;

                cout << "Id: ";
                cin >> id;
                cout << "Hora: ";
                cin >> hora;
                cout << "Minuto: ";
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

                bool ver = usuario->registrarEntradaManual(d);

                if (ver != true)
                {
                    cout << "Erro ao registrar entrada manual" << endl
                         << endl;
                    break;
                }
                else
                {
                    cout << "Entrada manual registrada: id " << id << endl
                         << endl;
                    break;
                }
            }
            case 's':
            {
                int id = 0;
                int hora = 0;
                int minuto = 0;
                int segundo = 0;
                int dia = 0;
                int mes = 0;
                int ano = 0;
                cout << "Id: ";
                cin >> id;
                cout << "Hora: ";
                cin >> hora;
                cout << "Minuto: ";
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

                bool ver = usuario->registrarSaidaManual(d);

                if (ver != true)
                {
                    cout << "Erro ao registrar saida manual" << endl
                         << endl;
                    break;
                }
                else
                {
                    cout << "Saida manual registrada: id " << id << endl
                         << endl;
                }
            }

            break;
        }
        }
        case 4:
        {
            int id = 1;
            string nome = "Maria";

            usuario = new Usuario(id, nome, 10);

            g->adicionar(usuario);
            cout << endl;
            break;
        };
        }

    } while (escolha != 0);
}
