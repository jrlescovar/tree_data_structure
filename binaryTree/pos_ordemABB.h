#include "tree.h"   //desnecesseraio esses include, porem coloquei para tirar simbolo de error, mesmo nao sendo execultavel
#include <stdio.h>

void pos_ordemRecursivo(tree *raiz){
    if(raiz != NULL){
        pos_ordemRecursivo(raiz->esq);
        pos_ordemRecursivo(raiz->dir);
        printf("%d\t", raiz->info);
    }
}