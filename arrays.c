#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "arrays.h"

// Функция func(x)
double func(double x) {
    return pow(x, 3) - 4 * pow(x, 2) + 2;
}

// Заполнение с консоли
double* full_elements_console(double* ptr_array, int n) {
    if (!ptr_array) return NULL;
    for (int i = 0; i < n; i++) {
        printf("array[%d] = ", i);
        scanf("%lf", &ptr_array[i]);
    }
    return ptr_array;
}

// Заполнение func
double* full_elements_func(double* ptr_array, int n) {
    if (!ptr_array) return NULL;
    for (int i = 0; i < n; i++) {
        ptr_array[i] = func(i);
    }
    return ptr_array;
}

// Печать элементов double
int put_elements(double* ptr_array, int n) {
    if (!ptr_array) return 0;
    for (int i = 0; i < n; i++) {
        printf("%.2f ", ptr_array[i]);
    }
    printf("\n");
    return n;
}

// Печать элементов
int put_elements_int(int* ptr_array, int n) {
    if (!ptr_array) return 0;
    for (int i = 0; i < n; i++) {
        printf("%d ", ptr_array[i]);
    }
    printf("\n");
    return n;
}

// Отбросить дробную часть (для лаб 11,14,16)
double* calc_elements(double* ptr_array, int n) {
    if (!ptr_array) return NULL;
    for (int i = 0; i < n; i++) {
        ptr_array[i] = (int)ptr_array[i];
    }
    return ptr_array;
}

// Сумма элементов
double sum_elements(double* ptr_array, int begin, int end) {
    if (!ptr_array || begin > end) return 0;
    double sum = 0;
    for (int i = begin; i <= end; i++) {
        sum += ptr_array[i];
    }
    return sum;
}

// Поиск элемента
int find_element(double* ptr_array, int n, double element) {
    if (!ptr_array) return -1;
    for (int i = 0; i < n; i++) {
        if (ptr_array[i] == element) return i;
    }
    return -1;
}

// Среднее арифметическое
double average_elements(double* ptr_array, int n) {
    if (n == 0) return 0;
    return sum_elements(ptr_array, 0, n - 1) / n;
}

// ДЗ 11: Среднее положительных на нечетных
double average_positive_odd_indices(double* ptr_array, int n) {
    double sum = 0;
    int count = 0;
    for (int i = 1; i < n; i += 2) {  // нечетные индексы: 1,3,5...
        if (ptr_array[i] > 0) {
            sum += ptr_array[i];
            count++;
        }
    }
    return count > 0 ? sum / count : 0;
}

// Поиск max от индекса ka
int find_max_from_index(double* ptr_array, int n, int ka) {
    if (ka >= n || !ptr_array || ka < 0) return -1;
    int max_idx = ka;
    for (int i = ka + 1; i < n; i++) {
        if (ptr_array[i] > ptr_array[max_idx]) max_idx = i;
    }
    return max_idx;
}

// ДЗ 14: Количество между двумя соседними A
int count_between_two_a(double* ptr_array, int n, double a) {
    int count = 0;
    int start = -1;
    for (int i = 0; i < n; i++) {
        if (ptr_array[i] == a) {
            if (start != -1) {
                count += i - start - 1;
                start = i;
            }
            else {
                start = i;
            }
        }
    }
    return count;
}

// Заполнить random от -1 to 1
double* fill_random_minus1_to1(double* ptr_array, int n) {
    if (!ptr_array) return NULL;
    for (int i = 0; i < n; i++) {
        ptr_array[i] = -1 + 2.0 * rand() / RAND_MAX;
    }
    return ptr_array;
}

// Удаление всех < avg
double* delete_less_than_avg(double* arr, int* size, double avg) {
    if (!size || !arr || *size <= 0) {
        if (size) *size = 0;
        return NULL;
    }
    int write = 0;
    for (int i = 0; i < *size; i++) {
        if (arr[i] >= avg) {
            arr[write++] = arr[i];
        }
    }
    *size = write;
    if (write == 0) {
        free(arr);
        return NULL;
    }
    return arr;
}
// Найти первый отрицательный
int find_first_negative(double* ptr_array, int n) {
    if (!ptr_array) return -1;
    for (int i = 0; i < n; i++) {
        if (ptr_array[i] < 0) return i;
    }
    return -1;
}

