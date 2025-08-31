#include <string.h>

#include "test.h"

START_TEST(s21_determinant_1) {
  matrix_t matr = {0};
  double result = 0.0;
  double expected = 1.0;
  s21_create_matrix(1, 1, &matr);

  matr.matrix[0][0] = 1.0;

  int return_value = s21_determinant(&matr, &result);

  s21_remove_matrix(&matr);

  char res[30] = {0}, exp[30] = {0};
  sprintf(res, "%.6lf", result);
  sprintf(exp, "%.6lf", expected);

  ck_assert_str_eq(res, exp);
  ck_assert_int_eq(return_value, 0);
}
END_TEST

START_TEST(s21_determinant_2) {
  matrix_t matr = {0};
  double result = 0.0;
  double expected = 10.0;
  s21_create_matrix(2, 2, &matr);

  matr.matrix[0][0] = 1.0;
  matr.matrix[0][1] = -2.0;
  matr.matrix[1][0] = 3.0;
  matr.matrix[1][1] = 4.0;

  int return_value = s21_determinant(&matr, &result);

  s21_remove_matrix(&matr);

  char res[30] = {0}, exp[30] = {0};
  sprintf(res, "%.6lf", result);
  sprintf(exp, "%.6lf", expected);

  ck_assert_str_eq(res, exp);
  ck_assert_double_eq(return_value, 0);
}
END_TEST

START_TEST(s21_determinant_3) {
  matrix_t matr = {0};
  double result = 0;
  s21_create_matrix(3, 2, &matr);

  matr.matrix[0][0] = 13.4;
  matr.matrix[0][1] = 2.18;
  matr.matrix[1][0] = 46.02;
  matr.matrix[1][1] = 7.9;
  matr.matrix[2][0] = 12.97;
  matr.matrix[2][1] = -41.7;
  int return_value = s21_determinant(&matr, &result);

  s21_remove_matrix(&matr);

  ck_assert_int_eq(return_value, 2);
}
END_TEST

START_TEST(s21_determinant_4) {
  matrix_t matr = {0};
  double result = 0.0;
  double expected = -102893.302885567315968;
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

  int return_value = s21_determinant(&matr, &result);

  s21_remove_matrix(&matr);

  char res[30] = {0}, exp[30] = {0};
  sprintf(res, "%.6lf", result);
  sprintf(exp, "%.6lf", expected);

  ck_assert_str_eq(res, exp);
  ck_assert_int_eq(return_value, 0);
}
END_TEST

START_TEST(s21_determinant_5) {
  matrix_t matr = {0};
  double result = 0.0;
  double expected = 0.0;
  s21_create_matrix(2, 2, &matr);

  matr.matrix[0][0] = 0.0;
  matr.matrix[0][1] = 3.15;
  matr.matrix[1][0] = 0.0;
  matr.matrix[1][1] = 0.0;
  int return_value = s21_determinant(&matr, &result);

  s21_remove_matrix(&matr);

  char res[30] = {0}, exp[30] = {0};
  sprintf(res, "%.6lf", result);
  sprintf(exp, "%.6lf", expected);

  ck_assert_str_eq(res, exp);
  ck_assert_int_eq(return_value, 0);
}
END_TEST

START_TEST(s21_determinant_6) {
  matrix_t matr = {0};
  double result = 0.0;
  double expected = 952432205.6;
  s21_create_matrix(4, 4, &matr);

  matr.matrix[0][0] = 123.0;
  matr.matrix[0][1] = 34.2;
  matr.matrix[0][2] = 12.0;
  matr.matrix[0][3] = 13.0;
  matr.matrix[1][0] = 27.0;
  matr.matrix[1][1] = 1.0;
  matr.matrix[1][2] = 64.0;
  matr.matrix[1][3] = 61.0;
  matr.matrix[2][0] = 545.0;
  matr.matrix[2][1] = 123.0;
  matr.matrix[2][2] = 34.0;
  matr.matrix[2][3] = 667.0;
  matr.matrix[3][0] = 123.0;
  matr.matrix[3][1] = 234.0;
  matr.matrix[3][2] = 34.0;
  matr.matrix[3][3] = 12.0;
  int return_value = s21_determinant(&matr, &result);

  s21_remove_matrix(&matr);

  char res[30] = {0}, exp[30] = {0};
  sprintf(res, "%.6lf", result);
  sprintf(exp, "%.6lf", expected);

  ck_assert_str_eq(res, exp);
  ck_assert_int_eq(return_value, 0);
}
END_TEST

