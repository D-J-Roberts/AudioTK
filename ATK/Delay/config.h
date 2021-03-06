/**
 * \file config.h
 */

#ifndef ATK_DELAY_CONFIG_H
#define ATK_DELAY_CONFIG_H

#ifdef _MSC_VER
# ifdef ATK_SHARED
#  ifdef BUILD_ATK_DELAY
#   define ATK_DELAY_EXPORT __declspec( dllexport )
#  else
#   define ATK_DELAY_EXPORT __declspec( dllimport )
#  endif
# else
#  define ATK_DELAY_EXPORT
# endif
#else
# define ATK_DELAY_EXPORT
#endif

#endif
