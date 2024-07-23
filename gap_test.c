#include <stdio.h>

void performGapTest(int arr[], int n, int target);

int main()
{
    int n, target;

    // Get the size of the array
    printf("Enter the number of elements in the sequence: ");
    scanf("%d", &n);

    int arr[n];

    // Input the sequence of numbers
    printf("Enter the sequence of integers:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    // Get the target number for gap test
    printf("Enter the target number for the gap test: ");
    scanf("%d", &target);

    // Perform the gap test
    performGapTest(arr, n, target);

    return 0;
}

void performGapTest(int arr[], int n, int target)
{
    int gap = -1;
    int totalGaps = 0;
    double meanGap = 0;

    // Iterate through the array to find gaps
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == target)
        {
            if (gap != -1)
            { // Check if it is not the first time the target is found
                printf("Gap: %d\n", gap);
                meanGap += gap;
                totalGaps++;
            }
            gap = 0; // Reset gap count after finding target
        }
        else if (gap != -1)
        {
            gap++; // Increment gap if we are in a gap
        }
    }

    // Calculate and display the mean gap length
    if (totalGaps > 0)
    {
        meanGap /= totalGaps;
        printf("Average gap length: %.2f\n", meanGap);
    }
    else
    {
        printf("Target number %d did not appear more than once.\n", target);
    }
}
