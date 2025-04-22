
/*
Faça um programa para determinar se uma cadeia de caracteres (string)
é da forma:
x C y
onde x e y são cadeias de caracteres compostas por letras ‘A’ e/ou ‘B’, e y é
o inverso de x. Isto é, se x = “ABABBA”, y deve equivaler a “BABAAB”. Em
cada ponto, você só poderá ler o próximo caractere da cadeia
*/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX 50//constante para tamanho da pilha

typedef struct//estrutura que vai guardar a pilha
{
    char info[MAX];
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

int push(Pilha *p, char valor) {
    if (pilha_cheia(p)) return 0;
    p->info[++(p->topo)] = valor;
    return 1;
}

int pop(Pilha *p, char *valor) {
    if (pilha_vazia(p)) return 0;
    *valor = p->info[(p->topo)--];
    return 1;
}


int verificacao(Pilha *p1, Pilha *p2) {
    if (p1->topo != p2->topo) {
        return 0;
    } else {
        while (!pilha_vazia(p1)) {
            char valor1, valor2;
            pop(p1, &valor1);
            pop(p2, &valor2);
    
            if (valor1 == valor2) {
                return 0;
            }
        }
        return 1;
    }
}

int main() {
    Pilha p1, p2;
    cria_pilha(&p1);
    cria_pilha(&p2);

    push(&p1, 'A');
    push(&p1, 'B');
    push(&p1, 'A');
    push(&p1, 'B');
    push(&p1, 'B');
    push(&p1, 'A');
    
    push(&p2, 'B');
    push(&p2, 'A');
    push(&p2, 'B');
    push(&p2, 'A');
    push(&p2, 'A');
    push(&p2, 'B');

    if(verificacao(&p1, &p2)) {
        printf("y eh inverso de x.\n");
    } else {
        printf("y nao eh inverso de x.\n");
    }
    return 0;
}
/* 
Reutilizei o código que verifica se as duas pilhas são iguais, como os valores
são constantes entre A e B, foi só mudar para verificar se todos são diferentes
caso algum fosse igual, significaria que y não é inverso de x
*/