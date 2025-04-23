#ifndef BUSCAR_ABB_H
#define BUSCAR_ABB_H
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include "tree.h"

void buscaABB(tree *raiz, int info, tree **aux) {
    if (raiz == NULL) {
        *aux = NULL;
    } else if (raiz->info == info) {
        *aux = raiz;
    } else if (info < raiz->info) {
        buscaABB(raiz->esq, info, aux);
    } else {
        buscaABB(raiz->dir, info, aux);
    }
}

tree *buscaABBInterativo(tree *raiz, int info) {
    while (raiz != NULL) {
        if (raiz->info == info) {
            return raiz;
        } else if (info < raiz->info) {
            raiz = raiz->esq;
        } else {
            raiz = raiz->dir;
        }
    }
    return 0;  // se nao encontrar
}



#endif