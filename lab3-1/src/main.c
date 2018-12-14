#include<stdio.h>
#include<stdlib.h>
int numbers[2000000];
void swap(int x, int y){
  int z=numbers[x];
  numbers[x]=numbers[y];
  numbers[y]=z;
}
void q_sort(int start, int end){
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
        swap(i, j);
        i++;
        j--;
      }
    }
    q_sort(start, j);
    q_sort(i, end);
}
int main(){
  int n;
  scanf("%d", &n);
  for(int i=0; i<n; i++){
    scanf("%d", &numbers[i]);
  }
  q_sort(0, n-1);
  for(int i=0; i<n; i++){
    printf("%d ",numbers[i]);
  }
  return 0;
}
