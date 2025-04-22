/*
Faça um programa que apresente um menu contínuo com as seguintes
opções e execute de acordo com a escolha do usuário.
void menu()
{
 printf("1-Inicializa pilha.\n");
 printf("2-Verifica se a pilha e vazia.\n");
 printf("3-Verifica se a pilha e cheia.\n");
 printf("4-Empilha o elemento na pilha.\n");
 printf("5-Desempilha elemento da pilha.\n");
 printf("6-Le topo de um pilha.\n");
 printf("7-Converte um numero decimal em binario.\n");
 printf("8-Sair.\n");
}
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

void menu() {
    printf("1-Inicializa pilha.\n");
    printf("2-Verifica se a pilha eh vazia.\n");
    printf("3-Verifica se a pilha eh cheia.\n");
    printf("4-Empilha o elemento na pilha.\n");
    printf("5-Desempilha elemento da pilha.\n");
    printf("6-Le topo de um pilha.\n");
    printf("7-Converte um numero decimal em binario.\n");
    printf("8-Sair.\n");
}

void conversao(int n) {
    Pilha p;
    cria_pilha(&p);

    while (n > 0) {
        push(&p, n % 2);
        n /= 2;
    }

    printf("Binario:");
    while (!pilha_vazia(&p)) {
        int aux;
        pop(&p, &aux);
        printf("%d", aux);
    }
}

int main() {
    Pilha p;
    int escolha, valor;
    while (escolha != 8){
        printf("\n");
        menu();
        printf("Escolha uma opcao: ");
        scanf("%d", &escolha);
        system("cls");

        if (escolha == 1) {
            cria_pilha(&p);
            printf("Pilha inicializada.\n");
        } else if (escolha == 2) {
            if(pilha_vazia(&p)) {
                printf("A pilha esta vazia.\n");
            } else {
                printf("A pilha nao esta vazia.\n");
            }
        } else if (escolha == 3) {
            if(pilha_cheia(&p)) {
                printf("A pilha esta cheia.\n");
            } else {
                printf("A pilha nao esta cheia.\n");
            }
        } else if (escolha == 4) {
            printf("Digite um valor para empilhar: \n");
            scanf("%d", &valor);
            push(&p, valor);
            printf("Valor empilhado.\n");
        } else if (escolha == 5) {
            pop(&p, &valor);
            printf("Valor desempilhado: %d\n", valor);
        } else if (escolha == 6) {
            printf("Topo da pilha: %d\n", p.info[p.topo]);
        } else if (escolha == 7) {
            printf("Digite um numero decimal: \n");
            scanf("%d", &valor);
            conversao(valor);
        } else if (escolha == 8) {
            printf("Ate mais\n");
        } else {
            printf("Opcao invalida.\n");
        }
    }
    return 0;
}

/*
O menu foi só um loopzinho que fica rodando até o usuário escolher a opção 8, que é sair do programa,
Cada opção chama a sua função respectiva, todas essas funçãoes já tinham sido implementadas antes, com
exceção da função de conversão de decimal para binário, que utiliza a técnica de divisão sucessiva por 2,
salvando os restos em uma pilha.
*/