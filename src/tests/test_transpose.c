#include <string.h>

#include "test.h"

START_TEST(s21_transpose_1) {
  matrix_t matr = {0};
  matrix_t result = {0};
  s21_create_matrix(1, 1, &matr);

  matr.matrix[0][0] = 1.0;

  int return_value = s21_transpose(&matr, &result);

  char res[30] = {0}, exp[30] = {0};
  sprintf(res, "%.6lf", result.matrix[0][0]);
  sprintf(exp, "%.6lf", 1.0);
  ck_assert_str_eq(res, exp);

  s21_remove_matrix(&matr);
  s21_remove_matrix(&result);

  ck_assert_int_eq(return_value, 0);
}
END_TEST

START_TEST(s21_transpose_2) {
  matrix_t matr = {0};
  matrix_t result = {0};
  s21_create_matrix(2, 2, &matr);

  matr.matrix[0][0] = 1.0;
  matr.matrix[0][1] = -2.0;
  matr.matrix[1][0] = 3.0;
  matr.matrix[1][1] = 4.0;

  int return_value = s21_transpose(&matr, &result);

  char res[30] = {0}, exp[30] = {0};
  sprintf(res, "%.6lf", result.matrix[0][0]);
  sprintf(exp, "%.6lf", 1.0);
  ck_assert_str_eq(res, exp);
  sprintf(res, "%.6lf", result.matrix[0][1]);
  sprintf(exp, "%.6lf", 3.0);
  ck_assert_str_eq(res, exp);
  sprintf(res, "%.6lf", result.matrix[1][0]);
  sprintf(exp, "%.6lf", -2.0);
  ck_assert_str_eq(res, exp);
  sprintf(res, "%.6lf", result.matrix[1][1]);
  sprintf(exp, "%.6lf", 4.0);
  ck_assert_str_eq(res, exp);

  s21_remove_matrix(&matr);
  s21_remove_matrix(&result);

  ck_assert_int_eq(return_value, 0);
}
END_TEST

START_TEST(s21_transpose_3) {
  matrix_t matr = {0};
  matrix_t result = {0};
  s21_create_matrix(3, 2, &matr);

  matr.matrix[0][0] = 13.4;
  matr.matrix[0][1] = 2.18;
  matr.matrix[1][0] = 46.02;
  matr.matrix[1][1] = 7.9;
  matr.matrix[2][0] = 12.97;
  matr.matrix[2][1] = -41.7;
  int return_value = s21_transpose(&matr, &result);

  char res[30] = {0}, exp[30] = {0};
  sprintf(res, "%.6lf", result.matrix[0][0]);
  sprintf(exp, "%.6lf", 13.4);
  ck_assert_str_eq(res, exp);
  sprintf(res, "%.6lf", result.matrix[0][1]);
  sprintf(exp, "%.6lf", 46.02);
  ck_assert_str_eq(res, exp);
  sprintf(res, "%.6lf", result.matrix[0][2]);
  sprintf(exp, "%.6lf", 12.97);
  ck_assert_str_eq(res, exp);
  sprintf(res, "%.6lf", result.matrix[1][0]);
  sprintf(exp, "%.6lf", 2.18);
  ck_assert_str_eq(res, exp);
  sprintf(res, "%.6lf", result.matrix[1][1]);
  sprintf(exp, "%.6lf", 7.9);
  ck_assert_str_eq(res, exp);
  sprintf(res, "%.6lf", result.matrix[1][2]);
  sprintf(exp, "%.6lf", -41.7);
  ck_assert_str_eq(res, exp);

  s21_remove_matrix(&matr);
  s21_remove_matrix(&result);

  ck_assert_int_eq(return_value, 0);
}
END_TEST

START_TEST(s21_transpose_4) {
  matrix_t matr = {0};
  matrix_t result = {0};
  s21_create_matrix(3, 3, &matr);

  matr.matrix[0][0] = -58.4531;
  matr.matrix[0][1] = -24.775;
  matr.matrix[0][2] = -59.3403;
  matr.matrix[1][0] = 63.67794;
  matr.matrix[1][1] = 8.974778;
  matr.matrix[1][2] = -67.5502;
  matr.matrix[2][0] = 15.47442;
  matr.matrix[2][1] = 5.08746;
  matr.matrix[2][2] = -92.8;

  int return_value = s21_transpose(&matr, &result);

  char res[30] = {0}, exp[30] = {0};
  sprintf(res, "%.6lf", result.matrix[0][0]);
  sprintf(exp, "%.6lf", -58.4531);
  ck_assert_str_eq(res, exp);
  sprintf(res, "%.6lf", result.matrix[0][1]);
  sprintf(exp, "%.6lf", 63.67794);
  ck_assert_str_eq(res, exp);
  sprintf(res, "%.6lf", result.matrix[0][2]);
  sprintf(exp, "%.6lf", 15.47442);
  ck_assert_str_eq(res, exp);
  sprintf(res, "%.6lf", result.matrix[1][0]);
  sprintf(exp, "%.6lf", -24.775);
  ck_assert_str_eq(res, exp);
  sprintf(res, "%.6lf", result.matrix[1][1]);
  sprintf(exp, "%.6lf", 8.974778);
  ck_assert_str_eq(res, exp);
  sprintf(res, "%.6lf", result.matrix[1][2]);
  sprintf(exp, "%.6lf", 5.08746);
  ck_assert_str_eq(res, exp);
  sprintf(res, "%.6lf", result.matrix[2][0]);
  sprintf(exp, "%.6lf", -59.3403);
  ck_assert_str_eq(res, exp);
  sprintf(res, "%.6lf", result.matrix[2][1]);
  sprintf(exp, "%.6lf", -67.5502);
  ck_assert_str_eq(res, exp);
  sprintf(res, "%.6lf", result.matrix[2][2]);
  sprintf(exp, "%.6lf", -92.8);
  ck_assert_str_eq(res, exp);

  s21_remove_matrix(&matr);
  s21_remove_matrix(&result);

  ck_assert_int_eq(return_value, 0);
}
END_TEST

