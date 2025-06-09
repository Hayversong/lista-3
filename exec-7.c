/*
Faça uma função para retornar o número de elementos da pilha que
possuem valor par e o número de elementos com valor ímpar.
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
void par_impar(Pilha *p) {
    int par = 0;
    int impar = 0;
    while (!pilha_vazia(p)) {
        int valor;
        pop(p, &valor);
        if(valor % 2 == 0) {
            par++;
        } else {
            impar++;
        }
    }
    printf("Quantidade de pares: %d\n", par);
    printf("Quantidade de impares: %d\n", impar);
}


int main() {
    Pilha p;
    cria_pilha(&p);

    push(&p, 9989);
    push(&p, 8999);
    push(&p, 9988);
    push(&p, 8988);

    par_impar(&p);

    return 0;
}

/*
    O código vai sempre pegando o valor do topo atual da pilha
    e depois vendo se o resto da divisão dele por 2 é igual a 0,
    se esse resto for igual a zero então é par, aí a variável
    de par recebe ela mesma mais 1, se não for, então a variavel
    de impar recebe ela mesma mais 1
*/