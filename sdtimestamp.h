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

#if SDT_PLATFORM == SDT_WINDOWS

int _gettimeofday(struct timeval* p, void* tz) {
    ULARGE_INTEGER ul; // As specified on MSDN.
    FILETIME ft;

    // Returns a 64-bit value representing the number of
    // 100-nanosecond intervals since January 1, 1601 (UTC).
    GetSystemTimeAsFileTime(&ft);

    // Fill ULARGE_INTEGER low and high parts.
    ul.LowPart = ft.dwLowDateTime;
    ul.HighPart = ft.dwHighDateTime;
    // Convert to microseconds.
    ul.QuadPart /= 10ULL;
    // Remove Windows to UNIX Epoch delta.
    ul.QuadPart -= 11644473600000000ULL;
    // Modulo to retrieve the microseconds.
    p->tv_usec = (long) (ul.QuadPart % 1000000LL);
    // Divide to retrieve the seconds.
    p->tv_sec = (long) (ul.QuadPart / 1000000LL);

    return 0;
}

int64_t
timestamp(void) {
    struct timeval tv;
    int ret = _gettimeofday(&tv, NULL);
    if (-1 == ret) return -1;
    return (int64_t) ((int64_t) tv.tv_sec * 1000 + (int64_t) tv.tv_usec / 1000);
}

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
