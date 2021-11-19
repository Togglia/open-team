#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>
//오픈소스 프로젝트
#define ROAD 0
#define WALL 1
#define DEST 2
#define SOURCE 3

//함수 선언
void draw(int arr[7][7]);
int print_menu(void);
void set_source_dest(int (*arr)[7]);
void reset(int (*arr)[7]);

int main()
{

	int map[7][7] = { {0,0,0,0,0,0,0},
	{0,1,0,0,1,1,1},
	{0,1,0,0,0,0,0},
	{1,1,0,1,0,0,0},
	{0,0,0,1,0,1,0},
	{0,1,0,1,0,1,0},
	{0,1,0,0,0,1,0} };

	int hide[7][7] = { {0,0,0,0,0,0,0},
		{0,1,0,0,1,1,1},
		{0,1,0,0,0,0,0},
		{1,1,0,1,0,0,0},
		{0,0,0,1,0,1,0},
		{0,1,0,1,0,1,0},
		{0,1,0,0,0,1,0} };



	srand((unsigned)time(NULL));

	int n;
	while (1)
	{
		n = print_menu();

		if (n == 0) {
			printf("시스템을 종료합니다\n"); break;
		}

		switch (n) {
		case 1: set_source_dest(map);break;
		case 2:;break;              //최단거리 함수 실행
		case 3: reset(map);break;
		default: printf("잘못된 입력입니다. 0~3숫자만 눌러주세요\n\n");
		}

	}
}
//함수 정의

int print_menu(void) {

	int n;

	printf("1.출발지와 목적지를 세팅합니다\n");
	printf("2.최단거리를 구합니다\n"); //최단거리계산
	printf("3.맵을 리셋시킵니다\n"); //리셋
	printf("0.종료\n");
	printf(">번호 선택: ");
	scanf_s("%d", &n);

	printf("\n");

	return n;
}


void draw(int arr[7][7])
{
	for (int i = 0; i < 7; i++)
	{
		for (int j = 0; j < 7; j++)
		{
			if (arr[i][j] == ROAD)
				printf("■"); //길
			else if (arr[i][j] == WALL)
				printf("※"); //벽
			else if (arr[i][j] == DEST)
				printf("●"); //목적지
			else if (arr[i][j] == SOURCE)
				printf("▲"); //출발지
			else
				printf("오류\n");  //에러 방지용 else문

		}
		printf("\n");
	}
}


//출발,목적지 세팅 함수
void set_source_dest(int (*arr)[7]) {
	
	int start_row, start_col; //출발 지점
	int dest_row, dest_col; //도착 지점


   //출발지
	while (1)
	{
		start_row = rand() % 7;
		start_col = rand() % 7;

		if (arr[start_row][start_col] == ROAD)
		{
			arr[start_row][start_col] = SOURCE;
			break;
		}
		else if (arr[start_row][start_col] == WALL);

	}
	//목적지
	while (1)
	{
		dest_row = rand() % 7;
		dest_col = rand() % 7;

		if (arr[dest_row][dest_col] == ROAD)
		{
			arr[dest_row][dest_col] = DEST;
			break;
		}
		else if (arr[dest_row][dest_col] == WALL);
		else if (arr[dest_row][dest_col] == SOURCE);//출발지와 중복 방지
	}
	draw(arr);
}
//최단거리 계산 함수


//리셋 시키는 함수
void reset(int (*arr)[7])  //int [7]형의 배열을 가리키는 arr라는 배열 포인터
{	
	int map_reset[7][7] = { {0,0,0,0,0,0,0},
	   {0,1,0,0,1,1,1},
	   {0,1,0,0,0,0,0},
	   {1,1,0,1,0,0,0},
	   {0,0,0,1,0,1,0},
	   {0,1,0,1,0,1,0},
	   {0,1,0,0,0,1,0} };
	
	int i, j;
	for (j = 0;j < 7;j++) {
		for (i = 0;i < 7;i++)
		{
			arr[j][i] = map_reset[j][i];
		}
	}
	printf("지도가 리셋되었습니다!\n");
	printf("1번을 눌러, 초기화된 지도를 확인해주세요!\n");
}
