#include "stdafx.h"
#include "MyMath.h"


int factorial(int n)
{
	if (n == 0)
		return 1;
	else
	{
		return n*factorial(n - 1);
	}
	return 0;
}


int* Unicum(int *a, int n, int &l)
{
	int *unicum = new int[n];
	l = 0;

	for (int i = 0; i < n; ++i)
	{
		bool isFind = false;
		int j = 0;
		while (!isFind && j < l)
		{
			if (a[i] == unicum[j])
				isFind = true;
			++j;
		}
		if (!isFind)
		{
			unicum[l] = a[i];
			l++;
		}
	}
	return unicum;
}

int* CountRepeat(int *a, int n, int &l)
{
	l = 0;
	int *unicum = Unicum(a, n, l);
	int *repeats = new int[l];
	for (int i = 0; i < l; ++i)
	{
		repeats[i] = 0;
		for (int j = 0; j < n; ++j)
		{
			if (unicum[i] == a[j])
				repeats[i]++;
		}
	}
	return repeats;
}

int DelCountRepeat(int *a, int n, int count)
{
	int l = 0;
	int *repeats = CountRepeat(a, n, l);

	int result = 1;
	for (int i = 0; i < l; ++i)
		result *= factorial(repeats[i]);

	//std::cout << result << std::endl;
	return count/result;
}

