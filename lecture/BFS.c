//
// Created by Dominic Furchert on 15.04.2025.
//

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  int val;
  struct node *next;
} node_t;

void enqueue(node_t **head, int val) {
  node_t *new_node = malloc(sizeof(node_t));
  if (!new_node) return;

  new_node->val = val;
  new_node->next = *head;

  *head = new_node;
}

int dequeue(node_t **head) {
  node_t *current, *prev = NULL;
  int retval = -1;

  if (*head == NULL) return -1;

  current = *head;
  while (current->next != NULL) {
    prev = current;
    current = current->next;
  }

  retval = current->val;
  free(current);

  if (prev)
    prev->next = NULL;
  else
    *head = NULL;

  return retval;
}

void bfs(int n, int adj[n][n]) {
  int visited[n];
  for (int i=0;i<n;i++) {
    visited[i]=0;
  }

  struct node *myQ = NULL;

  enqueue(&myQ,0);

  while (myQ!=NULL) {
    int vertex = dequeue(&myQ);
    if (visited[vertex]==0) {
      //visit vertex
      printf("Visited: %d\n", vertex); // ✅ print visited node
      visited[vertex] = 1;
      for (int i=0;i<n;i++) {
        if (adj[vertex][i]!=0 && visited[i]!=1) {
          enqueue(&myQ, i);
        }
      }
    }
  }

}


int main() {
  int adj[7][7];
  // Initialize the adjacency matrix to 0
  for (int i = 0; i < 7; i++) {
    for (int j = 0; j < 7; j++) {
      adj[i][j] = 0;
    }
  }

  // Example: add some edges
  adj[0][1] = 1;
  adj[1][2] = 1;
  adj[2][0] = 1;
  adj[1][5]=1;
  adj[3][4] = 1;
  adj[4][5] = 1;
  adj[2][4]=1;

  bfs(7, adj);


  return 0;
}