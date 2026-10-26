#include <stdio.h>

int main(void) {
    /* Banner */
    printf("+================================================+\n");
    printf("|         Campus Print & Copy Hub System         |\n");
    printf("|               CSE115.6L - Team 5               |\n");
    printf("|             North South University             |\n");
    printf("+================================================+\n");

    /* Menu */
    printf("\n+------------------------------------------------+\n");
    printf("|                      MENU                      |\n");
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

    /* Specimen job record */
    printf("\n\n+================================================+\n");
    printf("|               Specimen Job Token               |\n");
    printf("+================================================+\n");
    printf("  Job ID\t\t: 101\n");
    printf("  Customer name\t\t: Ruddra Hassan\n");
    printf("  Document pages\t: 13\n");
    printf("  Number of copies\t: 3\n");
    printf("  Print mode\t\t: Duplex\n");
    printf("  Priority status\t: Regular\n");
    printf("+------------------------------------------------+\n");
    /* Pages per copy = (document pages + 1) / 2; the remainder is dropped. */
    printf("  Pages per copy\t: 7\n");
    /* Total pages = pages per copy * number of copies */
    printf("  Total pages\t\t: 21\n");
    /* Estimated cost = total pages * rate per page */
    printf("  Estimated cost\t: BDT 73.50\n");
    printf("  Position in queue\t: 3\n");
    printf("+================================================+\n");

    return 0;
}
