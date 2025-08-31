#ifndef S21_MATRIX_H
#define S21_MATRIX_H

#include <math.h>
#include <stdlib.h>

#define SUCCESS 1
#define FAILURE 0
#define EPSILON 0.000001

typedef struct matrix_struct {
  double **matrix;
  int rows;
  int columns;
} matrix_t;

int s21_create_matrix(int rows, int columns, matrix_t *result);
void s21_remove_matrix(matrix_t *A);
int s21_eq_matrix(matrix_t *A, matrix_t *B);
int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
int s21_mult_number(matrix_t *A, double number, matrix_t *result);
int s21_transpose(matrix_t *A, matrix_t *result);
int s21_determinant(matrix_t *A, double *result);
int s21_calc_complements(matrix_t *A, matrix_t *result);
int s21_inverse_matrix(matrix_t *A, matrix_t *result);

void s21_census_matrix(matrix_t A, matrix_t *B);
void s21_create_minor_matrix(int A_i, int A_j, matrix_t A, matrix_t *result);
void s21_recurs_determinant(matrix_t *A, matrix_t *tmp_matrix, double *result);
void s21_gauss_determinant(matrix_t *A, matrix_t *tmp_matrix, double *result);
void s21_calc_comp_main(matrix_t *A, matrix_t *tmp_result);
void s21_fail_free(matrix_t *result, int i, int *error);

#endif