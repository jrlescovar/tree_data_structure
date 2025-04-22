#ifndef IN_ORDEM_ABB_H
#define IN_ORDEM_ABB_H
#include <stdio.h>
#include "tree.h"

void in_ordemRecursivo(tree *raiz){
    if(raiz != NULL){
        in_ordemRecursivo(raiz->esq);   // Percorre a subárvore esquerda
        printf("%d\t", raiz->info);     // Imprime o valor do nó atual
        in_ordemRecursivo(raiz->dir);   // Percorre a subárvore direita
    }
}
void in_ordemInterativo(tree *raiz) {
    pilha *p;
    init(&p);  // Inicializa a pilha
    push(&p, raiz);  // Empilha a raiz

    while (!isEmpty(p)) {
        if (raiz != NULL) {
            pop(&p, &raiz);  // Pega o nó atual
            while (raiz != NULL) {
                push(&p, raiz);  // Empilha o nó atual
                raiz = raiz->esq;  // Vai para o filho à esquerda
            }
        }
        pop(&p, &raiz);  // Retorna ao nó anterior (mais profundo sem filho esquerdo (NULL))
        printf("%d\t", raiz->info);  // Processa o nó (IN-ORDEN)
        raiz = raiz->dir;  // Vai para o filho à direita
        if (raiz != NULL)
            push(&p, raiz);  // Empilha o filho à direita
    }
    free(p);  // Libera a pilha
}
#endif
