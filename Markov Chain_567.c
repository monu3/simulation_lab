#include <stdio.h>

// Function prototypes
void weatherProblem();
void healthMonitoringProblem();
void stockMarketProblem();

int main()
{
    int choice;

    printf("Choose the problem to solve:\n");
    printf("1. Weather Problem\n");
    printf("2. Health Monitoring Problem\n");
    printf("3. Stock Market Problem\n");
    printf("Enter your choice (1-3): ");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
        weatherProblem();
        break;
    case 2:
        healthMonitoringProblem();
        break;
    case 3:
        stockMarketProblem();
        break;
    default:
        printf("Invalid choice. Please run the program again and choose a valid option.\n");
    }

    return 0;
}

void weatherProblem()
{
    double rainToday, rainTomorrow, noRainTomorrow;
    double noRainToday, rainAfterTomorrow, noRainAfterTomorrow;

    printf("Enter the probability of rain tomorrow if it is raining today (in percentage): ");
    scanf("%lf", &rainTomorrow);
    printf("Enter the probability of no rain tomorrow if it is raining today (in percentage): ");
    scanf("%lf", &noRainTomorrow);
    printf("Enter the probability of rain tomorrow if it is not raining today (in percentage): ");
    scanf("%lf", &rainToday);
    printf("Enter the probability of no rain tomorrow if it is not raining today (in percentage): ");
    scanf("%lf", &noRainToday);

    rainTomorrow /= 100;
    noRainTomorrow /= 100;
    rainToday /= 100;
    noRainToday /= 100;

    rainAfterTomorrow = (rainToday * rainTomorrow) + (noRainToday * rainToday);
    noRainAfterTomorrow = (rainToday * noRainTomorrow) + (noRainToday * noRainToday);

    printf("The probability of no rain the day after tomorrow if it is not raining today is: %.2f%%\n", noRainAfterTomorrow * 100);
}

void healthMonitoringProblem()
{
    double healthyTomorrow, sickTomorrow, healthyDayAfter, sickDayAfter;

    printf("Enter the probability of being healthy tomorrow if healthy today (in percentage): ");
    scanf("%lf", &healthyTomorrow);
    printf("Enter the probability of being sick tomorrow if healthy today (in percentage): ");
    scanf("%lf", &sickTomorrow);
    printf("Enter the probability of being healthy tomorrow if sick today (in percentage): ");
    scanf("%lf", &healthyDayAfter);
    printf("Enter the probability of being sick tomorrow if sick today (in percentage): ");
    scanf("%lf", &sickDayAfter);

    healthyTomorrow /= 100;
    sickTomorrow /= 100;
    healthyDayAfter /= 100;
    sickDayAfter /= 100;

    double probSickDayAfter = (sickDayAfter * sickDayAfter) + (healthyDayAfter * sickTomorrow);

    printf("The probability of being sick the day after tomorrow if sick today is: %.2f%%\n", probSickDayAfter * 100);
}

void stockMarketProblem()
{
    double upTomorrow, downTomorrow, upDayAfter, downDayAfter;

    printf("Enter the probability of market up tomorrow if market up today (in percentage): ");
    scanf("%lf", &upTomorrow);
    printf("Enter the probability of market down tomorrow if market up today (in percentage): ");
    scanf("%lf", &downTomorrow);
    printf("Enter the probability of market up tomorrow if market down today (in percentage): ");
    scanf("%lf", &upDayAfter);
    printf("Enter the probability of market down tomorrow if market down today (in percentage): ");
    scanf("%lf", &downDayAfter);

    upTomorrow /= 100;
    downTomorrow /= 100;
    upDayAfter /= 100;
    downDayAfter /= 100;

    double probDownDayAfter = (downDayAfter * downDayAfter) + (upDayAfter * downTomorrow);

    printf("The probability of market down the day after tomorrow if market is down today is: %.2f%%\n", probDownDayAfter * 100);
}
