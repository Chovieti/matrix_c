#include <string.h>

#include "test.h"

START_TEST(s21_calc_complements_1) {
  matrix_t matr = {0};
  matrix_t result = {0};
  s21_create_matrix(1, 1, &matr);

  matr.matrix[0][0] = 1.0;

  int return_value = s21_calc_complements(&matr, &result);

  s21_remove_matrix(&matr);

  char res[30] = {0}, exp[30] = {0};
  sprintf(res, "%.6lf", result.matrix[0][0]);
  sprintf(exp, "%.6lf", 1.0);

  s21_remove_matrix(&result);

  ck_assert_str_eq(res, exp);
  ck_assert_int_eq(return_value, 0);
}
END_TEST

START_TEST(s21_calc_complements_2) {
  matrix_t matr = {0};
  matrix_t result = {0};
  s21_create_matrix(2, 2, &matr);

  matr.matrix[0][0] = 1.0;
  matr.matrix[0][1] = -2.0;
  matr.matrix[1][0] = 3.0;
  matr.matrix[1][1] = 4.0;

  int return_value = s21_calc_complements(&matr, &result);

  s21_remove_matrix(&matr);

  char res[30] = {0}, exp[30] = {0};
  sprintf(res, "%.6lf", result.matrix[0][0]);
  sprintf(exp, "%.6lf", 4.0);
  ck_assert_str_eq(res, exp);

  sprintf(res, "%.6lf", result.matrix[0][1]);
  sprintf(exp, "%.6lf", -3.0);
  ck_assert_str_eq(res, exp);

  sprintf(res, "%.6lf", result.matrix[1][0]);
  sprintf(exp, "%.6lf", 2.0);
  ck_assert_str_eq(res, exp);

  sprintf(res, "%.6lf", result.matrix[1][1]);
  sprintf(exp, "%.6lf", 1.0);
  ck_assert_str_eq(res, exp);

  s21_remove_matrix(&result);

  ck_assert_double_eq(return_value, 0);
}
END_TEST

START_TEST(s21_calc_complements_3) {
  matrix_t matr = {0};
  matrix_t result = {0};
  s21_create_matrix(3, 2, &matr);

  matr.matrix[0][0] = 13.4;
  matr.matrix[0][1] = 2.18;
  matr.matrix[1][0] = 46.02;
  matr.matrix[1][1] = 7.9;
  matr.matrix[2][0] = 12.97;
  matr.matrix[2][1] = -41.7;
  int return_value = s21_calc_complements(&matr, &result);

  s21_remove_matrix(&matr);
  s21_remove_matrix(&result);

  ck_assert_int_eq(return_value, 2);
}
END_TEST

START_TEST(s21_calc_complements_4) {
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

  int return_value = s21_calc_complements(&matr, &result);

  s21_remove_matrix(&matr);

  char res[30] = {0}, exp[30] = {0};
  sprintf(res, "%.6lf", result.matrix[0][0]);
  sprintf(exp, "%.6lf", -489.200458);
  ck_assert_str_eq(res, exp);

  sprintf(res, "%.6lf", result.matrix[0][1]);
  sprintf(exp, "%.6lf", 4864.012666);
  ck_assert_str_eq(res, exp);

  sprintf(res, "%.6lf", result.matrix[0][2]);
  sprintf(exp, "%.6lf", 185.079488);
  ck_assert_str_eq(res, exp);

  sprintf(res, "%.6lf", result.matrix[1][0]);
  sprintf(exp, "%.6lf", -2601.011403);
  ck_assert_str_eq(res, exp);

  sprintf(res, "%.6lf", result.matrix[1][1]);
  sprintf(exp, "%.6lf", 6342.704405);
  ck_assert_str_eq(res, exp);

  sprintf(res, "%.6lf", result.matrix[1][2]);
  sprintf(exp, "%.6lf", -86.000947);
  ck_assert_str_eq(res, exp);

  sprintf(res, "%.6lf", result.matrix[2][0]);
  sprintf(exp, "%.6lf", 2206.122224);
  ck_assert_str_eq(res, exp);

  sprintf(res, "%.6lf", result.matrix[2][1]);
  sprintf(exp, "%.6lf", -7727.186659);
  ck_assert_str_eq(res, exp);

  sprintf(res, "%.6lf", result.matrix[2][2]);
  sprintf(exp, "%.6lf", 1053.017368);
  ck_assert_str_eq(res, exp);

  s21_remove_matrix(&result);

  ck_assert_int_eq(return_value, 0);
}
END_TEST

