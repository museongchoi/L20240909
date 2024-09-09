#include <iostream>
#include <conio.h>

using namespace std;

char Key;
int PlayerX = 1;
int PlayerY = 1;
bool bIsRunning = true;

void MakeMap(int** arr, int row, int col)
{
	for (int i = 0; i < row; i++)
	{
		arr[i] = new int[col];
	}
}

void deleteMakeMap(int** arr, int row, int col)
{
	for (int i = 0; i < row; i++)
	{
		delete[] arr[i];
	}
}

void Process()
{
	if (Key == 'w')
	{
		PlayerY--;
	}
	if (Key == 's')
	{
		PlayerY++;
	}
	if (Key == 'a')
	{
		PlayerX--;
	}
	if (Key == 'd')
	{
		PlayerX++;
	}
	if (Key == 'q')
	{
		bIsRunning = false;
	}
}

void Input()
{
	//cin >> Key;
	Key = _getch();
}

void ClearConsole()
{
	system("cls");
}

void Move(int row, int col)
{
	ClearConsole();
	for (int y = 0; y < row; y++)
	{
		for (int x = 0; x < col; x++)
		{
			if (PlayerX >= 0 && PlayerX <= col && PlayerY >= 0 && PlayerY <= row)
			{
				if (PlayerX == x && PlayerY == y)
				{
					cout << "*";
				}
			}
			else
			{
				bIsRunning = false;
			}
			cout << " ";
		}
		cout << endl;
	}
}


int main()
{
	cout << "������ �ִ� ������ �Է��ϼ���. row/col : ";
	int row = 0;
	int col = 0;
	cin >> row >> col;
	cout << endl;
	cout << "wasd �� �����̼���.";

	int** arr = new int* [row];
	MakeMap(arr, row, col);

	while (bIsRunning)
	{
		Input();
		Process();
		Move(row, col);
	}
	cout << "�� ������ �������ϴ�.";
	deleteMakeMap(arr, row, col);
	delete[] arr;

	return 0;
}