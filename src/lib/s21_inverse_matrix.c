#include <stdio.h>

#include "../s21_matrix.h"

int s21_inverse_matrix(matrix_t *A, matrix_t *result) {
  int error = 0;
  if ((A->rows == 0 || A->columns == 0) || A == NULL || A->matrix == NULL ||
      result == NULL)
    error = 1;
  else if (A->rows != A->columns)
    error = 2;
  else {
    double determinant = 0.0;
    s21_determinant(A, &determinant);
    if (determinant) {
      error = s21_create_matrix(A->rows, A->columns, result);
      if (error == 0) {
        matrix_t tmp_result = {0};
        if (A->rows == 1)
          result->matrix[0][0] = A->matrix[0][0];
        else {
          s21_create_matrix(A->rows, A->columns, &tmp_result);
          s21_calc_complements(A, &tmp_result);
          s21_transpose(&tmp_result, &tmp_result);
          for (int i = 0; i < A->rows; i++) {
            for (int j = 0; j < A->columns; j++) {
              result->matrix[i][j] = tmp_result.matrix[i][j] / determinant;
            }
          }
          s21_remove_matrix(&tmp_result);
        }
      }
    } else
      error = 2;
  }
  return error;
}