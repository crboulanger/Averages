/*
 **Lesson 22 Assignment
 **Author:  Christopher Boulanger
 **Created: 14 October 2013
 **Function: This program computes the moving average for a stream of data points it is receiving.
 **Documentation: C2C Jason Mossing helped me with this assignment. He is responsible for helping me to understand
 **Documentation: formatting, syntax, pointers, and arrays in C. We worked together from 10 October-19 October.
 */
#include <msp430.h> 
#include "Averages_Header.h"

/*
 * main.c
 */
#define N_AVG_SAMPLES 4
//Number values in the data stream
#define SIZE 10

int main(void) {
    WDTCTL = WDTPW | WDTHOLD;        // Stop watchdog timer

    int MaxValue;
    int MinValue;
    int range;
    int numbers[] = {45, 42, 41, 40, 43, 45, 46, 47, 49, 45};
    int tempArray[N_AVG_SAMPLES];
    MaxValue = -256;//assures that any input value will be a max. Initializes maximum
    MinValue = 255;//initializes minimum
    int        i, x = 0;
    int average;
    //SIZE + 2 because 1 is for char, and 2 is for int
    int averages[SIZE+2];
    // initializes average to zero
    //x keeps track of i
    for(i = 0; i <= N_AVG_SAMPLES; i++){
            x = i;
            tempArray[i] = 0;
            i = x;
    }

    /*
     * computes the average for each set
     */
    for(i = 0; i <= SIZE + 1; i++){
            average = FindAverage(tempArray, N_AVG_SAMPLES);
            averages[i] = average;
           addSample(numbers[i],tempArray, N_AVG_SAMPLES);
    }

    /*
     * calculates max, min, and range of the set
     */
    MaxValue = maximum(numbers, MaxValue, SIZE);
    MinValue = minimum(numbers, MinValue, SIZE);
    range = FindRange(MaxValue, MinValue);

    //Traps CPU
    while(1){

    }

        return 0;
}