START_TEST(s21_calc_complements_5) {
  matrix_t matr = {0};
  matrix_t result = {0};
  s21_create_matrix(2, 2, &matr);

  matr.matrix[0][0] = 0.0;
  matr.matrix[0][1] = 3.15;
  matr.matrix[1][0] = 0.0;
  matr.matrix[1][1] = 0.0;
  int return_value = s21_calc_complements(&matr, &result);

  char res[30] = {0}, exp[30] = {0};
  sprintf(res, "%.6lf", result.matrix[0][0]);
  sprintf(exp, "%.6lf", 0.0);
  ck_assert_str_eq(res, exp);

  sprintf(res, "%.6lf", result.matrix[0][1]);
  sprintf(exp, "%.6lf", 0.0);
  ck_assert_str_eq(res, exp);

  sprintf(res, "%.6lf", result.matrix[1][0]);
  sprintf(exp, "%.6lf", -3.15);
  ck_assert_str_eq(res, exp);

  sprintf(res, "%.6lf", result.matrix[1][1]);
  sprintf(exp, "%.6lf", 0.0);
  ck_assert_str_eq(res, exp);

  s21_remove_matrix(&matr);
  s21_remove_matrix(&result);

  ck_assert_int_eq(return_value, 0);
}
END_TEST

START_TEST(s21_calc_complements_6) {
  matrix_t matr = {0};
  matrix_t result = {0};
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
  int return_value = s21_calc_complements(&matr, &result);

  s21_remove_matrix(&matr);

  char res[30] = {0}, exp[30] = {0};
  sprintf(res, "%.6lf", result.matrix[0][0]);
  sprintf(exp, "%.6lf", 9642044.0);
  ck_assert_str_eq(res, exp);
  sprintf(res, "%.6lf", result.matrix[0][1]);
  sprintf(exp, "%.6lf", -5106002.0);
  ck_assert_str_eq(res, exp);
  sprintf(res, "%.6lf", result.matrix[0][2]);
  sprintf(exp, "%.6lf", 2757708.0);
  ck_assert_str_eq(res, exp);
  sprintf(res, "%.6lf", result.matrix[0][3]);
  sprintf(exp, "%.6lf", -7077418.0);
  ck_assert_str_eq(res, exp);
  sprintf(res, "%.6lf", result.matrix[1][0]);
  sprintf(exp, "%.6lf", -1044528.0);
  ck_assert_str_eq(res, exp);
  sprintf(res, "%.6lf", result.matrix[1][1]);
  sprintf(exp, "%.6lf", -1646674.0);
  ck_assert_str_eq(res, exp);
  sprintf(res, "%.6lf", result.matrix[1][2]);
  sprintf(exp, "%.6lf", 14972698.8);
  ck_assert_str_eq(res, exp);
  sprintf(res, "%.6lf", result.matrix[1][3]);
  sprintf(exp, "%.6lf", 393908.4);
  ck_assert_str_eq(res, exp);
  sprintf(res, "%.6lf", result.matrix[2][0]);
  sprintf(exp, "%.6lf", -67767.2);
  ck_assert_str_eq(res, exp);
  sprintf(res, "%.6lf", result.matrix[2][1]);
  sprintf(exp, "%.6lf", 164892.0);
  ck_assert_str_eq(res, exp);
  sprintf(res, "%.6lf", result.matrix[2][2]);
  sprintf(exp, "%.6lf", -1428169.2);
  ck_assert_str_eq(res, exp);
  sprintf(res, "%.6lf", result.matrix[2][3]);
  sprintf(exp, "%.6lf", 1525699.2);
  ck_assert_str_eq(res, exp);
  sprintf(res, "%.6lf", result.matrix[3][0]);
  sprintf(exp, "%.6lf", -1369136.8);
  ck_assert_str_eq(res, exp);
  sprintf(res, "%.6lf", result.matrix[3][1]);
  sprintf(exp, "%.6lf", 4736848.0);
  ck_assert_str_eq(res, exp);
  sprintf(res, "%.6lf", result.matrix[3][2]);
  sprintf(exp, "%.6lf", 283668.8);
  ck_assert_str_eq(res, exp);
  sprintf(res, "%.6lf", result.matrix[3][3]);
  sprintf(exp, "%.6lf", 230738.4);
  ck_assert_str_eq(res, exp);

  s21_remove_matrix(&result);

  ck_assert_int_eq(return_value, 0);
}
END_TEST

