#include <stdio.h>
#include <stdlib.h>

#include "mathio.h"
#include "gauss.h"
#include "backsubst.h"

int main(int argc, char *argv[]) {
	if(argc != 2) {
		fprintf(stderr, "%s: Należy podać nazwę 1 pliku do wczytania macierzy.\n", argv[0]);
		return 1;
	}

	FILE *file = fopen(argv[1], "r");
	if(file == NULL) {
		fprintf(stderr, "%s: Nie można otworzyć pliku \"%s\"!\n", argv[0], argv[1]);
		return 1;
	}

	matrix_t matr = read_matrix(file);
	if(matr.mat == NULL) {
		fprintf(stderr, "%s: Nie można utworzyć macierzy!\n", argv[0]);
		fclose(file);
		return 1;
	}

	fclose(file);
	free_matrix(matr);
	return 0;
}
