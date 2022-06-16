OS=$(shell uname)
ifeq ($(OS), Linux)
	LIBS=-lcheck -lpthread -lrt -lm -lsubunit
	OPEN=xdg-open
else
	LIBS= -lcheck
	OPEN=open
endif

all:

test:
	gcc calc_test.c rpn.c _my_stack.c -o test.out $(LIBS)
	./test.out

gcov_report:
	gcc -o test.out --coverage rpn.c _my_stack.c calc_test.c $(LIBS)
	./test.out
	lcov -t "test.out" -o test.info -c -d .
	genhtml -o report test.info
	$(OPEN) report/index.html

code_style:
	cp ../materials/linters/CPPLINT.cfg ./CPPLINT.cfg
	python3 ../materials/linters/cpplint.py --quiet  --extension=c *.c *.h
	cppcheck --quiet --enable=all --suppress=unusedFunction --suppress=constParameter --suppress=missingIncludeSystem *.c *.h

leaks: 
	make test
	CK_FORK=no leaks --atExit -- ./test.out
	make clean

clean:
	rm -rf *.o *.a *.out *.gcda *.gcno *.info *.dSYM *.info report
