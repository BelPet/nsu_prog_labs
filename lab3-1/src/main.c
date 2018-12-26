#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
static void swap(int *x, int *y){
    int z=*x;
    *x=*y;
    *y=z;
}

static void q_sort(int start, int end, int *numbers){
    if(end<=start)
        return;
    int i=start, j=end, a=numbers[(i+j)/2];
    while(i<=j){
        while(numbers[i]<a){i++;}
        while(a<numbers[j]){j--;}
        if(i<=j){
            swap(&numbers[i], &numbers[j]);
            i++;
            j--;
        }
    }
    q_sort(start, j, numbers);
    q_sort(i, end, numbers);
}

int main(){
    int n=0;
    scanf("%d", &n);
    int *numbers;
    numbers=(int*)malloc(n* sizeof(int));
    if (numbers==NULL) {
        perror("Failed");
        return EXIT_FAILURE;
    }
    for(int i=0; i<n; i++){
        scanf("%d", &numbers[i]);
    }
    q_sort(0, n-1, numbers);
    for(int i=0; i<n; i++){
        printf("%d ", numbers[i]);
    }
    free(numbers);
    return 0;
}
