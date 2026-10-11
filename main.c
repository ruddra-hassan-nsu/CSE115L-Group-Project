#include <stdio.h>
#define RATE_PER_PAGE 4.00

int main(void)
{
    int taskNum = 0, numPages, numCopies, isDuplex, isUrgent;

    printf("*=========================================*\n");
    printf("\tCampus Print & Copy Hub System\n");
    printf("\tCSE115.6L - Team 5\n");
    printf("\tNorth South University\n");
    printf("*=========================================*\n\n");
    printf("\t[1] Accept new print task\n");
    printf("\t[2] Display current queue\n");
    printf("\t[3] Process & complete next print task\n");
    printf("\t[4] Search task by customer\n");
    printf("\t[5] Generate daily revenue & task report\n");
    printf("\t[6] Save & load data\n");
    printf("\t[0] Exit\n\n");
    printf("*=========================================*\n");
    printf("\tChoose an option to continue\n");
    printf("*=========================================*\n\n");

    printf("*=========================================*\n");
    printf("\tNew Task Entry\n");
    printf("*=========================================*\n\n");

    taskNum = taskNum + 1;
    printf("Enter number of pages >> ");
    scanf("%d", &numPages);
    printf("Enter number of copies >> ");
    scanf("%d", &numCopies);
    printf("Duplex print? (1-YES, 0-NO) >> ");
    scanf("%d", &isDuplex);
    printf("Urgent? (1-YES, 0-NO) >> ");
    scanf("%d", &isUrgent);

    int sheetsPerCopy = isDuplex * ((numPages + 1) / 2) + (1 - isDuplex) * numPages;
    int totalSheets = sheetsPerCopy * numCopies;
    double totalCost = totalSheets * RATE_PER_PAGE;
    int queuePosition = isUrgent * taskNum + (1 - isUrgent) * (taskNum + 1); // innacurate, only placeholder

    printf("\n*=========================================*\n");
    printf("\tTask Token\n");
    printf("*=========================================*\n");
    printf("\tTask number\t: %d\n", taskNum);
    printf("\tDocument pages\t: %d\n", numPages);
    printf("\tNumber of copies: %d\n", numCopies);
    printf("\tDuplex flag\t: %d\n", isDuplex);
    printf("\tUrgent flag\t: %d\n", isUrgent);
    printf("*=========================================*\n");
    printf("\tPages per copy\t: %d\n", sheetsPerCopy);
    printf("\tTotal pages\t: %d\n", totalSheets);
    printf("\tTotal cost\t: BDT %.2f\n", totalCost);
    printf("\tPos. in queue\t: %d\n", queuePosition);

    return 0;
}
