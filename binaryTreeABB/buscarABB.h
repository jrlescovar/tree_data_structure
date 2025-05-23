#ifndef BUSCAR_ABB_H
#define BUSCAR_ABB_H
#include<stdio.h> //nao precisa disso aqui so para tirar simbolo de erro do meu compilador
#include<stdlib.h>
#include<ctype.h>
#include "tree.h"

void buscaABB(tree *raiz, int info, tree **aux){
    /*if (raiz == NULL) {
        *aux = NULL;
    } else if (raiz->info == info) {
        *aux = raiz;
    } else if (info < raiz->info) {
        buscaABB(raiz->esq, info, &*aux);
    } else {
        buscaABB(raiz->dir, info, &*aux);
    }*/
    if(raiz != NULL){
    	if(info == raiz->info){
    		*aux = raiz;
    	}else
    		if(info > raiz->info)
    			buscaABB(raiz->dir,info,&*aux);
    		else
    			buscaABB(raiz->esq,info,&*aux);
    }else{
    	*aux = NULL;
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

tree * buscaABBrecursivareturn(tree *raiz, int info){

	if(raiz != NULL){
		if(info == raiz->info)
			return raiz;
		else if(info > raiz->info)
			buscaABBrecursivareturn(raiz->dir, info);
		else
			buscaABBrecursivareturn(raiz->esq, info);

	}else
		return NULL;

}

#endif
