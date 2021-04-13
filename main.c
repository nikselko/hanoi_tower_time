/******************************************************************************
*                                                                             *
*   Program : Hanoi Tower time-complexity                                     *
*                                                                             *
*   Date : 13 / 04 / 2021                                                     *
*                                                                             *
*   Programmer : Nikita Seliverstov (nikselko)                                *
*                                                                             *
*                                                                             *
******************************************************************************/

#include <stdio.h>

float towerOfHanoi(unsigned int n, float time_counter, float movement_time)  // Hanoi Tower (int: Amount of disks, float: Amount of time spent, float: increment value in seconds)
{
    time_counter = time_counter + movement_time;                             // Incrementing

    if (n == 0)
    {
        return time_counter;                                                 // Last iteration returns amount of time spent
    }
    else
        return 2 * towerOfHanoi(n - 1, time_counter, movement_time);         // Complexity ~ F(n) = 2F(n-1) + 1
}

int main()
{
    const float universe_age = 13.8;                                         // Lets asume that's aproximate universe existing time
    unsigned int number_disks = 0;                                           // Amount of golden disks
    float movement_duration = 1;                                             // In seconds (for example: 1 move = 1 sec)

    printf("-Enter number of golden disks:\n->");                            // User input
    scanf ("%d", &number_disks);


    float seconds = towerOfHanoi(number_disks, 0, movement_duration);        // Getting time spent in seconds
    float billions_years = seconds / 3600 / 24 / 365 / 1e9;                  // Convertation to billions

    printf("\n-It will take %.1f billion years to move %d disks.\n", billions_years, number_disks);
    printf("\n-Fun fact! To finish all movements our universe should be older in %.1f times!\n", billions_years / universe_age);

    return 0;
}
