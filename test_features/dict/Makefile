all: dict_hash_table.o

dict_hash_table.o: dict_hash_table.c
	gcc -m64 -Wall -Werror -o $@ dict_hash_table.c

clean:
	@rm -v *.o