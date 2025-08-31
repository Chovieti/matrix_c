#include <string.h>

#include "test.h"

START_TEST(s21_sum_1) {
  matrix_t matr1 = {0};
  matrix_t matr2 = {0};
  matrix_t result = {0};
  s21_create_matrix(1, 1, &matr1);
  s21_create_matrix(1, 1, &matr2);

  matr1.matrix[0][0] = 1.0;
  matr2.matrix[0][0] = 1.0;

  int return_value = s21_sum_matrix(&matr1, &matr2, &result);

  char res[30] = {0}, exp[30] = {0};
  sprintf(res, "%.6lf", result.matrix[0][0]);
  sprintf(exp, "%.6lf", 2.0);
  ck_assert_str_eq(res, exp);

  s21_remove_matrix(&matr1);
  s21_remove_matrix(&matr2);
  s21_remove_matrix(&result);

  ck_assert_int_eq(return_value, 0);
}
END_TEST

START_TEST(s21_sum_2) {
  matrix_t matr1 = {0};
  matrix_t matr2 = {0};
  matrix_t result = {0};
  s21_create_matrix(2, 2, &matr1);
  s21_create_matrix(2, 2, &matr2);

  matr1.matrix[0][0] = 1.0;
  matr1.matrix[0][1] = 2.0;
  matr1.matrix[1][0] = 3.0;
  matr1.matrix[1][1] = 4.0;

  matr2.matrix[0][0] = 5.0;
  matr2.matrix[0][1] = 6.0;
  matr2.matrix[1][0] = 7.0;
  matr2.matrix[1][1] = 8.0;
  int return_value = s21_sum_matrix(&matr1, &matr2, &result);

  char res[30] = {0}, exp[30] = {0};
  sprintf(res, "%.6lf", result.matrix[0][0]);
  sprintf(exp, "%.6lf", 6.0);
  ck_assert_str_eq(res, exp);
  sprintf(res, "%.6lf", result.matrix[0][1]);
  sprintf(exp, "%.6lf", 8.0);
  ck_assert_str_eq(res, exp);
  sprintf(res, "%.6lf", result.matrix[1][0]);
  sprintf(exp, "%.6lf", 10.0);
  ck_assert_str_eq(res, exp);
  sprintf(res, "%.6lf", result.matrix[1][1]);
  sprintf(exp, "%.6lf", 12.0);
  ck_assert_str_eq(res, exp);

  s21_remove_matrix(&matr1);
  s21_remove_matrix(&matr2);
  s21_remove_matrix(&result);

  ck_assert_int_eq(return_value, 0);
}
END_TEST

START_TEST(s21_sum_3) {
  matrix_t matr1 = {0};
  matrix_t matr2 = {0};
  matrix_t result = {0};
  s21_create_matrix(2, 2, &matr1);
  s21_create_matrix(2, 2, &matr2);

  matr1.matrix[0][0] = 13.45;
  matr1.matrix[0][1] = 2.187;
  matr1.matrix[1][0] = 46.012;
  matr1.matrix[1][1] = 7.908;

  matr2.matrix[0][0] = 5.045;
  matr2.matrix[0][1] = 67.6;
  matr2.matrix[1][0] = 1023.45;
  matr2.matrix[1][1] = 8.97;
  int return_value = s21_sum_matrix(&matr1, &matr2, &result);

  char res[30] = {0}, exp[30] = {0};
  sprintf(res, "%.6lf", result.matrix[0][0]);
  sprintf(exp, "%.6lf", 18.495);
  ck_assert_str_eq(res, exp);
  sprintf(res, "%.6lf", result.matrix[0][1]);
  sprintf(exp, "%.6lf", 69.787);
  ck_assert_str_eq(res, exp);
  sprintf(res, "%.6lf", result.matrix[1][0]);
  sprintf(exp, "%.6lf", 1069.462);
  ck_assert_str_eq(res, exp);
  sprintf(res, "%.6lf", result.matrix[1][1]);
  sprintf(exp, "%.6lf", 16.878);
  ck_assert_str_eq(res, exp);

  s21_remove_matrix(&matr1);
  s21_remove_matrix(&matr2);
  s21_remove_matrix(&result);

  ck_assert_int_eq(return_value, 0);
}
END_TEST

