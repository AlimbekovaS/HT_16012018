#include<iostream>
#include<stdio.h>
#include<time.h>
#include<iomanip>
using namespace std;
unsigned short int z;
void rand(int *a, int size);
void DoubbleRand(int a[][4], const int row, const int col);
void BubbleSort(int *a, int size);
void main() {
	srand(time(0));
	setlocale(LC_ALL, "ru");
	while (true)
	{
		cout << "\nКакое задание?";
		cin >> z;
		if (z == 0)
		{
			break;
		}
		else if (z == 1)
		{
			//1.Дано целое число в двоичной системе счисления, т.е. последовательность цифр  0 и 1. Составить программу перевода этого числа в восьмеричную систему счисления.
			int bin[12];
			int i, j = 0;
			int index = 0;
			for (i = 0; i < 12; i++)
			{
				bin[i] = 0 + rand() % 2;
				cout << bin[i];
			}
			cout << endl;
			for (i = 11; i >= 0; i--)
			{
				j += bin[index] * (pow(2, i));
				index++;
			}
			cout << "Десятичное число " << j << endl;
			cout << "Восьмеричое число = " << oct << j << endl;

		}
		else if (z == 2)
		{
			//2.Ввести два массива действительных чисел, состоящих из 7 и  9 элементов. Сформировать третий массив из упорядоченных по убыванию значений обоих массивов.
			const int size = 7;
			const int size1 = 9;
			const int size2 = size + size1;
			int sizeP = size2 - size1;
			int arr[size], arr1[size1], arr2[size2];
			cout << "Первый массив: ";
			rand(arr, size);
			cout << "\nВторой массив: ";
			rand(arr1, size1);
			for (int i = 0; i < size; i++)
			{
				arr2[i] = arr[i];
			}
			int count = 0;
			for (int i = sizeP; i < size2; i++)
			{
				arr2[i] = arr1[count];
				count++;
			}
			cout << " \nОтсортированный массив: ";
			BubbleSort(arr2, size2);
		}
		else if (z == 3)
		{
			//3.	Ввести массив, в котором только два одинаковых элемента. Определить их местоположение.
			int mas[10] = { 5,8,5,3,4,7,1,6,2,0 }, index1 = 0, index2 = 0;
			for (int i = 0; i < 10; i++)
			{
				int f = 0;
				for (int j = 0; j < 10; j++) {
					if (i == j)
					{
						continue;
					}
					if (mas[i] == mas[j])
					{
						index1 = i;
						index2 = j;
						f = 1;
					}
				}
				if (f == 1)
				{
					break;
				}
			}
			cout << "местоположение первого элемента= " << index1 + 1;
			cout << "\nместоположение второго элемента= " << index2 + 1;
		}
		else if (z == 4)
		{

		}
		else if (z == 5)
		{
			//5.	Отсортировать по убыванию элементов последнего столбца целочисленный двухмерный массив 5×4
			int mas[5][4], mas1[5];
			for (int i = 0; i < 5; i++)
			{
				for (int j = 0; j < 4; j++)
				{
					mas[i][j] = rand() % 50;
					cout << setw(4) << mas[i][j];
				}
				cout << endl;
			}
			for (int i = 0; i < 5; i++)
			{
				for (int j = 3; j < 4; j++)
				{
					mas1[i] = mas[i][j];
				}
			}
			cout << "Отсортированные поубывнию элементы последнего столбца: ";
			for (int i = 0; i < 4; i++)
			{
				int f = 0;
				for (int j = 4; j > i; j--)
				{
					if (mas1[j] > mas1[j - 1])
					{
						int tmp = mas1[j];
						mas1[j] = mas1[j - 1];
						mas1[j - 1] = tmp;
						f = 1;
					}
				}
				if (f == 0)
				{
					break;
				}
			}
			for (int i = 0; i < 5; i++)
			{
				cout << mas1[i] << " ";
			}
		}
		else if (z == 6)
		{
			//6.	В матрице А(3-строки,4-столбца) поменять местами наименьшие элементы в первой и третей строке.
			const int row = 3, col = 4;
			int A[row][col], min, min1, index = 0, index1 = 0;
			DoubbleRand(A, 3, 4);
			for (int i = 0; i < 1; i++)
			{
				min = A[0][0];
				for (int j = 0; j < col; j++)
				{
					if (A[i][j] < min)
					{
						min = A[i][j];
						index = j;
					}
				}
			}
			for (int i = 2; i < 3; i++)
			{
				min1 = A[2][0];
				for (int j = 0; j < col; j++)
				{

					if (A[i][j] < min1)
					{
						min1 = A[i][j];
						index1 = j;
					}
				}
			}

			for (int i = 0; i < row; i++)
			{
				for (int j = 0; j < col; j++)
				{
					A[0][index] = min1;
					A[2][index1] = min;
				}
			}

			cout << endl <<"наименьший элемент в первой строке= "<< min << "\tнаименьший элемент в третей строке " << min1 << endl;
			for (int i = 0; i < row; i++)
			{
				for (int j = 0; j < col; j++)
				{
					cout << setw(4) << A[i][j];
				}
				cout << endl;
			}
		}
		else if (z == 7)
		{
			//7.Дан двухмерный массив 5×6. Определить среднее арифметическое каждого столбца,  определить максимум и минимум каждой строки.
			int matrix[5][6], sum1 = 0, sum2 = 0, sum3 = 0, sum4 = 0, sum5 = 0, sum6 = 0;
			int max1, min1, max2, min2, max3, min3, max4, min4, max5, min5;
			float sr_arif1, sr_arif2, sr_arif3, sr_arif4, sr_arif5, sr_arif6;
			for (int i = 0; i < 5; i++)
			{
				for (int j = 0; j < 6; j++)
				{
					matrix[i][j] = rand() % -50;
					cout << setw(4) << matrix[i][j];
				}
				cout << endl;
			}
			for (int i = 0; i < 5; i++)
			{
				for (int j = 0; j < 1; j++)
				{
					sum1 += matrix[i][j];
				}
			}
			for (int i = 0; i < 5; i++)
			{
				for (int j = 1; j < 2; j++)
				{
					sum2 += matrix[i][j];
				}
			}
			for (int i = 0; i < 5; i++)
			{
				for (int j = 2; j < 3; j++)
				{
					sum3 += matrix[i][j];
				}
			}
			for (int i = 0; i < 5; i++)
			{
				for (int j = 3; j < 4; j++)
				{
					sum4 += matrix[i][j];
				}
			}
			for (int i = 0; i < 5; i++)
			{
				for (int j = 4; j < 5; j++)
				{
					sum5 += matrix[i][j];
				}
			}
			for (int i = 0; i < 5; i++)
			{
				for (int j = 5; j < 6; j++)
				{
					sum6 += matrix[i][j];
				}
			}
			sr_arif1 = sum1 / 6;
			sr_arif2 = sum2 / 6;
			sr_arif3 = sum3 / 6;
			sr_arif4 = sum4 / 6;
			sr_arif5 = sum5 / 6;
			sr_arif6 = sum6 / 6;
			cout << "Ср.ариф первого столбца: " << sr_arif1
				<< "\nСр.ариф второго столбца: " << sr_arif2
				<< "\nСр.ариф третьего столбца: " << sr_arif3
				<< "\nСр.ариф четвертого столбца: " << sr_arif4
				<< "\nСр.ариф пятого столбца: " << sr_arif5
				<< "\nСр.ариф шестого столбца: " << sr_arif6 << endl;

			for (int i = 0; i < 1; i++)
			{
				max1 = matrix[0][0], min1 = matrix[0][0];
				for (int j = 0; j < 6; j++)
				{
					if (matrix[i][j] < min1)
						min1 = matrix[i][j];
					if (matrix[i][j] > max1)
						max1 = matrix[i][j];
				}
			}
			for (int i = 1; i < 2; i++)
			{
				max2 = matrix[1][0], min2 = matrix[1][0];
				for (int j = 0; j < 6; j++)
				{
					if (matrix[i][j] < min2)
						min2 = matrix[i][j];
					if (matrix[i][j] > max2)
						max2 = matrix[i][j];
				}
			}
			for (int i = 2; i < 3; i++)
			{
				max3 = matrix[2][0], min3 = matrix[2][0];
				for (int j = 0; j < 6; j++)
				{
					if (matrix[i][j] < min3)
						min3 = matrix[i][j];
					if (matrix[i][j] > max3)
						max3 = matrix[i][j];
				}
			}
			for (int i = 3; i < 4; i++)
			{
				max4 = matrix[3][0], min4 = matrix[3][0];
				for (int j = 0; j < 6; j++)
				{
					if (matrix[i][j] < min4)
						min4 = matrix[i][j];
					if (matrix[i][j] > max4)
						max4 = matrix[i][j];
				}
			}
			for (int i = 4; i < 5; i++)
			{
				max5 = matrix[4][0], min5 = matrix[4][0];
				for (int j = 0; j < 6; j++)
				{
					if (matrix[i][j] < min5)
						min5 = matrix[i][j];
					if (matrix[i][j] > max5)
						max5 = matrix[i][j];
				}
			}
			cout << "\nmax первой строки " << max1 << "\tmin первой строки " << min1
				<< "\nmax второй строки " << max2 << "\tmin второй строки " << min2
				<< "\nmax третьей строки " << max3 << "\tmin третьей строки " << min3
				<< "\nmax четвертой строки " << max4 << "\tmin четвертой строки " << min4
				<< "\nmax пятой строки " << max5 << "\tmin пятой строки " << min5;
		}
		else if (z == 8)
		{
			//8.	Дан двухмерный массив n×m элементов, найти количество четных и нечетных чисел в массиве.
			int mas[3][4], count = 0, count1 = 0;
			DoubbleRand(mas, 3, 4);
			for (int i = 0; i < 3; i++)
			{
				for (int j = 0; j < 4; j++)
				{
					if (mas[i][j] % 2 == 0)
					{
						count += 1;
					}
					else if (mas[i][j] % 2 != 0)
					{
						count1 += 1;
					}
				}
			}
			cout << "\nколичество четных чисел= " << count << "\t и нечетных чисел в массиве= " << count1 << endl;
		}
		else if (z == 9)
		{
			//9.	Дан двухмерный массив n ×m элементов. Определить, сколько раз встречается число 7 среди элементов массива.
			int mas[3][4], count = 0;
			DoubbleRand(mas, 3, 4);
			for (int i = 0; i < 3; i++)
			{
				for (int j = 0; j < 4; j++)
				{
					if (mas[i][j] == 7)
					{
						count += 1;
					}
				}
			}
			cout << "\n число 7 встречается среди элементов массива " << count << " раз" << endl;
		}
		else if (z == 10)
		{
			//10.	Дан массив из n × m элементов. Найти индексы первого наименьшего  элемента массива
			int mas[3][4], index = 0, index1 = 0;
			DoubbleRand(mas, 3, 4);
			int min = mas[0][0];
			for (int i = 0; i < 3; i++)
			{
				for (int j = 0; j < 4; j++)
				{
					if (mas[i][j] < min)
					{
						min = mas[i][j];
						index = i;
						index1 = j;
					}
				}
			}

			cout << "\n индексы первого наименьшего  элемента массива= " << index + 1 << " " << index1 + 1 << endl;


		}
	}
	system("pause");
}
void rand(int *a, int size)
{
	for (int i = 0; i < size; i++)
	{
		a[i] = rand() % 50;
		cout << a[i] << " ";
	}

}
void DoubbleRand(int a[][4], const int row, const int col)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			a[i][j] = rand() % 50;
			cout << setw(4) << a[i][j];
		}
		cout << endl;
	}
}
void BubbleSort(int *a, int size)
{
	for (int i = 0; i < size - 1; i++)
	{
		int f = 0;
		for (int j = size - 1; j > i; j--)
		{
			if (a[j] < a[j - 1])
			{
				int tmp = a[j];
				a[j] = a[j - 1];
				a[j - 1] = tmp;
				f = 1;
			}
		}
		if (f == 0)
		{
			break;
		}
	}

	for (int i = 0; i < size; i++)
	{
		cout << a[i] << " ";
	}

}


