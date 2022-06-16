OS=$(shell uname)
INSTALL_DIR=SMART_CALC1_0/
ifeq ($(OS), Linux)
	QMAKE=qmake
	OPT=-spec linux-g++ CONFIG+=qtquickcompiler
	BUILD_DIR=build-smart_calc-Desktop_Qt_6_2_4_GCC_64bit-Release
else
	QMAKE=qmake
	OPT=CONFIG+=qtquickcompiler
	BUILD_DIR=build-smart_calc-Desktop_Qt_6_2_4_GCC_64bit-Release/smart_calc.app/Contents/MacOS
endif

all:
	make create_make
	make -C build-smart_calc-Desktop_Qt_6_2_4_GCC_64bit-Release/ first

rebuild:
	make clean
	make remove
	make all

install:
	@mkdir SMART_CALC1_0
	@cp $(BUILD_DIR)/smart_calc $(INSTALL_DIR)smart_calc
	@cp materials/icon.png $(INSTALL_DIR)icon.png
	@cp materials/run.desktop $(INSTALL_DIR)run.desktop
	@make dvi

uninstall:
	@rm -rf $(INSTALL_DIR)

dist:
	@make install
	@tar -zcf calc.tar.gz $(INSTALL_DIR)
	@make uninstall

dvi:
	@cp materials/manual.pdf $(INSTALL_DIR)manual.pdf

tests:
	make -C src/ test

gcov_report:
	make -C src/ gcov_report

create_make:

	$(QMAKE) -o build-smart_calc-Desktop_Qt_6_2_4_GCC_64bit-Release/Makefile src/smart_calc.pro

run:
	./$(BUILD_DIR)/smart_calc

code_style:
	make -C src/ code_style

clean:
	make -C $(BUILD_DIR) clean
	make -C src/ clean
	rm -rf $(BUILD_DIR) 

leaks:
	make -C src/ leaks
