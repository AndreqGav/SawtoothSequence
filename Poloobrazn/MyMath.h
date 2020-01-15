#include "stdafx.h"
#include <iostream>

// вычисление факториала
int factorial(int n);

// создание за массива а, массив содержащий уникальные элементы
int* Unicum(int *a, int n, int &l);
// подсчет сколько раз повторяется элемент в массиве
int* CountRepeat(int *a, int n, int &l);
// удаляем повторяющиеся последовательности( формула count = count/(n1!*n2!*..*nk!), где ni - кол-во повторений элемента 
int DelCountRepeat(int *a, int n, int l);