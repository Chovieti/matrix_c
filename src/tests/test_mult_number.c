#include <string.h>

#include "test.h"

START_TEST(s21_mult_numb_1) {
  matrix_t matr = {0};
  double number = 5.25;
  matrix_t result = {0};
  s21_create_matrix(1, 1, &matr);

  matr.matrix[0][0] = 1.0;

  int return_value = s21_mult_number(&matr, number, &result);

  char res[30] = {0}, exp[30] = {0};
  sprintf(res, "%.6lf", result.matrix[0][0]);
  sprintf(exp, "%.6lf", 5.25);
  ck_assert_str_eq(res, exp);

  s21_remove_matrix(&matr);
  s21_remove_matrix(&result);

  ck_assert_int_eq(return_value, 0);
}
END_TEST

START_TEST(s21_mult_numb_2) {
  matrix_t matr = {0};
  double number = -6.1;
  matrix_t result = {0};
  s21_create_matrix(2, 2, &matr);

  matr.matrix[0][0] = 1.0;
  matr.matrix[0][1] = -2.0;
  matr.matrix[1][0] = 3.0;
  matr.matrix[1][1] = 4.0;

  int return_value = s21_mult_number(&matr, number, &result);

  char res[30] = {0}, exp[30] = {0};
  sprintf(res, "%.6lf", result.matrix[0][0]);
  sprintf(exp, "%.6lf", -6.1);
  ck_assert_str_eq(res, exp);
  sprintf(res, "%.6lf", result.matrix[0][1]);
  sprintf(exp, "%.6lf", 12.2);
  ck_assert_str_eq(res, exp);
  sprintf(res, "%.6lf", result.matrix[1][0]);
  sprintf(exp, "%.6lf", -18.3);
  ck_assert_str_eq(res, exp);
  sprintf(res, "%.6lf", result.matrix[1][1]);
  sprintf(exp, "%.6lf", -24.4);
  ck_assert_str_eq(res, exp);

  s21_remove_matrix(&matr);
  s21_remove_matrix(&result);

  ck_assert_int_eq(return_value, 0);
}
END_TEST

START_TEST(s21_mult_numb_3) {
  matrix_t matr = {0};
  double number = 13.175;
  matrix_t result = {0};
  s21_create_matrix(3, 2, &matr);

  matr.matrix[0][0] = 13.4;
  matr.matrix[0][1] = 2.18;
  matr.matrix[1][0] = 46.02;
  matr.matrix[1][1] = 7.9;
  matr.matrix[2][0] = 12.97;
  matr.matrix[2][1] = -41.7;
  int return_value = s21_mult_number(&matr, number, &result);

  char res[30] = {0}, exp[30] = {0};
  sprintf(res, "%.6lf", result.matrix[0][0]);
  sprintf(exp, "%.6lf", 176.545);
  ck_assert_str_eq(res, exp);
  sprintf(res, "%.6lf", result.matrix[0][1]);
  sprintf(exp, "%.6lf", 28.7215);
  ck_assert_str_eq(res, exp);
  sprintf(res, "%.6lf", result.matrix[1][0]);
  sprintf(exp, "%.6lf", 606.3135);
  ck_assert_str_eq(res, exp);
  sprintf(res, "%.6lf", result.matrix[1][1]);
  sprintf(exp, "%.6lf", 104.0825);
  ck_assert_str_eq(res, exp);
  sprintf(res, "%.6lf", result.matrix[2][0]);
  sprintf(exp, "%.6lf", 170.87975);
  ck_assert_str_eq(res, exp);
  sprintf(res, "%.6lf", result.matrix[2][1]);
  sprintf(exp, "%.6lf", -549.3975);
  ck_assert_str_eq(res, exp);

  s21_remove_matrix(&matr);
  s21_remove_matrix(&result);

  ck_assert_int_eq(return_value, 0);
}
END_TEST

START_TEST(s21_mult_numb_4) {
  matrix_t matr = {0};
  double number = 27.00823;
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

  int return_value = s21_mult_number(&matr, number, &result);

  char res[30] = {0}, exp[30] = {0};
  sprintf(res, "%.6lf", result.matrix[0][0]);
  sprintf(exp, "%.6lf", -1578.714769);
  ck_assert_str_eq(res, exp);
  sprintf(res, "%.6lf", result.matrix[0][1]);
  sprintf(exp, "%.6lf", -669.128898);
  ck_assert_str_eq(res, exp);
  sprintf(res, "%.6lf", result.matrix[0][2]);
  sprintf(exp, "%.6lf", -1602.676471);
  ck_assert_str_eq(res, exp);
  sprintf(res, "%.6lf", result.matrix[1][0]);
  sprintf(exp, "%.6lf", 1719.828449);
  ck_assert_str_eq(res, exp);
  sprintf(res, "%.6lf", result.matrix[1][1]);
  sprintf(exp, "%.6lf", 242.392868);
  ck_assert_str_eq(res, exp);
  sprintf(res, "%.6lf", result.matrix[1][2]);
  sprintf(exp, "%.6lf", -1824.411338);
  ck_assert_str_eq(res, exp);
  sprintf(res, "%.6lf", result.matrix[2][0]);
  sprintf(exp, "%.6lf", 417.936694);
  ck_assert_str_eq(res, exp);
  sprintf(res, "%.6lf", result.matrix[2][1]);
  sprintf(exp, "%.6lf", 137.40329);
  ck_assert_str_eq(res, exp);
  sprintf(res, "%.6lf", result.matrix[2][2]);
  sprintf(exp, "%.6lf", -2506.363744);
  ck_assert_str_eq(res, exp);

  s21_remove_matrix(&matr);
  s21_remove_matrix(&result);

  ck_assert_int_eq(return_value, 0);
}
END_TEST

