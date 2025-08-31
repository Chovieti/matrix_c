#include "test.h"

START_TEST(s21_eq_1) {
  matrix_t matr1 = {0};
  matrix_t matr2 = {0};
  s21_create_matrix(1, 1, &matr1);
  s21_create_matrix(1, 1, &matr2);
  matr1.matrix[0][0] = 1;
  matr2.matrix[0][0] = 1;
  int return_value = s21_eq_matrix(&matr1, &matr2);
  s21_remove_matrix(&matr1);
  s21_remove_matrix(&matr2);
  ck_assert_int_eq(return_value, 1);
}
END_TEST

START_TEST(s21_eq_2) {
  matrix_t matr1 = {0};
  matrix_t matr2 = {0};
  s21_create_matrix(1, 1, &matr1);
  s21_create_matrix(1, 1, &matr2);
  matr1.matrix[0][0] = 1;
  matr2.matrix[0][0] = 2;
  int return_value = s21_eq_matrix(&matr1, &matr2);
  s21_remove_matrix(&matr1);
  s21_remove_matrix(&matr2);
  ck_assert_int_eq(return_value, 0);
}
END_TEST

START_TEST(s21_eq_3) {
  matrix_t matr1 = {0};
  matrix_t matr2 = {0};
  s21_create_matrix(2, 2, &matr1);
  s21_create_matrix(2, 2, &matr2);
  matr1.matrix[0][0] = 1;
  matr2.matrix[1][1] = 1;
  int return_value = s21_eq_matrix(&matr1, &matr2);
  s21_remove_matrix(&matr1);
  s21_remove_matrix(&matr2);
  ck_assert_int_eq(return_value, 0);
}
END_TEST

START_TEST(s21_eq_4) {
  matrix_t matr1 = {0};
  matrix_t matr2 = {0};
  s21_create_matrix(3, 3, &matr1);
  s21_create_matrix(3, 3, &matr2);
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      matr1.matrix[i][j] = i + j;
      matr2.matrix[i][j] = i + j;
    }
  }
  int return_value = s21_eq_matrix(&matr1, &matr2);
  s21_remove_matrix(&matr1);
  s21_remove_matrix(&matr2);
  ck_assert_int_eq(return_value, 1);
}
END_TEST

START_TEST(s21_eq_5) {
  matrix_t matr1 = {0};
  matrix_t matr2 = {0};
  s21_create_matrix(3, 3, &matr1);
  s21_create_matrix(3, 3, &matr2);
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      matr1.matrix[i][j] = i + j;
      matr2.matrix[i][j] = i - j;
    }
  }
  int return_value = s21_eq_matrix(&matr1, &matr2);
  s21_remove_matrix(&matr1);
  s21_remove_matrix(&matr2);
  ck_assert_int_eq(return_value, 0);
}
END_TEST

START_TEST(s21_eq_6) {
  matrix_t matr1 = {0};
  matrix_t matr2 = {0};
  s21_create_matrix(3, 3, &matr1);
  s21_create_matrix(3, 3, &matr2);
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      matr1.matrix[i][j] = i + j;
      matr2.matrix[i][j] = i + j;
    }
  }
  int return_value = s21_eq_matrix(&matr1, &matr2);
  s21_remove_matrix(&matr1);
  s21_remove_matrix(&matr2);
  ck_assert_int_eq(return_value, 1);
}
END_TEST

Suite *s21_eq_matrix_suite(void) {
  Suite *c = suite_create("eq_matrix");
  TCase *tc = tcase_create("->");

  tcase_add_test(tc, s21_eq_1);
  tcase_add_test(tc, s21_eq_2);
  tcase_add_test(tc, s21_eq_3);
  tcase_add_test(tc, s21_eq_4);
  tcase_add_test(tc, s21_eq_5);
  tcase_add_test(tc, s21_eq_6);

  suite_add_tcase(c, tc);
  return c;
}