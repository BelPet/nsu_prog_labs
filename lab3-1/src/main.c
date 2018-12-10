#include <stdio.h>
int n, b[2000000];
void sort_q(int q, int w){
  if(w<=q){
    return;
  }
  int i,j,x,k;
  i=q;
  j=w;
  x=(i+j)/2;
  int a=b[x];
  while(i<=j){
    while(b[i]<a)i++;
    while(a<b[j])j--;
    if(i<=j){
      k=b[i];
      b[i]=b[j];
      b[j]=k;
      i++;
      j--;
    }
  }
  sort_q(q,j);
  sort_q(i,w);
}
int main() {
  scanf("%d", &n);
  int i=0;
  while(n>i){
    scanf("%d", &b[i]);
    i++;
  }
  sort_q(0, n-1);
  for(i=0; i<n; i++){
    printf("%d ",b[i]);
  }
}
