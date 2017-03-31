OBJ = main.o wifiscan.o screen.o
APPNAME = wifi.a

$(APPNAME) : $(OBJ)
	gcc -o $(APPNAME) $(OBJ) -lm -lcurl
	
%.o : %.c
	gcc -c -o $@ $< -std=c99
	
clean :
	rm $(OBJ) $(APPNAME)

archive :
	tar cf sound.tar *.c *.h makefile
