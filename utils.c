#include <stdlib.h>
#include <time.h>
#include <stdbool.h>


int randomNum(int min, int max)
{
    static bool initilized = false;
 
    if(!initilized)
    {
        initilized = true;
        srand(time(NULL));
    }
 
    return rand() % max + min;
}

int randomColor()
{
    return randomNum(0, 255);
}