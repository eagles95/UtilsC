install:
	gcc -c -fpic src/*.c -I include/
	gcc -shared -o /usr/lib/libutilsc.so *.o
	chmod 0755 /usr/lib/libutilsc.so
	ldconfig
	rm *.o
test:
	gcc -o test tests/conflict.c -lutilsc
	./test
	rm test
uninstall:
	rm /usr/lib/libutilsc.so
	ldconfig
