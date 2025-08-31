#include "../s21_matrix.h"

int s21_calc_complements(matrix_t *A, matrix_t *result) {
  int error = 0;
  if ((A->rows == 0 || A->columns == 0) || A == NULL || A->matrix == NULL ||
      result == NULL)
    error = 1;
  else if (A->rows != A->columns)
    error = 2;
  else {
    s21_create_matrix(A->rows, A->columns, result);
    if (A->rows == 1) {
      result->matrix[0][0] = A->matrix[0][0];
    } else if (A->rows == 2) {
      for (int i = 0; i < A->rows; i++) {
        for (int j = 0; j < A->columns; j++) {
          if ((A->matrix[(i + 1) % 2][(j + 1) % 2] == 0) || ((i + j) % 2 == 0))
            result->matrix[i][j] = A->matrix[(i + 1) % 2][(j + 1) % 2];
          else
            result->matrix[i][j] = -(A->matrix[(i + 1) % 2][(j + 1) % 2]);
        }
      }
    } else {
      matrix_t tmp_result = {0};
      s21_create_matrix(A->rows, A->columns, &tmp_result);
      s21_calc_comp_main(A, &tmp_result);
      s21_census_matrix(tmp_result, result);
      s21_remove_matrix(&tmp_result);
    }
  }
  return error;
}