START_TEST(s21_transpose_5) {
  matrix_t matr = {0};
  matrix_t result = {0};
  s21_create_matrix(2, 2, &matr);

  matr.matrix[0][0] = 0.0;
  matr.matrix[0][1] = 3.15;
  matr.matrix[1][0] = 0.0;
  matr.matrix[1][1] = 0.0;
  int return_value = s21_transpose(&matr, &result);
  char res[30] = {0}, exp[30] = {0};
  sprintf(res, "%.6lf", result.matrix[0][0]);
  sprintf(exp, "%.6lf", 0.0);
  ck_assert_str_eq(res, exp);
  sprintf(res, "%.6lf", result.matrix[0][1]);
  sprintf(exp, "%.6lf", 0.0);
  ck_assert_str_eq(res, exp);
  sprintf(res, "%.6lf", result.matrix[1][0]);
  sprintf(exp, "%.6lf", 3.15);
  ck_assert_str_eq(res, exp);
  sprintf(res, "%.6lf", result.matrix[1][1]);
  sprintf(exp, "%.6lf", 0.0);
  ck_assert_str_eq(res, exp);

  s21_remove_matrix(&matr);
  s21_remove_matrix(&result);

  ck_assert_int_eq(return_value, 0);
}
END_TEST

START_TEST(s21_transpose_6) {
  matrix_t matr = {0};
  matrix_t result = {0};
  s21_create_matrix(2, 3, &matr);
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 3; j++) {
      matr.matrix[i][j] = i + j;
    }
  }
  int return_value = s21_transpose(&matr, &result);
  char res[30] = {0}, exp[30] = {0};
  sprintf(res, "%.6lf", result.matrix[0][0]);
  sprintf(exp, "%.6lf", 0.0);
  ck_assert_str_eq(res, exp);
  sprintf(res, "%.6lf", result.matrix[0][1]);
  sprintf(exp, "%.6lf", 1.0);
  ck_assert_str_eq(res, exp);
  sprintf(res, "%.6lf", result.matrix[1][0]);
  sprintf(exp, "%.6lf", 1.0);
  ck_assert_str_eq(res, exp);
  sprintf(res, "%.6lf", result.matrix[1][1]);
  sprintf(exp, "%.6lf", 2.0);
  ck_assert_str_eq(res, exp);
  sprintf(res, "%.6lf", result.matrix[2][0]);
  sprintf(exp, "%.6lf", 2.0);
  ck_assert_str_eq(res, exp);
  sprintf(res, "%.6lf", result.matrix[2][1]);
  sprintf(exp, "%.6lf", 3.0);
  ck_assert_str_eq(res, exp);

  s21_remove_matrix(&matr);
  s21_remove_matrix(&result);
  ck_assert_int_eq(return_value, 0);
}
END_TEST

START_TEST(s21_transpose_7) {
  matrix_t matr = {0};
  s21_create_matrix(2, 3, &matr);
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 3; j++) {
      matr.matrix[i][j] = i + j;
    }
  }
  int return_value = s21_transpose(&matr, NULL);
  s21_remove_matrix(&matr);
  ck_assert_int_eq(return_value, 1);
}
END_TEST

Suite *s21_transpose_suite(void) {
  Suite *c = suite_create("transpose");
  TCase *tc = tcase_create("->");

  tcase_add_test(tc, s21_transpose_1);
  tcase_add_test(tc, s21_transpose_2);
  tcase_add_test(tc, s21_transpose_3);
  tcase_add_test(tc, s21_transpose_4);
  tcase_add_test(tc, s21_transpose_5);
  tcase_add_test(tc, s21_transpose_6);
  tcase_add_test(tc, s21_transpose_7);

  suite_add_tcase(c, tc);
  return c;
}