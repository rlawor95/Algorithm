#include <stdio.h>
#include <iostream>
using namespace std;

int _data[] = {100, 1, 2, 3, 5, 9, 5, 6, 4, 5};

void show()
{
    int i;
    for (i = 0; i < sizeof(_data) / sizeof(int); i++)
    {
        printf("%d ", _data[i]);
    }
}

inline void swap(int &a, int &b)
{
    int t = a;
    a = b;
    b = t;
}

// void quickSort(int A[], int low, int high)
// {
//     if (low >= high)
//         return; // base condition

//     // divide process
//     int i = low - 1, j = low;
//     int &pivot = A[high];

//     for (; j < high; ++j)
//     {
//         if (A[j] < pivot)
//             swap(A[++i], A[j]);
//     }
//     swap(A[++i], pivot);

//     // conquer process
//     quickSort(A, low, i - 1);
//     quickSort(A, i + 1, high);
// }

void quickSort(int data[], int start, int end)
{
    if (start >= end) // 원소가 1개인 경우
        return;

    int pivot = start;
    int left = start + 1;
    int right = end;

    while (left <= right) // 엇갈릴 때까지 반복
    {
        //left는 피벗보다 큰 값을 찾을 때 까지 순회
        while (left <= end && data[left] <= data[pivot])
            left++;

        //right는 피벗보다 작은 값을 찾을 때 까지 순회
        while (right > start && data[right] >= data[pivot])
            right--;

        if (left > right)
            swap(data[pivot], data[right]);
        else
            swap(data[left], data[right]);
    }

    quickSort(data, start, right - 1);
    quickSort(data, right + 1, end);
}


int main(void)
{
    quickSort(_data, 0, sizeof(_data) / sizeof(int) - 1);
    show();
    cout << "quick sort" << endl;
    return 0;
}
