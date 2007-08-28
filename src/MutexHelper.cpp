/*
  Name:         MutexHelper.cpp (implementation)
  Author:       Kip Warner (Kip@TheVertigo.com)
  Description:  Helper class wrapper for hardware based mutex. This should be
                used whenever possible in place of directly using the Mutex
                class since it is safer...
*/

// Includes...
#include "MutexHelper.h"

// Select Shiva namespace...
using namespace Shiva;

// Default constructor...
MutexHelper::MutexHelper(Mutex &_HelpedMutex)
    : HelpedMutex(_HelpedMutex)
{
    // Automatically lock the mutex...
    HelpedMutex.Lock();
}

// Deconstructor...
MutexHelper::~MutexHelper()
{
    // Unlock on the way out of scope...
    HelpedMutex.Unlock();
}

