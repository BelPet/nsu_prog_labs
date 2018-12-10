#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int arr[2000000];

void siftDown(int *numbers, int root, int bottom)
{
int maxChild;
int done = 0;
while ((root * 2 + 1 <= bottom) && (!done)){

if (root * 2 + 1 == bottom)
maxChild = root * 2 + 1;
else if (numbers[root * 2+1] > numbers[root * 2 + 2])
maxChild = root * 2 + 1;
else
maxChild = root * 2 + 2;
if (numbers[root] < numbers[maxChild])
{
int temp = numbers[root];
numbers[root] = numbers[maxChild];
numbers[maxChild] = temp;
root = maxChild;
}
else
done = 1;
}
}
void heapSort(int *numbers, int array_size)
{


for (int i = (array_size / 2) - 1; i >= 0; i--){
siftDown(numbers, i, array_size - 1);
}
for (int i = array_size-1; i >= 1; i--){
int tmp = numbers[0];
numbers[0] = numbers[i];
numbers[i] = tmp;
siftDown(numbers, 0, i-1);
}

}

int main() {

int x;
scanf("%d", &x);
for (int i = 0; i < x; i++){
scanf("%d", &arr[i]);
}
heapSort(arr, x);
for (int i = 0; i < x; i++){
printf("%d ", arr[i]);
}
return 0;
}
