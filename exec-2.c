/*Faça um programa que tenha uma nova função chamada popN() para
desempilhar n elementos a partir do topo da pilha. Não devem ser
utilizadas as funções de push e pop já existentes*/

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

int push(Pilha *p, int valor){
    if (p->topo >= MAX - 2) {
        
        printf("erro, pilha cheia.\n");
        
        return 1;
    }
    p->topo++;
    p->info[p->topo] = valor;

    printf("empilhado: %d\n", valor);
}

void popN(Pilha *p, int n){
    if(p->topo < n - 1){
        printf("a pilha não tem elementos");
        return;
    }
    for(int i = 0; i < n; i++){
        int aux = p->info[p->topo];
        printf("popado: %d\n", aux);
        p -> topo--;
    }
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

    push(&p, 1);
    push(&p, 2);
    printar_pilha(&p);

    popN(&p, 1);
    printar_pilha(&p);

    return 0;
}

/*a lógica de código foi feita em cima do código do exercício anterior, então sua estrutura está bem parecida, a única mudança realmente brusca foi na função pop, a qual agora tem um laço de repetição para desempilhar os n elementos*/