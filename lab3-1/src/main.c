#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void sort_q(int *mass, int q, int w){
  if(w>q){
    int i,j,x,k;
    srand(time(NULL));
    i=q;
    j=w;
    x=i+rand()%j;
    int a=mass[x];
    while(i<=j){
      while(mass[i]<a)i++;
      while(a<mass[j])j--;
      if(i<=j){
        k=mass[i];
        mass[i]=mass[j];
        mass[j]=k;
        i++;
        j--;
      }
    }
    sort_q(mass, q, j);
    sort_q(mass, i, w);
  }
}
int main() {
  int n, mass[2000000];
  scanf("%d", &n);
  for(int i=0; i<n; i++){
    scanf("%d", &mass[i]);
  }
  sort_q(mass, 0, n-1);
  for(int i=0; i<n; i++){
    printf("%d ",mass[i]);
  }
}
