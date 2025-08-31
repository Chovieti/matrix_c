#include "../s21_matrix.h"

int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int error = 0;
  int limit = 0;
  if (A == NULL || A->matrix == NULL || B == NULL || B->matrix == NULL ||
      result == NULL)
    error = 1;
  else if ((A->rows == 0 || A->columns == 0 || B->rows == 0 ||
            B->columns == 0) ||
           (A->columns != B->rows))
    error = 2;
  else {
    matrix_t tmp_result = {0};
    s21_create_matrix(A->rows, B->columns, &tmp_result);
    s21_create_matrix(A->rows, B->columns, result);
    limit = A->columns;
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < B->columns; j++) {
        tmp_result.matrix[i][j] = 0;
        for (int k = 0; k < limit; k++)
          tmp_result.matrix[i][j] += (A->matrix[i][k] * B->matrix[k][j]);
      }
    }
    s21_census_matrix(tmp_result, result);
    s21_remove_matrix(&tmp_result);
  }
  return error;
}