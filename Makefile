default: jacobi

CC = icc
CFLAGS = -std=c99 -Wall
LDFLAGS = -g -lm -O3 -fast -qopenmp 
SRC = jacobi.c

TCC = tau_cc.sh
TFLAGS = -std=c99 -Wall

jacobi: $(SRC)
	$(CC) $(CFLAGS) -o jacobi jacobi.c $(LDFLAGS)

tau: $(SRC)
	$(TCC) $(TFLAGS) -o jacobi jacobi.c

clean:
		rm -f jacobi
		rm -f *.out
		rm -f *.pomp.*
		rm -f profile.*


