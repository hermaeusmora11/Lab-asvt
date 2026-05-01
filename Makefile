CC = gcc
CFLAGS = -Wall -Wextra -Werror -std=c11 -Iinclude

SRC = $(wildcard src/*.c)
LIB_SRC = $(filter-out src/main.c, $(SRC))
TEST_SRC = $(wildcard tests/*_test.c)

OUT = app
TEST_OUT = test_app

all:
	$(CC) $(CFLAGS) $(SRC) -o $(OUT) -lm

clean:
	rm -f $(OUT) $(TEST_OUT)

format:
	find . -name "*.c" -o -name "*.h" | xargs clang-format -i

format-check:
	find . -name "*.c" -o -name "*.h" | xargs clang-format --dry-run --Werror

test:
	$(CC) $(CFLAGS) $(TEST_SRC) $(LIB_SRC) -o $(TEST_OUT) -lm
	./$(TEST_OUT)

.PHONY: all clean format format-check test
