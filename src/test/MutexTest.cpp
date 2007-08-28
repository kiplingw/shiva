/*
  Name:         MutexTest.cpp
  Author:       Kip Warner (Kip@TheVertigo.com)
  Description:  Run some tests on hardware mutex support...
  Quick Start:  gcc MutexTest.cpp ../Mutex.cpp -o MutexTest -lstdc++ && ./MutexTest
*/

// Includes...
#include "../Mutex.h"
#include <stdio.h>

// Entry point...
int main()
{
    // Create a mutex...
    Shiva::Mutex TestMutex;
    
    // Lock it...
    TestMutex.Lock();
   
    
    /*if(!TestMutex.TryLock())
        printf("TryLock failed...\n");
    
    printf("Trying to Lock now, should hang...\n");
    TestMutex.Lock();*/
    
    // Unlock it...
    TestMutex.Unlock();    
    
    // Done...
    return 0;
}

