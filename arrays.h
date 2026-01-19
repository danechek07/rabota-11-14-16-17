//arrays.h - Заголовочный файл для работы с одномерными массивами типа double
 
#ifndef ARRAYS_H
#define ARRAYS_H

/**
 * Функция, задающая значения элементов массива (как в лабораторной работе 8)
 * @param x аргумент функции
 * @return значение функции в точке x
 */
double func(double x);

/**
 * Заполнение массива значениями, получаемыми из функции func()
 * @param ptr_array указатель на массив
 * @param n размер массива
 * @return указатель на заполненный массив
 */
double* full_elements_func(double* ptr_array, int n);

/**
 * Печать элементов массива на экран
 * @param ptr_array указатель на массив
 * @param n размер массива
 * @return количество выведенных элементов
 */
int put_elements(double* ptr_array, int n);

/**
 * Обработка (преобразование) элементов массива согласно индивидуальному варианту
 * @param ptr_array указатель на массив
 * @param n размер массива
 * @return указатель на обработанный массив
 */
double* calc_elements(double* ptr_array, int n);

/**
 * Вычисление суммы элементов массива в заданном диапазоне индексов
 * @param ptr_array указатель на массив
 * @param begin начальный индекс диапазона (включительно)
 * @param end конечный индекс диапазона (включительно)
 * @return сумма элементов в диапазоне [begin, end]
 */
double sum_elements(double* ptr_array, int begin, int end);

/**
 * Поиск первого вхождения заданного элемента в массиве
 * @param ptr_array указатель на массив
 * @param n размер массива
 * @param element искомое значение
 * @return индекс найденного элемента или -1, если элемент не найден
 */
int find_element(double* ptr_array, int n, double element);

/**
 * Заполнение массива с клавиатуры (консольный ввод)
 * @param ptr_array указатель на массив
 * @param n размер массива
 * @return указатель на заполненный массив
 */
double* full_elements_console(double* ptr_array, int n);

/**
 * Заполнение массива случайными вещественными числами в диапазоне [-1, 1]
 * @param ptr_array указатель на массив
 * @param n размер массива
 * @return указатель на заполненный массив
 */
double* fill_random_minus1_to1(double* ptr_array, int n);

/**
 * Вычисление среднего арифметического положительных элементов,
 * находящихся на нечётных индексах
 * @param ptr_array указатель на массив
 * @param n размер массива
 * @return среднее значение или 0.0 при отсутствии подходящих элементов
 */
double average_positive_odd_indices(double* ptr_array, int n);

/**
 * Поиск индекса максимального элемента, начиная с заданного индекса
 * @param ptr_array указатель на массив
 * @param n размер массива
 * @param ka начальный индекс поиска
 * @return индекс максимального элемента или -1 при ошибке
 */
int find_max_from_index(double* ptr_array, int n, int ka);

/**
 * Подсчёт количества элементов, находящихся между двумя соседними
 * вхождениями значения A
 * @param ptr_array указатель на массив
 * @param n размер массива
 * @param a искомое значение
 * @return количество элементов между двумя первыми вхождениями A или 0
 */
int count_between_two_a(double* ptr_array, int n, double a);

/**
 * Удаление всех элементов, меньших заданного среднего значения.
 * @param arr указатель на массив
 * @param size указатель на текущее количество элементов; будет изменён на новый размер
 * @param avg порог
 * @return новый указатель на память или NULL при new_size == 0
 */
double* delete_less_than_avg(double* arr, int* size, double avg);

/**
 * Поиск первого отрицательного элемента
 * @param ptr_array указатель на массив
 * @param n размер массива
 * @return индекс первого отрицательного элемента или -1
 */
int find_first_negative(double* ptr_array, int n);

/**
 * Вставка заданного значения в массив на указанную позицию
 * @param arr указатель на массив
 * @param size указатель на текущее количество элементов
 * @param value вставляемое значение
 * @param pos позиция вставки
 * @return новый указатель на массив (может отличаться от входного)
 */
double* insert_value_at(double* arr, int* size, double value, int pos);

/**
 * Создание массива D из массивов A и B
 * @param a указатель на массив A
 * @param n размер массива A
 * @param b указатель на массив B
 * @param m размер массива B
 * @param d указатель на указатель для результата
 * @return размер созданного массива D
 */
int create_d_from_a_b(double* a, int n, double* b, int m, double** d);

/**
 * Заполнение массива целых чисел случайными значениями в диапазоне [-1000, 1000]
 * @param ptr_array указатель на массив
 * @param n размер массива
 * @return указатель на заполненный массив
 */
int* full_array_int(int* ptr_array, int n);

/**
 * Печать массива целых чисел
 * @param ptr_array указатель на массив
 * @param n размер массива
 * @return количество выведенных элементов
 */
int put_elements_int(int* ptr_array, int n);

/**
 * Пузырьковая сортировка массива целых чисел по возрастанию
 * @param ptr_array указатель на массив
 * @param n количество элементов
 */
void sort_bubble_int(int* ptr_array, int n);

/**
 * Сортировка выбором массива целых чисел по возрастанию
 * @param ptr_array указатель на массив
 * @param n количество элементов
 */
void sort_select_int(int* ptr_array, int n);

/**
 * Сортировка вставками массива целых чисел по возрастанию
 * @param ptr_array указатель на массив
 * @param n количество элементов
 */
void sort_insert_int(int* ptr_array, int n);

/**
 * Шейкерная (коктейльная) сортировка массива целых чисел по возрастанию
 * @param arr указатель на массив
 * @param size количество элементов
 */
void sort_cocktail_int(int* arr, int size);

#endif