#include "../s21_matrix.h"

int s21_determinant(matrix_t *A, double *result) {
  int error = 0;
  if (A->rows == 0 || A->columns == 0 || A->matrix == NULL || A == NULL ||
      result == NULL)
    error = 1;
  else if (A->rows != A->columns)
    error = 2;
  else {
    matrix_t tmp_matrix = {0};
    *result = 0.0;
    if (A->rows == 1)
      *result = A->matrix[0][0];
    else if (A->rows == 2)
      *result = (A->matrix[0][0] * A->matrix[1][1]) -
                (A->matrix[0][1] * A->matrix[1][0]);
    else if (A->rows > 2 && A->rows < 5)
      s21_recurs_determinant(A, &tmp_matrix, result);
    else if (A->rows >= 5)
      s21_gauss_determinant(A, &tmp_matrix, result);
  }
  return error;
}