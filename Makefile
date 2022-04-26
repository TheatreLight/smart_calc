all:
	make create_make
	make -C build-smart_calc-Desktop_Qt_6_2_4_GCC_64bit-Release/ first
	make run

rebuild:
	make clean
	make remove
	make all

install:
	@mkdir SMART_CALC1_0
	@cp build-smart_calc-Desktop_Qt_6_2_4_GCC_64bit-Release/smart_calc SMART_CALC1_0/smart_calc

uninstall:
	@rm -rf SMART_CALC1_0

dist:
	@make install
	@tar -zcf calc.tar.gz SMART_CALC1_0/
	@make uninstall

dvi:

tests:
	make -C src/ test

gcov_report:
	make -C src/ gcov_report

create_make:
	gcc_64/bin/qmake -o build-smart_calc-Desktop_Qt_6_2_4_GCC_64bit-Release/Makefile src/smart_calc.pro -spec linux-g++ CONFIG+=qtquickcompiler

run:
	./build-smart_calc-Desktop_Qt_6_2_4_GCC_64bit-Release/smart_calc

code_style:
	make -C src/ code_style

clean:
	make -C src/ clean

remove:
	rm -rf build-smart_calc-Desktop_Qt_6_2_4_GCC_64bit-Release/

remove_make:
	rm build-smart_calc-Desktop_Qt_6_2_4_GCC_64bit-Release/Makefile
