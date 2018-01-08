#include <cstdlib>
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include "Grafo.h"
#include <algorithm>
#include <string>

Grafo::Grafo() {

}

Grafo::~Grafo() {}

void Grafo::SetVertices(int  m_vertices) {
    Vertices = m_vertices ;
}
int Grafo::GetVertices() {
    return Vertices;
}

void Grafo::SetDirecionado(char m_direcionado) {
    Direcionado = m_direcionado;
}
char Grafo::GetDirecionado() {
    return Direcionado;
}

void Grafo::SetPesoVert(char  m_pesovert) {
    PesoVert = m_pesovert;
}
char Grafo::GetPesoVert() {
    return PesoVert;
}

void Grafo::Menu() {
    int escolha = Vertices;

    int **matriz = (int**)malloc(escolha * sizeof(int*));

    for (int i = 0; i < escolha; i++){
        matriz[i] = (int*) malloc(escolha * sizeof(int));
        for (int j = 0; j < escolha; j++){
             matriz[i][j] = 0;
        }
    }

    int *conta;

    conta = (int*) malloc (escolha * sizeof(int));


    char menu;
    int opcao;

    do {
        printf("\n|| MENU PRINCIPAL ||\n");

        printf("O que deseja fazer?"
                "1. Informar um novo Grafo\n"
                "2. Calcular o grau de um Vertice\n"
                "3. Verificar se o grafo é regular\n"
                "4. Verificar se o grafo é completo\n");
        std::cin >> opcao;

        switch (opcao) {
            case 1:
                Grafinhos(matriz, escolha);
                break;
            case 2:
                Grau(matriz, escolha, conta);
                break;
            case 3:
                Regular(escolha, conta);
                break;
            case 4:
                Completo(escolha, conta);
                break;
            default:
                printf("\nOpcao invalida.");
                break;
        }
    } while(menu == 'S' || menu == 's');

}

void Grafo::Grafinhos(int **matriz, int escolha) {

    int peso;

    printf("Digite a Quantidade de Vertices do seu Grafo:\n");
    scanf(" %d", &Vertices);

    printf("Digite <S> para Direcional e <N> para Nao Direcional: ");
    std::cin >> Direcionado;

    printf("O grafo possiu peso? <S> ou <N>");
    std::cin >> PesoVert;


    char adicionar;

    do {
        int esc1 = 0;
        int esc2 = 0;

        printf("Digite a origem da aresta: ");
        scanf(" %d", &esc1);
        printf("Digite o destino da aresta: ");
        scanf(" %d", &esc2);

        if (PesoVert == 'N' || PesoVert == 'n'){
            peso = 1;
        } else {
            printf("Digite o peso da aresta: ");
            scanf(" %d", &peso);
        }

        matriz[esc1-1][esc2-1] = peso;

        if(Direcionado == 'N' || Direcionado == 'n'){
            matriz[esc2-1][esc1-1] = matriz[esc1-1][esc2-1];
        }

        printf("Deseja adicionar mais uma Aresta? Digite <S> para Sim e <N> para nao.");
        scanf(" %s", &adicionar);

    } while(adicionar == 'S' || adicionar == 's');

    for(int i=0;i<escolha;i++){
        for(int j=0;j<escolha;j++){
            printf("%d\t", matriz[i][j]);
        }
        printf("\n");
    }
}

void Grafo::Grau(int **matriz, int escolha, int *conta){

    int selecionar, opc;
    char verificar;

    printf("Deseja saber <1> o grau de todas as vertices ou de <2> cada uma das vertices individualmente? ");
    scanf("%d", &opc);

    for (int i = 0; i < escolha; i++) {
        for (int j = 0; j < escolha; j++) {
            if(matriz[i][j] > 0) {
                conta[i] = conta[i] + 1;
            }
        }

    }

    if(opc == 1) {

        for(int i = 0; i < escolha; i++) {
            printf("\nGrau da vertice %d: %d", i + 1, conta[i]);
        }
        printf("\n");

    } else if (opc == 2) {
        do {
            printf("Digite o Vertice que deseja saber o grau: ");
            std::cin >> selecionar;

            printf("O grau do vertice %d e: %d", selecionar, conta[selecionar-1]);

            printf("\nDeseja saber o grau de outro vertice? <S> ou <N> ");
            std::cin >> verificar;

        } while(verificar == 'S' || verificar == 's');
    }

    Regular(escolha, conta);
    Completo(escolha, conta);

}

void Grafo::Regular(int escolha, int cont[]) {
    int regra = 0;
    for(int i = 1; i < escolha; i++) {
        if(cont[i] != cont[i-1]) {
            regra = 1;
        }
    }
    if (regra == 0) {
            printf("\nO grafo é regular.");
        } else {
            printf("\nO grafo não é regular.");
        }
}

void Grafo::Completo(int escolha, int cont[]) {
    int regra = 0;
    for(int i = 1; i < escolha; i++){
        if(cont[i] != cont[i-1]){
            regra = 1;
        }
    }

    if(regra == 0) {
        if(cont[1] = Vertices-1)
            printf("\nSeu Grafo e Completo\n");
        else
            printf("\nSeu Grafo nao e Completo\n");
    }else if(regra > 0) {
        printf("\nSeu Grafo nao e Completo\n");
    }
}
