#include <stdio.h>

#define RATE_PER_PAGE 3.50
#define DOUBLE_LINE "+================================================+"
#define SINGLE_LINE "+------------------------------------------------+"

/* global variables */
int g_job_id = 0, g_pages, g_copies, g_is_duplex, g_is_urgent;

void show_banner(void);
void show_menu(void);
void accept_print_job(void);
void read_print_job(void);
int get_pages_per_copy(int pages, int is_duplex);
int get_total_pages(int pages_per_copy, int copies);
int get_queue_position(int job_id, int is_urgent);
double get_estimated_cost(int total_pages);
void display_job_token(int job_id, int pages, int copies, int is_duplex,
                       int is_urgent, int pages_per_copy, int total_pages,
                       double estimated_cost, int queue_position);

int main(void) {
    show_banner();
    show_menu();
    accept_print_job();
    return 0;
}

/* Banner */
void show_banner(void) {
    printf(DOUBLE_LINE "\n");
    printf("|         Campus Print & Copy Hub System         |\n");
    printf("|               CSE115.6L - Team 5               |\n");
    printf("|             North South University             |\n");
    printf(DOUBLE_LINE "\n");
}

void show_menu(void) {
    printf("\n" SINGLE_LINE "\n");
    printf("|                      MENU                      |\n");
    printf(SINGLE_LINE "\n");
    printf("  [1] Accept new print job\n");
    printf("  [2] Display current queue\n");
    printf("  [3] Process & complete next print job\n");
    printf("  [4] Search job by customer\n");
    printf("  [5] Generate daily revenue & task report\n");
    printf("  [6] Save & load data\n");
    printf("  [0] Exit\n");
    printf(SINGLE_LINE "\n");
    printf("  Choose an option >> 1");
}

void accept_print_job(void) {
    int pages_per_copy, total_pages, queue_position;
    double estimated_cost;

    read_print_job();

    pages_per_copy = get_pages_per_copy(g_pages, g_is_duplex);
    total_pages = get_total_pages(pages_per_copy, g_copies);
    estimated_cost = get_estimated_cost(total_pages);
    queue_position = get_queue_position(g_is_urgent, g_job_id);

    display_job_token(g_job_id, g_pages, g_copies, g_is_duplex, g_is_urgent,
                      pages_per_copy, total_pages, estimated_cost,
                      queue_position);
}

void read_print_job(void) {
    printf("\n\n" DOUBLE_LINE "\n");
    printf("|              New Print Job Entry               |\n");
    printf(DOUBLE_LINE "\n");

    g_job_id = g_job_id + 1;
    printf("  Enter number of pages >> ");
    scanf("%d", &g_pages);
    printf("  Enter number of copies >> ");
    scanf("%d", &g_copies);
    printf("  Print mode (1 - Duplex, 0 - Simplex) >> ");
    scanf("%d", &g_is_duplex);
    printf("  Urgent? (1 - Yes, 0 - No) >> ");
    scanf("%d", &g_is_urgent);
}

int get_pages_per_copy(int pages, int is_duplex) {
    return is_duplex * ((pages + 1) / 2) + (1 - is_duplex) * pages;
}

int get_total_pages(int pages_per_copy, int copies) {
    return pages_per_copy * copies;
}

int get_queue_position(int is_urgent, int job_id) {
    return is_urgent * job_id + (1 - is_urgent) * (job_id + 1);
}

double get_estimated_cost(int total_pages) {
    return total_pages * RATE_PER_PAGE;
}

void display_job_token(int job_id, int pages, int copies, int is_duplex,
                       int is_urgent, int pages_per_copy, int total_pages,
                       double estimated_cost, int queue_position) {
    printf("\n\n" DOUBLE_LINE "\n");
    printf("|                   Job Token                    |\n");
    printf(DOUBLE_LINE "\n");
    printf("  Job ID\t\t: %d\n", job_id);
    printf("  Document pages\t: %d\n", pages);
    printf("  Number of copies\t: %d\n", copies);
    printf("  Duplex flag\t\t: %d\n", is_duplex);
    printf("  Urgent flag\t\t: %d\n", is_urgent);
    printf(SINGLE_LINE "\n");
    printf("  Pages per copy\t: %d\n", pages_per_copy);
    printf("  Total pages\t\t: %d\n", total_pages);
    printf("  Estimated cost\t: BDT %.2f\n", estimated_cost);
    printf("  Position in queue\t: %d\n", queue_position);
    printf(DOUBLE_LINE "\n");
}
