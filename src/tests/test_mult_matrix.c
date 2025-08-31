#include <string.h>

#include "test.h"

START_TEST(s21_mult_matr_1) {
  matrix_t matr1 = {0};
  matrix_t matr2 = {0};
  matrix_t result = {0};
  s21_create_matrix(1, 1, &matr1);
  s21_create_matrix(1, 1, &matr2);

  matr1.matrix[0][0] = 1.0;
  matr2.matrix[0][0] = 1.0;

  int return_value = s21_mult_matrix(&matr1, &matr2, &result);

  char res[30] = {0}, exp[30] = {0};
  sprintf(res, "%.6lf", result.matrix[0][0]);
  sprintf(exp, "%.6lf", 1.0);
  ck_assert_str_eq(res, exp);

  s21_remove_matrix(&matr1);
  s21_remove_matrix(&matr2);
  s21_remove_matrix(&result);

  ck_assert_int_eq(return_value, 0);
}
END_TEST

START_TEST(s21_mult_matr_2) {
  matrix_t matr1 = {0};
  matrix_t matr2 = {0};
  matrix_t result = {0};
  s21_create_matrix(2, 2, &matr1);
  s21_create_matrix(2, 2, &matr2);

  matr1.matrix[0][0] = 1.0;
  matr1.matrix[0][1] = -2.0;
  matr1.matrix[1][0] = 3.0;
  matr1.matrix[1][1] = 4.0;

  matr2.matrix[0][0] = 5.0;
  matr2.matrix[0][1] = 6.0;
  matr2.matrix[1][0] = -7.0;
  matr2.matrix[1][1] = 8.0;
  int return_value = s21_mult_matrix(&matr1, &matr2, &result);

  char res[30] = {0}, exp[30] = {0};
  sprintf(res, "%.6lf", result.matrix[0][0]);
  sprintf(exp, "%.6lf", 19.0);
  ck_assert_str_eq(res, exp);
  sprintf(res, "%.6lf", result.matrix[0][1]);
  sprintf(exp, "%.6lf", -10.0);
  ck_assert_str_eq(res, exp);
  sprintf(res, "%.6lf", result.matrix[1][0]);
  sprintf(exp, "%.6lf", -13.0);
  ck_assert_str_eq(res, exp);
  sprintf(res, "%.6lf", result.matrix[1][1]);
  sprintf(exp, "%.6lf", 50.0);
  ck_assert_str_eq(res, exp);

  s21_remove_matrix(&matr1);
  s21_remove_matrix(&matr2);
  s21_remove_matrix(&result);

  ck_assert_int_eq(return_value, 0);
}
END_TEST

START_TEST(s21_mult_matr_3) {
  matrix_t matr1 = {0};
  matrix_t matr2 = {0};
  matrix_t result = {0};
  s21_create_matrix(3, 2, &matr1);
  s21_create_matrix(2, 3, &matr2);

  matr1.matrix[0][0] = 13.4;
  matr1.matrix[0][1] = 2.18;
  matr1.matrix[1][0] = 46.02;
  matr1.matrix[1][1] = 7.9;
  matr1.matrix[2][0] = 12.97;
  matr1.matrix[2][1] = -41.7;

  matr2.matrix[0][0] = 5.04;
  matr2.matrix[0][1] = 67.0;
  matr2.matrix[0][2] = -6.3;
  matr2.matrix[1][0] = 1023.4;
  matr2.matrix[1][1] = 8.9;
  matr2.matrix[1][2] = -8.9;
  int return_value = s21_mult_matrix(&matr1, &matr2, &result);

  char res[30] = {0}, exp[30] = {0};
  sprintf(res, "%.6lf", result.matrix[0][0]);
  sprintf(exp, "%.6lf", 2298.548);
  ck_assert_str_eq(res, exp);
  sprintf(res, "%.6lf", result.matrix[0][1]);
  sprintf(exp, "%.6lf", 917.202);
  ck_assert_str_eq(res, exp);
  sprintf(res, "%.6lf", result.matrix[0][2]);
  sprintf(exp, "%.6lf", -103.822);
  ck_assert_str_eq(res, exp);
  sprintf(res, "%.6lf", result.matrix[1][0]);
  sprintf(exp, "%.6lf", 8316.8008);
  ck_assert_str_eq(res, exp);
  sprintf(res, "%.6lf", result.matrix[1][1]);
  sprintf(exp, "%.6lf", 3153.65);
  ck_assert_str_eq(res, exp);
  sprintf(res, "%.6lf", result.matrix[1][2]);
  sprintf(exp, "%.6lf", -360.236);
  ck_assert_str_eq(res, exp);
  sprintf(res, "%.6lf", result.matrix[2][0]);
  sprintf(exp, "%.6lf", -42610.4112);
  ck_assert_str_eq(res, exp);
  sprintf(res, "%.6lf", result.matrix[2][1]);
  sprintf(exp, "%.6lf", 497.86);
  ck_assert_str_eq(res, exp);
  sprintf(res, "%.6lf", result.matrix[2][2]);
  sprintf(exp, "%.6lf", 289.419);
  ck_assert_str_eq(res, exp);

  s21_remove_matrix(&matr1);
  s21_remove_matrix(&matr2);
  s21_remove_matrix(&result);

  ck_assert_int_eq(return_value, 0);
}
END_TEST

