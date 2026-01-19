#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <locale.h>
#include "arrays.h"
#define SIZE 100

int task11(int size);
int task14(int size);
int task16(int size);
int task17(int size);

int main() {
    srand((unsigned)time(NULL));
    setlocale(LC_ALL, "Rus");
    puts("===Лабораторные работы 11, 14, 16, 17: Работа с массивами ===\n");
    int size;
    printf("Укажите размер массива: ");
    scanf("%d", &size);

    /* Инициализируем генератор случайных чисел один раз */
    srand((unsigned)time(NULL));

    puts("=== Лабораторная 11 ===");
    task11(size);

    puts("=== Лабораторная 14 ===");
    task14(size);

    puts("=== Лабораторная 16 ===");
    task16(size);

    puts("=== Лабораторная 17 ===");
    task17(size);

    return 0;
}

int task11(int size) {
    double array[SIZE];
    if (size > SIZE) {
        printf("Размер превышает максимум %d\n", SIZE);
        return -1;
    }

    // Задание 1: Заполнение с консоли
    full_elements_console(array, size);

    // Печать исходного массива в таблице
    printf("\nТаблица для лаб 11 (исходная):\n");
    puts("------------------------------");
    printf("| Индекс | Исходное значение |\n");
    for (int i = 0; i < size; i++) {
        printf("| %6d | %17.2f |\n", i, array[i]);
    }
    puts("------------------------------");
    // Преобразование: отбросить дробную часть
    calc_elements(array, size);

    // Печать преобразованного
    printf("\nТаблица для лаб 11 (преобразованная):\n");
    puts("------------------------------");
    printf("| Индекс |    Новое значение |\n");
    for (int i = 0; i < size; i++) {
        printf("| %6d | %17.2f |\n", i, array[i]);
    }
    puts("------------------------------");
    // Среднее арифметическое всех
    double avg = average_elements(array, size);
    printf("Среднее арифметическое: %.2f\n", avg);

    // ДЗ 11: Среднее положительных на нечетных индексах
    puts(" ДЗ 11");
    double avg_pos_odd = average_positive_odd_indices(array, size);
    printf("Среднее положительных на нечетных индексах: %.2f\n", avg_pos_odd);
    puts(" ");
    return 0;
}

// Функция для лаб 14
int task14(int size) {
    double array[SIZE];
    if (size > SIZE) return -1;

    // Задание 1: Заполнение значениями func(x)
    puts("Исходные значения (func(x)):");
    full_elements_func(array, size);
    put_elements(array, size);

    // Преобразование, отброс дробной части (1.3 из лаб 11)
    puts("Преобразованные значения:");
    calc_elements(array, size);
    put_elements(array, size);

    //Задание 2: Работа с массивом
    // Сумма элементов
    double sum = sum_elements(array, 0, size - 1);
    printf("Сумма элементов: %.2f\n", sum);

    // Поиск элемента
    double a;
    printf("Введите значение для поиска: ");
    scanf("%lf", &a);
    int index = find_element(array, size, a);
    printf("Индекс элемента %.2f: %d\n", a, index);

    // Задание 3: Поиск max начиная с ka
    int ka;
    printf("Введите ka для поиска max: ");
    scanf("%d", &ka);
    int max_index = find_max_from_index(array, size, ka);
    if (max_index != -1)
        printf("Индекс max начиная с индекса %d: %d (значение %.2f)\n", ka, max_index, array[max_index]);
    else
        printf("Некорректный ka.\n");

    // ДЗ 14: Количество между двумя A
    puts(" ДЗ 14");
    printf("Введите A для подсчета между соседними: ");
    scanf("%lf", &a);
    int count_between = count_between_two_a(array, size, a);
    printf("Количество элементов между двумя %.2f: %d\n", a, count_between);
    puts(" ");
    return 0;
}

