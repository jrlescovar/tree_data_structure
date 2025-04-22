#ifndef POS_ORDEM_ABB_H
#define POS_ORDEM_ABB_H
#include <stdio.h>
#include "tree.h"

void pos_ordemRecursivo(tree *raiz){
    if(raiz != NULL){
        pos_ordemRecursivo(raiz->esq);
        pos_ordemRecursivo(raiz->dir);
        printf("%d\t", raiz->info);
    }
}

void pos_ordemInterativo(tree *raiz) {
    pilha *p, *p2;
    init(&p);
    init(&p2);
    push(&p, raiz);
    while (!isEmpty(p)) {
        pop(&p, &raiz);
        push(&p2, raiz);
        // Empilha primeiro a esquerda, depois a direita (invertido para a p2 sair certo)
        if (raiz->esq != NULL)
            push(&p, raiz->esq);
        if (raiz->dir != NULL)
            push(&p, raiz->dir);
    }
    // Agora, a p2 tem os nós na ordem pós-ordem
    while (!isEmpty(p2)) {
        pop(&p2, &raiz);
        printf("%d\t", raiz->info);
    }

    free(p);
    free(p2);
}
#endif