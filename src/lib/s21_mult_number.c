#include "../s21_matrix.h"

int s21_mult_number(matrix_t *A, double number, matrix_t *result) {
  int error = 0;
  if (A->rows == 0 || A->columns == 0 || A == NULL || result == NULL)
    error = 1;
  else {
    matrix_t tmp_result = {0};
    s21_create_matrix(A->rows, A->columns, &tmp_result);
    s21_create_matrix(A->rows, A->columns, result);
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++) {
        tmp_result.matrix[i][j] = A->matrix[i][j] * number;
      }
    }
    s21_census_matrix(tmp_result, result);
    s21_remove_matrix(&tmp_result);
  }
  return error;
}