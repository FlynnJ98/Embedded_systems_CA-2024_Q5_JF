#include "mbed.h"
#include <cstdio>

InterruptIn buttn(PC_13);

volatile int myflag = 0;

// pointer to store the object type buttn_fall
void buttn_fall(){
    myflag = 1;
}

// main() runs in its own thread in the OS
int main()
{
// counter starts at 0
    int counter = 0;
// Prints the statement on screen when the programe starts
    printf("This Programe counts the amount of times the button has been pressed & prints the total on screen\r\n");
    buttn.fall(&buttn_fall);

// while loop 
    while (true) {
// if statement saying if myflag is 1 == 1, print the statement.
        if(myflag == 1){
// print the total on the screen. increment the count by one with each press. 
            printf("Button Has been pressed. Total Number of presses is %d times!\r\n", counter++);
// resets so the statement isnt constantly printing without pressing the button
            myflag = 0;
        }
    }
}