#include "gauss.h"

void gauss_elim(matrix_t *mat) {
	int ax, i, j;
	for(ax = 0; ax < mat->row; ++ax) {
		for(i = ax+1; i < mat->row; ++i) {
			double z = mat->mat[i][ax];
			for(j = 0; j < mat->col; ++j) {
				//fprintf(stderr, "%lg %lg %lg\n", mat->mat[i][ax], mat->mat[ax][j], mat->mat[ax][ax]);
				mat->mat[i][j] -= mat->mat[ax][j] * z / mat->mat[ax][ax];
			}
		}
		print_matrix(stderr, *mat);
	}
}
