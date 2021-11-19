#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define INF 99
//make 7x7 map 
int d[49]; //distance 최종적 최단거리 배열
bool v[49]; //visited 방문처리 배열


void array_49row(int (*arr)[7],int row,int column)  //초기 위치(요소값=0)에 따른 49개의 열 생성 
{
	int i, j;
	
	arr[row][column] = 0; //초기 위치

	for (i = 0; i < 7; i++)
	{

		for (j = 0; j < 7; j++) {


			if ((i == row + 1) || (j == column + 1))
			{
				//1번째 case
				if ((i == row + 1) && (j != column + 1))
				{
					if (j == column) //j변동없이 i만 1차이
						arr[i][j] = 1;
					else
						arr[i][j] = INF;
				}
				//2번째 case
				else if ((j == column + 1) && (i != row + 1))
				{
					if (i == row) //i변동없이 j만 1차이
						arr[i][j] = 1;
					else
						arr[i][j] = INF;
				}
				//3번째 case
				else
				{
					arr[i][j] = INF;
				}
			}
			else {
				if (!((i == row) && (j == column)))
					arr[i][j] = INF;
			}

			if ((row >= 1) || (column >= 1))    //row, column 가 1이상이어야 왼쪽 위쪽 비교
			{
				if ((i == row - 1) || (j == column - 1))       //row-1은 위쪽 , column-1은 왼쪽 과의 비교
				{
					//1번째 case
					if ((i == row - 1) && (j != column - 1))
					{
						if (j == column)
							arr[i][j] = 1;
						else
							arr[i][j] = INF;
					}
					//2번째 case
					else if ((j == column - 1) && (i != row - 1))
					{
						if (i == row)
							arr[i][j] = 1;
						else
							arr[i][j] = INF;
					}
					//3번째 case
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

int smallindex() //탐색
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

void dijkstra(int (*arr)[49],int start) //다익스트라 알고리즘
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

	int initiate[49][49]; //초기위치에 따른 거리 배열 전부
	
	int* p[49]; //arr_1_dim 각각을 나타낼 포인터 배열
	int arr[7][7];
	int arr_1_dim[49]; //물리적으로 1차원으로 나타낼시 위치
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
					arr_1_dim[7 * i + j] = arr[i][j]; // 7*i+j 의 의미는 메모리 관점 1차원 위치  
				}

			}
			p[row * 7 + column] = arr_1_dim;

			for (int i = 0; i < 49; i++) {
				initiate[row * 7 + column][i] = p[row * 7 + column][i];
			}
		}
	}
	
	/*                   //확인을 위한 출력문
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
	printf("출발지(0~48) : %d\n",start);
	printf("\n");

	dijkstra(initiate, start);

	printf("출발지 위치에서의 거리를 보여줍니다\n");
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
	printf("도착지(0~48) : %d\n",dest);
	printf("출발지%d에서 도착지%d까지의 최단 거리는 %d입니다\n",start,dest, d[dest]);
	



	return 0;
}