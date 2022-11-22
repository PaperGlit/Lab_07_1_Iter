#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_07_1_Iter/Lab_07_1_Iter.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

void TestChange(int** a, const int col1, const int col2, const int rowCount)
{
	int tmp;
	for (int j = 0; j < rowCount; j++)
	{
		tmp = a[j][col1];
		a[j][col1] = a[j][col2];
		a[j][col2] = tmp;
	}
}

void TestSort(int** a, const int rowCount, const int colCount)
{
	for (int i0 = 0; i0 < colCount - 1; i0++)
		for (int i1 = 0; i1 < colCount - i0 - 1; i1++)
			if ((a[0][i1] < a[0][i1 + 1])
				||
				(a[0][i1] == a[0][i1 + 1] &&
					a[1][i1] > a[1][i1 + 1])
				||
				(a[0][i1] == a[0][i1 + 1] &&
					a[1][i1] == a[1][i1 + 1] &&
					a[2][i1] > a[2][i1 + 1]))
				Change(a, i1, i1 + 1, rowCount);
}

void TestCalc(int** a, const int rowCount, const int colCount, int& S, int& k)
{
	for (int i = 0; i < rowCount; i++)
		for (int j = 0; j < colCount; j++)
			if (a[i][j] % 2 == 0 && i + j % 8 != 0)
			{
				S += a[i][j];
				k++;
			}
}

namespace UnitTestLab071Iter
{
	TEST_CLASS(UnitTestLab071Iter)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			srand((unsigned)time(NULL));
			int Low = 7;
			int High = 62;
			int w, x, y, z;
			int rowCount = 7;
			int colCount = 6;
			int** a = new int* [rowCount];
			for (int i = 0; i < rowCount; i++)
				a[i] = new int[colCount];
			Create(a, rowCount, colCount, Low, High);
			int** b = a;
			TestSort(a, rowCount, colCount);
			Sort(b, rowCount, colCount);
			for (int i = 0; i < rowCount; i++)
				for (int j = 0; j < colCount; j++)
					Assert::AreEqual(a[i][j], b[i][j]);
			TestCalc(a, rowCount, colCount, w, x);
			Calc(b, rowCount, colCount, y, z);
			Assert::AreEqual(w, y);
			Assert::AreEqual(x, z);
		}
	};
}
