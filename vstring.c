#include "vstring.h"

#include <stdlib.h>

VSTRING vstring_init ( void ) ;

typedef struct vstring {
    int id ;

    // Private
    Status state ;
    char * data ;
    int size ;
    int capacity ;
} Vstring ;

typedef struct vstring_header {
    int id ;
} HVSTRING ;

typedef struct class_vstring {
    int default_capacity ;
    VSTRING ( * init ) ( void ) ;
    VSTRING ( * getInstance ) ( int ) ;
    void ( * destroy ) ( int ) ;

    // Private
    int nInstances ;
    Vstring * instances ;
} C_Vstring ;

void vstring_class_init ( void )
{
    C_Vstring * pClass_vstring = ( C_Vstring * ) pClass_VSTRING ;
    pClass_vstring = ( C_Vstring * ) malloc ( sizeof ( C_Vstring ) ) ;

    pClass_vstring -> instances = NULL ;
    pClass_vstring -> nInstances = 0 ;

    pClass_vstring -> default_capacity = 7 ;
    pClass_vstring -> init = vstring_init ;

}

void vstring_class_destroy ( void ) {
    // Free all instances
    // Free class
}

VSTRING vstring_init ( void )
{
    Vstring * pVstring = NULL ;

    pVstring = ( Vstring * ) malloc ( sizeof ( Vstring ) ) ;

    C_Vstring * pClass_vstring = ( C_Vstring * ) pClass_VSTRING ;

    pVstring -> capacity = pClass_vstring -> default_capacity ;
    pVstring -> data = ( char * ) malloc ( sizeof ( char ) * pVstring -> capacity ) ;
    pVstring -> size = 0 ;
    pVstring -> state = SUCCESS ;
    pVstring -> id = pClass_vstring -> nInstances ;

    pClass_vstring -> instances = ( Vstring * ) realloc ( pClass_vstring -> instances , sizeof ( Vstring ) * pClass_vstring -> nInstances ) ;
    pClass_vstring -> instances [ pClass_vstring -> nInstances ++ ] = * pVstring ;

    VSTRING header ;

    header.id = pVstring -> id ;

    return header ;
}