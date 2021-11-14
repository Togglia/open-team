#include <stdio.h>
#include <stdlib.h>
#define INF 99
//함수 내에 다익스트라 넣어야함  7x7로 시도
const int num = 7; //make 7x7 
int d[9];
//int arr[num][num]; //배열의 크기 정하지 못할때 동적할당 써야해서
int** arr;
int row, column; // row column index

void func() {
	int i, j;

	
	for (row = 0; row < num; row++) {
		for (column = 0; column < num; column++) {
			arr[row][column] = 0; //초기 위치

			for (i = 0; i < num; i++)
			{

				for (j = 0; j < num; j++) {
					

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


					//문제점 > i==row-1 이랑 j==column-1도 비교해야

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


					printf("%5d", arr[i][j]);
				}

				printf("\n");
			}
			//int z = 3 * i + j; //3x3일때 1차원적 위치 
			for (i = 0; i < num; i++)
			{
				for (j = 0; j < num; j++)
				{
					d[num* i + j] = arr[i][j];
					printf("d[%d]:%2d ", num * i + j, d[num * i + j]);
				}
				
			}
			printf("\n");

		}
	}
	/*
	for (i = 0; i < num*num; i++) { // 0 ~ n^2 까지

		printf("%3d", d[i]);  //맨 마지막 d[9] 나열
	}
	*/
}

int main(void) {

	arr = (int**)malloc(sizeof(int *) * num);
	
	for (int i = 0; i < num; i++)
		{
			arr[i] =(int*)malloc(sizeof(int) * num);
		}
	
	
	func();

	for (int i = 0; i < num; i++)
	{
		free(arr[i]);
	}
	free(arr);
	
	return 0;
}