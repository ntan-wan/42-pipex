all : test

test:
	make bonus -C libft
	gcc *.c libft/libft.a && ./a.out in.txt out.txt

fclean:
	make fclean -C libft