#include <stdio.h>

#define RATE_PER_PAGE 3.50

int main(void) {
    int job_id = 0, pages, copies, is_duplex, is_urgent;
    int pages_per_copy, total_pages, queue_position;
    double estimated_cost;

    printf("+================================================+\n");
    printf("\tCampus Print & Copy Hub System\n");
    printf("\tCSE115.6L - Team 5\n");
    printf("\tNorth South University\n");
    printf("+================================================+\n");

    printf("\n+------------------------------------------------+\n");
    printf("\tMENU\n");
    printf("+------------------------------------------------+\n");
    printf("  [1] Accept new print job\n");
    printf("  [2] Display current queue\n");
    printf("  [3] Process & complete next print job\n");
    printf("  [4] Search job by customer\n");
    printf("  [5] Generate daily revenue & task report\n");
    printf("  [6] Save & load data\n");
    printf("  [0] Exit\n");
    printf("+------------------------------------------------+\n");
    printf("  Choose an option >> 1");

    printf("\n\n+================================================+\n");
    printf("\tNew Print Job Entry\n");
    printf("+================================================+\n");

    job_id = job_id + 1;
    printf("  Enter number of pages >> ");
    scanf("%d", &pages);
    printf("  Enter number of copies >> ");
    scanf("%d", &copies);
    printf("  Print mode (1 - Duplex, 0 - Simplex) >> ");
    scanf("%d", &is_duplex);
    printf("  Urgent? (1 - Yes, 0 - No) >> ");
    scanf("%d", &is_urgent);

    pages_per_copy = is_duplex * ((pages + 1) / 2) + (1 - is_duplex) * pages;
    total_pages = pages_per_copy * copies;
    estimated_cost = total_pages * RATE_PER_PAGE;
    queue_position = is_urgent * job_id + (1 - is_urgent) * (job_id + 1);

    printf("\n\n+================================================+\n");
    printf("\tJob Token\n");
    printf("+================================================+\n");
    printf("  Job ID\t\t: %d\n", job_id);
    printf("  Document pages\t: %d\n", pages);
    printf("  Number of copies\t: %d\n", copies);
    printf("  Duplex flag\t\t: %d\n", is_duplex);
    printf("  Urgent flag\t\t: %d\n", is_urgent);
    printf("+------------------------------------------------+\n");
    printf("  Pages per copy\t: %d\n", pages_per_copy);
    printf("  Total pages\t\t: %d\n", total_pages);
    printf("  Estimated cost\t: BDT %.2f\n", estimated_cost);
    printf("  Position in queue\t: %d\n", queue_position);
    printf("+================================================+\n");

    return 0;
}
