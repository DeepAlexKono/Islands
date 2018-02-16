
#include "stdafx.h"
#include "iostream"
#include "ctime"

using namespace std;

void Check(int **matrix, int i, int j, int M, int N); // ������� ��������� ��������� �������
void deleteRight(int **matrix, int x, int y, int M, int N);
void deleteLeft(int **matrix, int x, int y, int M, int N);
void deleteDown(int **matrix, int x, int y, int M, int N);
void deleteUp(int **matrix, int x, int y, int M, int N);
int main()
{
	setlocale(0, "rus");
	srand(time(0)); // ��������� ������

	int islands = 0, M, N; // ���-�� �������� � ������ �������
	cout << "������� ������ �����:" << endl;
	cout << "�����: "; cin >> M;
	cout << "��������: "; cin >> N;
	int **matrix = new int *[M]; // ������� - ��������� �� ���������
	///////////////////////////////
	/// �������� ������� //////////
	for (int i = 0; i < M; i++)
	{
		matrix[i] = new int[N];
	}
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			matrix[i][j] = rand() % 2; // ����� �� 0 �� 1
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
	///// ��������� �������� /////////
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (matrix[i][j] == 1) // ���� ������� �������
			{
				Check(matrix, i, j, M, N); // �������� �������
				islands += 1; // ������������ �������
			}
		}
	}
	///////////////////////////////
	cout << "���������� �������� =  " << islands << endl;
}
void Check(int **matrix, int i, int j, int M, int N) // �� ���� ��������� �������, � ������, ������� �������� i,j
{
	//bool found = false;
	int x = i; // ���������� ��������� ����������
	int y = j; // ��� ����� ��������� �������� �������� ������������� ��������
	if (y + 1 < N && matrix[x][y + 1] == 1) // ����� ������ (� ���������)
	{
		// matrix[x][y + 1] = 0;        // ��������/����������� �������� �������
		// y += 1;                        // �������� ������� ��������. ��� ����� ��������� �� ��������� �������
		deleteRight(matrix, x, y, M, N);
		       // �������� ��� ��������, ���� �� ��� �������
	}
	if (x + 1 < M && matrix[x + 1][y] == 1) // ����� �����
	{
		// matrix[x + 1][y] = 0;
		// x += 1;
		deleteDown(matrix, x, y, M, N);
		Check(matrix, x, y, M, N);
	}
	if (y - 1 >= 0 && matrix[x][y - 1] == 1) // ����� �����
	{
		deleteLeft(matrix, x, y, M, N);
		Check(matrix, x, y, M, N);
	}
	if (x - 1 >= 0 && matrix[x - 1][y] == 1) // ����� ������
	{
		deleteUp(matrix, x, y, M, N);
		Check(matrix, x, y, M, N);
	}
}
void deleteRight(int **matrix, int x, int y, int M, int N) // �������� ������
{
	int a = x;
	int b = y;

		matrix[a][b + 1] = 0;
		b += 1;
		Check(matrix, a, b, M, N);
}
void deleteLeft(int **matrix, int x, int y, int M, int N) // �������� �����
{
	int a = x;
	int b = y;

		matrix[a][b - 1] = 0;
		b -= 1;
		Check(matrix, a, b, M, N);
}
void deleteDown(int **matrix, int x, int y, int M, int N) // �������� �����
{
	int a = x;
	int b = y;

		matrix[a + 1][b] = 0;
		a += 1;
		Check(matrix, a, b, M, N);
}
void deleteUp(int **matrix, int x, int y, int M, int N) // �������� ������
{
	int a = x;
	int b = y;
		
		matrix[a - 1][b] = 0;
		a -= 1;
		Check(matrix, a, b, M, N);
}