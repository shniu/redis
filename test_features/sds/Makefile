all: sds_test_01.o sds_zero_length_array.o

sds_test_01.o: sds_test_01.c
	gcc -m64 -Wall -Werror -o $@ sds_test_01.c

sds_zero_length_array.o: sds_zero_length_array.c
	gcc -m64 -Wall -Werror -o $@ sds_zero_length_array.c

clean:
	@rm -v *.o