#include "matriz.h"

void lerMatriz(Matriz *m) {

    char nome[30];
    FILE *arq;

    arq=fopen("matriz.txt", "r");
    fgets(nome, 1, arq);

    for (m->i = 0; m->i < LIN; m->i++){
        for (m->j  = 0; m->j < COL; m->j++){
            fscanf(arq, "%d ", &m->matA[m->i][m->j]);
    }

    }

    fclose(arq);

}

void multMatriz(Matriz *m) {

    int linhaInicial = 0, colunaInicial = 0;
    int tam;

    printf("\nInforme a linha e coluna inicial:\n\n");
    printf("Linha Inicial: ");
    scanf("%d", &linhaInicial);
    printf("Coluna Inicial: ");
    scanf("%d", &colunaInicial);

    printf("\nTamanho da matriz: \n");
    scanf("%d", &tam);

    m->linhaInicial = linhaInicial;
    m->colunaInicial = colunaInicial;

    int **matC, aux = 0, cont = 0;
    matC = (int**)malloc(tam*sizeof(int*));
    for(int i = 0; i < tam; i++) {
        matC[i] = (int*)malloc(tam*sizeof(int));
    }
    int x = 0, y = 0, mat1[tam][tam], mat2[tam][tam];

    printf("\nMatriz resultante:\n");

    for (m->i = linhaInicial; m->i < tam + linhaInicial; m->i++){
        for (m->j = colunaInicial; m->j < tam + colunaInicial; m->j++){
            printf("%d ", m->matA[m->i][m->j]);
            mat1[x][y] = m->matA[m->i][m->j];
            y++;
        }
        y = 0;
        x++;
        printf("\n");
    }

    x = 0, y = 0;
    printf("\nTransposta:\n");
    for(x = 0; x < tam; x++) {
        for(y = 0; y < tam; y++) {
            mat2[x][y] = mat1[y][x];
            printf("%d ", mat2[x][y]);
        }
        printf("\n");
    }
    
    printf("\nResultado da multiplicação:\n");

    for(x = 0; x < tam; x++) {
        for(y = 0; y < tam; y++) {

            matC[x][y] = 0;
        
            for (cont = 0; cont < tam; cont++) {
                aux +=  mat1[x][cont] * mat2[cont][y];
            }

            matC[x][y] = aux;
            aux = 0;
        }
    }
    for(x = 0; x < tam; x++) {
        for(y = 0; y < tam; y++) {
            printf("%d ", matC[x][y]);
        }
        printf("\n");
    }

    m->matC = matC;
    m->tam = tam;

}



void hash(Matriz *m, HashTable *h) {

    int chave = 0;

    chave = m->linhaInicial*100+m->colunaInicial;
    insert(h, chave, *m);
    printf("\n");
    imprime(h);
   
}

void initialize(HashTable *h, int M){

	h->table = (DataTable*) malloc (M * sizeof(DataTable));

	for(int i = 0; i < M; i++) {
		h->table[i].key = -1;
		h->table[i].tam = 0;
	}

	h->M = M;

}


void imprime(HashTable *h) {

	for(int i = 0; i < h->M; i++) {
		printf("KEY: %d - VALUE: \n", h->table[i].key);
        for (int x = 0; x < h->table[i].tam; x++) {
            for (int y = 0; y < h->table[i].tam; y++) {
                printf("%d ", h->table[i].value[x][y]);
            }
            printf("\n");
        }
    }

}

void insert(HashTable *h, int key, Matriz value){

	int idx = HASH(key, h->M);
	int aux = idx;

	while (h->table[idx].key != -1){
		idx = (idx + 1) % h->M;
		if (idx == aux){
			printf("OPENED HASH IS FULL!\n");
			return;
		}
	}	

	h->table[idx].tam = value.tam;
	h->table[idx].key = key;
	h->table[idx].value = value.matC;

}