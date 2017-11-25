install:
	gcc -c -fpic src/*.c -I include/
	gcc -shared -o /usr/lib/libutilsc.so *.o
	cp include/*.h /usr/include/
	chmod 0755 /usr/lib/libutilsc.so
	ldconfig
	rm *.o
test:
	gcc -o test tests/testInclude.c -lutilsc
	./test
	rm test
uninstall:
	rm /usr/include/hash.h
	rm /usr/include/list.h
	rm /usr/include/object.h
	rm /usr/include/pqueue.h
	rm /usr/include/queue.h
	rm /usr/include/stack.h
	rm /usr/lib/libutilsc.so
	ldconfig