// Функция для лаб 16
int task16(int size) {
    // Задание 1: Работа с динамическим массивом
    double* ptr_array = (double*)malloc(size * sizeof(double));
    if (ptr_array == NULL) {
        puts("Ошибка выделения памяти");
        return -1;
    }

    // Заполнение значениями из функции (из лаб. 14)
    full_elements_func(ptr_array, size);
    printf("Массив до преобразования(func(x)):\n");
    put_elements(ptr_array, size);

    // Создание нового массива для результата преобразования
    double* ptr_transformed = (double*)malloc(size * sizeof(double));
    if (ptr_transformed == NULL) {
        puts("Ошибка выделения памяти для преобразованного массива");
        free(ptr_array);
        return -1;
    }
    // Копируем оригинал в новый массив
    for (int i = 0; i < size; i++) {
        ptr_transformed[i] = ptr_array[i];
    }
    // Преобразование нового массива (отброс дробной части)
    calc_elements(ptr_transformed, size);
    printf("Массив после преобразования:\n");
    put_elements(ptr_transformed, size);

    // Освобождение памяти для ptr_transformed
    free(ptr_transformed);

    // Освобождение оригинала (мы будем работать с ptr_transformed дальше)
    free(ptr_array);
    ptr_array = NULL;

    // Задание 2: Переписанная программа с random [-1;1]
    puts("\nМассив с случайными числами [-1;1]");
    double* arr = (double*)malloc(size * sizeof(double));
    if (!arr) {
        puts("Ошибка выделения памяти");
        return -1;
    }
    fill_random_minus1_to1(arr, size);
    /* печатаем исходный массив */
    printf("Случайный массив ([-1;1]):\n");
    put_elements(arr, size);
    double sum = sum_elements(arr, 0, size - 1);
    /* 1) среднее арифметическое из исходного массива */
    double avg = 0.0;
    if (size > 0) avg = sum / (double)size;
    printf("Среднее арифметическое: %.6f\n", avg);

    int cur_size = size;
    arr = delete_less_than_avg(arr, &cur_size, avg);
    /* 2) удаляем из текущего массива все элементы < avg */
    printf("Новообразованный массив после удаления элементов < avg (size = %d):\n", cur_size);
    if (cur_size > 0 && arr != NULL) {
        put_elements(arr, cur_size);
    }
    else {
        printf("(пустой массив)\n");
    }
    /* 3) вставляем -999 перед первым отрицательным (если есть) */
    int pos = find_first_negative(arr, cur_size);
    if (pos != -1) {
        arr = insert_value_at(arr, &cur_size, -999.0, pos);
        printf("Массив после вставки -999 (size = %d):\n", cur_size);
        if (cur_size > 0 && arr != NULL) {
            printf("Debug: arr = %p, cur_size = %d\n", (void*)arr, cur_size);
            put_elements(arr, cur_size);
        }
        else {
            puts("После вставки массив пустой или ошибка памяти");
        }
    }
    else {
        printf("Нет отрицательных элементов для вставки.\n");
    }
    if (arr != NULL) free(arr);

    // ДЗ 16: Генерация трех массивов и создание четвертого
    puts("\n ДЗ 16: Генерация массивов A, B, C и создание D");
    int n = 10 + rand() % 21;  // 10-30
    int m = 10 + rand() % 21;
    int l = 10 + rand() % 21;

    double* a = (double*)malloc(n * sizeof(double));
    double* b = (double*)malloc(m * sizeof(double));
    double* c = (double*)malloc(l * sizeof(double));

    fill_random_minus1_to1(a, n);
    fill_random_minus1_to1(b, m);
    fill_random_minus1_to1(c, l);

    printf("Массив A (размер %d):\n", n);
    put_elements(a, n);
    printf("Массив B (размер %d):\n", m);
    put_elements(b, m);
    printf("Массив C (размер %d):\n", l);
    put_elements(c, l);

    // Создать D: значения до min в A (не включая min), затем B без min и max элементов
    double* d;
    int h = create_d_from_a_b(a, n, b, m, &d);
    printf("Массив D (размер %d):\n", h);
    put_elements(d, h);
    puts(" ");
    free(a);
    free(b);
    free(c);
    free(d);

    return 0;
}

int task17(int size) {
    const int trials = 100;
    int sizes[] = { 100, 1000, 10000 };
    const char* names[] = { "Выбором", "Пузырек", "Коктейль", "Вставки" };

    /* ---------- МАССИВЫ ТОЛЬКО ДЛЯ 100 ---------- */
    int* base100 = (int*)malloc(100 * sizeof(int));
    full_array(base100, 100);

    printf("Неотсортированный массив (100 элементов):\n");
    put_elements_int(base100, 100);

    int* sorted100 = (int*)malloc(100 * sizeof(int));
    for (int i = 0; i < 100; i++) sorted100[i] = base100[i];
    sort_select(sorted100, 100);

    printf("\nОтсортированный массив (100 элементов):\n");
    put_elements_int(sorted100, 100);

    free(sorted100);
    free(base100);

    puts("------------------------------------------------------");
    printf("| Размер | %8s | %8s | %8s | %8s |\n",
        names[0], names[1], names[2], names[3]);
    printf("|--------|----------|----------|----------|----------|\n");

    for (int s = 0; s < 3; s++) {
        int n = sizes[s];
        printf("| %6d |", n);

        int* base = (int*)malloc(n * sizeof(int));
        full_array(base, n);

        for (int alg = 0; alg < 4; alg++) {
            double total = 0.0;

            for (int t = 0; t < trials; t++) {
                int* arr = (int*)malloc(n * sizeof(int));
                for (int i = 0; i < n; i++) arr[i] = base[i];

                clock_t start = clock();
                if (alg == 0) sort_select(arr, n);
                if (alg == 1) sort_bubble(arr, n);
                if (alg == 2) sort_cocktail(arr, n);
                if (alg == 3) sort_insert(arr, n);
                total += (double)(clock() - start) / CLOCKS_PER_SEC;

                free(arr);
            }
            printf("  %7.4f |", total / trials);
        }
        printf("\n");
        free(base);
    }
    puts("------------------------------------------------------");
    return 0;
}
