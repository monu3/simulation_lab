#include <stdio.h>
#include <math.h>

double factorial(int n)
{
    if (n == 0 || n == 1)
        return 1;
    else
        return n * factorial(n - 1);
}

double poisson(double lambda, int k)
{
    return (exp(-lambda) * pow(lambda, k)) / factorial(k);
}

int main()
{
    double lambda = 1.0 / 10.0; // Arrival rate (customers per minute)
    double mu = 1.0 / 5.0;      // Service rate (customers per minute)

    // Probability that a customer will not have to wait at the counter
    double p0 = exp(-(lambda / mu));
    p0 = ceil(p0 * 1000) / 1000; // rounding up to three decimal places

    // Expected number of customers in the bank
    double L = (lambda * mu) / (mu - lambda);
    L = ceil(L);

    // Average time a customer spends in the bank
    double W = 1 / (mu - lambda);
    W = ceil(W);

    printf("Probability that a customer will not have to wait at the counter: %.2lf\n", p0);
    printf("Expected number of customers in the bank: %.2lf\n", L);
    printf("Average time a customer spends in the bank: %.2f minutes\n", W);

    return 0;
}
