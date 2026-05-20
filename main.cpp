#include <iostream>
#include <windows.h>
#include <string>
#include <algorithm>
#include <iomanip>
using namespace std;
int main()
{
    SetConsoleOutputCP(65001);

    string nomes[20];
    int qtdAlunos;
    float notas[20][5];
    float media[20];
    int qtdDisciplina;

    cout << "=== SISTEMA DE NOTAS v4.0 ===" << endl;

    do
    {
        cout << "Quantidade de alunos(1 a 20): ";
        cin >> qtdAlunos;
    } while (qtdAlunos < 1 || qtdAlunos > 20);

    cin.ignore();

    for (int i = 0; i < qtdAlunos; i++)
    {
        cout << "Nome do aluno " << i + 1 << ": ";
        getline(cin, nomes[i]);
    }
    do
    {
        cout << "Quantidade de disciplinas(1 a 5): " << endl;
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

    return 0;
}