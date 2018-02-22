#ifndef VSTRING_H
#define VSTRING_H


#include "object.h"
#include <stdlib.h>

typedef struct vstring_public {
    int id ;
    //void ( * destroy ) ( int ) ;

} VSTRING ;

typedef struct class_vstring_public {
    const int default_capacity ;
    VSTRING ( * init ) ( void ) ;
    VSTRING ( * getInstance ) ( int ) ;
    void ( * destroy ) ( int ) ;
} C_VSTRING ;

C_VSTRING * pClass_VSTRING = NULL ;

void vstring_class_init ( void ) ;
#define VSTRING_INIT vstring_class_init() ; \
C_VSTRING Class_VSTRING = * pClass_VSTRING

void vstring_class_destroy ( void ) ;
#define VSTRING_DESTROY vstring_class_destroy()


#endif
