
#include "stdafx.h"
#include "iostream"
#include "ctime"

using namespace std;

void Check(int **matrix, int i, int j, int M, int N); // фунцкия обработки элементов матрицы
void deleteRight(int **matrix, int x, int y, int M, int N);
void deleteLeft(int **matrix, int x, int y, int M, int N);
void deleteDown(int **matrix, int x, int y, int M, int N);
void deleteUp(int **matrix, int x, int y, int M, int N);
int main()
{
	setlocale(0, "rus");
	srand(time(0)); // временной рандом

	int islands = 0, M, N; // кол-во островов и размер матрицы
	cout << "Введите размер карты:" << endl;
	cout << "Строк: "; cin >> M;
	cout << "Столбцов: "; cin >> N;
	int **matrix = new int *[M]; // матрица - указатели на указатели
	///////////////////////////////
	/// СОЗДАНИЕ МАССИВА //////////
	for (int i = 0; i < M; i++)
	{
		matrix[i] = new int[N];
	}
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			matrix[i][j] = rand() % 2; // числа от 0 до 1
		}
	}
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cout << matrix[i][j];
		}
		cout << endl;
	}
	///////////////////////////////
	///// Реализуем проверку /////////
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (matrix[i][j] == 1) // если текущий элемент
			{
				Check(matrix, i, j, M, N); // вызываем функцию
				islands += 1; // подсчитываем острова
			}
		}
	}
	///////////////////////////////
	cout << "Количество островов =  " << islands << endl;
}
void Check(int **matrix, int i, int j, int M, int N) // на вход принимаем матрицу, её размер, текущие счётчики i,j
{
	//bool found = false;
	int x = i; // используем локаньные переменные
	int y = j; // тем самым оставляем исходные счётчики неизменяемыми функцией
	if (y + 1 < N && matrix[x][y + 1] == 1) // поиск справа (с проверкой)
	{
		// matrix[x][y + 1] = 0;        // зануляем/отбрасываем найдённые единицы
		// y += 1;                        // изменяем индексы элемента. Тем самым переходим на следующий элемент
		deleteRight(matrix, x, y, M, N);
		       // рекурсия для проверки, есть ли ещё единицы
	}
	if (x + 1 < M && matrix[x + 1][y] == 1) // поиск внизу
	{
		// matrix[x + 1][y] = 0;
		// x += 1;
		deleteDown(matrix, x, y, M, N);
		Check(matrix, x, y, M, N);
	}
	if (y - 1 >= 0 && matrix[x][y - 1] == 1) // поиск слева
	{
		deleteLeft(matrix, x, y, M, N);
		Check(matrix, x, y, M, N);
	}
	if (x - 1 >= 0 && matrix[x - 1][y] == 1) // поиск вверху
	{
		deleteUp(matrix, x, y, M, N);
		Check(matrix, x, y, M, N);
	}
}
void deleteRight(int **matrix, int x, int y, int M, int N) // удаление справа
{
	int a = x;
	int b = y;

		matrix[a][b + 1] = 0;
		b += 1;
		Check(matrix, a, b, M, N);
}
void deleteLeft(int **matrix, int x, int y, int M, int N) // удаление слева
{
	int a = x;
	int b = y;

		matrix[a][b - 1] = 0;
		b -= 1;
		Check(matrix, a, b, M, N);
}
void deleteDown(int **matrix, int x, int y, int M, int N) // удаление снизу
{
	int a = x;
	int b = y;

		matrix[a + 1][b] = 0;
		a += 1;
		Check(matrix, a, b, M, N);
}
void deleteUp(int **matrix, int x, int y, int M, int N) // удаление сверху
{
	int a = x;
	int b = y;
		
		matrix[a - 1][b] = 0;
		a -= 1;
		Check(matrix, a, b, M, N);
}