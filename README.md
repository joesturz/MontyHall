# MontyHall
A computaional simulation of the Monty Hall Problem in C: http://en.wikipedia.org/wiki/Monty_Hall_problem

This is a problem that many people would not believe the results of until computational simulation proved otherwise.

to compile:

$ gcc -o MontyHall main.c

to run:

$ ./MontyHall

The program defaults to 1 billion tries.This takes about a minute on modern processors to complete.
You can add an argument that will change the default number of tries.  The minimum is 100 tries.

To run with argument:

$ ./MonteHall 100

Console output shows:
Start time,
The percent complete
the probabilty of a correct guess if you change your choice, 
End time.
