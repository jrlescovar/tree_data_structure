#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include "in_ordemABB.h"
#include "pos_ordemABB.h"
#include "pre_ordemABB.h"
#include "tree.h"
#include "InserirABB.h"
int main(void)
{
    tree *raiz = NULL;
    int press, ok;
    do
    {
        system("cls");
        printf("Digite o Numero\n");
        printf("[1] - Inserir na Arvore\n");
        printf("[2] - Exibir a Arvore\n");
        printf("[0] - SAIR\n");
        printf("Opcao: ");
        scanf("%d", &press);
        switch (press)
        {
        case 1:
            do
            {
                printf("\n\n Inserir na Arvore...");
                printf("Digite [0] para parar de Inserir | Digite um Numero: ");
                scanf("%d", &ok);
                if (ok != 0)
                    insereABBrecursivo(&raiz, ok);
            } while (ok != 0);
            break;
        case 2:
            printf("\n\n");
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
            getch();
            break;
        default:
            printf("Opcao Invalida!, tente [1], [2] ou [0]");
            getch();
        }

    } while (press != 0);
}