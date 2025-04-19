#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

#include "tree.h"

void insereABB(tree **raiz, int info){
    tree *aux;
    int flag = 0; //for stop while 
    if(*raiz == NULL){// raiz == null , then create a new tree
        *raiz = criaNo(info);
    }else{
        aux = *raiz;
        while(!flag){// could be , while(1) and  to stop it would be break;
            if(info < aux->info){//valor for menor que o atual entra pras raizes da esquerda
                if(aux->esq == NULL){
                    aux->esq = criaNo(info);
                    flag = 1; //stop while
                }else //se ja estiver ocupado, avança ate achar um local nulo para inserir
                    aux = aux->esq; 
            }else{
                if(aux->dir == NULL){ //caso valor seja maior vai para direita
                    aux->dir = criaNo(info);
                    flag = 1;// stop while
                }else//se ja estiver ocupado, avança ate achar um local nulo para inserir
                    aux = aux->dir;
            }
        }
    }
}

//Forma recursvia 1
void insereABBrecursivo(tree **raiz, int info){
    if(*raiz == NULL){ // se tiver vazio
        *raiz = criaNo(info);
    }else{
        if(info < (*raiz)->info)//valor menor que o atual vai para esquerda
            if((*raiz)->esq == NULL) //se estiver vazio, insere
                (*raiz)->esq = criaNo(info);
            else
                insereABBrecursivo(&(*raiz)->esq, info);//caso não esteja vazio, desce a raiz para esquerda
        else //valor maior que o atual vai para direita
            if((*raiz)->dir == NULL)//se estiver vazio insere
                (*raiz)->dir = criaNo(info);
            else
                insereABBrecursivo(&(*raiz)->dir, info);//caso nao esteja vazio, desce a raiz para direita
    }
}

//Forma recursiva 2 ( MENOR )
void insereABBR(tree **raiz, int info){
    if (*raiz == NULL)
        *raiz = criaNo(info);
    else {
        if (info < (*raiz)->info)
            insereABBR(&(*raiz)->esq, info);
        else
            insereABBR(&(*raiz)->dir, info);
    }
}
