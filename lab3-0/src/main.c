#include<stdio.h>
#include<stdlib.h>

int numbers[2000000];

void sift_down(int root, int bottom){
  int max_child, done=0;
  while((root*2+1<=bottom) && (!done)){
    if(root*2+1==bottom)
    max_child=root*2+1;
    else 
    if(numbers[root *2+1]>numbers[root*2+2])
    max_child=root*2+1;
    else
    max_child=root*2+2;
    if(numbers[root]<numbers[max_child]){
      int temp=numbers[root];
      numbers[root]=numbers[max_child];
      numbers[max_child]=temp;
      root=max_child;
    } else {done=1;}
  }
}
void heap_sort(int n){
  for(int i=(n/2)-1; i>=0; i--){
    sift_down(numbers, i, n-1);
  }
  for(int i=n-1; i>=1; i--){
    int tmp=numbers[0];
    numbers[0]=numbers[i];
    numbers[i]=tmp;
    sift_down(numbers, 0, i-1);
  }
}
int main(){
  int n;
  scanf("%d", &n);
  for(int i=0; i<n; i++){
    scanf("%d", &numbers[i]);
  }
  heap_sort(n);
  for(int i=0; i<n; i++){
    printf("%d ", numbers[i]);
  }
  return 0;
}
