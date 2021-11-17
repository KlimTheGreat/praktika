#include <stdlib.h>

// ���������� ���������� ��������
void mergeSort(int* a, int left, int right)
{
    if (left == right) return; // ������� ����������
    int mid = (left + right) / 2; // �������� ������������������
    // ����������� ����� ������� ���������� ��� ������ ��������
    mergeSort(a, left, mid);
    mergeSort(a, mid + 1, right);
    int i = left;  // ������ ������� ����
    int j = mid + 1; // ������ ������� ����
    int* tmp = (int*)malloc(right * sizeof(int)); // �������������� ������
    for (int step = 0; step < right - left + 1; step++) // ��� ���� ��������� ��������������� �������
    {
        // ������ � ������������������ �������� �� ��������� ���� �����
        // ��� ������� ������� ���� ���� j > right
        if ((j > right) || ((i <= mid) && (a[i] < a[j])))
        {
           tmp[step] = a[i];
            i++;
        }
        else
        {
            tmp[step] = a[j];
            j++;
        }
    }
    // ������������������ � ������
    for (int step = 0; step < right - left + 1; step++)
        a[left + step] = tmp[step];
}


// ������� ����������
void quickSort(int* numbers, int left, int right)
{
    int pivot; // ����������� �������
    int l_hold = left; //����� �������
    int r_hold = right; // ������ �������
    pivot = numbers[left];
    while (left < right) // ���� ������� �� ���������
    {
        while ((numbers[right] >= pivot) && (left < right))
            right--; // �������� ������ ������� ���� ������� [right] ������ [pivot]
        if (left != right) // ���� ������� �� ����������
        {
            numbers[left] = numbers[right]; // ���������� ������� [right] �� ����� ������������
            left++; // �������� ����� ������� ������
        }
        while ((numbers[left] <= pivot) && (left < right))
            left++; // �������� ����� ������� ���� ������� [left] ������ [pivot]
        if (left != right) // ���� ������� �� ����������
        {
            numbers[right] = numbers[left]; // ���������� ������� [left] �� ����� [right]
            right--; // �������� ������ ������� ������
        }
    }
    numbers[left] = pivot; // ������ ����������� ������� �� �����
    pivot = left;
    left = l_hold;
    right = r_hold;
    if (left < pivot) // ���������� �������� ���������� ��� ����� � ������ ����� �������
        quickSort(numbers, left, pivot - 1);
    if (right > pivot)
        quickSort(numbers, pivot + 1, right);
}


// ���������� ���������
void insertSort(int* arr, int n) 
{ 
    for (int i = 1; i < n; i++) {
        for (int j = i; j > 0 && arr[j - 1] > arr[j]; j--) {
            int tmp = arr[j - 1];
            arr[j - 1] = arr[j];
            arr[j] = tmp;
        }
    }
}