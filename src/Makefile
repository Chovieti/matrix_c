CC = gcc
FLAGS = -g -Wall -Wextra -Werror -std=c11
TEST_DIR = tests
TEST_RUNNER = tests/build/test_runner

SRC = lib/s21_create_matrix.c \
	lib/s21_remove_matrix.c \
	lib/s21_eq_matrix.c \
	lib/s21_sum_matrix.c \
	lib/s21_sub_matrix.c \
	lib/s21_mult_matrix.c \
	lib/s21_mult_number.c \
	lib/s21_transpose.c \
	lib/s21_determinant.c \
	lib/s21_calc_complements.c \
	lib/s21_inverse_matrix.c \
	lib/s21_matrix_common.c

TBD = tests/build
LINK_TEST_LIBS = -lcheck -lm -lsubunit
VALGRIND = valgrind --tool=memcheck --leak-check=full ./$(TEST_RUNNER)

UNAME := $(shell uname)
ifeq ($(UNAME), Darwin)
	LINK_TEST_LIBS = -lcheck -lm
	VALGRIND = echo "valgrind is not supported on MacOS"
	CLANG_FORMAT = clang_format
endif

all: s21_matrix.a

s21_matrix.a: $(SRC)
	$(CC) $(FLAGS) -c $(SRC)
	ar rcs $@ *.o

gcov_report_common:
	mkdir -p tests/build
	$(CC) --coverage -fPIC -O0 $(SRC) $(TEST_DIR)/*.c -o $(TBD)/test_cov_runner $(LINK_TEST_LIBS)
	./$(TBD)/test_cov_runner

gcov_report: gcov_report_common
	gcovr -e 'tests/*' --html gcov_report.html

gcov_report_console: gcov_report_common
	gcov -H $(TBD)/test_cov_runner-s21*.gcno

clean:
	rm -rf *.o
	rm -rf *.a
	rm -rf $(TBD)
	rm -rf *.html
	rm -rf *.css
	rm -rf *.gcov

.PHONY: test
test: $(TEST_RUNNER)
	CK_FORK=yes ./$(TEST_RUNNER)

tests/build/test_runner: $(SRC) $(TEST_DIR)/*.c
	mkdir -p tests/build
	$(CC) $(SRC) $(TEST_DIR)/*.c $(LINK_TEST_LIBS) $(FLAGS) -o $@

.PHONY: check_valgrind
check_valgrind: $(TEST_RUNNER)
	CK_FORK=no $(VALGRIND)