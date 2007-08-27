/*
  Name:         Mutex.cpp (implementation)
  Author:       Kip Warner (Kip@TheVertigo.com)
  Description:  Implements support for hardware based mutexes...
*/

// Includes...
#include "Mutex.h"

// Select Shiva namespace...
using namespace Shiva;

// Lock mutex...
void Mutex::Lock()
{
    // Keep trying until locked...
    while(!TryLock())
    {
        /* TODO: Thread should yield its time slice here */    
    }
}

// Check if the mutex is locked, without trying to change it...
bool Mutex::IsLocked() const
{
    // Return state...
    return (bool) bLocked;
}

// Try to lock the mutex...
bool Mutex::TryLock()
{
    // Variables...
    register volatile unsigned char bLockedBefore;

    // Try to lock mutex via hardware support...
    asm volatile(
        
        // Load the intended lock value (1) into AH register...
        "movb   $0x01,  %%ah    ;\n"
        
        // Toggle lock using value in EAX and save old back in AH...
        "xchgb  %0,     %%ah    ;\n"
        
        // Save the old lock value in unLockedBefore...
        "movb   %%ah,  %1       ;\n"
        
            // Output registers...
            : "=r"  (bLocked),
              "=r"  (bLockedBefore)
            
            // Input registers...
            : "0"   (bLocked)
            
            // Clobbered registers...
            : "%ah");
    
    // If locked already, then failed. Otherwise, lock now toggled...
    return (bLockedBefore) ? false : true;
}

// Unlock mutex...
void Mutex::Unlock()
{
    // Release...
    asm volatile(
    
        // Clear the lock...
        "movb $0x00, %0"
        
            // Output register...
            : "=m"  (bLocked)

            // Neither any inputs nor clobbered registers...
            : 
            :);
}

// Deconstructor...
Mutex::~Mutex()
{
    // Unlock on the way out...
    Unlock();
}

