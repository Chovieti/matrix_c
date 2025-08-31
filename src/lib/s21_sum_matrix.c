#include "../s21_matrix.h"

int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int error = 0;
  if (A->rows == 0 || A->columns == 0 || B->rows == 0 || B->columns == 0 ||
      A == NULL || B == NULL || result == NULL)
    error = 1;
  else if ((A->rows != B->rows) || (A->columns != B->columns))
    error = 2;
  else {
    matrix_t tmp_result = {0};
    s21_create_matrix(A->rows, A->columns, &tmp_result);
    s21_create_matrix(A->rows, A->columns, result);
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++) {
        tmp_result.matrix[i][j] = A->matrix[i][j] + B->matrix[i][j];
      }
    }
    s21_census_matrix(tmp_result, result);
    s21_remove_matrix(&tmp_result);
  }
  return error;
}