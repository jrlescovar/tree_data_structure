#define TF 6
struct KDTree{
    int ponto[k];
    struct kdtree *esq, *dir;
}
typedef struct KDTree kdTree;

kdTree *CriaNo(int ponto[k]){
    kdTree *no = (kdTree*) = malloc(sizeof(kdTree));
    int i;
    for(i=0; i < K ;i++)
        no->ponto[i]= ponto[i];
    no->esq = no->dir = NULL;
    return no;
}

void ordena(int pontos[TF][K], int d, int ini, int fim){
    int i,j,TL = fim, aux[K];
    while(TL >= ini){
        for(i = ini, i<TL; i++){
            if(pontos[i][d] > pontos[i + 1][d]){
                for(j=0; j<K; j++)
                    aux[j] = pontos[i][j];
                for(j = 0; j <K; j++)
                    pontos[i][j] = pontos[i+1][j];
                for(j=0; j<K; j++)
                    pontos[i+1][j] = aux[j];
            }
            TL--;
        }
    }
}
void insereKdTree(kdTree **raiz, int pontos[TF][K], int n,int ini, int fim){
    int d,meio;
    if(ini<fim){
        d = n%K;
        ordena(pontos,d,ini,fim);
        meio = (ini + fim)/2;
        *raiz = CriaNo(pontos[meio]);
        insereKdTree(&(*raiz)->esq, pontos, n+1, ini, meio-1);
        insereKdTree(&(*raiz)->dir, pontos, n+1, meio+1, fim);
    }
}
int main(){
    int pontos[TF][K] = {{30,4},{5,25},{10,12},{70,70},{50,3}};
    kdTree *raiz = NULL;
    //insereKdtree(&raiz, pontos, 0, 0, TF-1);
    ordena(pontos, 0,0, TF-1);
    int i;
    for(i=0; i<TF;i++)
        printf("(%d,%d)\n",pontos[i][0],pontos[i][1]);
}