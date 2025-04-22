#ifndef PRE_ORDEM_ABB_H
#define PRE_ORDEM_ABB_H
#include <stdio.h>
#include "tree.h"

//
void pre_ordemRecursivo(tree *raiz){
    if(raiz != NULL){
        printf("%d\t", raiz->info);
        pre_ordemRecursivo(raiz->esq);
        pre_ordemRecursivo(raiz->dir);
    }
}

void pre_ordemInterativo(tree *raiz) { 
    pilha *p;
    init(&p);  // Passando a pilha por referência
    push(&p, raiz);  // Passando a pilha por referência

    while (!isEmpty(p)) {
        if (raiz != NULL) {
            pop(&p, &raiz);  // Passando a pilha por referência e atribuindo o valor à raiz
            while (raiz != NULL) {
                printf("%d\t", raiz->info);
                push(&p, raiz);  // Empilha o nó atual
                raiz = raiz->esq;  // Vai para o filho à esquerda
            }
        }
        pop(&p, &raiz);  // Passando a pilha por referência e atribuindo o valor à raiz
        raiz = raiz->dir;  // Depois vai para o filho à direita
        if (raiz != NULL)
            push(&p, raiz);  // Empilha o filho à direita
    }
    free(p);  // Libera a pilha após o uso
}
#endif
