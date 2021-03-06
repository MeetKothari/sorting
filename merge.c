/************************************************************************/
/* mergesort */
/************************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef enum { OK, ERROR } status ;

typedef char byte ;

void mergesort(byte data[], int n, int elementsize, int (*p_cmp_f)( ) ) ;

void memcopy( byte *to, byte *from, int count ) {

  while ( count-- > 0 ) *to++ = *from++ ;

}

int compare( byte *a , byte *b ) {

  int *x, *y ;

  x = (int *) a ;

  y = (int *) b ;

  if ( *x < *y ) return -1 ;

  if ( *x == *y ) return 0 ;

  if ( *x > *y ) return 1 ;

}
int main( int argc, char *argv[] ) {

  int *A, i, n ;

  FILE *fin ;

  fin = fopen( argv[1], "r" ) ;

  n = atoi( argv[2] ) ;

  A = ( int * ) malloc( sizeof( int ) * n ) ;

  for ( i = 0 ; i < n ; i++ ) fscanf( fin, "%d", &A[i] ) ;

  mergesort( (byte *)A, n, sizeof(int), compare ) ;

  printf( "\n" ) ; printf( "The smallest number is: %d.\n", A[0] ) ;

  printf( "\n" ) ; printf( "The middle number is: %d.\n", A[n/2] ) ;

  printf( "\n" ) ; printf( "The largest number is: %d.\n", A[n-1] ) ;

  fclose( fin ) ;

  return 0 ;

}

void mergesort(byte data[], int n, int elementsize, int (*p_cmp_f)( ) ){

  byte *firsthalf ;

  byte *endoffirsthalf ;

  byte *secondhalf ;

  byte *endofsecondhalf ;

  byte *resultbuffer , *p_result ;

  int halfsize ;

  if ( n <= 1 ) return ;

  halfsize = n / 2 ;

  firsthalf = data ;

  secondhalf = data + halfsize * elementsize ;

  mergesort(firsthalf, halfsize, elementsize, p_cmp_f) ;

  mergesort(secondhalf, n-halfsize, elementsize, p_cmp_f) ;

  endoffirsthalf = secondhalf ;

  endofsecondhalf = data + n * elementsize ;

  resultbuffer = (byte *) malloc(n * elementsize) ;

  p_result = resultbuffer ;

  while (firsthalf < endoffirsthalf && secondhalf < endofsecondhalf) {

    if ((*p_cmp_f)(firsthalf, secondhalf) < 0 ) {

      memcpy(p_result, firsthalf, elementsize) ;

      firsthalf += elementsize ;

    } else {

      memcpy(p_result, secondhalf, elementsize) ;

      secondhalf += elementsize ;

    }

    p_result += elementsize ;

  }

  while (firsthalf < endoffirsthalf) {

    memcpy(p_result, firsthalf, elementsize) ;

    firsthalf += elementsize ;

    p_result += elementsize ;

  }

  while (secondhalf < endofsecondhalf) {

    memcpy(p_result, secondhalf, elementsize) ;

    secondhalf += elementsize ;

    p_result += elementsize ;

  }

  memcpy(data, resultbuffer, n * elementsize) ;

  free(resultbuffer) ;

}

  
