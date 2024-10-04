#include <stdio.h>
#include <stdlib.h>
// Функция "просеивания" через кучу - формирование кучи
void siftDown(int *numbers, int root, int bottom)
{
    int maxChild; // индекс максимального потомка
    int done = 0; // флаг того, что куча сформирована
    // Пока не дошли до последнего ряда
    while ((root * 2 <= bottom) && (!done))
    {
        if (root * 2 == bottom)    // если мы в последнем ряду,
            maxChild = root * 2;    // запоминаем левый потомок
            // иначе запоминаем больший потомок из двух
        else if (numbers[root * 2] > numbers[root * 2 + 1])
            maxChild = root * 2;
        else
            maxChild = root * 2 + 1;
        // если элемент вершины меньше максимального потомка
        if (numbers[root] < numbers[maxChild])
        {
            int temp = numbers[root]; // меняем потомка и родителя местами
            numbers[root] = numbers[maxChild];
            numbers[maxChild] = temp;
            root = maxChild; // корнем становится индекс максимального потомка
        }
        else // иначе
            done = 1; // пирамида сформирована
    }
}
// Функция сортировки на куче
void heapSort(int *numbers, int array_size)
{
    // Формируем нижний ряд пирамиды
    for (int i = (array_size / 2); i >= 0; i--)
        siftDown(numbers, i, array_size - 1);
    // Просеиваем через пирамиду остальные элементы
    for (int i = array_size - 1; i >= 1; i--)
    {
        int temp = numbers[0];
        numbers[0] = numbers[i];
        numbers[i] = temp;
        siftDown(numbers, 0, i - 1);
    }
}
int main()
{
    int a[8] = {1, 5, 6, 11, 7,2,4,45};
    // Заполнение массива случайными числами

    // Вывод элементов массива до сортировки
    for (int i = 0; i<10; i++)
        printf("%d ", a[i]);
    printf("\n");
    heapSort(a, 8); // вызов функции сортировки
    // Вывод элементов массива после сортировки
    for (int i = 0; i<8; i++)
        printf("%d ", a[i]);
    return 0;
}
