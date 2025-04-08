#include <stdio.h>
#include <stdlib.h>

struct node {
    int val;
    struct node *next;
    struct node *prev;
};

void printList(struct node *node) {
    while (node != NULL) {
        printf(" %d ", node->val);
        node = node->next;
    }
}

struct node* reverse(struct node *head) {
    struct node *temp = NULL;
    struct node *current = head;

    if (head == NULL || head->next == NULL) /* check for empty list or one elemement lists */
        return head;

    /* swap next and prev for all nodes of doubly linked list */
    while (current != NULL) {
        printf("current %d\n", current->val);
        temp = current->prev;          /* save prev */
        current->prev = current->next; /* swap prev with next */
        current->next = temp;          /* apply prev saved to next */
        current = current->prev;       /* next (i.e. prev, because reverted) */
    }
    /* now current is NULL, temp has the second last known value */

    printf("current %d\n", current ? current->val : -1);
    printf("temp %d\n", temp ? temp->val : -1);
    printf("head %d\n", head ? head->val : -1);

    return temp->prev;          /* becase temp is  */
}


struct node* reverseRecursive(struct node *head) {

    printf("START %d\n", head ? head->val : -1);

    /* empty list */
    if (head == NULL) {
        printf("No recursion necessary\n");
        return NULL;
    }

    /* swap prev and next */
    struct node* temp = head->next;
    head->next = head->prev;
    head->prev = temp;

    printf("List after swapping:");
    printList(head); printf("\n");

    /* base case, i.e., finished */
    if (head->prev == NULL) {
        printf("BASE CASE\n");
        return head;
    }

    /* keep reversing if not finished */
    head = reverseRecursive(head->prev);
    printf("FINISHED with new head: %d\n", head->val);
    printList(head); printf("\n");
    return head;
}

int main() {
    /* Init list */
    struct node* head = NULL;
    struct node* second = NULL;
    struct node* third = NULL;
    struct node* fourth = NULL;

    head = (struct node*)malloc(sizeof(struct node));
    second = (struct node*)malloc(sizeof(struct node));
    third = (struct node*)malloc(sizeof(struct node));
    fourth = (struct node*)malloc(sizeof(struct node));

    head->val = 1;
    head->next = second;
    /* head->next = NULL; */
    head->prev = NULL;

    second->val = 2;
    second->next = third;
    second->prev = head;

    third->val = 3;
    third->next = fourth;
    third->prev = second;

    fourth->val = 5;
    fourth->next = NULL;
    fourth->prev = third;

    printf("Original Doubly linked list:\n");
    printList(head); printf("\n");

    /* REVERSING CALL(S) */
    head = reverse(head);       /* assign new head */
    /* head = reverseRecursive(head); */

    printf("\nReversed Doubly linked list \n");
    printList(head);
    printf("\ndone\n");

    return 0;
}

