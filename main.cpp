#include <iostream>
#include <windows.h>
#include <string>
#include <algorithm>
#include <iomanip>
#include <fstream>
#include <ctime> 

using namespace std;

int main()
{

    SetConsoleOutputCP(65001);

    string nomes[20];
    int qtdAlunos;
    float notas[20][5];
    float media[20];
    int qtdDisciplina;
    int opcaoInicial;

    // --- LEITURA DE ALUNOS ---
    cout << "=== SISTEMA DE NOTAS v4.1 ===" << endl;
    cout << "1- Novo relatório" << endl;
    cout << "2- Ver relatório salvo" << endl;
    cout << "3- Sobre o sistema " << endl;
    cout << "Escolha uma opção: " << endl;
    cin >> opcaoInicial;
    
    
    if (opcaoInicial == 2)
    {
        ifstream leitura("relatorio.txt");
        if (leitura.is_open())
        {
            string linha;
            cout << "\n";
            while (getline(leitura, linha))
            {
                cout << linha << endl;
            }
            leitura.close();
        }
        else
        {
            cout << "Nenhum relatório encontrado. " << endl;
        }
        return 0;
    }

   // === IMPLEMENTAÇÃO DA TAREFA 1: SOBRE O SISTEMA ===
    if (opcaoInicial == 3)
    {
        cout << "\n=== SOBRE ===" << endl;
        cout << "Sistema de Notas v4.1" << endl;
        cout << "Desenvolvido por: Rafael Luiz" << endl;
        cout << "Turma: LOPAL 2026 - SENAI-SP" << endl;
        
        cout << "\nPressione Enter para voltar ao menu inicial...";
        string pausa;
        cin.ignore(); 
        getline(cin, pausa); 
         
        return main(); 
    }
    
    do
    {
        cout << "Quantidade de alunos (1 a 20): ";
        cin >> qtdAlunos;
    } while (qtdAlunos < 1 || qtdAlunos > 20);

    cin.ignore();
    for (int i = 0; i < qtdAlunos; i++)
    {
        cout << "Nome do aluno " << i + 1 << ": ";
        getline(cin, nomes[i]);
    }

    // --- NOTAS E MÉDIAS (COMMIT 2) ---
    do
    {
        cout << "Quantidade de disciplinas (1 a 5): ";
        cin >> qtdDisciplina;
    } while (qtdDisciplina < 1 || qtdDisciplina > 5);

    cin.ignore();

    for (int i = 0; i < qtdAlunos; i++)
    {
        cout << "\nNotas de " << nomes[i] << ":" << endl;
        float soma = 0;
        for (int j = 0; j < qtdDisciplina; j++)
        {
            do
            {
                cout << "Disciplina " << j + 1 << " (0 a 10): ";
                cin >> notas[i][j];
            } while (notas[i][j] < 0 || notas[i][j] > 10);
            soma += notas[i][j];
        }
        media[i] = soma / qtdDisciplina;
    }

    cout << "\nAlunos cadastrados: " << endl;
    for (int i = 0; i < qtdAlunos; i++)
    {
        cout << "  " << i + 1 << ". " << nomes[i] << " - Media: " << fixed << setprecision(2) << media[i] << endl;
    }

    // --- CLASSIFICAÇÃO E RELATÓRIO (COMMIT 3) ---
    cout << "\n=== RELATÓRIO ===" << endl;
    int aprovados = 0, recuperacao = 0, reprovados = 0;

    for (int i = 0; i < qtdAlunos; i++)
    {
        cout << nomes[i] << " - Media: " << fixed << setprecision(2) << media[i] << " - ";

       
        if (media[i] >= 7)
        {
            cout << "Aprovado" << endl;
            aprovados++;
        }
        else if (media[i] >= 5)
        {
            cout << "Recuperação" << endl;
            recuperacao++;
        }
        else
        { 
            cout << "Reprovado" << endl;
            reprovados++;
        }
    }

    // --- SALVAR EM ARQUIVO (COMMIT 4) ---
    ofstream arquivo("relatorio.txt");

    if (arquivo.is_open())
    {

        time_t agora = time(0);
        char* dataHora = ctime(&agora);
        arquivo << "Data do relatorio: " << dataHora;

        arquivo << "=== RELATÓRIO === " << endl;
        for (int i = 0; i < qtdAlunos; i++)
        {
            arquivo << nomes[i] << " - Média: " << fixed << setprecision(2) << media[i] << " - ";
            if (media[i] >= 7)
            {
                arquivo << "Aprovado" << endl;
            }
            else if (media[i] >= 5)
            {
                arquivo << "Recuperação" << endl;
            }
            else
            {
                arquivo << "Reprovado" << endl;
            }
        }

        arquivo << "\nResumo: " << aprovados << " Aprovados, "
                << recuperacao << " em Recuperação, "
                << reprovados << " Reprovados." << endl;

        arquivo.close();
        cout << "\nRelatório salvo em relatorio.txt" << endl;
    }
    else
    {
        cout << "Erro ao criar arquivo." << endl;
    }

    cout << "\nResumo: " << aprovados << " aprovados, " << recuperacao << " em recuperação, " << reprovados << " reprovados." << endl;

    return 0;
}
 