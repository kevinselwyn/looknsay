NAME    := looknsay
BUILD   := build
EXEC    := $(BUILD)/$(NAME)
BIN_DIR := /usr/local/bin

all: build

build: $(NAME).c
	mkdir -p $(BUILD)
	gcc -o $(EXEC) $< -O2

test: build
	./$(EXEC) 1 10

memcheck:
	gcc -o $(EXEC) $(NAME).c -g -O0
	valgrind ./$(EXEC) 1 10

install: build
	install -m 0755 $(EXEC) $(BIN_DIR)

uninstall:
	rm -f $(BIN_DIR)/$(NAME)

clean:
	rm -r $(BUILD)
