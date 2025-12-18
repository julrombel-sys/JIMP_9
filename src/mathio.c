#include "mathio.h"

matrix_t new_matrix(int row, int col) {
	matrix_t matr;
	matr.mat = malloc(row * sizeof(int*));
	if(matr.mat == NULL)
		return matr;
	for(int i = 0; i < row; ++i) {
		matr.mat = malloc(col * sizeof(int));
		if(matr.mat == NULL) {
			for(int j = 0; j < i; ++j)
				free(matr.mat[j]);
			free(matr.mat);
			matr.mat = NULL;
			return matr;
		}
	}
	matr.row = row;
	matr.col = col;
	return matr;
}

matrix_t read_matrix(FILE *file)  {
	matrix_t matr;
	matr.mat = NULL;

	if(fscanf(file, "%d%d", &matr.row, &matr.col) != 2)
		return matr;
	matr.mat = malloc(matr.row * sizeof(int*));
	if(matr.mat == NULL)
		return matr;
	for(int i = 0; i < matr.row; ++i) {
		matr.mat[i] = malloc(matr.col * sizeof(int));
		if(matr.mat[i] == NULL) {
			for(int j = 0; j < i; ++j)
				free(matr.mat[j]);
			free(matr.mat);
			matr.mat = NULL;
			return matr;
		}
		for(int j = 0; j < matr.col; ++j) {
			if(fscanf(file, "%d", &matr.mat[i][j]) != 1) {
				for(int k = 0; k <= i; ++k)
					free(matr.mat[k]);
				free(matr.mat);
				matr.mat = NULL;
				return matr;
			}
		}
	}
	return matr;
}

void print_matrix(FILE* file, matrix_t matr) {
	fprintf(file, "%dx%d\n", matr.row, matr.col);
	for(int i = 0; i < matr.row; ++i) {
		fputc('[', file);
		for(int j = 0; j < matr.col; ++j)
			fprintf(file, "\t%d", matr.mat[i][j]);
		fputc(']', file);
		fputc('\n', file);
	}
}

void free_matrix(matrix_t matr) {
	for(int i = 0; i < matr.row; ++i)
		free(matr.mat[i]);
	free(matr.mat);
}
