all: rtu

rtu: 
	gcc rtu-di8.c -o rtu-di8 -lsqlite3 -lmodbus

clean:
	rm -rf *.o rtu-di8
