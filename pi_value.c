// question 3

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define NUM_POINTS 1000000

double estimate_pi(int num_points)
{
    int points_inside_circle = 0;

    // Generate random points and check if they fall inside the unit circle
    for (int i = 0; i < num_points; i++)
    {
        double x = (double)rand() / RAND_MAX; // random x-coordinate between 0 and 1
        double y = (double)rand() / RAND_MAX; // random y-coordinate between 0 and 1

        // Check if the point is inside the unit circle
        if (x * x + y * y <= 1)
        {
            points_inside_circle++;
        }
    }

    // Estimate the value of pi
    return 4.0 * points_inside_circle / num_points;
}

int main()
{
    // Initialize random number generator with current time
    srand(time(NULL));

    // Estimate pi using Monte Carlo method
    double pi_estimate = estimate_pi(NUM_POINTS);

    // Print the result
    printf("Estimated value of pi using Monte Carlo method: %.6f\n", pi_estimate);

    return 0;
}
