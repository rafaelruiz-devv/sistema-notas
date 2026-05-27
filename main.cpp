#include <iostream>
#include <windows.h>
#include <string>
#include <algorithm>
#include <iomanip>
#include <fstream>

using namespace std;

int main()
{
    
    SetConsoleOutputCP(65001);

    string nomes[20];
    int qtdAlunos;
    float notas[20][5];
    float media[20];
    int qtdDisciplina;

    // --- LEITURA DE ALUNOS ---
    cout << "=== SISTEMA DE NOTAS v4.0 ===" << endl;

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

    for (int i = 0; i < qtdAlunos; i++) {
        cout << nomes[i] << " - Media: " << fixed << setprecision(2) << media[i] << " - ";
        
        // CORRIGIDO: alterado media[7] para media[i]
        if (media[i] >= 7) {
            cout << "Aprovado" << endl;
            aprovados++;
        } else if (media[i] >= 5) {
            cout << "Recuperação" << endl;
            recuperacao++;
        } else { // CORRIGIDO: Adicionado o fluxo para reprovados na tela
            cout << "Reprovado" << endl;
            reprovados++;
        }
    }

    // --- SALVAR EM ARQUIVO (COMMIT 4) ---
    ofstream arquivo("relatorio.txt");

    if (arquivo.is_open()) {
        arquivo << "=== RELATÓRIO === " << endl;
        for (int i = 0; i < qtdAlunos; i++) {
            arquivo << nomes[i] << " - Média: " << fixed << setprecision(2) << media[i] << " - ";
            if (media[i] >= 7) {
                arquivo << "Aprovado" << endl;
            } else if (media[i] >= 5) {
                arquivo << "Recuperação" << endl;
            } else {
                arquivo << "Reprovado" << endl;
            }
        }
        
       
        arquivo << "\nResumo: " << aprovados << " Aprovados, " 
                << recuperacao << " em Recuperação, " 
                << reprovados << " Reprovados." << endl;

        arquivo.close(); 
        cout << "\nRelatório salvo em relatorio.txt" << endl;
    } else {
        cout << "Erro ao criar arquivo." << endl;
    }
    
    cout << "\nResumo: " << aprovados << " aprovados, " << recuperacao << " em recuperação, " << reprovados << " reprovados." << endl;
    
    return 0;
}