START_TEST(s21_calc_complements_7) {
  matrix_t matr = {0};
  matrix_t result = {0};
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
  int return_value = s21_calc_complements(&matr, &result);

  s21_remove_matrix(&matr);

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
  sprintf(res, "%.6lf", result.matrix[0][3]);
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
  sprintf(res, "%.6lf", result.matrix[1][3]);
  sprintf(exp, "%.6lf", 0.0);
  ck_assert_str_eq(res, exp);
  sprintf(res, "%.6lf", result.matrix[2][0]);
  sprintf(exp, "%.6lf", 0.0);
  ck_assert_str_eq(res, exp);
  sprintf(res, "%.6lf", result.matrix[2][1]);
  sprintf(exp, "%.6lf", 0.0);
  ck_assert_str_eq(res, exp);
  sprintf(res, "%.6lf", result.matrix[2][2]);
  sprintf(exp, "%.6lf", 0.0);
  ck_assert_str_eq(res, exp);
  sprintf(res, "%.6lf", result.matrix[2][3]);
  sprintf(exp, "%.6lf", 0.0);
  ck_assert_str_eq(res, exp);
  sprintf(res, "%.6lf", result.matrix[3][0]);
  sprintf(exp, "%.6lf", 0.0);
  ck_assert_str_eq(res, exp);
  sprintf(res, "%.6lf", result.matrix[3][1]);
  sprintf(exp, "%.6lf", 0.0);
  ck_assert_str_eq(res, exp);
  sprintf(res, "%.6lf", result.matrix[3][2]);
  sprintf(exp, "%.6lf", 0.0);
  ck_assert_str_eq(res, exp);
  sprintf(res, "%.6lf", result.matrix[3][3]);
  sprintf(exp, "%.6lf", 0.0);
  ck_assert_str_eq(res, exp);

  s21_remove_matrix(&result);

  ck_assert_int_eq(return_value, 0);
}
END_TEST

START_TEST(s21_calc_complements_8) {
  matrix_t matr = {0};
  matrix_t result = {0};
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
  int return_value = s21_calc_complements(&matr, &result);

  s21_remove_matrix(&matr);

  char res[30] = {0}, exp[30] = {0};
  sprintf(res, "%.6lf", result.matrix[0][0]);
  sprintf(exp, "%.6lf", -6809.132498);
  ck_assert_str_eq(res, exp);
  sprintf(res, "%.6lf", result.matrix[0][1]);
  sprintf(exp, "%.6lf", -27728.797668);
  ck_assert_str_eq(res, exp);
  sprintf(res, "%.6lf", result.matrix[0][2]);
  sprintf(exp, "%.6lf", -21107.575533);
  ck_assert_str_eq(res, exp);
  sprintf(res, "%.6lf", result.matrix[0][3]);
  sprintf(exp, "%.6lf", -8028.351222);
  ck_assert_str_eq(res, exp);
  sprintf(res, "%.6lf", result.matrix[0][4]);
  sprintf(exp, "%.6lf", 20264.523495);
  ck_assert_str_eq(res, exp);
  sprintf(res, "%.6lf", result.matrix[0][5]);
  sprintf(exp, "%.6lf", -43207.502451);
  ck_assert_str_eq(res, exp);
  sprintf(res, "%.6lf", result.matrix[1][0]);
  sprintf(exp, "%.6lf", -236637.785151);
  ck_assert_str_eq(res, exp);
  sprintf(res, "%.6lf", result.matrix[1][1]);
  sprintf(exp, "%.6lf", 194131.733338);
  ck_assert_str_eq(res, exp);
  sprintf(res, "%.6lf", result.matrix[1][2]);
  sprintf(exp, "%.6lf", -7945.883947);
  ck_assert_str_eq(res, exp);
  sprintf(res, "%.6lf", result.matrix[1][3]);
  sprintf(exp, "%.6lf", -55758.691822);
  ck_assert_str_eq(res, exp);
  sprintf(res, "%.6lf", result.matrix[1][4]);
  sprintf(exp, "%.6lf", -194601.15094);
  ck_assert_str_eq(res, exp);
  sprintf(res, "%.6lf", result.matrix[1][5]);
  sprintf(exp, "%.6lf", -168972.903892);
  ck_assert_str_eq(res, exp);
  sprintf(res, "%.6lf", result.matrix[2][0]);
  sprintf(exp, "%.6lf", 212688.946593);
  ck_assert_str_eq(res, exp);
  sprintf(res, "%.6lf", result.matrix[2][1]);
  sprintf(exp, "%.6lf", -193318.912806);
  ck_assert_str_eq(res, exp);
  sprintf(res, "%.6lf", result.matrix[2][2]);
  sprintf(exp, "%.6lf", -25881.980344);
  ck_assert_str_eq(res, exp);
  sprintf(res, "%.6lf", result.matrix[2][3]);
  sprintf(exp, "%.6lf", 2393.196083);
  ck_assert_str_eq(res, exp);
  sprintf(res, "%.6lf", result.matrix[2][4]);
  sprintf(exp, "%.6lf", 100895.745923);
  ck_assert_str_eq(res, exp);
  sprintf(res, "%.6lf", result.matrix[2][5]);
  sprintf(exp, "%.6lf", 73222.421125);
  ck_assert_str_eq(res, exp);
  sprintf(res, "%.6lf", result.matrix[3][0]);
  sprintf(exp, "%.6lf", 272134.4407);
  ck_assert_str_eq(res, exp);
  sprintf(res, "%.6lf", result.matrix[3][1]);
  sprintf(exp, "%.6lf", -260538.637497);
  ck_assert_str_eq(res, exp);
  sprintf(res, "%.6lf", result.matrix[3][2]);
  sprintf(exp, "%.6lf", 32753.368879);
  ck_assert_str_eq(res, exp);
  sprintf(res, "%.6lf", result.matrix[3][3]);
  sprintf(exp, "%.6lf", 12778.96049);
  ck_assert_str_eq(res, exp);
  sprintf(res, "%.6lf", result.matrix[3][4]);
  sprintf(exp, "%.6lf", 190803.094655);
  ck_assert_str_eq(res, exp);
  sprintf(res, "%.6lf", result.matrix[3][5]);
  sprintf(exp, "%.6lf", 151759.907066);
  ck_assert_str_eq(res, exp);
  sprintf(res, "%.6lf", result.matrix[4][0]);
  sprintf(exp, "%.6lf", -144056.312358);
  ck_assert_str_eq(res, exp);
  sprintf(res, "%.6lf", result.matrix[4][1]);
  sprintf(exp, "%.6lf", 93876.52726);
  ck_assert_str_eq(res, exp);
  sprintf(res, "%.6lf", result.matrix[4][2]);
  sprintf(exp, "%.6lf", 9441.394562);
  ck_assert_str_eq(res, exp);
  sprintf(res, "%.6lf", result.matrix[4][3]);
  sprintf(exp, "%.6lf", 39494.096797);
  ck_assert_str_eq(res, exp);
  sprintf(res, "%.6lf", result.matrix[4][4]);
  sprintf(exp, "%.6lf", -91342.266694);
  ck_assert_str_eq(res, exp);
  sprintf(res, "%.6lf", result.matrix[4][5]);
  sprintf(exp, "%.6lf", -23781.775079);
  ck_assert_str_eq(res, exp);
  sprintf(res, "%.6lf", result.matrix[5][0]);
  sprintf(exp, "%.6lf", -70863.062396);
  ck_assert_str_eq(res, exp);
  sprintf(res, "%.6lf", result.matrix[5][1]);
  sprintf(exp, "%.6lf", 68800.966405);
  ck_assert_str_eq(res, exp);
  sprintf(res, "%.6lf", result.matrix[5][2]);
  sprintf(exp, "%.6lf", 63126.682111);
  ck_assert_str_eq(res, exp);
  sprintf(res, "%.6lf", result.matrix[5][3]);
  sprintf(exp, "%.6lf", 51813.138707);
  ck_assert_str_eq(res, exp);
  sprintf(res, "%.6lf", result.matrix[5][4]);
  sprintf(exp, "%.6lf", -45017.7449);
  ck_assert_str_eq(res, exp);
  sprintf(res, "%.6lf", result.matrix[5][5]);
  sprintf(exp, "%.6lf", -15562.993093);
  ck_assert_str_eq(res, exp);

  s21_remove_matrix(&result);

  ck_assert_int_eq(return_value, 0);
}
END_TEST

