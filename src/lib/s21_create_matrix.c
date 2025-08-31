#include "../s21_matrix.h"

int s21_create_matrix(int rows, int columns, matrix_t *result) {
  int error = 0;
  if (rows <= 0 || columns <= 0 || result == NULL)
    error = 1;
  else {
    result->matrix = (double **)calloc(rows, sizeof(double *));
    if (result->matrix == NULL) error = 1;

    for (int i = 0; i < rows && error == 0; i++) {
      result->matrix[i] = (double *)calloc(columns, sizeof(double));
      if (result->matrix[i] == NULL) s21_fail_free(result, i, &error);
    }
    if (error == 0) {
      result->rows = rows;
      result->columns = columns;
    }
  }
  return error;
}
