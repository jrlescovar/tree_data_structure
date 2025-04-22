#ifndef TREE_H
#define TREE_H
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
typedef struct Node {
    tree *no;
    struct Node *prox;
} Node;

typedef struct {
    Node *topo;
} pilha;

// Função para inicializar a pilha
void init(pilha **p) {
    *p = (pilha *)malloc(sizeof(pilha));
    (*p)->topo = NULL;
}

// Função para verificar se a pilha está vazia
int isEmpty(pilha *p) {
    return p->topo == NULL;
}

// Função para empilhar um nó na pilha
void push(pilha **p, tree *no) {
    Node *novo = (Node *)malloc(sizeof(Node));
    if (novo != NULL) {
        novo->no = no;
        novo->prox = (*p)->topo;
        (*p)->topo = novo;
    }
}

// Função para desempilhar um nó da pilha
void pop(pilha **p, tree **raiz) {
    if (!isEmpty(*p)) {
        Node *temp = (*p)->topo;
        *raiz = temp->no;
        (*p)->topo = temp->prox;
        free(temp);
    } else {
        *raiz = NULL;  // Caso a pilha esteja vazia
    }
}

#endif