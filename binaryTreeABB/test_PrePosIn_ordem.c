#include <stdio.h>
#include <stdlib.h>
#include "in_ordemABB.h"
#include "pos_ordemABB.h"
#include "pre_ordemABB.h"
#include "tree.h"
#include "InserirABB.h"



//Testar se ta imprimindo na ordem certa;


int main(void){
    tree *raiz = NULL;
    printf("Arvore Simples para Exibir nos Modos Pre-Pos-In\n\n\n");
    insereABBrecursivo(&raiz, 48);
    insereABBrecursivo(&raiz, 23);
    insereABBrecursivo(&raiz, 77);
    insereABBrecursivo(&raiz, 34);
    insereABBrecursivo(&raiz, 7);
    insereABBrecursivo(&raiz, 69);
    insereABBrecursivo(&raiz, 111);
    printf("\t\t        48\n");
    printf("\t\t       /  \\\n");
    printf("\t\t     23    77\n");
    printf("\t\t    / \\   / \\\n");
    printf("\t\t   7  34 69 111\n\n\n");

    printf("[Pre-Ordem] Visita primeiro a raiz, depois a subTree esquerda e em seguida a direita.");
    printf("\nPre-ordem (interativo): ");
    pre_ordemInterativo(raiz);
    printf("\nPre-ordem (Recursivo):  ");
    pre_ordemRecursivo(raiz);

    printf("\n\n[In-Ordem] Percorre a subTree esquerda, depois a raiz e por ultimo a direita. Em uma ABB, mostra os valores em ordem crescente.");
    printf("\nIn-ordem (interativo):  ");
    in_ordemInterativo(raiz);
    printf("\nIn-ordem (Recursivo):   ");
    in_ordemRecursivo(raiz);

    printf("\n\n[Pos-Ordem] Visita primeiro a subTree esquerda, depois a direita e por fim a raiz. Muito usada para deletar folhas da Tree.");
    printf("\nPos-ordem (interativo): ");
    pos_ordemInterativo(raiz);
    printf("\nPos-ordem (Recursivo):  ");
    pos_ordemRecursivo(raiz);



}
