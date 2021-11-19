#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>
//���¼ҽ� ������Ʈ
#define ROAD 0
#define WALL 1
#define DEST 2
#define SOURCE 3

//�Լ� ����
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
			printf("�ý����� �����մϴ�\n"); break;
		}

		switch (n) {
		case 1: set_source_dest(map);break;
		case 2:;break;              //�ִܰŸ� �Լ� ����
		case 3: reset(map);break;
		default: printf("�߸��� �Է��Դϴ�. 0~3���ڸ� �����ּ���\n\n");
		}

	}
}
//�Լ� ����

int print_menu(void) {

	int n;

	printf("1.������� �������� �����մϴ�\n");
	printf("2.�ִܰŸ��� ���մϴ�\n"); //�ִܰŸ����
	printf("3.���� ���½�ŵ�ϴ�\n"); //����
	printf("0.����\n");
	printf(">��ȣ ����: ");
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
				printf("��"); //��
			else if (arr[i][j] == WALL)
				printf("��"); //��
			else if (arr[i][j] == DEST)
				printf("��"); //������
			else if (arr[i][j] == SOURCE)
				printf("��"); //�����
			else
				printf("����\n");  //���� ������ else��

		}
		printf("\n");
	}
}


//���,������ ���� �Լ�
void set_source_dest(int (*arr)[7]) {
	
	int start_row, start_col; //��� ����
	int dest_row, dest_col; //���� ����


   //�����
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
	//������
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
		else if (arr[dest_row][dest_col] == SOURCE);//������� �ߺ� ����
	}
	draw(arr);
}
//�ִܰŸ� ��� �Լ�


//���� ��Ű�� �Լ�
void reset(int (*arr)[7])  //int [7]���� �迭�� ����Ű�� arr��� �迭 ������
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
	printf("������ ���µǾ����ϴ�!\n");
	printf("1���� ����, �ʱ�ȭ�� ������ Ȯ�����ּ���!\n");
}
