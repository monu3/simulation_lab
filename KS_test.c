#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function prototypes
int compare(const void *a, const void *b);
double ks_test(double sample[], int n, double (*cdf)(double));

double uniform_cdf(double x);

int main()
{
    int n;

    printf("Enter the number of sample points: ");
    scanf("%d", &n);

    double sample[n];
    printf("Enter the sample points:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%lf", &sample[i]);
    }

    double D = ks_test(sample, n, uniform_cdf);
    printf("KS statistic D: %.5f\n", D);

    // Here we would compare D with critical values for the KS test
    // For simplicity, we omit the critical value comparison and p-value calculation

    return 0;
}

// Compare function for qsort
int compare(const void *a, const void *b)
{
    double x = *(double *)a;
    double y = *(double *)b;
    if (x < y)
        return -1;
    if (x > y)
        return 1;
    return 0;
}

// KS test function
double ks_test(double sample[], int n, double (*cdf)(double))
{
    // Sort the sample
    qsort(sample, n, sizeof(double), compare);

    // Compute the EDF and the CDF
    double D = 0.0;
    for (int i = 0; i < n; i++)
    {
        double F_empirical = (double)(i + 1) / n;
        double F_theoretical = cdf(sample[i]);
        double D_plus = F_empirical - F_theoretical;
        double D_minus = (i > 0 ? F_theoretical - (double)i / n : F_theoretical);
        if (D_plus > D)
            D = D_plus;
        if (D_minus > D)
            D = D_minus;
    }

    return D;
}

// Uniform CDF
double uniform_cdf(double x)
{
    if (x < 0.0)
        return 0.0;
    if (x > 1.0)
        return 1.0;
    return x;
}
