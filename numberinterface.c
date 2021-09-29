/**************************/
/* numberinterface.c      */
/**************************/

#include "numberinterface.h"

status appendanumber( list *p_L, int n ){

  int *m = ( int * ) malloc ( sizeof( int ) ) ;

  if ( m == NULL ) return ERROR ;

  *m = n ;

  if( append( p_L , ( generic_ptr ) m ) == ERROR ){

    free( m ) ;

    return ERROR ;

  }

  return OK ;

}

status getnextnumber( list *p_L, int *n ){

  int *m ;

  if ( delete( p_L, ( generic_ptr * ) &m ) == ERROR ) return ERROR ;

  *n = *m ;

  free( m ) ;

  return OK ;

}

						     

