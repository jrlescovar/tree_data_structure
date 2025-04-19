#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include "tree.h"

void localiza(tree *raiz, int info, tree **no){
	if(raiz != NULL){
		if(raiz->info == info)
			*no = raiz;
		else{
			localiza(raiz->esq, info, &*no);
			localiza(raiz->dir, info, &*no);
		}
	}
}

tree *localizaNo(tree * raiz, int infopai){
	tree *no;
	localiza(raiz,infopai,&no);
	return no;
}


void insere(tree **raiz, int info, int infopai, char lado){
	tree *pai;
	if(*raiz == NULL){
		*raiz = criaNo(info);
	}else{
		pai = localizaNo(*raiz, infopai);
		if(pai != NULL){
			if(lado == 'D' && pai->dir == NULL)
				pai->dir = criaNo(info);
			else
				if(lado == 'E' && pai->esq == NULL)
					pai->esq = criaNo(info);
				else
					printf("Lado Indisponivel\n\n");
		}
	}
}
int main(void){
	tree *raiz = NULL;
	insere(&raiz, 50, 0,' ');
	insere(&raiz, 60, 50,'D');
	insere(&raiz, 45, 50,'E');
	printf("Pai - %d", raiz->info);
	printf("\nFilho Esquerda - %d",raiz->esq->info);
	printf("\nFilho Direita - %d",raiz->dir->info);
}
