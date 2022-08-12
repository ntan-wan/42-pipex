all : test

test:
	make bonus -C libft
	gcc *.c libft/libft.a && ./a.out in.txt "grep apple" "wc -w" outfile

fclean:
	make fclean -C libft