START_TEST(s21_sum_4) {
  matrix_t matr1 = {0};
  matrix_t matr2 = {0};
  matrix_t result = {0};
  s21_create_matrix(3, 3, &matr1);
  s21_create_matrix(3, 3, &matr2);

  matr1.matrix[0][0] = -58.453132;
  matr1.matrix[0][1] = -24.775042;
  matr1.matrix[0][2] = -59.340386;
  matr1.matrix[1][0] = 63.677941;
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

  int return_value = s21_sum_matrix(&matr1, &matr2, &result);

  char res[30] = {0}, exp[30] = {0};
  sprintf(res, "%.6lf", result.matrix[0][0]);
  sprintf(exp, "%.6lf", -16.666232);
  ck_assert_str_eq(res, exp);
  sprintf(res, "%.6lf", result.matrix[0][1]);
  sprintf(exp, "%.6lf", 51.268058);
  ck_assert_str_eq(res, exp);
  sprintf(res, "%.6lf", result.matrix[0][2]);
  sprintf(exp, "%.6lf", -10.955386);
  ck_assert_str_eq(res, exp);
  sprintf(res, "%.6lf", result.matrix[1][0]);
  sprintf(exp, "%.6lf", 44.734741);
  ck_assert_str_eq(res, exp);
  sprintf(res, "%.6lf", result.matrix[1][1]);
  sprintf(exp, "%.6lf", 89.356778);
  ck_assert_str_eq(res, exp);
  sprintf(res, "%.6lf", result.matrix[1][2]);
  sprintf(exp, "%.6lf", -137.1652);
  ck_assert_str_eq(res, exp);
  sprintf(res, "%.6lf", result.matrix[2][0]);
  sprintf(exp, "%.6lf", 61.48642);
  ck_assert_str_eq(res, exp);
  sprintf(res, "%.6lf", result.matrix[2][1]);
  sprintf(exp, "%.6lf", -62.75964);
  ck_assert_str_eq(res, exp);
  sprintf(res, "%.6lf", result.matrix[2][2]);
  sprintf(exp, "%.6lf", -129.005);
  ck_assert_str_eq(res, exp);

  s21_remove_matrix(&matr1);
  s21_remove_matrix(&matr2);
  s21_remove_matrix(&result);

  ck_assert_int_eq(return_value, 0);
}
END_TEST

START_TEST(s21_sum_5) {
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
  int return_value = s21_sum_matrix(&matr1, &matr2, &result);
  char res[30] = {0}, exp[30] = {0};
  sprintf(res, "%.6lf", result.matrix[0][0]);
  sprintf(exp, "%.6lf", 1.0);
  ck_assert_str_eq(res, exp);
  sprintf(res, "%.6lf", result.matrix[0][1]);
  sprintf(exp, "%.6lf", 2.5);
  ck_assert_str_eq(res, exp);
  sprintf(res, "%.6lf", result.matrix[1][0]);
  sprintf(exp, "%.6lf", 4.8);
  ck_assert_str_eq(res, exp);
  sprintf(res, "%.6lf", result.matrix[1][1]);
  sprintf(exp, "%.6lf", 9.4);
  ck_assert_str_eq(res, exp);

  s21_remove_matrix(&matr1);
  s21_remove_matrix(&matr2);
  s21_remove_matrix(&result);

  ck_assert_int_eq(return_value, 0);
}
END_TEST

START_TEST(s21_sum_6) {
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
  int return_value = s21_sum_matrix(&matr1, &matr2, &result);
  s21_remove_matrix(&matr1);
  s21_remove_matrix(&matr2);
  s21_remove_matrix(&result);
  ck_assert_int_eq(return_value, 2);
}
END_TEST

START_TEST(s21_sum_7) {
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
  int return_value = s21_sum_matrix(&matr1, &matr2, NULL);
  s21_remove_matrix(&matr1);
  s21_remove_matrix(&matr2);
  ck_assert_int_eq(return_value, 1);
}
END_TEST

Suite *s21_sum_matrix_suite(void) {
  Suite *c = suite_create("sum_matrix");
  TCase *tc = tcase_create("->");

  tcase_add_test(tc, s21_sum_1);
  tcase_add_test(tc, s21_sum_2);
  tcase_add_test(tc, s21_sum_3);
  tcase_add_test(tc, s21_sum_4);
  tcase_add_test(tc, s21_sum_5);
  tcase_add_test(tc, s21_sum_6);
  tcase_add_test(tc, s21_sum_7);

  suite_add_tcase(c, tc);
  return c;
}