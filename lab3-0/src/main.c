#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

void siftDown(int *numbers, int root, int bottom)
{
int maxChild; // индекс максимального потомка
int done = 0; // флаг того, что куча сформирована
// Пока не дошли до последнего ряда
while ((root * 2 + 1 <= bottom) && (!done)){

if (root * 2 + 1 == bottom) // если мы в последнем ряду,
maxChild = root * 2 + 1; // запоминаем левый потомок
// иначе запоминаем больший потомок из двух
else if (numbers[root * 2+1] > numbers[root * 2 + 2])
maxChild = root * 2 + 1;
else
maxChild = root * 2 + 2;
// если элемент вершины меньше максимального потомка
if (numbers[root] < numbers[maxChild])
{
int temp = numbers[root]; // меняем их местами
numbers[root] = numbers[maxChild];
numbers[maxChild] = temp;
root = maxChild;
}
else // иначе
done = 1; // пирамида сформирована
}
}
// Функция сортировки на куче
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
int arr[2222222];
scanf("%d", &x);
for (int i = 0; i < x; i++){
scanf("%d", &arr[i]);
}
heapSort(arr, x);
for (int i = 0; i < x; i++){
printf("%d", arr[i]);
}
return 0;
}
