#include<stdio.h>
int n, numbers[2000000];
void qsort(int start, int end){
  if(end<=start){return;}
  int i,j,k,l;
  i=start;
  j=end;
  k=(i+j)/2;
  int a=numbers[k];
  while(i<=j){
    while(numbers[i]<a){i++;}
    while(a<numbers[j]){j--;}
    if(i<=j){
      l=numbers[i];
      numbers[i]=numbers[j];
      numbers[j]=l;
      i++;
      j--;
    }
  }
  qsort(start, j);
  qsort(i, end);
}
int main(){
scanf("%d", &n);
for(int i=0; i<n; i++){
  scanf("%d", &numbers[i]);
}
qsort(0, n-1);
for(int i=0; i<n; i++){
  printf("%d ", numbers[i]);
}
}
