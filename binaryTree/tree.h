#include <stdlib.h>

struct Tree{
	int info;
	struct Tree *esq, *dir;
};typedef struct Tree tree;

tree *criaNo(int info){
    tree *raiz = (tree *)malloc(sizeof(tree));
    raiz->info = info;
    raiz->esq = NULL;
    raiz->dir = NULL;
    return raiz;
}