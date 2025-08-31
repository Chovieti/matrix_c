#include "../s21_matrix.h"

int s21_transpose(matrix_t *A, matrix_t *result) {
  int error = 0;
  if (A->rows == 0 || A->columns == 0 || A == NULL || A->matrix == NULL ||
      result == NULL)
    error = 1;
  else {
    matrix_t tmp_result = {0};
    s21_create_matrix(A->columns, A->rows, &tmp_result);
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++) {
        tmp_result.matrix[j][i] = A->matrix[i][j];
      }
    }
    s21_create_matrix(A->columns, A->rows, result);
    s21_census_matrix(tmp_result, result);
    s21_remove_matrix(&tmp_result);
  }
  return error;
}