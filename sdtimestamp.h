/* ========================================================================
   $File: $
   $Date: $
   $Revision: $
   $Creator: Tristan Magniez $
   $Notice: (C) Copyright 2010 by Megrov, Inc. All Rights Reserved. $
   ======================================================================== */

#if !defined(SDTIMESTAMP_H)
#define SDTIMESTAMP_H

#include <stdint.h>

int64_t sdTimestamp(void);

#endif

#ifdef SDTS_IMPLEMENTATION

#define SDTS_WINDOWS 1
#define SDTS_MAC     2
#define SDTS_UNIX    3

#if defined( _WIN32 )
#define SDTS_PLATFORM SDT_WINDOWS
#elif defined( __APPLE__ )
#define SDTS_PLATFORM SDT_MAC
#else
#define SDTS_PLATFORM SDT_UNIX
#endif

#if SDTS_PLATFORM == SDTS_WINDOWS

//NOTE(doc): supposing you have included windows.h before

int _gettimeofday(struct timeval* p, void* tz) {
    ULARGE_INTEGER ul;
    FILETIME ft;
    GetSystemTimeAsFileTime(&ft);
    ul.LowPart = ft.dwLowDateTime;
    ul.HighPart = ft.dwHighDateTime;
    ul.QuadPart /= 10ULL;
    ul.QuadPart -= 11644473600000000ULL;
    p->tv_usec = (long) (ul.QuadPart % 1000000LL);
    p->tv_sec = (long) (ul.QuadPart / 1000000LL);
    return 0;
}

//TODO(doc): properly test that
int64_t
timestamp(void) {
    struct timeval tv;
    int ret = _gettimeofday(&tv, NULL);
    //TODO(doc): ret will never == to -1 
    if (-1 == ret) return -1;
    return (int64_t) ((int64_t) tv.tv_sec * 1000 + (int64_t) tv.tv_usec / 1000);
}

#elif SDTS_PLATFORM == SDTS_MAC

SDTIMESTAMP NOT IMPLEMENTED YET FOR MAC

#else

#include <stdlib.h>
#include <sys/time.h>

int64_t
timestamp(void) {
    struct timeval tv;
    int ret = gettimeofday(&tv, NULL);
    if (-1 == ret) return -1;
    return (int64_t) ((int64_t) tv.tv_sec * 1000 + (int64_t) tv.tv_usec / 1000);
}

#endif

#endif
