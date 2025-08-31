#include "../s21_matrix.h"

void s21_census_matrix(matrix_t A, matrix_t *B) {
  for (int i = 0; i < B->rows; i++) {
    for (int j = 0; j < B->columns; j++) {
      B->matrix[i][j] = A.matrix[i][j];
    }
  }
}

void s21_create_minor_matrix(int A_i, int A_j, matrix_t A, matrix_t *result) {
  int true_i = 0, true_j = 0;
  for (int i = 0; i < A.rows; i++) {
    if (i != A_i) {
      for (int j = 0; j < A.columns; j++) {
        if (j != A_j) {
          result->matrix[true_i][true_j] = A.matrix[i][j];
          true_j++;
        }
      }
      true_i++;
    }
    true_j = 0;
  }
}

void s21_recurs_determinant(matrix_t *A, matrix_t *tmp_matrix, double *result) {
  double tmp_result = 0.0;
  for (int k = 0; k < A->rows; k++) {
    s21_create_matrix(A->rows - 1, A->columns - 1, tmp_matrix);
    s21_create_minor_matrix(k, 0, *A, tmp_matrix);
    s21_determinant(tmp_matrix, &tmp_result);
    s21_remove_matrix(tmp_matrix);
    if (k % 2 == 0)
      *result += A->matrix[k][0] * tmp_result;
    else
      *result -= A->matrix[k][0] * tmp_result;
  }
}

void s21_gauss_determinant(matrix_t *A, matrix_t *tmp_matrix, double *result) {
  double tmp_result = 1.0;
  s21_create_matrix(A->rows, A->columns, tmp_matrix);
  s21_census_matrix(*A, tmp_matrix);
  for (int k = 0; k < A->rows - 1; k++) {
    for (int i = k; i < A->rows; i++) {
      double tmp_mul = tmp_matrix->matrix[i][k];
      if (tmp_mul != 0) {
        for (int j = k; j < A->columns; j++) {
          tmp_matrix->matrix[i][j] /= tmp_mul;
        }
        tmp_result *= tmp_mul;
      } else {
        for (int j = 0; j < A->columns; j++)
          tmp_matrix->matrix[i][j] +=
              tmp_matrix->matrix[(i + 1) % tmp_matrix->rows][j];
        i--;
      }
    }
    for (int i = k + 1; i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++) {
        tmp_matrix->matrix[i][j] -= tmp_matrix->matrix[k][j];
      }
    }
  }
  *result = tmp_result *
            tmp_matrix->matrix[tmp_matrix->rows - 1][tmp_matrix->columns - 1];
  s21_remove_matrix(tmp_matrix);
}

void s21_calc_comp_main(matrix_t *A, matrix_t *tmp_result) {
  for (int i = 0; i < A->rows; i++) {
    for (int j = 0; j < A->columns; j++) {
      matrix_t tmp_matrix = {0};
      s21_create_matrix(A->rows - 1, A->columns - 1, &tmp_matrix);
      s21_create_minor_matrix(i, j, *A, &tmp_matrix);
      double determinant = 0.0;
      s21_determinant(&tmp_matrix, &determinant);
      s21_remove_matrix(&tmp_matrix);
      if ((i + j) % 2 == 0 || determinant == 0)
        tmp_result->matrix[i][j] = determinant;
      else
        tmp_result->matrix[i][j] = -determinant;
    }
  }
}

void s21_fail_free(matrix_t *result, int i, int *error) {
  for (int j = 0; j < i; j++) {
    free(result->matrix[j]);
  }
  free(result->matrix);
  result->matrix = NULL;
  *error = 1;
}