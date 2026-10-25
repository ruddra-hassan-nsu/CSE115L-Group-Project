#include <stdio.h>
#define RATE_PER_SHEET 4.00

/* global variables */
int g_taskNum = 0, g_pages, g_copies, g_duplex, g_urgent;

void banner(void);
void menu(void);
void read_job(void);
int sheets_per_copy(int pages, int duplex);
double total_cost(int totalSheets);
void print_job(int perCopy);

int main(void)
{
    banner();
    menu();
    read_job();
    print_job(sheets_per_copy(g_pages, g_duplex));
    return 0;
}

/* ==== OWNER: Member 1 | banner | status: TODO ==== */
void banner(void)
{
    printf("*=========================================*\n");
    printf("\tCampus Print & Copy Hub System\n");
    printf("\tCSE115.6L - Team 5\n");
    printf("\tNorth South University\n");
    printf("*=========================================*\n\n");
}

/* ==== OWNER: Member 1 | menu | status: TODO ==== */
void menu(void)
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

/* ==== OWNER: Member 4 | read_job | status: TODO ==== */
void read_job(void)
{
    /* TODO: g_taskNum = g_taskNum + 1; scanf the four fields into g_* */
}

/* ==== OWNER: Member 3 | sheets_per_copy | status: TODO ==== */
int sheets_per_copy(int pages, int duplex)
{
    /* TODO: same expression as v2, using the parameters, no globals */
    return 0;
}

/* ==== OWNER: Member 3 | total_cost | status: TODO ==== */
double total_cost(int totalSheets)
{
    /* TODO: return totalSheets * RATE_PER_SHEET */
    return 0.0;
}

/* ==== OWNER: Member 2 | print_job | status: TODO ==== */
void print_job(int perCopy)
{
    /* TODO: totalSheets = perCopy * g_copies; cost = total_cost(totalSheets);
       print the task token like v2 */
}
