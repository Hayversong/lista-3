/*
Dado uma pilha que armazene números, escreva uma função que
forneça o maior, o menor e a média aritmética dos elementos da pilha.
*/
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX 50//constante para tamanho da pilha

typedef struct//estrutura que vai guardar a pilha
{
    int info[MAX];
    int topo; 
}Pilha;

void cria_pilha(Pilha *p){
    p->topo = -1;
}

int pilha_vazia(Pilha *p){//verifica se a pilha tá vazia
    return p->topo == -1;
}

int pilha_cheia(Pilha *p){
    return p->topo == MAX - 1;
}

int push(Pilha *p, int valor) {
    if (pilha_cheia(p)) return 0;
    p->info[++(p->topo)] = valor;
    return 1;
}

int pop(Pilha *p, int *valor) {
    if (pilha_vazia(p)) return 0;
    *valor = p->info[(p->topo)--];
    return 1;
}

void calcularEstatisticas(Pilha *p, int *maior, int *menor, float *media) {
    if (pilha_vazia(p)) {
        *maior = *menor = 0;
        *media = 0.0;
        return;
    }

    int soma = 0;
    int count = 0;
    *maior = INT_MIN;
    *menor = INT_MAX;

    Pilha aux;
    cria_pilha(&aux);

        while (!pilha_vazia(p)) {
            int valor;
            pop(p, &valor);
        
            if (valor > *maior) *maior = valor;
            if (valor < *menor) *menor = valor;
            soma += valor;
            count++;

            push(&aux, valor);
        }

    *media = (float)soma / count;

    
        while (!pilha_vazia(&aux)) {
            int valor;
            pop(&aux, &valor);
            push(p, valor);
        }
    }

int main() {
    Pilha p;
    cria_pilha(&p);

    push(&p, 10);
    push(&p, 20);
    push(&p, 5);
    push(&p, 30);

    int maior, menor;
    float media;

    calcularEstatisticas(&p, &maior, &menor, &media);

    printf("maior: %d\n", maior);
    printf("menor: %d\n", menor);
    printf("media: %.2f\n", media);

    return 0;
}

/*o processo para criar a pilha e todas suas funcionalidades são os mesmos utilizados anteriormente, para o cálculo de média eu usei como base o código do exercicio anterior para usar uma pillha auxiliar que iria ser usada para calcular, a função percorre a pilha inteira enquanto mantém os elementos nessa pilha auxiliar, vai atualizando o maior e o menor conforme necessário e por último faz a soma dos elementos, assim calcula a média e retorna os valores*/