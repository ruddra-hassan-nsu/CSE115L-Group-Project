#include <stdio.h>
#define RATE_PER_PAGE 4.00

int main(void)
{
    int taskNum = 0, numPages, numCopies, isDuplex, isUrgent;

    // Header
    printf("+================================================+\n");
    printf("|         Campus Print & Copy Hub System         |\n");
    printf("|               CSE115.6L - Team 5               |\n");
    printf("|             North South University             |\n");
    printf("+================================================+\n\n");

    // Selection Menu
    printf("  [1] Accept new print task\n");
    printf("  [2] Display current queue\n");
    printf("  [3] Process & complete next print task\n");
    printf("  [4] Search task by customer\n");
    printf("  [5] Generate daily revenue & task report\n");
    printf("  [6] Save & load data\n");
    printf("  [0] Exit\n\n");

    // Footer
    printf("+------------------------------------------------+\n");
    printf("|  Choose an option to continue                  |\n");
    printf("+------------------------------------------------+\n\n");

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

    // Specimen task record
    printf("+================================================+\n");
    printf("|               Task Token              |\n");
    printf("+================================================+\n\n");
    printf("Task number\t: %d\n", taskNum);
    printf("Document pages\t: %d\n", numPages);
    printf("Number of copies: %d\n", numCopies);
    printf("Duplex flag\t: %d\n", isDuplex);
    printf("Urgent flag\t: %d\n", isUrgent);
    printf("--------------------------------------------------\n");
    printf("Pages per copy\t: %d\n", sheetsPerCopy);
    printf("Total pages\t: %d\n", totalSheets);
    printf("Total cost\t: BDT %.2f\n", totalCost);
    printf("Pos. in queue\t: %d\n", queuePosition);
    printf("--------------------------------------------------\n");

    return 0;
}
