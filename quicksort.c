#include <stdio.h>
#include <stdlib.h>

typedef enum { OK, ERROR } status ;

status quick_sort( int a[], int low, int high ) ;

int main( int argc, char *argv[] ) {

  int *A, i, n ;

  FILE *fin ;

  fin = fopen( argv[1], "r" ) ;

  n = atoi( argv[2] ) ;

  A = ( int * ) malloc( sizeof( int ) * n ) ;

  for ( i = 0 ; i < n ; i++ ) fscanf(fin, "%d", &A[i] ) ;

  if ( quick_sort( A, 0, n-1 ) == ERROR ) printf("\n Trouble sorting.\n ") ;

  printf("\n");

  printf("The smallest number is: %d.\n", A[0] ) ;

  printf("The middle number is: %d.\n", A[n/2] ) ;

  printf("The largest number is: %d.\n", A[n-1] ) ;

  printf("\n");

  fclose( fin );

  return 0 ;

}

void swap( int *a, int *b ) {

  int temp ;

  temp = *a ;

  *a = *b ;

  *b = temp ;

}

status quick_sort( int a[], int low, int high ) {

  int i, j, pivot ;

  if ( high <= low ) return 0 ;

  i = low - 1 ;

  j = high ;

  pivot = a[high] ; 

  while ( 1 ) {

    do i = i + 1; while ( ( a[i] < pivot ) && ( i <= high ) ) ;

    do j = j - 1; while ( (a[j] > pivot ) && ( j >= low ) ) ;

    if ( i >= j ) break ;

    swap ( &a[i], &a[j] ) ;

  }

  swap( &a[i], &a[high] ) ; 

  quick_sort( a, low , i-1 ) ; 

  quick_sort( a, i+1, high ) ; 

}