START_TEST(s21_mult_matr_4) {
  matrix_t matr1 = {0};
  matrix_t matr2 = {0};
  matrix_t result = {0};
  s21_create_matrix(3, 3, &matr1);
  s21_create_matrix(3, 3, &matr2);

  matr1.matrix[0][0] = -58.4531;
  matr1.matrix[0][1] = -24.775;
  matr1.matrix[0][2] = -59.3403;
  matr1.matrix[1][0] = 63.67794;
  matr1.matrix[1][1] = 8.974778;
  matr1.matrix[1][2] = -67.5502;
  matr1.matrix[2][0] = 15.47442;
  matr1.matrix[2][1] = 5.08746;
  matr1.matrix[2][2] = -92.8;

  matr2.matrix[0][0] = 41.7869;
  matr2.matrix[0][1] = 76.0431;
  matr2.matrix[0][2] = 48.385;
  matr2.matrix[1][0] = -18.9432;
  matr2.matrix[1][1] = 80.382;
  matr2.matrix[1][2] = -69.615;
  matr2.matrix[2][0] = 46.012;
  matr2.matrix[2][1] = -67.8471;
  matr2.matrix[2][2] = -36.205;

  int return_value = s21_mult_matrix(&matr1, &matr2, &result);

  char res[30] = {0}, exp[30] = {0};
  sprintf(res, "%.6lf", result.matrix[0][0]);
  sprintf(exp, "%.6lf", -4703.621948);
  ck_assert_str_eq(res, exp);
  sprintf(res, "%.6lf", result.matrix[0][1]);
  sprintf(exp, "%.6lf", -2410.35171);
  ck_assert_str_eq(res, exp);
  sprintf(res, "%.6lf", result.matrix[0][2]);
  sprintf(exp, "%.6lf", 1044.873943);
  ck_assert_str_eq(res, exp);
  sprintf(res, "%.6lf", result.matrix[1][0]);
  sprintf(exp, "%.6lf", -617.227106);
  ck_assert_str_eq(res, exp);
  sprintf(res, "%.6lf", result.matrix[1][1]);
  sprintf(exp, "%.6lf", 10146.763739);
  ck_assert_str_eq(res, exp);
  sprintf(res, "%.6lf", result.matrix[1][2]);
  sprintf(exp, "%.6lf", 4901.932947);
  ck_assert_str_eq(res, exp);
  sprintf(res, "%.6lf", result.matrix[2][0]);
  sprintf(exp, "%.6lf", -3719.658331);
  ck_assert_str_eq(res, exp);
  sprintf(res, "%.6lf", result.matrix[2][1]);
  sprintf(exp, "%.6lf", 7881.873957);
  ck_assert_str_eq(res, exp);
  sprintf(res, "%.6lf", result.matrix[2][2]);
  sprintf(exp, "%.6lf", 3754.390284);
  ck_assert_str_eq(res, exp);

  s21_remove_matrix(&matr1);
  s21_remove_matrix(&matr2);
  s21_remove_matrix(&result);

  ck_assert_int_eq(return_value, 0);
}
END_TEST

