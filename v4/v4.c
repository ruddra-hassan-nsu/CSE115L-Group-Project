#include <stdio.h>

#define RATE_PER_PAGE 3.50
#define MAX_PAGES 1000
#define MAX_COPIES 100
#define DOUBLE_LINE "+================================================+"
#define SINGLE_LINE "+------------------------------------------------+"

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
int get_queue_position(int job_id, int is_urgent);

void accept_print_job(void);
void process_next_job(void);

void display_job_token(int job_id, int pages, int copies, int is_duplex,
                       int is_urgent, int pages_per_copy, int total_pages,
                       double estimated_cost, int queue_position);
void display_report(int job_id, double total_revenue, int urgent_waiting,
                    int regular_waiting);

/* Ruddra's Task -- menu loop */
int main(void) {
    /*
     * Start writing your code from here.
     * Status: TODO
     */

    return 0;
}

/* Ehsan's Task -- banner, menu, placeholder */
void show_banner(void) {
    /*
     * Start writing your code from here.
     * Status: TODO
     */
}

void show_menu(void) {
    /*
     * Start writing your code from here.
     * Status: TODO
     */
}

void show_unavailable(void) {
    /*
     * Start writing your code from here.
     * Status: TODO
     */
}

/* Ruddra's Task -- input and validation */
int validate_range(int min, int max) {
    /*
     * Start writing your code from here.
     * Status: TODO
     */

    return 0;
}

void read_print_job(void) {
    /*
     * Start writing your code from here.
     * Status: TODO
     */
}

/* Iftekhar's Task -- calculations and accept print job */
int get_pages_per_copy(int pages, int is_duplex) {
    /*
     * Start writing your code from here.
     * Status: TODO
     */

    return 0;
}

int get_total_pages(int pages_per_copy, int copies) {
    /*
     * Start writing your code from here.
     * Status: TODO
     */

    return 0;
}

double get_estimated_cost(int total_pages) {
    /*
     * Start writing your code from here.
     * Status: TODO
     */

    return 0;
}

int get_queue_position(int is_urgent, int job_id) {
    /*
     * Start writing your code from here.
     * Status: TODO
     */

    return 0;
}

/* Ruddra's Task -- accept_print_job and process next job */

void accept_print_job(void) {
    /*
     * Start writing your code from here.
     * Status: TODO
     */
}

void process_next_job(void) {
    /*
     * Start writing your code from here.
     * Status: TODO
     */
}

/* Khaled's Task -- display print token, display report */

void display_print_token(int job_id, int pages, int copies, int is_duplex,
                         int is_urgent, int pages_per_copy, int total_pages,
                         double estimated_cost, int queue_position) {
    /*
     * Start writing your code from here.
     * Status: TODO
     */
}

void display_report(int job_id, double total_revenue, int urgent_waiting,
                    int regular_waiting) {
    /*
     * Start writing your code from here.
     * Status: TODO
     */
}
