StudentList = StudentList.o
PalindromeChecker = PalindromeChecker.o
ready : $(StudentList) $(PalindromeChecker) main.o
	gcc -w -o ready $(StudentList) $(PalindromeChecker) main.o

main.o :  main.c StudentList.h PalindromeChecker.h 
	cc -w -c main.c
		
StudentList.o :  StudentList.c StudentList.h 
	cc -w -c StudentList.c

PalindromeChecker.o : PalindromeChecker.c PalindromeChecker.h
	cc -w -c PalindromeChecker.c
 
clean: 
	rm -f $(StudentList) $(PalindromeChecker) main.o
