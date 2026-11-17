#include <stdio.h>

#define RATE_PER_PAGE 3.50
#define MAX_PAGES 1000
#define MAX_COPIES 100

/* global variables */
int g_job_id = 0, g_pages, g_copies, g_is_duplex, g_is_urgent, g_urgent_waiting,
    g_regular_waiting;
double total_revenue;

/* prototypes */
void show_banner(void);
void show_menu(void);
void show_unavailable(void);

int validate_range(int min, int max);
void read_print_job(void);

int get_pages_per_copy(int pages, int is_duplex);
int get_total_pages(int pages_per_copy, int copies);
double get_estimated_cost(int total_pages);
int get_queue_position(int is_urgent);

void accept_print_job(void);
void process_next_job(void);

void display_job_token(int job_id, int pages, int copies, int is_duplex,
                       int is_urgent, int pages_per_copy, int total_pages,
                       double estimated_cost, int queue_position);
void display_report(int job_id, double total_revenue, int urgent_waiting,
                    int regular_waiting);

int main(void) {
    int choice;

    show_banner();
    do {
        show_menu();
        choice = validate_range(0, 6);

        switch (choice) {
            case 1:
                accept_print_job();
                break;
            case 3:
                process_next_job();
                break;
            case 5:
                display_report(g_job_id, total_revenue, g_urgent_waiting, g_regular_waiting);
                break;
            case 2:
            case 4:
            case 6:
                show_unavailable();
                break;
        }
    } while (choice != 0);

    return 0;
}

void show_banner(void) {
    printf("+================================================+\n");
    printf("\tCampus Print & Copy Hub System\n");
    printf("\tCSE115.6L - Team 5\n");
    printf("\tNorth South University\n");
    printf("+================================================+\n");
}

void show_menu(void) {
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
    printf("  Choose an option >> ");
}

void show_unavailable(void) {
    printf("\n  Unfortunately this option is not available in Version 4.\n");
}

int validate_range(int min, int max) {
    int n;

    scanf("%d", &n);
    while (n < min || n > max) {
        printf("  Invalid input. Enter a number from %d to %d. >> ", min, max);
        scanf("%d", &n);
    }

    return n;
}

void read_print_job(void) {
    printf("\n+================================================+\n");
    printf("\tNew Print Job Entry\n");
    printf("+================================================+\n");

    g_job_id++;
    printf("  Enter number of pages >> ");
    g_pages = validate_range(1, MAX_PAGES);
    printf("  Enter number of copies >> ");
    g_copies = validate_range(1, MAX_COPIES);
    printf("  Print mode (1 - Duplex, 0 - Simplex) >> ");
    g_is_duplex = validate_range(0, 1);
    printf("  Urgent? (1 - Yes, 0 - No) >> ");
    g_is_urgent = validate_range(0, 1);
}

int get_pages_per_copy(int pages, int is_duplex) {
    if (is_duplex)
        return (pages + 1) / 2;
    return pages;
}

int get_total_pages(int pages_per_copy, int copies) {
    return pages_per_copy * copies;
}

double get_estimated_cost(int total_pages) {
    return total_pages * RATE_PER_PAGE;
}

int get_queue_position(int is_urgent) {
    if (is_urgent) {
        g_urgent_waiting++;
        return g_urgent_waiting;
    }
    g_regular_waiting++;
    return g_urgent_waiting + g_regular_waiting;
}

void accept_print_job(void) {
    int pages_per_copy, total_pages, queue_position;
    double estimated_cost;

    read_print_job();
    pages_per_copy = get_pages_per_copy(g_pages, g_is_duplex);
    total_pages = get_total_pages(pages_per_copy, g_copies);
    estimated_cost = get_estimated_cost(total_pages);
    queue_position = get_queue_position(g_is_urgent);

    total_revenue += estimated_cost;

    display_job_token(g_job_id, g_pages, g_copies, g_is_duplex, g_is_urgent,
                      pages_per_copy, total_pages, estimated_cost,
                      queue_position);
}

void process_next_job(void) {
    if (g_urgent_waiting > 0) {
        g_urgent_waiting--;
        printf("\n  Completed the next urgent job.\n");
    } else if (g_regular_waiting > 0) {
        g_regular_waiting--;
        printf("\n  Completed the next regular job.\n");
    } else {
        printf("\n  The queue is empty.\n");
    }
}

void display_job_token(int job_id, int pages, int copies, int is_duplex,
                       int is_urgent, int pages_per_copy, int total_pages,
                       double estimated_cost, int queue_position) {
    printf("\n+================================================+\n");
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
}

void display_report(int job_id, double total_revenue, int urgent_waiting,
                    int regular_waiting) {
    printf("\n+================================================+\n");
    printf("\tDaily Report\n");
    printf("+================================================+\n");
    printf("  Jobs accepted\t\t: %d\n", job_id);
    printf("  Total revenue\t\t: BDT %.2f\n", total_revenue);
    printf("  Urgent waiting\t: %d\n", urgent_waiting);
    printf("  Regular waiting\t: %d\n", regular_waiting);
    printf("+================================================+\n");
}
