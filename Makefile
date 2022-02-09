

all:
	gcc -g -Wall Main_arvLLRB_.c Funcs_arvLLRB_.c Head_arvLLRB_.h Funcs_my_string_.c Head_my_string_.h -o ARVLLRB

run:
	./ARVLLRB

make test:
	clear
	gcc -g -Wall Main_arvLLRB_.c Funcs_arvLLRB_.c Head_arvLLRB_.h Funcs_my_string_.c Head_my_string_.h -o ARVLLRB
	./ARVLLRB <1.in

val:
	clear
	valgrind --tool=memcheck --leak-check=full --track-origins=yes --show-leak-kinds=all --show-reachable=yes ./ARVLLRB <1.in