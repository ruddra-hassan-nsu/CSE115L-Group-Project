#include <stdio.h>

int main(void)
{
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

  // Specimen task record
  printf("+================================================+\n");
  printf("|               Specimen Task Token              |\n");
  printf("+================================================+\n\n");
  printf("  Task number\t\t: 101\n");
  printf("  Customer name\t\t: Ruddra Hassan\n");
  printf("  Document pages\t: 13 page(s)\n");
  printf("  Number of copies\t: 3 set(s)\n");
  printf("  Print mode\t\t: Duplex, Coloured\n");
  printf("  Priority status\t: Regular\n\n");
  printf("--------------------------------------------------\n");
  printf("  Pages per copy\t: 7 page(s)\n");  // Uses the formula: ( number of document pages + 1 ) / 2; the remainder must be excluded.
  printf("  Total pages\t\t: 21 page(s)\n");  // Uses the formula: pages per copy * number of copies.
  printf("  Estimated price\t: BDT 84.00\n"); // Uses the formula: total pages * rate of page.
  printf("  Pos. in queue\t\t: 3\n");
  printf("--------------------------------------------------\n");

  return 0;
}
