#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#define INF 99
								//make 7x7 
int d[49]; //distance 
bool v[49]; //visited


int smallindex()
{
	int min = INF;
	int index = 0;
	for (int i = 0; i < 49; i++)
	{
		if (d[i] < min && !v[i])
		{
			min = d[i];
			index = i;
		}
	}
	return index;
}
void array_49row(int (*arr)[7],int row,int column)
{
	int i, j;
	
	arr[row][column] = 0; //�ʱ� ��ġ
			//==================================================================49�� ����
	for (i = 0; i < 7; i++)
	{

		for (j = 0; j < 7; j++) {


			if ((i == row + 1) || (j == column + 1))
			{
				//1��° case
				if ((i == row + 1) && (j != column + 1))
				{
					if (j == column) //j�������� i�� 1����
						arr[i][j] = 1;
					else
						arr[i][j] = INF;
				}
				//2��° case
				else if ((j == column + 1) && (i != row + 1))
				{
					if (i == row) //i�������� j�� 1����
						arr[i][j] = 1;
					else
						arr[i][j] = INF;
				}
				//3��° case
				else
				{
					arr[i][j] = INF;
				}
			}
			else {
				if (!((i == row) && (j == column)))
					arr[i][j] = INF;
			}

			if ((row >= 1) || (column >= 1))    //row, column �� 1�̻��̾�� ���� ���� ��
			{
				if ((i == row - 1) || (j == column - 1))       //row-1�� ���� , column-1�� ���� ���� ��
				{
					//1��° case
					if ((i == row - 1) && (j != column - 1))
					{
						if (j == column)
							arr[i][j] = 1;
						else
							arr[i][j] = INF;
					}
					//2��° case
					else if ((j == column - 1) && (i != row - 1))
					{
						if (i == row)
							arr[i][j] = 1;
						else
							arr[i][j] = INF;
					}
					//3��° case
					else
					{
						arr[i][j] = INF;
					}
				}
			}
			printf("%5d", arr[i][j]);
		}

		printf("\n");
	}
	//====================================================================================49�� ����
	printf("\n");
}
void dijkstra(int (*arr)[49],int start)
{
	for (int i = 0; i < 49; i++)
	{
		d[i] = arr[start][i];
	}
	v[start] = true;
	for (int i = 0; i < 48; i++)
	{
		int current = smallindex();
		v[current] = true;
		for (int j = 0; j < 49; j++)
		{
			if (!v[j])
			{
				if (d[current] + arr[current][j] < d[j])
				{
					d[j] = d[current] + arr[current][j];
				}
			}
		}
	}
}
int main(void) {
	srand((unsigned)time(NULL));

	int initiate[49][49];
	//int* p1,*p2;
	int* p[49]; //arr_1_dim ������ ��Ÿ�� ������
	int arr[7][7];
	int arr_1_dim[49]; //���������� 1�������� ��Ÿ���� ��ġ
	int row, column;
	for (row = 0; row < 7; row++)
	{
		for (column = 0; column < 7; column++)
		{
			array_49row(arr, row, column);
			for (int i = 0; i < 7; i++)
			{
				for (int j = 0; j < 7; j++)
				{
					arr_1_dim[7 * i + j] = arr[i][j]; // 7*i+j �� �ǹ̴� �޸� ���� 1���� ��ġ  
				}

			}
			p[row * 7 + column] = arr_1_dim;

			for (int i = 0; i < 49; i++) {
				initiate[row * 7 + column][i] = p[row * 7 + column][i];
			}
		}
	}
	
	/*
	for (int i = 0; i< 49; i++)
	{
		for (int j = 0; j < 49; j++)
		{	
			
			initiate[i][j] = p[i][j];
		}
	}*/
	
	for (int i= 0; i < 49; i++)
	{
		for (int j = 0; j < 49; j++)
		{

			printf("%5d", initiate[i][j]);
		}
		printf("\n\n");
	}

	printf("\n");
	int start;
	start = rand() % 49;
	printf("����� �Է�: %d\n",start);

	dijkstra(initiate, start);
	for (int i = 0; i < 49; i++)
	{
		printf("%3d", d[i]);
	}
	printf("\n");
	
	int dest;
	dest = rand() % 49;
	if (dest == start)
	{
		dest = rand() % 49;
	}
	printf("������ : %d\n",dest);


	printf("������������ �Ÿ��� %d�Դϴ�\n", d[dest]);
	




	/*
	array_49row(arr, 0, 0);  //�ʱ� ��ġ(�ڽŰ�=0) �ε����� i,j������
	for (int i = 0; i < 7; i++)
	{
		for (int j = 0; j < 7; j++)
		{
			arr_1_dim[7 * i + j] = arr[i][j]; // 7*i+j �� �ǹ̴� �޸� ���� 1���� ��ġ  
		}

	}
	p1 = arr_1_dim;
	for (int i = 0; i < 49; i++)
	{
	
			printf("%3d",p1[i]); // 7*i+j �� �ǹ̴� �޸� ���� 1���� ��ġ  
		
	}
	printf("\n");
	
	array_49row(arr, 0, 1);

	for (int i = 0; i < 7; i++)
	{
		for (int j = 0; j < 7; j++)
		{
			arr_1_dim[7 * i + j] = arr[i][j]; // 7*i+j �� �ǹ̴� �޸� ���� 1���� ��ġ  
		}

	}
	p2 = arr_1_dim;
	for (int i = 0; i < 49; i++)
	{

		printf("%3d", p2[i]); // 7*i+j �� �ǹ̴� �޸� ���� 1���� ��ġ  

	}
	*/
	
	/*
	int* p[49];
	for (int i = 0; i < 7; i++)
	{
		for (int j = 0; j < 7; j++)
		{
			p[7*i+j] 
		}
	}
	*/	

	return 0;
}