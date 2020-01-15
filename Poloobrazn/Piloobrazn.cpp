#include "stdafx.h"
#include <iostream>
#include<fstream>
#include "MyMath.h"
#include <string>

using namespace std;

int _count = 0;  // кол-во удовлетвор€ющих последовательностей

// n - общее число чисел, k - число элементов в промежуточной последовательности, a - массив чисел
// cur - текущий элемент  промежуточной посл., b - булевский массив, содержащтй инфо использовали элемент или нет
// less - true - ищем элемент больше текущего, false - меньше текущего
// s - дл€ визуализации последрвательности

void Pil(int n, int k, int *a, int cur, bool *b, bool less, string s)
{
	if (k == n)
	{
		_count++; // увеличиваем общий счЄтчик последовательностей 
		// cout << s << endl; // будут повтор€ющиес€ при выводе
		return;
	}
	else
	{
		for (int i = 0; i < n; ++i)
		{
			if (b[i]) // если элемент ещЄ не использовали в построении последовательности
			{
				if ((cur < a[i]) && less || (cur > a[i]) && !less) // выполнение услови€ - ищем элемент больше или меньше текущего
				{
					b[i] = false; // помечам, как использованный
					Pil(n, k + 1, a, a[i], b, !less, s + to_string(a[i])); // в вызваной мен€ем less на противоположенное
					//чтобы искать элемент, удовлетвор€ющий условию задачи                               увеличиваем k
					b[i] = true; // ставим обратно, чтобы его можно было использовать в построении следующих послед.
				}
			}
		}
	}
}

int main()
{
	setlocale(LC_ALL, "Russian");
	int n;
	cout << "¬ведите кол-во чисел" << endl;
	cin >> n;

	int *a = new int[n];

	for (int i = 0; i < n; ++i)
	{
		cin >> a[i];
	}
	/* ввод из файла
	for (int i = 0; i < n; ++i)
		a[i] = 0;

	ifstream f("input.txt");
	int k = 0;
	// считываем данные из файла
	while (!f.eof() && k < n)
	{
		f >> a[k];
		k++;
	}

	for (int i = 0; i < n; ++i)
		cout << a[i] << ' ';
	*/
	cout << endl;

	bool *b = new bool[n]; // true - элемент ещЄ не включен в стро€щуюс€ последовательность, false - иначе

	for (int i = 0; i < n; ++i)
		b[i] = true;
	// —хема:
	// C(n) = G_C(n-1) + L_C(n-1)
	// где G_C(n-1) - первый элемент больше второго
	// где L_C(n-1) - первый меньше второго
	for (int i = 0; i < n; ++i)
	{
		b[i] = false;
		Pil(n, 1, a, a[i], b, false,""); // G_C(n-1)
		Pil(n, 1, a, a[i], b, true,""); //  L_C(n-1)
		b[i] = true;
	}
	cout << endl;

	// удал€ем из счета повтор€ющиес€ последовательности( если были одинаковые элементы в массиве, то такие будут)
	int count = DelCountRepeat(a, n, _count);
	cout << " ол-во последовательностей: " << count << endl;
	system("pause");
	return 0;
}

