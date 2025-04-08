#include <stdio.h>
#include <stdlib.h>


struct node
{
    int val;
    struct node *next;
    struct node *prev;
};

struct node *merge(struct node *list1, struct node *list2) {

    /* Check for empty lists */
    /* AHA: makes it faster */
    if (list1 == NULL) {
        return list2;
    } else if (list2 == NULL) {
        return list1;
    }

    /* pointer to the head of the new merged list */
    struct node *head = malloc(sizeof(struct node));
    head->next = NULL;
    head->prev = NULL;

    /* traveling pointers */
    struct node *p = head;      /* for the merge list */
    struct node *p1 = list1;    /* for the list 1 */
    struct node *p2 = list2;    /* for the list 2 */

    /* while both lists have elements */
    while (p1 && p2) {
        if (p1->val < p2->val) {
            p->next = p1;       /* link p1 to merged trailing */
            p1->prev = p;
            p1 = p1->next;      /* move traveling p1 */
        } else {
            p->next = p2;       /* link p2 to merged trailing */
            p2->prev = p;
            p2 = p2->next;      /* mvoe traveling p2 */
        }
        p = p->next;            /* move traveling p of merged to recently added */
    }

    /* once one list is finished, handle remaining in the other */
    /* AHA: no list is needed */
    /* AHA: here also if, because might finish at the same time */
    if (p1) {
        p->next = p1;
        p1->prev = p;
    } else if (p2) {
        p->next = p2;
        p2->prev = p;
    }

    /* return pointer to new head */
    return head->next;
}

void printList(struct node *head) {
    while (head != NULL) {
        printf("%d ", head->val);
        head = head->next;
    }
    printf("\n");
}

int main(int argc, char *argv[])
{
    /* example usage */
    struct node *list1 = NULL;
    struct node *list2 = NULL;

    /* populate the lists with sorted values */
    int list1Values[] = {1, 3, 5, 7, 9};
    int list2Values[] = {2, 4, 6, 8, 10};
    /* fill in reversed order to not loose the head list1 or list2 */
    for (int i = 4; i >= 0; --i) {
        struct node *newNode = malloc(sizeof(struct node));
        newNode->val = list1Values[i];
        newNode->next = list1;
        newNode->prev = NULL;
        if (list1 != NULL) {
            list1->prev = newNode;
        }
        list1 = newNode;
    }
    for (int i = 4; i >= 0; --i) {
        struct node *newNode = malloc(sizeof(struct node));
        newNode->val = list2Values[i];
        newNode->next = list2;
        newNode->prev = NULL;
        if (list2 != NULL) {
            list2->prev = newNode;
        }
        list2 = newNode;
    }

    printf("List 1: ");
    printList(list1);

    printf("List 2: ");
    printList(list2);

    /* merge the two lists and print the result */
    struct node *mergedList = merge(list1, list2);

    printf("Merged List: ");
    printList(mergedList);

    /* free */
    struct node *tmp;
    while (mergedList != NULL) {
        tmp = mergedList;
        mergedList= mergedList->next;
        free(tmp);
    }
    return 0;
}
