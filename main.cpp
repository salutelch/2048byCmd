#define _CRT_SECURE_NO_WARNINGS
#include "My2048.h"
extern int score;
extern int arr[4][4];
extern int over[4][4];
extern int DontMove[4][4];
extern int temp[4];

int main(int argc, char *argv[])
{
START:
	system("cls");
	score = 0;
	srand((unsigned int)time(NULL));
	//��ʼ��
	InIt();
	//��ӡ
	Print();
	//��¼��Ϸ��ʼʱ��
	int ftime = clock();
	//��ȡ����
	while (1)
	{
		setOver();
		cout << endl;
		cout << "------score: " << score << "------" << endl;
		char ch = _getch();
		if (ch == -32)
		{
			switch (ch = _getch())
			{
			case 72:
				Up();
				system("cls");
				Print();
				break;
			case 80:
				down();
				system("cls");
				Print();
				break;
			case 75:
				left();
				system("cls");
				Print();
				break;
			case 77:
				right();
				system("cls");
				Print();
				break;
			default:
				break;
			}
		}
		if (GameOver())
		{
			goto Over;
		}
	}

Over:
	//��¼��Ϸ����ʱ��
	int ltime = clock();
	double gtime = ltime - ftime;
	gtime /= 1000;

	//��������ӡ������Ϣ
		system("cls");
		cout << "���ɵ�����˰ɹ�������" << endl;
		cout << "��������ķ���: " << score << endl;
		cout << "��Ϸʱ��: " << gtime << "s" << endl;
		cout << "��q�˳�!" << endl;
		cout << "��a����!" << endl;
		while (1)
		{
			char ch = _getch();
			if (ch == 'q')
				return 0;
			if (ch == 'a')
				goto START;
		}

	system("pause");
	return 0;
}