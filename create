#include <stdlib.h>
#include <stdio.h>

int main( int argc , char *argv[] ){

  int i , n ;

  FILE *fout ;

  fout = fopen( "numbers" , "w" ) ;

  for ( i = 1 ; i <= 1000000 ; i++ ) {

    n = rand() % 10000 ;

    fprintf( fout, "%7d\n", n < 1000 ? n + 1000 : n ) ;

  }

  fclose( fout ) ;

  return 0 ;

}
