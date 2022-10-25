FLAGS=-Wall -Wextra -Werror
FILES=ft_garbage read rush02 ft_print_value key_val ft_morse
SRC=$(addsuffix .c,$(FILES))
OBJ=$(addsuffix .o,$(FILES))
BIN=rush-02

all: $(BIN)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(BIN)

re: fclean all

$(BIN): $(OBJ)
	gcc $(FLAGS) -o $(BIN) $(OBJ) 

%.o: %.c
	gcc $(FLAGS) -o $@ -c $<

git: re
	norminette
	make fclean
