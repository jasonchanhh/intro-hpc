#include <omp.h>
#include <stdio.h>
#include <stdlib.h>

#define N 10
#define REPEAT 10

int main (int argc, char *argv[]) {

//   int a[N], b[N];
//   int tid;
//   int i,j;
//
//   for (i=0;i<N;i++) {
//     a[i]=0;
//     b[i]=rand();
//   }
//
// #pragma omp parallel private(j, tid)
//   tid = omp_get_thread_num();
//   printf("Thread = %d\n", tid);
//
//   for(j=0; j<REPEAT; j++) {
// #pragma omp for
//     for (i=0; i<N; i++) {
//       a[i] = b[i];
//       printf("Thread[%d], a is : %d, at (%d,%d)\n",tid, a[i], i, j);
//     }
//   }
int nthreads, tid;
/* These are commonly used variable names - nthreads is short for Number of threads, while */
/* tid is short for Thread ID. These are just conventions though, so you can use your own too */

/* Fork a team of threads giving them their own copies of variables */
#pragma omp parallel private(tid)
{
/* Obtain thread number */
tid = omp_get_thread_num();
printf("Hello, world from thread = %d\n", tid);

/* Only master thread does this */
#pragma omp master
{
  nthreads = omp_get_num_threads();
  printf("Number of threads = %d\n", nthreads);
}
}  /* All threads join master thread and disband */

  return EXIT_SUCCESS;
}
