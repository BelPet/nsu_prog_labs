#include<stdio.h>
#include<stdlib.h>
void swap(int *mass, int x, int y){
  int z=mass[x];
  mass[x]=mass[y];
  mass[y]=z;
}
void q_sort(int *numbers, int start, int end){
  if(end<=start){return;}
    int i,j,l;
    i=start;
    j=end;
    l=(i+j)/2;
    int a=numbers[l];
    while(i<=j){
      while(numbers[i]<a)i++;
      while(a<numbers[j])j--;
      if(i<=j){
        swap(numbers, i, j);
        i++;
        j--;
      }
    }
    q_sort(numbers, start, j);
    q_sort(numbers, i, end);
}
int main(){
  int n;
  scanf("%d", &n);
  int numbers[n];
  for(int i=0; i<n; i++){
    scanf("%d", &numbers[i]);
  }
  q_sort(numbers, 0, n-1);
  for(int i=0; i<n; i++){
    printf("%d ",numbers[i]);
  }
  return 0;
}
