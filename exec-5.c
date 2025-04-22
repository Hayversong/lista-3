/*
Faça um programa que utilizando apenas as funções desenvolvidas
para a pilha, implemente uma função que teste se duas pilhas são iguais
ou não.
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
int teste_pilhas(Pilha *p1, Pilha *p2) {
    int igual;
    if (p1->topo != p2->topo) {
        return igual = 0;
    } else {
        while (!pilha_vazia(p1)) {
            int valor1, valor2;
            pop(p1, &valor1);
            pop(p2, &valor2);
    
            if (valor1 != valor2) {
                return igual = 0;
            }
        }
        return igual = 1;
    }

}

int main() {
    Pilha p1, p2;
    cria_pilha(&p1);
    cria_pilha(&p2);

    push(&p1, 9);
    push(&p1, 9);
    push(&p2, 9);
    push(&p2, 7);

    if(teste_pilhas(&p1, &p2) == 0){
        printf("As pilhas sao diferentes\n");
    } else{
        printf("As pilhas sao iguais\n");
    }

    return 0;
}

/*
    Basicamente, o código vai comparando os valores que estão no topo das daus pilhas, 
    se forem iguais, ele vai tirando os valores do topo e comparando com o próximo valor,
    se não forem iguais, ele retorna 0, se os últimos valores forem iguais, ele retorna 1.
*/