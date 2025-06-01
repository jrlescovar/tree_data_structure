/*
APLICAÇÃO COM ARQUIVO
N = 10
				{
				|		CODIGO | NOME  | STATUS | ELO
				|-------------------------------------------       Reg
				|	1 |		   |       |        |	 0			   [112 | carla | 1 | 10]	
				|	2 |	122	   |  jose |   1    |    11
AREA DE DADOS	|	3 |		   |       |        |    0              RegDad
	------>		|	4 |		   |       |        |    0              [122  |jose | 1  | 12 ] 
				|	5 |	85	   |  joao |    1   |    0              122 % N = 2
				|	6 |		   |       |        |    0
				|	...		   |       |        |    0
				|	9 |	  	   |       |        |    0
				{		   	   |       |        |    0
AREA DE			|	10| 92     | maia  |    1   |    0
				|   11| 112    | carla |    1   |    10
	overflow	|	<EOF>
				|	
				{
*/

void insereArqHash(TpReg reg){
	TpReg regDad; char achou;
	int ender;
	FILE *ptrArq = fope("arqHash.dat","rb+");
	ender = Hash(reg.codgio);
	fseek(ptrArq,ender * sizeof(TpReg), 0);
	fread(&regDad,sizeof(TpReg),1,ptrArq);
	if(regDad.codigo == 0){ // area de dados disponivel.
		fseek(ptrArq, ender * sizeof(TpReg), 0);
		fwrite(&reg, sizeof(TpReg), 1,ptrArq);
	}else{ // colisao
		buscaHash(ptrArq, reg.codigo, ender, &achou); // busca varrendo encadeamento, ve se o codigo que quero cadastrar ja tem no arquivo.
		
		if(achou)
			printf("Codigo já Existe!\n");
		else{
			reg.elo = regDad.elo;
			fseek(ptrArq,0,2);
			regDad.elo = ftell(ptrArq)/sizeof(TpReg);
			fwrite(&reg, sizeof(TpReg),1,ptrArq);
			fseek(ptrArq,ender * sizeof(TpReg),0);
			fwrite(&regDad, sizeof(TpReg),1,ptrArq);
		}
	}
	fclsoe(ptrArq);
}