// Вставить значение на позицию
double* insert_value_at(double* arr, int* size, double value, int pos) {
    if (!size || pos < 0 || pos > *size) return arr;
    double* new_arr = (double*)malloc((*size + 1) * sizeof(double));
    if (!new_arr) {
        puts("Ошибка malloc при вставке");
        return arr; 
    }
    // Копируем элементы до pos
    for (int i = 0; i < pos; i++) {
        new_arr[i] = arr[i];
    }
    new_arr[pos] = value;
    // Копируем остаток
    for (int i = pos; i < *size; i++) {
        new_arr[i + 1] = arr[i];
    }
    (*size)++;
    free(arr);  // Освобождаем старый буфер
    return new_arr;
}


// ДЗ 16: Создать D из A и B
int create_d_from_a_b(double* a, int n, double* b, int m, double** d) {
    if (!a || !b || !d) return 0;
    // Найти индекс min в A
    int min_idx_a = 0;
    for (int i = 1; i < n; i++) {
        if (a[i] < a[min_idx_a]) min_idx_a = i;
    }
    int part1 = min_idx_a;  // Количество элементов до min (не включая)

    // Найти индексы min и max в B
    int min_idx_b = 0;
    int max_idx_b = 0;
    for (int i = 1; i < m; i++) {
        if (b[i] < b[min_idx_b]) min_idx_b = i;
        if (b[i] > b[max_idx_b]) max_idx_b = i;
    }
    int part2 = m - 1;  // Удаляем min (один)
    if (min_idx_b != max_idx_b) part2--;  // Если разные, удаляем ещё max

    int h = part1 + part2;
    *d = (double*)malloc(h * sizeof(double));
    if (*d == NULL) return 0;

    // Копировать элементы до min из A (не включая min)
    int idx = 0;
    for (int i = 0; i < min_idx_a; i++) {
        (*d)[idx++] = a[i];
    }

    // Копировать B, исключая индексы min_idx_b и max_idx_b
    for (int i = 0; i < m; i++) {
        if (i != min_idx_b && i != max_idx_b) {
            (*d)[idx++] = b[i];
        }
        else if (min_idx_b == max_idx_b && i == min_idx_b) {
            // Если min==max, пропускаем только один раз
            continue;
        }
    }

    return h;
}

// Заполнение массива случайными значениями в диапазоне -1000..1000
int* full_array(int* ptr_array, int n) {
    if (!ptr_array) return NULL;
    for (int i = 0; i < n; i++) {
        ptr_array[i] = (rand() % 2001) - 1000; // -1000 .. 1000
    }
    return ptr_array;
}

// Печать массива
int put_array(int* ptr_array, int n) {
    return put_elements_int(ptr_array, n);
}

// Пузырьковая сортировка
void sort_bubble(int* ptr_array, int n) {
    if (!ptr_array) return;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (ptr_array[j] > ptr_array[j + 1]) {
                int tmp = ptr_array[j];
                ptr_array[j] = ptr_array[j + 1];
                ptr_array[j + 1] = tmp;
            }
        }
    }
}

// Сортировка выбором
void sort_select(int* ptr_array, int n) {
    if (!ptr_array) return;
    for (int i = 0; i < n - 1; i++) {
        int imin = i;
        for (int j = i + 1; j < n; j++) {
            if (ptr_array[j] < ptr_array[imin]) imin = j;
        }
        if (imin != i) {
            int tmp = ptr_array[i];
            ptr_array[i] = ptr_array[imin];
            ptr_array[imin] = tmp;
        }
    }
}

// Сортировка вставками
void sort_insert(int* ptr_array, int n) {
    if (!ptr_array) return;
    for (int i = 1; i < n; i++) {
        int temp = ptr_array[i];
        int j = i;
        while (j > 0 && ptr_array[j - 1] > temp) {
            ptr_array[j] = ptr_array[j - 1];
            j--;
        }
        ptr_array[j] = temp;
    }
}

// Сортировка коктейлем
void sort_cocktail(int* arr, int size) {
    if (!arr) return;
    int left = 0;
    int right = size - 1;
    int swapped;
    do {
        swapped = 0;
        for (int i = left; i < right; i++) {
            if (arr[i] > arr[i + 1]) {
                int tmp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = tmp;
                swapped = 1;
            }
        }
        right--;
        for (int i = right; i > left; i--) {
            if (arr[i - 1] > arr[i]) {
                int tmp = arr[i - 1];
                arr[i - 1] = arr[i];
                arr[i] = tmp;
                swapped = 1;
            }
        }
        left++;
    } while (swapped && left < right);
}
