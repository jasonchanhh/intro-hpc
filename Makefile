default: jacobi

CC = icc
CFLAGS = -std=c99 -Wall
LDFLAGS = -lm -O3 -fast -fp-model fast 
SRC = jacobi.c

TCC = tau_cc.sh
TFLAGS = -std=c99 -Wall

jacobi: $(SRC)
	$(CC) $(CFLAGS) -o jacobi jacobi.c $(LDFLAGS)

tau: $(SRC)
	$(TCC) $(TFLAGS) -o jacobi jacobi.c

clean: jacobi
		rm -f jacobi
		rm -f jacobi.out
		rm -f *.pomp.*
		rm -f profile.*
