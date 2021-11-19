#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define INF 99
//make 7x7 map 
int d[49]; //distance ������ �ִܰŸ� �迭
bool v[49]; //visited �湮ó�� �迭


void array_49row(int (*arr)[7],int row,int column)  //�ʱ� ��ġ(��Ұ�=0)�� ���� 49���� �� ���� 
{
	int i, j;
	
	arr[row][column] = 0; //�ʱ� ��ġ

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
			//printf("%5d", arr[i][j]);
		}

		//printf("\n");
	}
	
	//printf("\n");
}

int smallindex() //Ž��
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

void dijkstra(int (*arr)[49],int start) //���ͽ�Ʈ�� �˰���
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

	int initiate[49][49]; //�ʱ���ġ�� ���� �Ÿ� �迭 ����
	
	int* p[49]; //arr_1_dim ������ ��Ÿ�� ������ �迭
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
	
	/*                   //Ȯ���� ���� ��¹�
	for (int i= 0; i < 49; i++)
	{
		for (int j = 0; j < 49; j++)
		{

			printf("%5d", initiate[i][j]);
		}
		printf("\n\n");
	}*/
	//printf("\n");
	int start;
	start = rand() % 49;
	printf("�����(0~48) : %d\n",start);
	printf("\n");

	dijkstra(initiate, start);

	printf("����� ��ġ������ �Ÿ��� �����ݴϴ�\n");
	for (int i = 0; i < 49; i++)
	{
		printf("%3d", d[i]);
		if ((i+1) % 7 == 0)
		{
			printf("\n");
		}
	}
	printf("\n");
	
	int dest;
	dest = rand() % 49;
	if (dest == start)
	{
		dest = rand() % 49;
	}
	printf("������(0~48) : %d\n",dest);
	printf("�����%d���� ������%d������ �ִ� �Ÿ��� %d�Դϴ�\n",start,dest, d[dest]);
	



	return 0;
}