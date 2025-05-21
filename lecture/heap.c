#include <stdio.h>

void printArray2(int A[], int n)
{
  for (int i = 0; i < n; i++)
  {
    printf("%d ", A[i]);
  }
  printf("\n");
}

#include <math.h>  // Required for log2 and pow

void printArray(int A[], int n)
{
  int level = 0;
  int count = 0;
  int nextLevelCount = 1;

  for (int i = 0; i < n; i++) {
    if (count == 0) {
      // Start of a new level
      int spaces = (1 << ((int)log2(n) - level)); // 2^(log2(n) - level)
      spaces=spaces;
      for (int s = 0; s < spaces; s++) printf(" ");
    }

    printf("%2d ", A[i]);
    count++;

    if (count == nextLevelCount) {
      printf("\n");
      level++;
      count = 0;
      nextLevelCount <<= 1;  // Double nodes in next level
    }
  }
  printf("\n");
}


int get_parent(int index) {
  return (index-1)/2;
}

int left_child(int index) {
  return 2*index+1;
}

int right_child(int index) {
  return 2*index+2;
}

int heapify(int Heap[], int index, int n) {
  int m = index;
  int l = left_child(index);
  int r = right_child(index);
  if (l < n && Heap[l] > Heap[m]) {m = l;}
  if (r < n && Heap[r] > Heap[m]) {m = r;}
  if (index != m) {
    int tmp;
    tmp = Heap[index];
    Heap[index] = Heap[m];
    Heap[m] = tmp;
    //printArray(Heap,n);
    heapify(Heap, m, n);
  }
  return index;
}

int heapify_itr(int Heap[], int index, int n) {
  while (left_child(index) < n) {
    int m=index;
    int l = left_child(index);
    int r = right_child(index);
    if (l < n && Heap[l] > Heap[m]) {m = l;}
    if (r < n && Heap[r] > Heap[m]) {m = r;}
    if (index != m) {
      int tmp = Heap[index];
      Heap[index] = Heap[m];
      Heap[m] = tmp;
      index = m;
    }else {
      return index;
    }
  }
  return index;
}

void build_heap_floyd(int Heap[], int n) {
  printf("\n Built by Floyd:\n");
  for (int i=get_parent(n);i>=0;i--) {
    printArray(Heap,n);
    heapify(Heap, i, n);
  }
}

int insert(int zahl, int Heap[], int n) {
  int index=0;
  while (Heap[index]!=-1) {
    index++;
  }
  if (index==n) {
    return -1; //Full
  }
  Heap[index]=zahl; //insert zahl at end

  while (index!=0) {
    if (Heap[index]<=Heap[get_parent(index)]) {
      return index;
    }else {
      int tmp = Heap[index];
      Heap[index]=Heap[get_parent(index)];
      Heap[get_parent(index)] = tmp;
    }
    index=get_parent(index);
  }
  return index;
}

void build_heap_insert(int Array[], int Heap[], int n) {
  printf("\n Built by Insert:\n");
  for (int i=0;i<n;i++) {
    insert(Array[i], Heap, n);
    printArray(Heap,n);
  }
}

int remove_zahl(int zahl, int Heap[], int n){
  int index = 0;
  while (Heap[index] != zahl && index < n) {
    index++;
  }

  if (Heap[index]!=zahl) {
    return -1;
  }

  Heap[index]=Heap[n-1];
  Heap[n-1]=-1;

  if (Heap[index]>Heap[get_parent(index)]) {
    while (index!=0) {
      int tmp = Heap[index];
      Heap[index]=Heap[get_parent(index)];
      Heap[get_parent(index)] = tmp;
      index=get_parent(index);
    }
  }else {
    heapify(Heap,index,n);
  }

  return index;
}

void heap_sort(int Heap[], int n) {
  printf("\n HeapSort:\n");
  int output[n];
  int i=0;
  while (n!=0) {
    output[i] = Heap[0];
    i++;
    Heap[0]=Heap[n-1];
    Heap[n-1]=-1;
    n--;
    heapify(Heap,0,n);
  }

  for (int a = 0; a<i;a++) {
    printf("%i",output[a]);
  }
}

//heapify an array; after deletion or values have changed O(logn)

//build by insert: start with empty and fill up one by one an call heapify after every insertion O(nlogn)

//build by floyd: start with full and heapify bottom to top O(n)

int main() {
  //max Heap
  int Array[] = {6, 0, 5, 9, 4, 1, 3, 7, 8, 2};
  int n = sizeof(Array)/sizeof(Array[0]);
  int HeapFloyd[] = {6, 0, 5, 9, 4, 1, 3, 7, 8, 2};
  int HeapInsert[n];

  for (int i = 0; i < n; ++i) {
    HeapInsert[i]=-1;
  }

  build_heap_floyd(HeapFloyd, n);
  build_heap_insert(Array, HeapInsert, n);
  heap_sort(HeapFloyd,n);
  /*
  printf("Unsorted Array : \n");
  printArray(Array, n);
  //HeapSort(Array, size);
  printf("Sorted Array : \n");
  printArray(Array, n);
  */
  return 0;
}