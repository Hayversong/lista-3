/*
Faça um programa que tenha uma nova função chamada pop2() para
desempilhar dois elementos da pilha e uma outra função chamada
push2() para empilhar 2 elementos a partir do topo da pilha. Não devem
ser utilizadas as funções de push e pop já existentes.
*/
#include <stdio.h>
#include <stdlib.h>

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

int push2(Pilha *p, int valor1, int valor2){
    if (p->topo >= MAX - 2) {
        
        printf("erro, pilha cheia.\n");
        
        return 1;
    }
    p->topo++;
    p->info[p->topo] = valor1;

    p->topo++;
    p->info[p->topo] = valor2;

    printf("empilhado: %d %d\n", valor1, valor2);
}

void pop2(Pilha *p){
    if(p->topo < 1){
        printf("a pilha tem menos de 2 elementos");
        return;
    }

    int valor1 = p->info[p->topo];
    p->topo--;

    int valor2 = p->info[p->topo];
    p->topo--;

    printf("popado: %d e %d\n", valor1, valor2);
}
void printar_pilha(Pilha *p){
    printf("Pilha: ");
    for (int i = 0; i <= p->topo; i++) {
        printf("%d ", p->info[i]);
    }
    printf("\n");
}

int main(){
    Pilha p;
    cria_pilha(&p);

    push2(&p, 15, 5);
    push2(&p, 20, 1);
    printar_pilha(&p);

    pop2(&p);
    printar_pilha(&p);

    return 0;
}

/*
    eu usei a estrutura de pilha estática para fazer o exercicio, usei como base os slides e adaptei o código para inserir mais elementos do que os de exemplo
*/