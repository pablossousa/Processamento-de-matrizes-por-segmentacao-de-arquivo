#ifndef MATRIZ_H 
#define MATRIZ_H

#define LIN 1000
#define COL 1000

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


typedef struct Matriz {
    int i, j, matA[LIN][COL], **matC, tam, linhaInicial, colunaInicial;
} Matriz;

void lerMatriz(Matriz *m);
void multMatriz(Matriz *m);


#define HASH(v, M) (v % M)

typedef struct DataTable DataTable;
typedef struct HashTable HashTable;

struct DataTable{
	int key;
	int **value;
	int tam;
};

struct HashTable{
	DataTable *table;
	int M;
};

void initialize(HashTable *h, int M);
void imprime(HashTable *h);
void insert(HashTable *h, int key, Matriz value);
void hash(Matriz *m, HashTable *h);


#endif