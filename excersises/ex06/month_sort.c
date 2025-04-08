#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* given month struct */
struct month {
    int month_number;
    char *month_name;
    struct month *next;
};

void print_months(struct month *head) {
    /* AHA: Understand while loop condition */
    printf("months: ");
    struct month *p = head;
    while (p != NULL) {
        printf("%s (%d), ", p->month_name, p->month_number);
        p = p->next;
    }
    printf("\n");
}

struct month *get_previous_month(struct month *head, struct month *a) {
    /* AHA: Understand trailing pointers */
    if (head == NULL || a == NULL) {
        return NULL;
    } else if (head->next == a) {
        return head;
    }

    struct month *p = head;

    while (p->next != a) {
        p = p->next;
    }
    return p;
}

struct month *swap_month(struct month *head, struct month *a, struct month *b) {

    /* printf("Swap %d with %d\n", a->month_number, b->month_number); */

    struct month *prev_a;
    struct month *prev_b;

    /* Since its incremental slection sort, it is not needed to check for
       head==b. We can always assume a comes before b in the order of the linked
       list. */
    if (a == b) {
        /* Trivial; nothing to do */
        return head;
    } else if (head == a) {
        /* Case: if a is head */
        /* AHA: prev_a does not work in this case, thus return first, or if
         * around
         */
        /* AHA: on head change, new head has to be returned and reassigned */

        if (a->next == b) {
            /* Subcase: if a and b are adjacent */
            /* AHA: this is also a subcase */
            a->next = b->next;
            b->next = a;
        } else {
            /* Subcase: a and b are not adjacent */
            /* These variables are needed in this case */
            /* temporary head next, because head gets reassigned */
            struct month *tmp_a_next = a->next;
            prev_b = get_previous_month(head, b); /* preceding of b */
            a->next = b->next;                    /* same as adjacent */
            b->next = tmp_a_next; /* AHA: cannot say head->next, because
                                     (head=a)->next gets reassigne */
            prev_b->next = a;     /* same as adjacent, but with prev_b */
        }
        head = b; /* for both subcases: reassigne head */
    }

    else if (a->next == b) {
        /* Case: a and b are adjacent */
        /* AHA: This is also a case to consider */

        prev_a = get_previous_month(head, a); /* get preceding of a */
        a->next = b->next;                    /* reasigne node pointers */
        b->next = a;
        prev_a->next = b;
    } else {
        /* otherwise */
        /* AHA: need to use tmp_a_next, instead of tmp_a at the beginning */

        /* temporary a next, because a gets reassigned */
        struct month *tmp_a_next = a->next;
        prev_a = get_previous_month(head, a); /* get preceding of a */
        prev_b = get_previous_month(head, b); /* and b */
        prev_a->next = b;                     /* use preceding of a */
        a->next = b->next;
        b->next = tmp_a_next;
        prev_b->next = a;
    }

    /* default return same head */
    return head;
}

struct month *selection_sort(struct month *head) {
    /* Implement the selection sort algorithm */
    /* AHA: k->next instead of i->next or tmp_i->next */

    struct month *i; /* traveling pointer outer loop */
    struct month *j; /* traveling pointer inner loop */
    struct month *k; /* temporary storage for min val in inner loop */

    i = head;
    while (i != NULL) { /* for i=1 to n-1 do */
        print_months(head);

        k = i; /* k=i */
        j = i->next;
        while (j != NULL) { /* for j=i+1 to n do  */
            if (j->month_number < k->month_number) {
                k = j; /* if A[j] < A[k] then k=j */
            }
            j = j->next; /* j++ */
        }
        head = swap_month(head, i, k); /* exchange A[i] and A[k]*/

        i = k->next; /* i++ */
    }

    /* because head might have changed */
    return head;
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
        /* printf("free %d\n", p->month_number); */
        free(p);
        p = q;
        q = q->next;
    }
    free(p);
}

int main(int argc, char *argv[]) {
    struct month *head;
    head = init_months(head);

    printf("Sorting:\n");
    print_months(head);

    /* sort and print */
    head = selection_sort(head);
    print_months(head);

    free_months(head);
    return 0;
}
