#ifndef COMMON_DEBUG_H
#define COMMON_DEBUG_H

#include <cassert>
#include <iostream>

#define _unused( x ) ((void)(x))

#ifdef KDEBUG
    #define _dp( x ) { x; }
    #define _dpf( x ) { x(); }
#else
    #define _dp( x )
    #define _dpf( x ) _unused(x)
#endif

#endif //COMMON_DEBUG_H