START_TEST(s21_mult_numb_5) {
  matrix_t matr = {0};
  double number = 1.0;
  matrix_t result = {0};
  s21_create_matrix(2, 2, &matr);

  matr.matrix[0][0] = 0.0;
  matr.matrix[0][1] = 3.15;
  matr.matrix[1][0] = 0.0;
  matr.matrix[1][1] = 0.0;
  int return_value = s21_mult_number(&matr, number, &result);
  char res[30] = {0}, exp[30] = {0};
  sprintf(res, "%.6lf", result.matrix[0][0]);
  sprintf(exp, "%.6lf", 0.0);
  ck_assert_str_eq(res, exp);
  sprintf(res, "%.6lf", result.matrix[0][1]);
  sprintf(exp, "%.6lf", 3.15);
  ck_assert_str_eq(res, exp);
  sprintf(res, "%.6lf", result.matrix[1][0]);
  sprintf(exp, "%.6lf", 0.0);
  ck_assert_str_eq(res, exp);
  sprintf(res, "%.6lf", result.matrix[1][1]);
  sprintf(exp, "%.6lf", 0.0);
  ck_assert_str_eq(res, exp);

  s21_remove_matrix(&matr);
  s21_remove_matrix(&result);

  ck_assert_int_eq(return_value, 0);
}
END_TEST

START_TEST(s21_mult_numb_6) {
  matrix_t matr = {0};
  double number = 0;
  matrix_t result = {0};
  s21_create_matrix(2, 3, &matr);
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 3; j++) {
      matr.matrix[i][j] = i + j;
    }
  }
  int return_value = s21_mult_number(&matr, number, &result);
  char res[30] = {0}, exp[30] = {0};
  sprintf(res, "%.6lf", result.matrix[0][0]);
  sprintf(exp, "%.6lf", 0.0);
  ck_assert_str_eq(res, exp);
  sprintf(res, "%.6lf", result.matrix[0][1]);
  sprintf(exp, "%.6lf", 0.0);
  ck_assert_str_eq(res, exp);
  sprintf(res, "%.6lf", result.matrix[0][2]);
  sprintf(exp, "%.6lf", 0.0);
  ck_assert_str_eq(res, exp);
  sprintf(res, "%.6lf", result.matrix[1][0]);
  sprintf(exp, "%.6lf", 0.0);
  ck_assert_str_eq(res, exp);
  sprintf(res, "%.6lf", result.matrix[1][1]);
  sprintf(exp, "%.6lf", 0.0);
  ck_assert_str_eq(res, exp);
  sprintf(res, "%.6lf", result.matrix[1][2]);
  sprintf(exp, "%.6lf", 0.0);
  ck_assert_str_eq(res, exp);

  s21_remove_matrix(&matr);
  s21_remove_matrix(&result);
  ck_assert_int_eq(return_value, 0);
}
END_TEST

START_TEST(s21_mult_numb_7) {
  matrix_t matr = {0};
  double number = 1234.5678;
  s21_create_matrix(2, 3, &matr);
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 3; j++) {
      matr.matrix[i][j] = i + j;
    }
  }
  int return_value = s21_mult_number(&matr, number, NULL);
  s21_remove_matrix(&matr);
  ck_assert_int_eq(return_value, 1);
}
END_TEST

Suite *s21_mult_number_suite(void) {
  Suite *c = suite_create("mult_number");
  TCase *tc = tcase_create("->");

  tcase_add_test(tc, s21_mult_numb_1);
  tcase_add_test(tc, s21_mult_numb_2);
  tcase_add_test(tc, s21_mult_numb_3);
  tcase_add_test(tc, s21_mult_numb_4);
  tcase_add_test(tc, s21_mult_numb_5);
  tcase_add_test(tc, s21_mult_numb_6);
  tcase_add_test(tc, s21_mult_numb_7);

  suite_add_tcase(c, tc);
  return c;
}