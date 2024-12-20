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

        cout << endl;
        switch (escolha)
        {
        case 1:
        {
            int catraca, id, hora, minuto, segundo, dia, mes, ano = 0;
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
                cout << "[Entrada] Catraca " << catraca << " travada" << endl << endl;
                break;
            }
            cout << "[Entrada] Catraca " << catraca << " abriu: id " << id << endl << endl;

            break;
        }
        case 2:
        {
            // cout << endl;
            int catraca, id, hora, minuto, segundo, dia, mes, ano = 0;
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

            verifica = catracaSair->sair(id, d);

            if (verifica != true)
            {
                cout << "[Saida] Catraca " << catraca << " travada" << endl << endl;
                break;
            }

            cout << "[Saida] Catraca " << catraca << " abriu: id " << id << endl << endl;
            break;
        }
        case 3:
        {
            // cout << endl;
            cout << "Entrada (e) ou Saida (s)? ";
            char opcao;
            cin >> opcao;
            if (opcao == 'e')
            {
                int id, hora, minuto, segundo, dia, mes, ano = 0;

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
                    cout << "Erro ao registrar entrada manual" << endl << endl;
                    break;
                }
                else
                {
                    cout << "Entrada manual registrada: id " << id << endl << endl;
                    break;
                }
            }
            if (opcao == 's')
            {
                int id, hora, minuto, segundo, dia, mes, ano = 0;
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
                    cout << "Erro ao registrar saida manual" << endl << endl;
                    break;
                }
                else
                {
                    cout << "Saida manual registrada: id " << id << endl << endl;
                }

                break;
            }
        }
        case 4:
        {
            // cout << endl;
            int id = 0;
            cout << "Id: ";
            cin >> id;

            string nome;
            cout << "Nome: ";
            cin >> nome;
            usuario = new Usuario(id, nome, 10);

            bool verificaUsuario = g->adicionar(usuario);
            if (verificaUsuario != true)
            {
                cout << "Erro ao cadastrar" << endl;
                break;
            }
            cout << "Usuario cadastrado com sucesso" << endl
                 << endl;
            break;
        }
        case 5:
        {   
            int mes, ano = 0;

            cout << "Mes: ";
            cin >> mes;

            cout << "Ano: ";
            cin >> ano;
            cout << endl;
            
            cout << "Relatorio de horas trabalhadas" << endl;
            for (int i = 0; i < g->getQuantidade(); i++)
            {
                cout << g->getUsuarios()[i]->getNome() << ": " << g->getUsuarios()[i]->getHorasTrabalhadas(mes, ano) << endl;
            }
            cout << endl;
            break;
        }

        case 0:
        {
            escolha = 0;
        };
        }

    } while (escolha != 0);
}