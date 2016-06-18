NAME    := looknsay
BIN_DIR := /usr/local/bin

all: build

build: $(NAME).c
	gcc -o $(NAME) $< -O2

test: build
	./$(NAME) 1 10

install: build
	install -m 0755 $(NAME) $(BIN_DIR)

uninstall:
	rm -f $(BIN_DIR)/$(NAME)

clean:
	rm -r $(NAME)