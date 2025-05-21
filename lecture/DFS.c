//
// Created by Dominic Furchert on 15.04.2025.
//

#include <stdio.h>
#include <stdlib.h>


void dfs(int n, int adj[n][n]) {
  int stack[n];
  int stackEnd = -1;

  int visited[n];
  for (int i=0;i<n;i++) {
    visited[i]=0;
  }

  for (int start = 0; start<n; start++) {
    stack[0]=start;
    stackEnd = 0;

    while (stackEnd>-1) {
      int vertex = stack[stackEnd];
      stackEnd--;

      if (visited[vertex]==0) {
        printf("Visited: %d\n", vertex); // ✅ print visited node
        visited[vertex]=1;
        for (int i=0;i<n;i++) {
          if (visited[i]==0 && adj[vertex][i]!=0) {
            stackEnd++;
            stack[stackEnd]=i;
          }
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

  dfs(7, adj);

  return 0;
}