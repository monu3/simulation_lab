#include <stdio.h>

// Function prototypes
double mean(int arr[], int n);
void autocorrelation(int arr[], int n, double acf[], int maxLag);

int main()
{
    int n, maxLag;

    printf("Enter the length of the sequence: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter the sequence of integers:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("Enter the maximum lag: ");
    scanf("%d", &maxLag);

    if (maxLag >= n)
    {
        printf("Maximum lag should be less than the length of the sequence.\n");
        return 1;
    }

    double acf[maxLag + 1];
    autocorrelation(arr, n, acf, maxLag);

    printf("Autocorrelation function values:\n");
    for (int lag = 0; lag <= maxLag; lag++)
    {
        printf("Lag %d: %.5f\n", lag, acf[lag]);
    }

    return 0;
}

double mean(int arr[], int n)
{
    double sum = 0.0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
    }
    return sum / n;
}

void autocorrelation(int arr[], int n, double acf[], int maxLag)
{
    double arrMean = mean(arr, n);

    for (int lag = 0; lag <= maxLag; lag++)
    {
        double numerator = 0.0;
        double denominator = 0.0;

        for (int i = 0; i < n - lag; i++)
        {
            numerator += (arr[i] - arrMean) * (arr[i + lag] - arrMean);
        }

        for (int i = 0; i < n; i++)
        {
            denominator += (arr[i] - arrMean) * (arr[i] - arrMean);
        }

        acf[lag] = numerator / denominator;
    }
}
