#include<stdio.h>
#include<string.h>

char swap(char *numbers,int x, int y){
  char z=numbers[x];
  numbers[x]=numbers[y];
  numbers[y]=z;
  return *numbers;
}

void transposition(char *numbers, int p){
  int t=0, length=strlen(numbers), i=length-2;
  while(i>=0){
    if(p==0){break;}
    if(numbers[i]<numbers[i+1]){
      p--;
      for(int j=length-1; j>i; j--){
        if(numbers[i]<numbers[j]){
          swap(numbers, i, j);
          break;
        }
      }
      int q=i+1, w=length-1;
      for(int s=(length-i-1)/2; s>0; s--){
        swap(numbers, q, w);
        q++;
        w--;
      }
      printf("%s\n", numbers);
      i=length-2;
    }
    else{i--;}
  }
}

int error(char *numbers){
  int z=0, excess=0, d[10];
  for(int i=0; i<10; i++){
    d[i]=0;
  }
  for(int i=0; i<strlen(numbers); i++){
    if(numbers[i]<'0' || numbers[i]>'9'){z=1; break;}
    d[numbers[i]-'0']+=1;
    if(d[numbers[i]-'0']>1){z=1; break;}
  }
  return z;
}

int main(){
  char numbers[10];
  int p;
  scanf("%s", numbers);
  scanf("%d", &p);
  if(error(numbers)==1){printf("bad input");}
  else
  {
    transposition(numbers, p);
  }
  return 0;
}
