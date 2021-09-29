#include <stdio.h>
#include <stdlib.h>

typedef enum { OK, ERROR } status ;

status insertionsort( int A[] , int n ) ;

int main( int argc, char *argv[] ) {

  int *A, i, n ;

  FILE *fin ;

  fin = fopen( argv[1], "r" ) ;

  n = atoi( argv[2] ) ;

  A = ( int * ) malloc( sizeof(int) * n ) ;

  for ( i = 0 ; i < n ; i++ ) fscanf(fin, "%d", &A[i] ) ;

  if ( insertionsort( A, n ) == ERROR ) printf("\n Trouble sorting.\n ") ;

  printf("\n");

  printf("The smallest number is: %d.\n", A[0] ) ;

  printf("The middle number is: %d.\n", A[n/2] ) ;

  printf("The largest number is: %d.\n", A[n-1] ) ;

  printf("\n");

 return 0 ;

}

status insertionsort( int A[] , int n ) {

  int i, j, next, temp ;

  for ( i = 0 ; i < n ; i++ ) {

    next = A[i] ;

    j = i ;

    while ( ( j > 0 ) && ( A[j-1] > next ) ) {

      A[j] = A[j-1] ;

      j = j - 1 ;

    }

    A[j] = next ;
 }

  return OK ;
}

