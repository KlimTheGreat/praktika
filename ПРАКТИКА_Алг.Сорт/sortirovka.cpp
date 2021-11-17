#include <stdlib.h>

// сортировка нисходящим слиянием
void mergeSort(int* a, int left, int right)
{
    if (left == right) return; // границы сомкнулись
    int mid = (left + right) / 2; // середина последовательности
    // рекурсивный вызов функции сортировки для каждой половины
    mergeSort(a, left, mid);
    mergeSort(a, mid + 1, right);
    int i = left;  // начало первого пути
    int j = mid + 1; // начало второго пути
    int* tmp = (int*)malloc(right * sizeof(int)); // дополнительный массив
    for (int step = 0; step < right - left + 1; step++) // для всех элементов дополнительного массива
    {
        // запись в последовательность меньшего из элементов двух путей
        // или остатка первого пути если j > right
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
    // последовательность в массив
    for (int step = 0; step < right - left + 1; step++)
        a[left + step] = tmp[step];
}


// быстрая сортировка
void quickSort(int* numbers, int left, int right)
{
    int pivot; // разрешающий элемент
    int l_hold = left; //левая граница
    int r_hold = right; // правая граница
    pivot = numbers[left];
    while (left < right) // пока границы не сомкнутся
    {
        while ((numbers[right] >= pivot) && (left < right))
            right--; // сдвигаем правую границу пока элемент [right] больше [pivot]
        if (left != right) // если границы не сомкнулись
        {
            numbers[left] = numbers[right]; // перемещаем элемент [right] на место разрешающего
            left++; // сдвигаем левую границу вправо
        }
        while ((numbers[left] <= pivot) && (left < right))
            left++; // сдвигаем левую границу пока элемент [left] меньше [pivot]
        if (left != right) // если границы не сомкнулись
        {
            numbers[right] = numbers[left]; // перемещаем элемент [left] на место [right]
            right--; // сдвигаем правую границу вправо
        }
    }
    numbers[left] = pivot; // ставим разрешающий элемент на место
    pivot = left;
    left = l_hold;
    right = r_hold;
    if (left < pivot) // Рекурсивно вызываем сортировку для левой и правой части массива
        quickSort(numbers, left, pivot - 1);
    if (right > pivot)
        quickSort(numbers, pivot + 1, right);
}


// сортировка вставками
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