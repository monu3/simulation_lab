// question 4

#include <stdio.h>
#include <math.h>

double poisson(int x, double lambda)
{
    return exp(-lambda) * pow(lambda, x) / tgamma(x + 1);
}

int main()
{
    double lambda = 12.0; // Average arrival rate of cars per hour
    printf("Poisson distribution for lambda = %.2f:\n", lambda);

    for (int x = 0; x <= 15; x++)
    {
        double probability = poisson(x, lambda);
        printf("P(X = %d) = %.6f\n", x, probability);
    }

    return 0;
}
