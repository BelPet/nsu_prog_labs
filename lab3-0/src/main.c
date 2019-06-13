#include <stdio.h>
#include <stdlib.h>

static void swap(int *x, int *y)
{
    int z = *x;
    *x = *y;
    *y = z;
}

static void sift(int root, int bottom, int *numbers)
{
  int max_child;
   
  while(root * 2 + 1 <= bottom){
      
    if(root * 2 + 1 == bottom)
        
      max_child = root * 2 + 1;
    
    else {
        
      if(numbers[root * 2 + 1] > numbers[root * 2 + 2])
    
          max_child = root * 2 + 1;
      
      else
      
          max_child = root * 2 + 2;
    }
      
    if(numbers[root] < numbers[max_child]) {
        
      swap(&numbers[root], &numbers[max_child]);
      root = max_child;
    
    }
    else
      return;
  }
}

static void heap_sort(int n, int *numbers)
{
  for(int i = (n / 2) - 1; i >= 0; i--)
      
    sift(i, n - 1, numbers);
    
  for(int i = n - 1; i >= 1; i--){
      
    swap(&numbers[0], &numbers[i]);
    sift(0, i - 1, numbers);
      
  }  
}

int main()
{
  int n = 0;
    
  scanf("%d", &n);
  
  int *numbers = malloc(n* sizeof(int));
    
  if (numbers == NULL) {
        
      perror("Failed");
      return EXIT_FAILURE;
        
  }
    
  for(int i = 0; i < n; i++)
      
    scanf("%d", &numbers[i]);

  heap_sort(n, numbers);
    
  for(int i=0; i<n; i++)
      
    printf("%d ", numbers[i]);
  
  free(numbers);
  return 0;
}
