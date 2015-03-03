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



int* buildDoors()
{
    //set the seed
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
    srand((unsigned)time(NULL));
    
    int count = 1000000;
    int i;
    int change = 0;
    int noChange = 0;
    printf("Running the test %i times", count);
    for(i = 0; i < count; i++)
    {
        change = change + changeChoiceAfterReveal();
        noChange = noChange + dontChangeChoiceAfterReveal();;
    }
    float ratioChange = change/(float)count;
    float ratioNoChange = noChange/(float)count;
    printf("Change door after reveal: %f\n", ratioChange);
    printf("Keep same door after reveal: %f\n", ratioNoChange);
    return 0;
}