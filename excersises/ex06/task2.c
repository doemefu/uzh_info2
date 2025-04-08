#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/* Functions already implemented */
struct month *init_months(struct month *head);
void free_months(struct month *head);

/* given month struct */
struct month {
    int month_number;
    char *month_name;
    struct month *next;
};

void print_months(struct month *head) {
    /* Task 2.1 */
    //printf("Todo print months:\n");
    while(head != NULL){
        printf("%s (%i); ", head->month_name, head->month_number);
        head = head->next;
    }
}

struct month *get_previous_month(struct month *head, char *searchMonthName) {
    /* Task 2.2 */
    while(head->next != NULL){
        if (strcmp((*(*head).next).month_name, searchMonthName)==0) {
            printf("Preceding of %s is %s; ", searchMonthName, (*head).month_name);
            return head;
        }
        head = (*head).next;
    }
    printf("Nothing found");
    return NULL;
}

struct month *get_previous_month_struct(struct month *head, struct month *a) {
    /* Task 2.2 */
    struct month *prev = head;
    while(head->next != NULL || a != NULL){
        if ((*prev).next == a) {
            printf("Preceding of %s is %s; ", a->month_name, (*prev).month_name);
            return prev;
        }
        prev = (*prev).next;
    }
    printf("Nothing found");
    return NULL;
}

struct month *swap_month(struct month *head, struct month *a, struct month *b) {
    /* Task 2.3 */
    struct month *start = head;
    while (start->next != a && start!=a) {
        start = start->next;
    }
    struct month *tmp = a->next;
    a->next = b->next;
    if (start!=a) {
        start->next = b;
        b->next = tmp;
    }else {
        start = b;
        start->next = tmp;
        head=start;
    }

    start = tmp;

    while (start->next != b) {
        start = start->next;
    }
    start->next = a;

    return head;
}


struct month *selection_sort(struct month *head) {
    /* TODO: Implement task 2.4 */
    //struct month *start = head;
    printf("\n");
    //print_months(head);
    //printf("hmmm");

    struct month *start = head;
    int i =0;
    struct month *min;
    struct month *tmp;

    while (start->next != NULL) {
        printf("\n Run number %i: ", i++);
        print_months(head);

        min = start;
        tmp = start->next;

        while (tmp != NULL) {
            if (tmp->month_number < min->month_number) {
                min = tmp;
            }
            tmp = tmp->next;
        }
        head = swap_month(head,start, min);
        start = min->next;
    }

    return head;
}

int main(int argc, char *argv[]) {
    /* Init month linked list */
    struct month *head;
    head = init_months(head);
    /* Print the linked list as it is after initialization */
    print_months(head);

    printf("\nTask2.2: ");
    printf("return value: %s", get_previous_month(head, "July")->month_name);

    printf("\nTask2.3: ");
    struct month *x = head->next->next->next->next->next->next->next->next->next->next;
    struct month *y = head->next->next->next->next->next->next->next->next->next->next->next;
    head = swap_month(head, x,y);
    print_months(head);

    /* TODO: Task 2.4: Goal is to implement the selection sort algorithm */
    printf("\nSorting Task:");
    head = selection_sort(head);
    /* print_months(head); */

    /* Cleanup */
    free_months(head);
    return 0;
}

struct month *init_months(struct month *head) {
    int n = 12;
    int init_order[n];
    char *month_strings[] = {"January",   "February", "March",    "April",
                             "May",       "June",     "July",     "August",
                             "September", "Oktober",  "November", "Dezember"};
    struct month *h;
    struct month *p; /* trailing pointer */

    /* create random order with fisher-yates shuffle */
    for (int i = 0; i < n; ++i) {
        init_order[i] = i + 1;
    }
    srand(time(0));
    for (int i = n - 1; i > 0; --i) {
        int j = rand() % (i + 1); /* generate random index below i */
        /* swap a[i] with a[j] */
        int tmp = init_order[i];
        init_order[i] = init_order[j];
        init_order[j] = tmp;
    }

    /* create month linked list */
    h = malloc(sizeof(struct month)); /* first node, gets returned */
    h->month_number = init_order[0];  /*  */
    h->month_name = month_strings[h->month_number - 1];
    p = h; /* pointer that goes through list */
    for (int i = 1; i < n; ++i) {
        struct month *m = malloc(sizeof(struct month));
        /* printf("create month %d\n", i); */
        m->month_number = init_order[i];
        m->month_name = month_strings[m->month_number - 1];
        p->next = m; /* previous node points now to this */

        p = m; /* increment trailing pointer */
    }
    p->next = NULL;
    return h;
}

void free_months(struct month *head) {
    /* free month linked list */
    struct month *p = head;
    struct month *q = head->next;
    while (q) {
        free(p);
        p = q;
        q = q->next;
    }
    free(p);
}
