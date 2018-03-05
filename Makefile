CC=gcc
LIBS=-lm

SRC_DIR=./src
SRCS=list_sorting.c
OBJS=$(SRCS:%.c=$(SRC_DIR)/%.o)

TEST_DIR=./test
TEST_SRCS= test_list_sorting.c
TEST_OBJS=$(TEST_SRCS:.c=.o)
TEST_EXES=$(TEST_SRCS:%.c=$(TEST_DIR)/%)

RM=rm -f

$(SRC_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) -g -c $< -o $@

$(TEST_DIR)/%.o: $(TEST_DIR)/%.c $(OBJS)
	$(CC) -g -c $< -o $@

$(TEST_DIR)/%: $(TEST_DIR)/%.c $(OBJS)
	$(CC) -g -o $@ $^ $(LIBS)

.PHONY:all clean

all: $(OBJS) $(TEST_EXES)

test_list_sorting: $(TEST_DIR)/test_list_sorting.c $(OBJS)


clean:
	$(RM) $(OBJS) $(TEST_OBJS) $(TEST_EXES)
