#include "test.h"

START_TEST(s21_create_1) {
  matrix_t matr = {0};
  int return_value = s21_create_matrix(1, 1, &matr);
  ck_assert_int_eq(matr.rows, 1);
  ck_assert_int_eq(matr.columns, 1);
  s21_remove_matrix(&matr);
  ck_assert_int_eq(return_value, 0);
}
END_TEST

START_TEST(s21_create_2) {
  matrix_t matr = {0};
  int return_value = s21_create_matrix(2, 2, &matr);
  ck_assert_int_eq(matr.rows, 2);
  ck_assert_int_eq(matr.columns, 2);
  s21_remove_matrix(&matr);
  ck_assert_int_eq(return_value, 0);
}
END_TEST

START_TEST(s21_create_3) {
  matrix_t matr = {0};
  int return_value = s21_create_matrix(3, 3, &matr);
  ck_assert_int_eq(matr.rows, 3);
  ck_assert_int_eq(matr.columns, 3);
  s21_remove_matrix(&matr);
  ck_assert_int_eq(return_value, 0);
}
END_TEST

START_TEST(s21_create_4) {
  matrix_t matr = {0};
  int return_value = s21_create_matrix(5, 5, &matr);
  ck_assert_int_eq(matr.rows, 5);
  ck_assert_int_eq(matr.columns, 5);
  s21_remove_matrix(&matr);
  ck_assert_int_eq(return_value, 0);
}
END_TEST

START_TEST(s21_create_5) {
  matrix_t matr = {0};
  int return_value = s21_create_matrix(10, 10, &matr);
  ck_assert_int_eq(matr.rows, 10);
  ck_assert_int_eq(matr.columns, 10);
  s21_remove_matrix(&matr);
  ck_assert_int_eq(return_value, 0);
}
END_TEST

START_TEST(s21_create_6) {
  matrix_t matr = {0};
  int return_value = s21_create_matrix(1, 3, &matr);
  ck_assert_int_eq(matr.rows, 1);
  ck_assert_int_eq(matr.columns, 3);
  s21_remove_matrix(&matr);
  ck_assert_int_eq(return_value, 0);
}
END_TEST

START_TEST(s21_create_7) {
  matrix_t matr = {0};
  int return_value = s21_create_matrix(3, 1, &matr);
  ck_assert_int_eq(matr.rows, 3);
  ck_assert_int_eq(matr.columns, 1);
  s21_remove_matrix(&matr);
  ck_assert_int_eq(return_value, 0);
}
END_TEST

START_TEST(s21_create_8) {
  matrix_t matr = {0};
  int return_value = s21_create_matrix(0, 3, &matr);
  s21_remove_matrix(&matr);
  ck_assert_int_eq(return_value, 1);
}
END_TEST

START_TEST(s21_create_9) {
  matrix_t matr = {0};
  int return_value = s21_create_matrix(5, 0, &matr);
  s21_remove_matrix(&matr);
  ck_assert_int_eq(return_value, 1);
}
END_TEST

START_TEST(s21_create_10) {
  matrix_t matr = {0};
  int return_value = s21_create_matrix(0, 0, &matr);
  s21_remove_matrix(&matr);
  ck_assert_int_eq(return_value, 1);
}
END_TEST

START_TEST(s21_create_11) {
  int return_value = s21_create_matrix(5, 3, NULL);
  ck_assert_int_eq(return_value, 1);
}
END_TEST

START_TEST(s21_create_12) {
  matrix_t matr = {0};
  int return_value = s21_create_matrix(5, 3, &matr);
  ck_assert_int_eq(return_value, 0);
  return_value = s21_create_matrix(3, 5, &matr);
  s21_remove_matrix(&matr);
  ck_assert_int_eq(return_value, 0);
}
END_TEST

START_TEST(s21_create_13) {
  matrix_t matr = {0};
  int return_value = s21_create_matrix(-1, -1, &matr);
  ck_assert_int_eq(return_value, 1);
}
END_TEST

Suite *s21_create_matrix_suite(void) {
  Suite *c = suite_create("create_matrix");
  TCase *tc = tcase_create("->");

  tcase_add_test(tc, s21_create_1);
  tcase_add_test(tc, s21_create_2);
  tcase_add_test(tc, s21_create_3);
  tcase_add_test(tc, s21_create_4);
  tcase_add_test(tc, s21_create_5);
  tcase_add_test(tc, s21_create_6);
  tcase_add_test(tc, s21_create_7);
  tcase_add_test(tc, s21_create_8);
  tcase_add_test(tc, s21_create_9);
  tcase_add_test(tc, s21_create_10);
  tcase_add_test(tc, s21_create_11);
  tcase_add_test(tc, s21_create_12);
  tcase_add_test(tc, s21_create_13);

  suite_add_tcase(c, tc);
  return c;
}