START_TEST(s21_mult_matr_5) {
  matrix_t matr1 = {0};
  matrix_t matr2 = {0};
  matrix_t result = {0};
  s21_create_matrix(2, 2, &matr1);
  s21_create_matrix(2, 2, &matr2);

  matr1.matrix[0][0] = 1.0;
  matr1.matrix[0][1] = 2.5;
  matr1.matrix[1][0] = 4.8;
  matr1.matrix[1][1] = 9.4;

  matr2.matrix[0][0] = 0.0;
  matr2.matrix[0][1] = 0.0;
  matr2.matrix[1][0] = 0.0;
  matr2.matrix[1][1] = 0.0;
  int return_value = s21_mult_matrix(&matr1, &matr2, &result);
  char res[30] = {0}, exp[30] = {0};
  sprintf(res, "%.6lf", result.matrix[0][0]);
  sprintf(exp, "%.6lf", 0.0);
  ck_assert_str_eq(res, exp);
  sprintf(res, "%.6lf", result.matrix[0][1]);
  sprintf(exp, "%.6lf", 0.0);
  ck_assert_str_eq(res, exp);
  sprintf(res, "%.6lf", result.matrix[1][0]);
  sprintf(exp, "%.6lf", 0.0);
  ck_assert_str_eq(res, exp);
  sprintf(res, "%.6lf", result.matrix[1][1]);
  sprintf(exp, "%.6lf", 0.0);
  ck_assert_str_eq(res, exp);

  s21_remove_matrix(&matr1);
  s21_remove_matrix(&matr2);
  s21_remove_matrix(&result);

  ck_assert_int_eq(return_value, 0);
}
END_TEST

START_TEST(s21_mult_matr_6) {
  matrix_t matr1 = {0};
  matrix_t matr2 = {0};
  matrix_t result = {0};
  s21_create_matrix(2, 3, &matr1);
  s21_create_matrix(3, 2, &matr2);
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 3; j++) {
      matr1.matrix[i][j] = i + j;
      matr2.matrix[j][i] = i + j;
    }
  }
  int return_value = s21_mult_matrix(&matr1, &matr2, &result);
  char res[30] = {0}, exp[30] = {0};
  sprintf(res, "%.6lf", result.matrix[0][0]);
  sprintf(exp, "%.6lf", 5.0);
  ck_assert_str_eq(res, exp);
  sprintf(res, "%.6lf", result.matrix[0][1]);
  sprintf(exp, "%.6lf", 8.0);
  ck_assert_str_eq(res, exp);
  sprintf(res, "%.6lf", result.matrix[1][0]);
  sprintf(exp, "%.6lf", 8.0);
  ck_assert_str_eq(res, exp);
  sprintf(res, "%.6lf", result.matrix[1][1]);
  sprintf(exp, "%.6lf", 14.0);
  ck_assert_str_eq(res, exp);

  s21_remove_matrix(&matr1);
  s21_remove_matrix(&matr2);
  s21_remove_matrix(&result);
  ck_assert_int_eq(return_value, 0);
}
END_TEST

START_TEST(s21_mult_matr_7) {
  matrix_t matr1 = {0};
  matrix_t matr2 = {0};
  s21_create_matrix(2, 3, &matr1);
  s21_create_matrix(3, 2, &matr2);
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 3; j++) {
      matr1.matrix[i][j] = i + j;
      matr2.matrix[j][i] = i + j;
    }
  }
  int return_value = s21_mult_matrix(&matr1, &matr2, NULL);
  s21_remove_matrix(&matr1);
  s21_remove_matrix(&matr2);
  ck_assert_int_eq(return_value, 1);
}
END_TEST

Suite *s21_mult_matrix_suite(void) {
  Suite *c = suite_create("mult_matrix");
  TCase *tc = tcase_create("->");

  tcase_add_test(tc, s21_mult_matr_1);
  tcase_add_test(tc, s21_mult_matr_2);
  tcase_add_test(tc, s21_mult_matr_3);
  tcase_add_test(tc, s21_mult_matr_4);
  tcase_add_test(tc, s21_mult_matr_5);
  tcase_add_test(tc, s21_mult_matr_6);
  tcase_add_test(tc, s21_mult_matr_7);

  suite_add_tcase(c, tc);
  return c;
}