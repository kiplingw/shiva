/*
  Name:         Mutex.h (definition)
  Author:       Kip Warner (Kip@TheVertigo.com)
  Description:  Implements support for hardware based mutexes...
*/

// Multiple include protection...
#ifndef __SHIVA_MUTEX__
#define __SHIVA_MUTEX__

// Within the Shiva namespace...
namespace Shiva
{
    // Mutex class...
    class Mutex
    {
        // Public methods...
        public:
        
            // Default constructor...
            Mutex() : bLocked(0x00) {}
            
            // Lock mutex...
            void Lock();

            // Check if the mutex is locked, without trying to change it...
            bool IsLocked() const;

            // Try to lock the mutex...
            bool TryLock();

            // Unlock mutex...
            void Unlock();
            
            // Deconstructor...
           ~Mutex();

        // Protected attributes...
        protected:
        
            // Lock state...
            volatile unsigned char  bLocked;
    };
}

#endif

