#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void quic_sort(int *mass, int x, int y){
  if(y>x){
    int i,j,l,k;
    srand(time(NULL));
    i=x;
    j=y;
    l=i+rand()%j;
    int a=mass[l];
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
    quic_sort(mass, x, j);
    quic_sort(mass, i, y);
  } else {return;}
}
int main(){
  int n, mass[2000000];
  scanf("%d", &n);
  for(int i=0; i<n; i++){
    scanf("%d", &mass[i]);
  }
  quic_sort(mass, 0, n-1);
  for(int i=0; i<n; i++){
    printf("%d ",mass[i]);
  }
  return 0;
}
