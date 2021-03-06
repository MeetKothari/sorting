#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "list.h"
#include "numberinterface.h"
#include "globals.h"

void refill( int A[], list Bins[] ) ;

int getdigit( int number, int position ) ;

status radixsort( int A[], int n ) ;

int main( int argc, char *argv[] ){

  int *A ;

  int i ;

  int n ;

  FILE *fin ;

  fin = fopen( argv[1], "r" ) ;

  n = atoi( argv[2] ) ;

  A = ( int * ) malloc ( sizeof(int) * n ) ;

  for ( i = 0 ; i < n ; i++ ) fscanf( fin, "%d", &A[i] ) ;

  if ( radixsort( A, n ) == ERROR ) printf("\nTrouble sorting.\n\n") ;

  printf("\n") ;

  printf("The smallest number is %d.\n", A[0] ) ;

  printf("The middle number is   %d.\n", A[n/2] ) ;

  printf("The largest number is  %d.\n", A[n-1] ) ;

  printf("\n") ;

  fclose( fin ) ;

  return 0 ;

}

status radixsort( int A[], int n ){

  int i, j, digit ;

  list Bins[10] ;

  for ( i = 0 ; i < 10 ; i++ ) init_list( &Bins[i] ) ;

  for ( i = 1 ; i <= 4 ; i++ ){

    for ( j = 0 ; j < n ; j++ ){

      digit = getdigit( A[j], i-1 ) ;

      appendanumber( &Bins[digit], A[j] ) ;

    }

    refill( A, Bins ) ;

  }

  return 0 ;

}

int getdigit( int number, int position ){

  int digit ;

  number = number / pow( 10, position ) ;

  digit = number % 10 ;

  return digit ;

}

void refill( int A[], list Bins[] ){

  int i ;

  int j ;

  int n ;

  j = 0 ;

  for ( i = 0 ; i < 10 ; i++ ){

    while( !empty_list(Bins[i] ) ){

      getnextnumber( &Bins[i], &n ) ;

      A[j] = n ;

      j++ ;

    }
  }
}

