/*
  Name:         MutexHelper.h (definition)
  Author:       Kip Warner (Kip@TheVertigo.com)
  Description:  Helper class wrapper for hardware based mutex. This should be
                used whenever possible in place of directly using the Mutex
                class since it is safer...
*/

// Multiple include protection...
#ifndef __SHIVA_MUTEXHELPER__
#define __SHIVA_MUTEXHELPER__

// Includes...
#include "Mutex.h"

// Within the Shiva namespace...
namespace Shiva
{
    // Mutex helper class...
    class MutexHelper
    {
        // Public methods...
        public:
        
            // Default constructor...
            MutexHelper(Mutex &_HelpedMutex);
            
            // Deconstructor...
           ~MutexHelper();

        // Protected attributes...
        protected:
        
            // The actual mutex...
            Mutex  &HelpedMutex;
    };
}

#endif

