#define _CRT_SECURE_NO_WARNINGS
#include "My2048.h"
extern int score;
extern int arr[4][4];
extern int over[4][4];
extern int DontMove[4][4];
extern int temp[4];
using namespace std;

int main(int argc, char *argv[])
{
	int ftime;
	do{
		do
		{
			system("cls");
			score = 0;
			srand((unsigned int)time(NULL));
			//初始化
			InIt();
			//打印
			Print();
			//记录游戏开始时间
			ftime = clock();
			//获取输入
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
					goto OVER;
				}
			}
		} while (1);
OVER:
		//记录游戏结束时间
		int ltime = clock();
		double gtime = ltime - ftime;
		gtime /= 1000;

		//清屏并打印结束信息
		system("cls");
		cout << "死了啊喂ヽ(●-`Д´-)ノ" << endl;
		cout << "这里是你的分数: " << score << endl;
		cout << "游戏时间: " << gtime << "s" << endl;
		cout << "按q退出!" << endl;
		cout << "按a重来!" << endl;
		while (1)
		{
			char ch = _getch();
			if (ch == 'q')
				return 0;
			if (ch == 'a')
				goto AGAIN;
		}

AGAIN:
		continue;

	} while (1);

	system("pause");
	return 0;
}
