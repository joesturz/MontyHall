//
//  main.c
//  MontyHall
//
//  Created by Joe Sturzenegger on 3/2/15.
//  Copyright (c) 2015 Joe Sturzenegger. All rights reserved.
//

//Monty Hall
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


// helper method for building an array of 3 elements representing the 3 doors
// the elements are randomized for each call
int* buildDoors()
{
    //srand((unsigned)time(NULL));
    int randomDoor = rand()%3;
    static int doors[3];
    int i;
    for (i = 0; i < 3; i++)
    {
        if (i == randomDoor)
        {
            doors[i] = 1;
        }
        else
        {
            doors[i] = 0;
        }
    }
    return doors;
}

//Change your decision after an empty door is revealed
int changeChoiceAfterReveal()
{
    int* doors;
    doors = buildDoors();
    //printf("random door array: %i, %i, %i\n", *(doors+0), *(doors+1), *(doors+2));
    
    //get random selection
    //srand((unsigned)time(NULL));
    int choice = rand()%3;
    //printf("door choice: %i\n", choice);
    
    //reveal door
    int i;
    int revealedDoor = -1;
    for(i = 0; i < 3; i++)
    {
        if(i != choice && *(doors+i) != 1)
        {
            revealedDoor = i;
            break;
        }
    }
    //printf("Revealed Door: %i\n", revealedDoor);
    
    //switch choice after reveal
    for(i = 0; i < 3; i++)
    {
        if(i != revealedDoor && i != choice)
        {
            choice = i;
            break;
        }
    }
    //printf("Choice changed to: %i\n", choice);
    
    //printf("The choice is: %i\n", *(doors+choice));
    if(*(doors+choice) == 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

//Make no change in your decision after a single an empty door is revealed
int dontChangeChoiceAfterReveal()
{
    int* doors;
    doors = buildDoors();
    //printf("random door array: %i, %i, %i\n", *(doors+0), *(doors+1), *(doors+2));
    
    //get random selection
    //srand((unsigned)time(NULL));
    int choice = rand()%3;
    //printf("door choice: %i\n", choice);
    
    //reveal door
    int i;
    int revealedDoor = -1;
    for(i = 0; i < 3; i++)
    {
        if(i != choice && *(doors+i) != 1)
        {
            revealedDoor = i;
            break;
        }
    }
    //printf("Revealed Door: %i\n", revealedDoor);
    
    //printf("The choice is: %i\n", *(doors+choice));
    if(*(doors+choice) == 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int main(int argc, const char * argv[])
{
    long count = 1000000000L;
    if(argc > 1)
    {
       count = atol(argv[1]);
       if(count < 100)
       {
	 printf("You have chosen less than the minimum of 100.\n");
	 printf("The minimum has been set!\n");
	 count = 100L;
       }
    }
    time_t rawtime;
    struct tm * timeinfo;
    time ( &rawtime );
    timeinfo = localtime ( &rawtime );
    //seed rand
    srand((unsigned)time(NULL));
    
    //the number of times to run the test
    //long count = 1000000000L;
    long i;
    long change = 0L;
    //int noChange = 0;
    printf("Running the test %ld times\n", count);
    printf ( "Start time: %s", asctime (timeinfo) );
    long modNum = count/100;
    int percent = 0;
    for(i = 0; i < count; i++)
    {
        if(i%modNum == 0)
        {
	  printf("%d%% Complete\n", percent);
	  percent++;
        }
        change = change + changeChoiceAfterReveal();
        //noChange = noChange + dontChangeChoiceAfterReveal();;
    }
    float ratioChange = change/(float)count;
    //float ratioNoChange = noChange/(float)count;
    
    time ( &rawtime );
    timeinfo = localtime ( &rawtime );
    printf ( "End time: %s", asctime (timeinfo) );
    printf("Change door after reveal: %f\n", ratioChange);
    //printf("Keep same door after reveal: %f\n", ratioNoChange);
    return 0;
}
