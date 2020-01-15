#include "stdafx.h"
#include <iostream>
#include<fstream>
#include "MyMath.h"
#include <string>

using namespace std;

int _count = 0;  // ���-�� ��������������� �������������������

// n - ����� ����� �����, k - ����� ��������� � ������������� ������������������, a - ������ �����
// cur - ������� �������  ������������� ����., b - ��������� ������, ���������� ���� ������������ ������� ��� ���
// less - true - ���� ������� ������ ��������, false - ������ ��������
// s - ��� ������������ ������������������

void Pil(int n, int k, int *a, int cur, bool *b, bool less, string s)
{
	if (k == n)
	{
		_count++; // ����������� ����� ������� ������������������� 
		// cout << s << endl; // ����� ������������� ��� ������
		return;
	}
	else
	{
		for (int i = 0; i < n; ++i)
		{
			if (b[i]) // ���� ������� ��� �� ������������ � ���������� ������������������
			{
				if ((cur < a[i]) && less || (cur > a[i]) && !less) // ���������� ������� - ���� ������� ������ ��� ������ ��������
				{
					b[i] = false; // �������, ��� ��������������
					Pil(n, k + 1, a, a[i], b, !less, s + to_string(a[i])); // � �������� ������ less �� �����������������
					//����� ������ �������, ��������������� ������� ������                               ����������� k
					b[i] = true; // ������ �������, ����� ��� ����� ���� ������������ � ���������� ��������� ������.
				}
			}
		}
	}
}

int main()
{
	setlocale(LC_ALL, "Russian");
	int n;
	cout << "������� ���-�� �����" << endl;
	cin >> n;

	int *a = new int[n];

	for (int i = 0; i < n; ++i)
	{
		cin >> a[i];
	}
	/* ���� �� �����
	for (int i = 0; i < n; ++i)
		a[i] = 0;

	ifstream f("input.txt");
	int k = 0;
	// ��������� ������ �� �����
	while (!f.eof() && k < n)
	{
		f >> a[k];
		k++;
	}

	for (int i = 0; i < n; ++i)
		cout << a[i] << ' ';
	*/
	cout << endl;

	bool *b = new bool[n]; // true - ������� ��� �� ������� � ���������� ������������������, false - �����

	for (int i = 0; i < n; ++i)
		b[i] = true;
	// �����:
	// C(n) = G_C(n-1) + L_C(n-1)
	// ��� G_C(n-1) - ������ ������� ������ �������
	// ��� L_C(n-1) - ������ ������ �������
	for (int i = 0; i < n; ++i)
	{
		b[i] = false;
		Pil(n, 1, a, a[i], b, false,""); // G_C(n-1)
		Pil(n, 1, a, a[i], b, true,""); //  L_C(n-1)
		b[i] = true;
	}
	cout << endl;

	// ������� �� ����� ������������� ������������������( ���� ���� ���������� �������� � �������, �� ����� �����)
	int count = DelCountRepeat(a, n, _count);
	cout << "���-�� �������������������: " << count << endl;
	system("pause");
	return 0;
}

