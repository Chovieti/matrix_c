#include "test.h"

START_TEST(s21_remove_1) {
  matrix_t matr = {0};
  s21_create_matrix(1, 1, &matr);
  s21_remove_matrix(&matr);
  ck_assert_int_eq(matr.rows, 0);
  ck_assert_int_eq(matr.columns, 0);
}
END_TEST

START_TEST(s21_remove_2) {
  matrix_t matr = {0};
  s21_create_matrix(3, 3, &matr);
  s21_remove_matrix(&matr);
  ck_assert_int_eq(matr.rows, 0);
  ck_assert_int_eq(matr.columns, 0);
}
END_TEST

START_TEST(s21_remove_3) {
  matrix_t matr = {0};
  s21_create_matrix(5, 5, &matr);
  s21_remove_matrix(&matr);
  ck_assert_int_eq(matr.rows, 0);
  ck_assert_int_eq(matr.columns, 0);
}
END_TEST

START_TEST(s21_remove_4) {
  matrix_t matr = {0};
  s21_create_matrix(10, 10, &matr);
  s21_remove_matrix(&matr);
  ck_assert_int_eq(matr.rows, 0);
  ck_assert_int_eq(matr.columns, 0);
}
END_TEST

START_TEST(s21_remove_5) {
  matrix_t matr = {0};
  s21_create_matrix(1, 3, &matr);
  s21_remove_matrix(&matr);
  ck_assert_int_eq(matr.rows, 0);
  ck_assert_int_eq(matr.columns, 0);
}
END_TEST

START_TEST(s21_remove_6) {
  matrix_t matr = {0};
  s21_create_matrix(3, 1, &matr);
  s21_remove_matrix(&matr);
  ck_assert_int_eq(matr.rows, 0);
  ck_assert_int_eq(matr.columns, 0);
}
END_TEST

Suite *s21_remove_matrix_suite(void) {
  Suite *c = suite_create("remove_matrix");
  TCase *tc = tcase_create("->");

  tcase_add_test(tc, s21_remove_1);
  tcase_add_test(tc, s21_remove_2);
  tcase_add_test(tc, s21_remove_3);
  tcase_add_test(tc, s21_remove_4);
  tcase_add_test(tc, s21_remove_5);
  tcase_add_test(tc, s21_remove_6);

  suite_add_tcase(c, tc);
  return c;
}