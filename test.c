#include <omp.h>
#include <stdio.h>
#include <stdlib.h>

#define N 10
#define REPEAT 10

int main (int argc, char *argv[]) {

  int a[N], b[N];
  int tid;
  int i,j;

  for (i=0;i<N;i++) {
    a[i]=0;
    b[i]=rand();
  }

#pragma omp parallel private(j, tid)
  tid = omp_get_thread_num();
  printf("Thread = %d\n", tid);

  for(j=0; j<REPEAT; j++) {
#pragma omp for
    for (i=0; i<N; i++) {
      a[i] = b[i];
      printf("Thread[%d], a is : %d\n",tid, a[i]);
    }
  }

  return EXIT_SUCCESS;
}
