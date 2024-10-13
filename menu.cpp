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
    GerenciadorDeUsuario *g = new GerenciadorDeUsuario(10);
    Usuario* usuario;
    Catraca *catracaEntrar = new Catraca(g);
    Catraca *catracaSair = new Catraca(g);

    int id = 0;
    int catraca = 0;
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
        cin >> escolha;
        // escolha = 1;

        switch (escolha)
        {
        case 1:
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
            bool verifica = catracaEntrar->entrar(id, d);
            if (verifica != true)
            {
                cout << "[Entrada] Catraca " << catraca << " travada" << endl;
            }
            cout << "[Entrada] Catraca " << catraca <<" abriu: id " << id << endl;
            
            cout << endl;

            break;
        case 2:
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
        case 3:
            cout << "Entrada (e) ou Saida (s)? ";
            char acao;
            cin >> acao;
            if (acao == 'e')
            {
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
                usuario->registrarEntradaManual(d);
                
                
            }

        case 4:
            id = 1;
            string nome = "Maria";

            Usuario *user = new Usuario(id, nome, 10);

            g->adicionar(user);
            cout << endl;
            break;
        }

    } while (escolha != 0);
}
