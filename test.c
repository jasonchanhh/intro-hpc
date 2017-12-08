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
    printf("Thread[%d], a is : %d, at (%d)\n",tid, a[i], j);
// #pragma omp for
//     for (i=0; i<N; i++) {
//       a[i] = b[i];
      // printf("Thread[%d], a is : %d, at (%d,%d)\n",tid, a[i], i, j);
    }
  }


  return EXIT_SUCCESS;
}
