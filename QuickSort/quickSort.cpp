#include <stdio.h>

int number = 10;
int data[] = {1, 10, 5, 8, 7, 6, 4, 3, 2, 9};

void show()
{
    int i;
    for (i = 0; i < number; i++)
    {
        printf("%d ", data[i]);
    }
}

inline void swap(int &a, int &b)
{
    int t = a;
    a = b;
    b = t;
}

void quickSort(int A[], int low, int high)
{
    if (low >= high)
        return; // base condition

    // divide process
    int i = low - 1, j = low;
    int &pivot = A[high];

    for (; j < high; ++j)
    {
        if (A[j] < pivot)
            swap(A[++i], A[j]);
    }
    swap(A[++i], pivot);

    // conquer process
    quickSort(A, low, i - 1);
    quickSort(A, i + 1, high);
}

int main(void)
{
    quickSort(data, 0, number - 1);
    show();
    return 0;
}