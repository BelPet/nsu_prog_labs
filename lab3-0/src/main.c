#include <stdio.h>
#include <stdlib.h>
void sorting(int *numbers, int left, int right)
{
    int pivot;
    int l_hold = left;
    int r_hold = right;
    pivot = numbers[left];
    while (left < right)
    {
        while ((numbers[right] >= pivot) && (left < right))
            right--;
        if (left != right)
        {
            numbers[left] = numbers[right];
            left++;
        }
        while ((numbers[left] <= pivot) && (left < right))
            left++;
        if (left != right)
        {
            numbers[right] = numbers[left];
            right--;
        }
    }
    numbers[left] = pivot;
    pivot = left;
    left = l_hold;
    right = r_hold;
    if (left < pivot)
        sorting(numbers, left, pivot - 1);
    if (right > pivot)
        sorting(numbers, pivot + 1, right);
}
int main()
{
    int n;
    int number;
    scanf("%ld", &n);
    int a[n];
    for (int i = 0; i<n; i++) {
        a[i]=scanf("%d", &number);
    }
    sorting(a, 0, n-1);
    for (int i = 0; i<n; i++){
        printf("%d ", a[i]);}
    return 0;
}