START_TEST(s21_calc_complements_9) {
  matrix_t matr = {0};
  matrix_t result = {0};
  s21_create_matrix(2, 3, &matr);
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 3; j++) {
      matr.matrix[i][j] = i + j;
    }
  }
  int return_value = s21_calc_complements(&matr, &result);

  s21_remove_matrix(&matr);
  s21_remove_matrix(&result);
  ck_assert_int_eq(return_value, 2);
}
END_TEST

START_TEST(s21_calc_complements_10) {
  matrix_t matr = {0};
  s21_create_matrix(2, 3, &matr);
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 3; j++) {
      matr.matrix[i][j] = i + j;
    }
  }
  int return_value = s21_calc_complements(&matr, NULL);
  s21_remove_matrix(&matr);
  ck_assert_int_eq(return_value, 1);
}
END_TEST

Suite *s21_calc_complements_suite(void) {
  Suite *c = suite_create("calc_complements");
  TCase *tc = tcase_create("->");

  tcase_add_test(tc, s21_calc_complements_1);
  tcase_add_test(tc, s21_calc_complements_2);
  tcase_add_test(tc, s21_calc_complements_3);
  tcase_add_test(tc, s21_calc_complements_4);
  tcase_add_test(tc, s21_calc_complements_5);
  tcase_add_test(tc, s21_calc_complements_6);
  tcase_add_test(tc, s21_calc_complements_7);
  tcase_add_test(tc, s21_calc_complements_8);
  tcase_add_test(tc, s21_calc_complements_9);
  tcase_add_test(tc, s21_calc_complements_10);

  suite_add_tcase(c, tc);
  return c;
}