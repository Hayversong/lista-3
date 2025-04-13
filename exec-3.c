/*
Faça um programa que utilizando apenas as funções desenvolvidas
para a pilha, implemente uma função que receba uma pilha como
parâmetro e retorna como resultado uma cópia dessa pilha. Essa função
deve obedecer ao protótipo:
Pilha *pilha_copia (Pilha* p);
Obs.: Ao final da função copia_pilha, a pilha p recebida como parâmetro
deve estar no mesmo estado em que ela começou a função.
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

void push(Pilha *p, int valor){
    if (p->topo >= MAX - 1) {

        printf("erro, pilha cheia.\n");
        
        return;
    }
    p->topo++;
    p->info[p->topo] = valor;

    printf("empilhado: %d\n", valor);
}

int pop(Pilha *p){
    if(p->topo < 0){

        printf("a pilha nao tem elementos");

        return -1;
    }

    int valor = p->info[p->topo];
    p->topo--;
    return valor;
    printf("popado: %d\n", valor);
}

void printar_pilha(Pilha *p){
    printf("Pilha: ");
    for (int i = 0; i <= p->topo; i++) {
        printf("%d ", p->info[i]);
    }
    printf("\n");
}

Pilha* pilha_copia(Pilha* p) {//copiando a pilha sem mexer no seus estado 
    Pilha *aux = (Pilha*)malloc(sizeof(Pilha));
    Pilha *copia = (Pilha*)malloc(sizeof(Pilha));
    cria_pilha(aux);
    cria_pilha(copia);

    while (p->topo >= 0) {//pilha passando do original
        int valor = pop(p);
        push(aux, valor);
    }

    while (aux->topo >= 0) {
        int valor = pop(aux);
        push(p, valor);       
        push(copia, valor);
    }

    free(aux);
    return copia;
}

int main(){
    Pilha p;
    cria_pilha(&p);

    push(&p, 15);
    push(&p, 20);
    push(&p, 25);
    printar_pilha(&p);

    Pilha *copia = pilha_copia(&p);

    //pop(&p);
    printar_pilha(&p);

    printf("pilha copiada: \n");
    printar_pilha(copia);

    free(copia);
    return 0;
}

/*
    usei a estrutura de código dos exercicíos anteriores, de começo tive certas dificuldades com a função pop a qual estava dando erro mas com um pequeno ajuste tudo certo, a copia_pilha passa o valor da pilha original para uma auxiliar e inverte ela, depois passa a auxiliar para a original e para a cópia, assim é possível retornar as duas pilhas certinho.
*/