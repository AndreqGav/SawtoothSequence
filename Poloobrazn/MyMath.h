#include "stdafx.h"
#include <iostream>

// ���������� ����������
int factorial(int n);

// �������� �� ������� �, ������ ���������� ���������� ��������
int* Unicum(int *a, int n, int &l);
// ������� ������� ��� ����������� ������� � �������
int* CountRepeat(int *a, int n, int &l);
// ������� ������������� ������������������( ������� count = count/(n1!*n2!*..*nk!), ��� ni - ���-�� ���������� �������� 
int DelCountRepeat(int *a, int n, int l);