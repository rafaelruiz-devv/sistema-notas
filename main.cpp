#include <iostream>
#include <windows.h>
#include <string>
#include <algorithm>
#include <iomanip>
using namespace std;
    int main(){
        SetConsoleOutputCP(65001);

        string nomes[20];
        int qtdAlunos;

        cout << "=== SISTEMA DE NOTAS v4.0 ===" << endl;
        
        do{
            cout << "Quantidade de alunos(1 a 20): ";
            cin >> qtdAlunos;
        }while (qtdAlunos < 1 || qtdAlunos > 20);

        cin.ignore();
        for (int i = 0; i < qtdAlunos; i++){
            cout << "Nome do aluno: " << i + 1 << ": ";
            getline(cin, nomes[i]);
        }

        cout << "\nAlunos cadastrados: " << endl;
        for (int i = 0; i < qtdAlunos; i++){
            cout << "  " << i + 1 << ". " << nomes[i] << endl;
        }

        


        return 0;
    }