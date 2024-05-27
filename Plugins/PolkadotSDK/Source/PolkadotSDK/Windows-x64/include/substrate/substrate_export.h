
#ifndef LIB_SUBSTRATE_EXPORT_H
#define LIB_SUBSTRATE_EXPORT_H

#ifdef LIB_SUBSTRATE_STATIC_DEFINE
#  define LIB_SUBSTRATE_EXPORT
#  define LIB_SUBSTRATE_NO_EXPORT
#else
#  ifndef LIB_SUBSTRATE_EXPORT
#    ifdef substrate_EXPORTS
        /* We are building this library */
#      define LIB_SUBSTRATE_EXPORT __declspec(dllexport)
#    else
        /* We are using this library */
#      define LIB_SUBSTRATE_EXPORT __declspec(dllimport)
#    endif
#  endif

#  ifndef LIB_SUBSTRATE_NO_EXPORT
#    define LIB_SUBSTRATE_NO_EXPORT 
#  endif
#endif

#ifndef LIB_SUBSTRATE_DEPRECATED
#  define LIB_SUBSTRATE_DEPRECATED __declspec(deprecated)
#endif

#ifndef LIB_SUBSTRATE_DEPRECATED_EXPORT
#  define LIB_SUBSTRATE_DEPRECATED_EXPORT LIB_SUBSTRATE_EXPORT LIB_SUBSTRATE_DEPRECATED
#endif

#ifndef LIB_SUBSTRATE_DEPRECATED_NO_EXPORT
#  define LIB_SUBSTRATE_DEPRECATED_NO_EXPORT LIB_SUBSTRATE_NO_EXPORT LIB_SUBSTRATE_DEPRECATED
#endif

#if 0 /* DEFINE_NO_DEPRECATED */
#  ifndef LIB_SUBSTRATE_NO_DEPRECATED
#    define LIB_SUBSTRATE_NO_DEPRECATED
#  endif
#endif

#endif /* LIB_SUBSTRATE_EXPORT_H */
