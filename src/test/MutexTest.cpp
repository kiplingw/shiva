/*
  Name:         MutexTest.cpp
  Author:       Kip Warner (Kip@TheVertigo.com)
  Description:  Run some tests on hardware mutex support...
  Quick Start:  gcc MutexTest.cpp ../Mutex.cpp ../MutexHelper.cpp -o MutexTest -lstdc++ && ./MutexTest
*/

// Includes...
#include "../MutexHelper.h"
#include <stdio.h>

// Entry point...
int main()
{
    // Create a mutex helper...
    Shiva::Mutex        HelpedMutex;
    Shiva::MutexHelper  TestMutexHelper(HelpedMutex);
    
    // Lock it...
//    TestMutexHelper.Lock();
   
    
    /*if(!TestMutex.TryLock())
        printf("TryLock failed...\n");
    
    printf("Trying to Lock now, should hang...\n");
    TestMutex.Lock();*/
    
    // Unlock it...
//    TestMutexHelper.Unlock();    

    // Done...
    return 0;
}

