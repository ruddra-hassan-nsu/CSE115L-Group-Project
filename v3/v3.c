#include <stdio.h>
#define RATE_PER_SHEET 4.00

/* global variables */
int g_task_num = 0, g_pages, g_copies, g_duplex, g_urgent;

void show_banner(void);
void show_menu(void);
void read_job(void);
int calc_sheets_per_copy(int pages, int duplex);
int calc_total_sheets(int sheets_per_copy, int copies);
double calc_total_cost(int total_sheets);
void accept_job(void);

int main(void)
{
    show_banner();
    show_menu();
    accept_job();
    return 0;
}

void show_banner(void)
{
    printf("*=========================================*\n");
    printf("\tCampus Print & Copy Hub System\n");
    printf("\tCSE115.6L - Team 5\n");
    printf("\tNorth South University\n");
    printf("*=========================================*\n\n");
}

void show_menu(void)
{
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
}

void read_job(void)
{
    printf("*=========================================*\n");
    printf("\tNew Task Entry\n");
    printf("*=========================================*\n\n");

    g_task_num = g_task_num + 1;
    printf("Enter number of pages >> ");
    scanf("%d", &g_pages);
    printf("Enter number of copies >> ");
    scanf("%d", &g_copies);
    printf("Duplex print? (1-YES, 0-NO) >> ");
    scanf("%d", &g_duplex);
    printf("Urgent? (1-YES, 0-NO) >> ");
    scanf("%d", &g_urgent);
}

int calc_sheets_per_copy(int pages, int duplex)
{
    return duplex * ((pages + 1) / 2) + (1 - duplex) * pages;
}

int calc_total_sheets(int sheets_per_copy, int copies)
{
    return sheets_per_copy * copies;
}

double calc_total_cost(int total_sheets)
{
    return total_sheets * RATE_PER_SHEET;
}

int calc_queue_position(int task_number, int is_urgent)
{
    return is_urgent * (task_number) + (1 - is_urgent) * (task_number + 1);
}

void accept_job(void)
{
    read_job();
    int sheets_per_copy = calc_sheets_per_copy(g_pages, g_duplex);
    int total_sheets = calc_total_sheets(sheets_per_copy, g_copies);

    printf("\n*=========================================*\n");
    printf("\tTask Token\n");
    printf("*=========================================*\n");
    printf("\tTask number\t: %d\n", g_task_num);
    printf("\tDocument pages\t: %d\n", g_pages);
    printf("\tNumber of copies: %d\n", g_copies);
    printf("\tDuplex flag\t: %d\n", g_duplex);
    printf("\tUrgent flag\t: %d\n", g_urgent);
    printf("*=========================================*\n");
    printf("\tPages per copy\t: %d\n", sheets_per_copy);
    printf("\tTotal pages\t: %d\n", total_sheets);
    printf("\tTotal cost\t: BDT %.2f\n", calc_total_cost(total_sheets));
    printf("\tPos. in queue\t: %d\n", calc_queue_position(g_task_num, g_urgent));
}
