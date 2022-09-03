#include "matriz.h"

int main() {

	int ans = 0, cont = 0;

	Matriz m;
	HashTable h;

	while (1) {

		printf("\n1- Executar o programa");
		printf("\n2- Sair\n");
		scanf("%d", &ans);

		if (ans == 1) {
	
			lerMatriz(&m);
			multMatriz(&m);
			int M = m.tam*m.tam;
			if (cont == 0) {
				initialize(&h,M);
			}
			hash(&m,&h);
			cont++;

		} else if (ans == 2) {
			printf("\nVocê saiu do programa\n");
			return 0;

		}

	}

	return 0;
}