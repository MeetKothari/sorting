#include <stdio.h>
#include <stdlib.h>

typedef enum { OK, ERROR } status ;

status selectionsort( int A[] , int n ) ;

int main( int argc, char *argv[] ) {

  int *A ;

  int i ;

  int n ;

  FILE *fin ;

  fin = fopen( argv[1], "r" ) ;

  n = atoi( argv[2] ) ;

  A = ( int * ) malloc( sizeof(int) * n ) ;

  for ( i = 0 ; i < n ; i++ ) fscanf(fin, "%d", &A[i] ) ;

  if ( selectionsort( A, n ) == ERROR ) printf("\n Trouble sorting.\n ") ;

  printf("\n");

  printf("The smallest number is: %d.\n", A[0] ) ;

  printf("The middle number is: %d.\n", A[n/2] ) ;

  printf("The largest number is: %d.\n", A[n-1] ) ;

  printf("\n");


  return 0 ;

}

status selectionsort( int A[] , int n ) {

  int i, j, min_index, temp ;

  for ( i = 0 ; i < (n-1) ; i++ ) {

    min_index = i ;

    for ( j = i+1 ; j < n ; j++ ) if ( A[j] < A[min_index] ) min_index = j ;

    temp = A[i] ;

    A[i] = A[min_index] ;

    A[min_index] = temp ;

  }

  return OK ;

}
