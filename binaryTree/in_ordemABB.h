#include "tree.h"   //desnecesseraio esses include, porem coloquei para tirar simbolo de error, mesmo nao sendo execultavel
#include <stdio.h>

void in_ordemRecursivo(tree *raiz){
    if(raiz != NULL){
        in_ordemRecursivo(raiz->esq);   // Percorre a subárvore esquerda
        printf("%d\t", raiz->info);     // Imprime o valor do nó atual
        in_ordemRecursivo(raiz->dir);   // Percorre a subárvore direita
    }
}
