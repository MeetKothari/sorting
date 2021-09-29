#include <stdio.h>
#include <stdlib.h>

typedef enum { OK, ERROR } status ;

status shellsort( int A[] , int n ) ;

int main( int argc, char *argv[] ) {

  int *A, i, n ;

  FILE *fin ;

  fin = fopen( argv[1], "r" ) ;

  n = atoi( argv[2] ) ;

  A = ( int * ) malloc( sizeof(int) * n ) ;


  for ( i = 0 ; i < n ; i++ ) fscanf(fin, "%d", &A[i] ) ;

  if ( shellsort( A, n ) == ERROR ) printf("\n Trouble sorting.\n ") ;

  printf("\n");

  printf("The smallest number is: %d.\n", A[0] ) ;

  printf("The middle number is: %d.\n", A[n/2] ) ;

  printf("The largest number is: %d.\n", A[n-1] ) ;

  printf("\n");

  fclose( fin );


  return 0 ;

}

status shellsort( int A[] , int n ) {

  int i, j, gap , temp ;

  gap = ( n / 3 ) ;

  while ( gap > 0 ) {

    for ( i = 0 ; i < n ; i++ ) {

      j = i ;

      temp = A[i] ;

      while ( ( j >= gap ) && ( A[j-gap] > temp ) ) {

	A[j] = A[j-gap] ;

	j = j - gap ;

      }

      A[j] = temp ;

    }

    gap = gap / 3 ;

  }

  return OK ;

}
