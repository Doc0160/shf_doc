/* ========================================================================
   $File: $
   $Date: $
   $Revision: $
   $Creator: Tristan Magniez $
   $Notice: (C) Copyright 2016 by Tristan Magniez. All Rights Reserved. $
   ======================================================================== */

#if !defined(SDT_H)

float sdtTime();

#define SDT_H
#endif

#ifdef SDT_IMPLEMENTATION

#define SDT_WINDOWS 1
#define SDT_MAC     2
#define SDT_UNIX    3

#if defined( _WIN32 )
#define SDT_PLATFORM SDT_WINDOWS
#elif defined( __APPLE__ )
#define SDT_PLATFORM SDT_MAC
#else
#define SDT_PLATFORM SDT_UNIX
#endif

/*
  NOTE(doc):
  These functions are intended be called from a single thread only. In a
  multi-threaded environment make sure to call Time from the main thread only.
  Also try to set a thread affinity for the main thread to avoid core swaps.
  This can help prevent annoying bios bugs etc. from giving weird time-warp
  effects as the main thread gets passed from one core to another. This shouldn't
  be a problem, but it's a good practice to setup the affinity. Calling these
  functions on multiple threads multiple times will grant a heft performance
  loss in the form of false sharing due to CPU cache synchronization across
  multiple cores.
  More info: https://msdn.microsoft.com/en-us/library/windows/desktop/ee417693(v=vs.85).aspx
*/

#if SDT_PLATFORM == SDT_WINDOWS

//NOTE(doc): supposing you have included windows.h before

float sdtTime()
{
    static int first = 1;
    static LARGE_INTEGER prev;
    static double factor;

    LARGE_INTEGER now;
    QueryPerformanceCounter(&now);

    if (first)
    {
        first = 0;
        prev = now;
        LARGE_INTEGER freq;
        QueryPerformanceFrequency(&freq);
        factor = 1.0 / (double)freq.QuadPart;
        return 0;
    }

    float elapsed = (float)((double)(now.QuadPart - prev.QuadPart) * factor);
    prev = now;
    return elapsed;
}

#elif SDT_PLATFORM == SDT_MAC

#include <mach/mach_time.h>
    
float sdtTime()
{
    static int first = 1;
    static uint64_t prev = 0;
    static double factor;
    
    if (first)
    {
        first = 0;
        mach_timebase_info_data_t info;
        mach_timebase_info(&info);
        factor = (double)info.numer / ((double)info.denom * 1000000000.0);
        prev = mach_absolute_time();
        return 0;
    }
    
    uint64_t now = mach_absolute_time();
    float elapsed = (float)((double)(now - prev) * factor);
    prev = now;
    return elapsed;
}

#else

#include <time.h>
    
float sdtTime()
{
    static int first = 1;
    struct timespec prev;
        
    if (first)
    {
        first = 0;
        clock_gettime(CLOCK_MONOTONIC, &prev);
        return 0;
    }
        
    struct timespec now;
    clock_gettime(CLOCK_MONOTONIC, &now);
    float elapsed = (float)((double)(now.tv_nsec - prev.tv_nsec) * 1000000000.0);
    prev = now;
    return elapsed;
}

#endif

#endif // SDT_IMPLEMENTATION
