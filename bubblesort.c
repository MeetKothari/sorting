#include <stdio.h>
#include <stdlib.h>

typedef enum { OK, ERROR } status ;

status bubblesort( int A[] , int n ) ;

int main( int argc, char *argv[] ) {

  int *A, i, n ;

  FILE *fin ;

  fin = fopen( argv[1], "r" ) ;

  n = atoi( argv[2] ) ;

  A = ( int * ) malloc( sizeof( int ) * n ) ;

  for ( i = 0 ; i < n ; i++ ) fscanf( fin, "%d", &A[i] ) ;

  if ( bubblesort( A, n ) == ERROR ) printf( "\n Trouble sorting.\n " ) ;

  printf( "\n" ) ;

  printf( "The smallest number is: %6d.\n", A[0] ) ;

  printf( "The middle number is: %6d.\n", A[n/2] ) ;

  printf( "The largest number is: %6d.\n", A[n-1] ) ;

  printf( "\n" ) ;

  fclose( fin ) ;

  return 0 ;

}

status bubblesort( int A[] , int n ) {

  int i, j, temp ;

  for ( i = 0 ; i < ( n - 1 ) ; i++ )

    for ( j = 0 ; j < ( n - 1 ) - i ; j++ )

      if ( A[j] > A[j + 1] ) {

	temp = A[j] ;

	A[j] = A[j + 1] ;

	A[j + 1] = temp ; }

  return OK ;
}
