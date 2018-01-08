#include <cstdlib>
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include "Grafo.h"
#include <algorithm>
#include <locale.h>

#define MAX_SIZE    100

int i, j;

Grafo::Grafo() {
    
    setlocale(LC_ALL, "Portuguese");
    
    Matriz = (int**)malloc(MAX_SIZE * sizeof(int*));

    for (i = 0; i < MAX_SIZE; i++){
        Matriz[i] = (int*) malloc(MAX_SIZE * sizeof(int));
        for (j = 0; j < MAX_SIZE; j++){
             Matriz[i][j] = 0;
        }
    }
}

Grafo::~Grafo() {}

void Grafo::Menu() {
    int opcao;
    bool grafo = false, grau = false;
    
    do {
        printf("\n--------------------------------------------------------------\n");
        printf("\n|| MENU PRINCIPAL ||\n");
        
        printf("\nO que deseja fazer?\n"
                "\t1. Informar um novo Grafo\n"
                "\t2. Calcular o grau de um Vértice\n"
                "\t3. Verificar se o grafo é regular\n"
                "\t4. Verificar se o grafo é completo\n"
                "\t0. Sair\n\n");
        std::cin >> opcao;
        
        switch (opcao) {
            case 1:
                Grafinhos();
                grafo = true;
                break;
            case 2:
                if (grafo == true) {
                    Grau();
                    grau = true;
                } else
                    printf("Você deve informar um grafo primeiro!");
                break;
            case 3:
                if (grafo == true && grau == true)
                    Regular();
                else if (grafo == false)
                    printf("Você deve informar um grafo primeiro!");
                else if (grau == false)
                    printf("Você deve calcular o grau primeiro!");
                break;
            case 4:
                if (grafo == true && grau == true)
                    Completo();
                else if (grafo == false)
                    printf("Você deve informar um grafo primeiro!");
                else if (grau == false)
                    printf("Você deve calcular o grau primeiro!");
                break;
            case 0:
                printf("\n--------------------------------------------------------------\n");
                printf("\n\xa9 Programa desenvolvido pelos alunos Larissa Silva e Raí Aris\n");
                printf("\n--------------------------------------------------------------\n");
            default:
                break;
        }
    } while(opcao != 0);
  
}

void Grafo::Grafinhos() {
    printf("\n--------------------------------------------------------------\n");
    printf("\nDigite a quantidade de vértices do seu grafo: ");
    scanf(" %d", &Vertices);

    printf("Digite <1> para direcionado e <2> para não direcionado: ");
    std::cin >> Direcionado;

    printf("O grafo possiu peso? <S> ou <N> ");
    std::cin >> PesoVert;

    int escolha = Vertices, peso;
    char adicionar;
    int **mat = (int**)malloc(escolha * sizeof(int*));

    for (i = 0; i < escolha; i++){
        mat[i] = (int*) malloc(escolha * sizeof(int));
        for (j = 0; j < escolha; j++){
             mat[i][j] = 0;
        }
    }  
    
    do {
        int esc1 = 0;
        int esc2 = 0;

        printf("\nDigite a origem da aresta: ");
        scanf(" %d", &esc1);
        printf("Digite o destino da aresta: ");
        scanf(" %d", &esc2);

        if (PesoVert == 'N' || PesoVert == 'n'){
            peso = 1;
        } else {
            printf("\nDigite o peso da aresta: ");
            scanf(" %d", &peso);
        }

        mat[esc1-1][esc2-1] = peso;
        
        if(Direcionado == 2){
            mat[esc2-1][esc1-1] = mat[esc1-1][esc2-1];
        }

        printf("\nDeseja adicionar mais uma aresta? Digite <S> para Sim e <N> para Não ");
        scanf(" %s", &adicionar);

    } while(adicionar == 'S' || adicionar == 's');
    
    Grafo::SetMatriz(mat);
    
    printf("\n");
    
    for(i = 0; i < escolha; i++){
        for(j = 0; j < escolha; j++){
            printf("%d\t", Grafo::GetMatriz()[i][j]);
        }
        printf("\n\n");
    }
    
}

void Grafo::Grau(){
   
    int selecionar, opc;
    char verificar;
    
    cont = (int*) malloc (Vertices * sizeof(int));
    
    printf("--------------------------------------------------------------\n");
    printf("\n\nDeseja saber <1> o grau de todas as vértices ou de <2> cada uma das vértices individualmente? ");
    scanf("%d", &opc);
    
    for (i = 0; i < Vertices; i++) {
        for (j = 0; j < Vertices; j++) {
            if(Grafo::GetMatriz()[i][j] > 0) {
                cont[i] = cont[i] + 1;
            }
        }
        
    }
    
    if(opc == 1) {

        for(i = 0; i < Vertices; i++) {
            printf("\nGrau da vértice %d: %d", i + 1, cont[i]);
        }
        printf("\n");
        
    } else if (opc == 2) {
        do {
            printf("\nDigite o vértice que deseja saber o grau: ");
            std::cin >> selecionar;

            printf("\nO grau do vertice %d e: %d\n", selecionar, cont[selecionar-1]);

            printf("\nDeseja saber o grau de outro vértice? <S> ou <N> ");
            std::cin >> verificar;

        } while(verificar == 'S' || verificar == 's');
    }
}

void Grafo::Regular() {
    printf("\n--------------------------------------------------------------\n");
    int regra = 0;
    for(int i = 1; i < Vertices; i++) {
        if(cont[i] != cont[i-1]) {
            regra = 1;
        }
    }
    if (regra == 0) {
            printf("\nO grafo é regular.\n");
        } else {
            printf("\nO grafo não é regular.\n");
        }
}

void Grafo::Completo() {
    printf("\n--------------------------------------------------------------\n");
    int regra = 0;
    for(i = 1; i < Vertices; i++){
        if(cont[i] != cont[i-1]){
            regra = 1;
        }
    }
    
    if(regra == 0) {
        if(cont[1] = Vertices-1)
            printf("\nO grafo é completo\n");
        else
            printf("\nO grafo não é completo\n");    
    }else if(regra > 0) {
        printf("\nO grafo não é completo\n");
    }
}

//--------------------------------------------- GETTERS E SETTERS -------------------------------------------------------\\

void Grafo::SetVertices(int  vertices) {
    Vertices = vertices ;
}
int Grafo::GetVertices() {
    return Vertices;
}

void Grafo::SetDirecionado(int direcionado) {
    Direcionado = direcionado;
}
int Grafo::GetDirecionado() {
    return Direcionado; 
}

void Grafo::SetPesoVert(char  pesovert) {
    PesoVert = pesovert;
}
char Grafo::GetPesoVert() {
    return PesoVert;
}

int **Grafo::GetMatriz() {
    return Matriz;
}
void Grafo::SetMatriz(int **matriz) {
    Matriz = matriz;
}

int *Grafo::GetCont() {
    return cont;
}
void Grafo::SetCont(int *Cont) {
    cont = Cont;
}