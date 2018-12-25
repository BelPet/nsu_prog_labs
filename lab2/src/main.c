#include<stdio.h>
#include<string.h>
#include<stdbool.h>

#define ALL_NUMBERS 10//Колличество всех возможных элементов в перестановке

void swap(char *numbers,int x, int y){
    char z=numbers[x];
    numbers[x]=numbers[y];
    numbers[y]=z;
}

void transposition(char *numbers, int p){
    int length=strlen(numbers), i=length-2;
    while(i>=0){
        if(p==0){ break;}
        if(numbers[i]<numbers[i+1])
        {
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
        } else { i--;}
    }
}

bool error(char *numbers){
    bool z=true;

    int shift[ALL_NUMBERS], length=strlen(numbers);
    for(int i=0; i<ALL_NUMBERS; i++){
        shift[i]=0;
    }
    for(int i=0; i<length; i++){
        if(numbers[i]<'0' || numbers[i]>'9'){ z=false; break;}
        shift[numbers[i]-'0']+=1;
        if(shift[numbers[i]-'0']>1){ z=false; break;}
    }
    return z;
}

int main(){
    char numbers[10]="";
    int p=0;
    scanf("%11s", numbers);
    scanf("%d", &p);
    if(error(numbers)==false){ printf("bad input");}
    else { transposition(numbers, p);}
    return 0;
}
