// quiestion 2

#include <stdio.h>

int main()
{
    // Variables
    float arrival_rate = 1.0;         // customers per minute
    float service_time = 20.0 / 60.0; // service time in minutes
    float walk_time = 1.5;            // time to reach the correct seat in minutes
    float game_start_time = 120.0;    // game start time in minutes
    float total_time = 0.0;           // total time spent by a sports fan

    // Calculation of total time spent by a sports fan
    float time_to_purchase_ticket = 1.0 / arrival_rate * service_time;
    total_time = time_to_purchase_ticket + walk_time;

    printf("Total time spent by a sports fan to be seated: %.2f minutes\n", total_time);

    // Check if the fan can be seated for the kick-off
    if (game_start_time - total_time >= 0)
    {
        printf("The sports fan can expect to be seated for the kick-off.\n");
    }
    else
    {
        printf("The sports fan cannot expect to be seated for the kick-off.\n");
    }

    return 0;
}