START_TEST(s21_determinant_7) {
  matrix_t matr = {0};
  double result = 0.0;
  double expected = 0.0;
  s21_create_matrix(4, 4, &matr);

  matr.matrix[0][0] = 1.0;
  matr.matrix[0][1] = 2.0;
  matr.matrix[0][2] = 3.0;
  matr.matrix[0][3] = 4.0;
  matr.matrix[1][0] = 5.0;
  matr.matrix[1][1] = 6.0;
  matr.matrix[1][2] = 7.0;
  matr.matrix[1][3] = 8.0;
  matr.matrix[2][0] = 9.0;
  matr.matrix[2][1] = 10.0;
  matr.matrix[2][2] = 11.0;
  matr.matrix[2][3] = 12.0;
  matr.matrix[3][0] = 13.0;
  matr.matrix[3][1] = 14.0;
  matr.matrix[3][2] = 15.0;
  matr.matrix[3][3] = 16.0;
  int return_value = s21_determinant(&matr, &result);

  s21_remove_matrix(&matr);

  char res[30] = {0}, exp[30] = {0};
  sprintf(res, "%.6lf", result);
  sprintf(exp, "%.6lf", expected);

  ck_assert_str_eq(res, exp);
  ck_assert_int_eq(return_value, 0);
}
END_TEST

START_TEST(s21_determinant_8) {
  matrix_t matr = {0};
  double result = 0.0;
  double expected = -802815.232364;
  s21_create_matrix(6, 6, &matr);

  matr.matrix[0][0] = 6.3021, matr.matrix[0][1] = 5.7026,
  matr.matrix[0][2] = 1.6706, matr.matrix[0][3] = -5.835;
  matr.matrix[0][4] = -9.0227, matr.matrix[0][5] = 9.964,
  matr.matrix[1][0] = 1.31975, matr.matrix[1][1] = 5.6416;
  matr.matrix[1][2] = -5.94, matr.matrix[1][3] = 6.87,
  matr.matrix[1][4] = 5.9235, matr.matrix[1][5] = 0.5749;
  matr.matrix[2][0] = -7.8921, matr.matrix[2][1] = 1.32,
  matr.matrix[2][2] = 4.49, matr.matrix[2][3] = -8.5;
  matr.matrix[2][4] = 9.49, matr.matrix[2][5] = 4.2334,
  matr.matrix[3][0] = 7.908, matr.matrix[3][1] = 8.536;
  matr.matrix[3][2] = -8.43, matr.matrix[3][3] = 8.772,
  matr.matrix[3][4] = 0.29, matr.matrix[3][5] = -4.1;
  matr.matrix[4][0] = 9.5913, matr.matrix[4][1] = 9.89,
  matr.matrix[4][2] = 3.9663, matr.matrix[4][3] = -2.699;
  matr.matrix[4][4] = 4.8925, matr.matrix[4][5] = -7.0,
  matr.matrix[5][0] = -6.5, matr.matrix[5][1] = -2.75;
  matr.matrix[5][2] = -7.285, matr.matrix[5][3] = -8.719,
  matr.matrix[5][4] = 0.7374, matr.matrix[5][5] = 8.313938;
  int return_value = s21_determinant(&matr, &result);

  s21_remove_matrix(&matr);

  char res[30] = {0}, exp[30] = {0};
  sprintf(res, "%.6lf", result);
  sprintf(exp, "%.6lf", expected);

  ck_assert_str_eq(res, exp);
  ck_assert_int_eq(return_value, 0);
}
END_TEST

START_TEST(s21_determinant_9) {
  matrix_t matr = {0};
  double result = 0;
  s21_create_matrix(2, 3, &matr);
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 3; j++) {
      matr.matrix[i][j] = i + j;
    }
  }
  int return_value = s21_determinant(&matr, &result);

  s21_remove_matrix(&matr);
  ck_assert_int_eq(return_value, 2);
}
END_TEST

START_TEST(s21_determinant_10) {
  matrix_t matr = {0};
  s21_create_matrix(2, 3, &matr);
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 3; j++) {
      matr.matrix[i][j] = i + j;
    }
  }
  int return_value = s21_determinant(&matr, NULL);
  s21_remove_matrix(&matr);
  ck_assert_int_eq(return_value, 1);
}
END_TEST

Suite *s21_determinant_suite(void) {
  Suite *c = suite_create("determinant");
  TCase *tc = tcase_create("->");

  tcase_add_test(tc, s21_determinant_1);
  tcase_add_test(tc, s21_determinant_2);
  tcase_add_test(tc, s21_determinant_3);
  tcase_add_test(tc, s21_determinant_4);
  tcase_add_test(tc, s21_determinant_5);
  tcase_add_test(tc, s21_determinant_6);
  tcase_add_test(tc, s21_determinant_7);
  tcase_add_test(tc, s21_determinant_8);
  tcase_add_test(tc, s21_determinant_9);
  tcase_add_test(tc, s21_determinant_10);

  suite_add_tcase(c, tc);
  return c;
}