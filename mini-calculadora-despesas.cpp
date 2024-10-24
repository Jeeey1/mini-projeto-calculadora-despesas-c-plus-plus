// Projeto resolvendo problemas do dia-a-dia: Calculadora de despesas
// Você e três amigos dividem um apartamento e precisam gerenciar as despesas mensais de forma justa. Cada um contribui com uma parte do valor total das contas (aluguel, internet, água, luz, etc.). Para facilitar esse processo, você decide criar um programa em C++ que ajude a calcular quanto cada pessoa deve pagar ou receber no final do mês.

// Enunciado do Projeto
// Desenvolva um programa em C++ que:

// Solicite o nome dos quatro moradores do apartamento.
// Solicite o valor total das despesas mensais.
// Solicite quanto cada morador contribuiu para as despesas.
// Calcule a média de contribuição por pessoa.
// Determine quanto cada pessoa deve pagar ou receber para igualar as contribuições.

#include <iostream>
#include <string>

using namespace std;

int main(){
    char saida = true;
    int qtdMoradores;
    double despesas, soma = 0, mediaContri;

    do{
        system("cls");
        cout << "Bem-vindo ao sistema de despesas" << endl;
        cout << "Digite quantos moradores deseja incluir no calculo: ";
        cin >> qtdMoradores;
        system("cls");

        cout << "Total de pessoas selecionadas: " << qtdMoradores << endl;

        // Declaração de variavel
        // Determina quantos moradores vao estar na casa e atribui as arrays
        string moradores[qtdMoradores];
        double contribuicao[qtdMoradores], igualContri[qtdMoradores];

        for (int i = 0; i < qtdMoradores; i++){
            cout << "Digite o nome do morador: ";
            cin.ignore();
            getline(cin, moradores[i]);

            cout << "Digite quanto " << moradores[i] << " contribuiu na casa: ";
            cin >> contribuicao[i];

            soma += contribuicao[i];
        }

        mediaContri = soma / 4;

        for(int i = 0; i < qtdMoradores; i++){
            igualContri[i] = contribuicao[i] - mediaContri;
        }

        cout << "Digite o total das despesas da casa: ";
        cin >> despesas;


        cout << "Moradores: " << moradores[0] << ", " << moradores[1] << ", " << moradores[2] << ", " << moradores[3] << endl;
        cout << "Despesas totais: R$" << despesas << endl;
        cout << "Contribuicoes: " << moradores[0] << " - R$ " << contribuicao[0] << ", " << moradores[1] << " - R$ " << contribuicao[1] << ", " << moradores[2] << " - R$ " << contribuicao[2] << ", " << moradores[3] << " - R$ " << contribuicao[3] << endl;
        cout << "Media de contribuicao: R$" << mediaContri << endl;
        cout << endl;
        for(int i = 0; i < qtdMoradores; i++){
            if (igualContri[i] < 0){
                cout << moradores[i] << " deve receber R$ " << -igualContri[i] << endl;
            } else if (igualContri[i] < 0){
                cout << moradores[i] << " deve pagar R$ " << igualContri[i] << endl;
            } else {
                cout << moradores[i] << " deve pagar R$ " << igualContri[i] << endl;
            }
        }
        
        // realiza verificação se o usuario quer refazer o calculo ou sair do sistema
        char continuar;
        cout << "Deseja refazer o calculo?: ";
        cin >> continuar;

        if (continuar != 'S' and continuar != 's'){
        saida = false;
        }

    } while (saida);

    // impressora caso usuário deseja sair do sistema
    cout << "Voce saiu do sistema...";

    return 0;
}