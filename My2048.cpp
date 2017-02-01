#include "My2048.h"

//全局变量
int score = 0;
int arr[4][4];
int over[4][4];
int DontMove[4][4];
int temp[4];

bool For_Null()
{
	for (int i = 0; i < 4; ++i)
	{
		for (int j = 0; j < 4; ++j)
		{
			if (arr[i][j] == 0)
				return true;
		}
	}
	return false;
}

void setDontMove()
{
	for (int i = 0; i < 4; ++i)
	{
		for (int j = 0; j < 4; ++j)
		{
			DontMove[i][j] = arr[i][j];
		}
	}
}

bool Stop()
{
	for (int i = 0; i < 4; ++i)
	{
		for (int j = 0; j < 4; ++j)
		{
			if (DontMove[i][j] != arr[i][j])
			{
				return false;
			}
		}
	}
	return true;
}

//随机位置产生数字
void Rand()
{
	while (1)
	{
		int x = rand() % 4;
		int y = rand() % 4;
		if (arr[x][y] == 0)
		{
			arr[x][y] = rand() % 10 ? 2 : 4;
			break;
		}
	}
}

//初始化
void InIt()
{
	for (int i = 0; i < 4; ++i)
	{
		for (int j = 0; j < 4; ++j)
		{
			arr[i][j] = 0;
			over[i][j] = 0;
		}
		temp[i] = 0;
	}
	//随机一个坐标附上值
	int x = rand() % 4;
	int y = rand() % 4;
	arr[x][y] = rand() % 10 ? 2 : 4;

	//随机一个坐标并判断是否有数字后附上值
	if (For_Null())
		Rand();
}

//打印
void Print()
{
	for (int i = 0; i < 4; ++i)
	{
		for (int j = 0; j < 4; ++j)
		{
			cout << setw(4) << arr[i][j] << " ";
		}
		cout << endl;
	}
}

//上
void Up()
{
	bool flag = false;
	int index = 0;
	setDontMove();
	for (int i = 0; i < 4; ++i)
	{
		for (int j = 0; j < 4; ++j)
		{
			//假如坐标为0则跳过
			if (arr[j][i] == 0)
			{
				continue;
			}

			//假如flag为false说明是第一次有数字
			if (!flag)
			{
				temp[index++] = arr[j][i];
				flag = true;
			}
			else
			{
				if (arr[j][i] == temp[index - 1])
				{
					temp[index - 1] += arr[j][i];
					score += (arr[j][i] * 2);
					flag = false;
				}
				else
				{
					temp[index++] = arr[j][i];
					flag = true;
				}
			}
		}
		index = 0;
		flag = false;
		for (int k = 0; k < 4; ++k)
		{
			arr[k][i] = temp[k];
			temp[k] = 0;
		}
	}
	if (!Stop())
	{
		if (For_Null())
		{
			Rand();
		}
	}
}

//左
void left()
{
	bool flag = false;
	int index = 0;
	setDontMove();
	for (int i = 0; i < 4; ++i)
	{
		for (int j = 0; j < 4; ++j)
		{
			//假如坐标为0则跳过
			if (arr[i][j] == 0)
			{
				continue;
			}

			//假如flag为false说明是第一次有数字
			if (!flag)
			{
				temp[index++] = arr[i][j];
				flag = true;
			}
			else
			{
				if (arr[i][j] == temp[index - 1])
				{
					temp[index - 1] += arr[i][j];
					score += (arr[i][j] * 2);
					flag = false;
				}
				else
				{
					temp[index++] = arr[i][j];
					flag = true;
				}
			}
		}
		index = 0;
		flag = false;
		for (int k = 0; k < 4; ++k)
		{
			arr[i][k] = temp[k];
			temp[k] = 0;
		}
	}
	if (!Stop())
	{
		if (For_Null())
		{
			Rand();
		}
	}
}

//下
void down()
{
	bool flag = false;
	int index = 3;
	setDontMove();
	for (int i = 0; i < 4; ++i)
	{
		for (int j = 3; j >= 0; --j)
		{
			//假如坐标为0则跳过
			if (arr[j][i] == 0)
			{
				continue;
			}

			//假如flag为false说明是第一次有数字
			if (!flag)
			{
				temp[index--] = arr[j][i];
				flag = true;
			}
			else
			{
				if (arr[j][i] == temp[index + 1])
				{
					temp[index + 1] += arr[j][i];
					score += (arr[j][i] * 2);
					flag = false;
				}
				else
				{
					temp[index--] = arr[j][i];
					flag = true;
				}
			}
		}
		index = 3;
		flag = false;
		for (int k = 0; k < 4; ++k)
		{
			arr[k][i] = temp[k];
			temp[k] = 0;
		}
	}
	if (!Stop())
	{
		if (For_Null())
		{
			Rand();
		}
	}
}

//右
void right()
{
	bool flag = false;
	int index = 3;
	setDontMove();
	for (int i = 0; i < 4; ++i)
	{
		for (int j = 3; j >= 0; --j)
		{
			//假如坐标为0则跳过
			if (arr[i][j] == 0)
			{
				continue;
			}

			//假如flag为false说明是第一次有数字
			if (!flag)
			{
				temp[index--] = arr[i][j];
				flag = true;
			}
			else
			{
				if (arr[i][j] == temp[index + 1])
				{
					temp[index + 1] += arr[i][j];
					score += (arr[i][j] * 2);
					flag = false;
				}
				else
				{
					temp[index--] = arr[i][j];
					flag = true;
				}
			}
		}
		index = 3;
		flag = false;
		for (int k = 0; k < 4; ++k)
		{
			arr[i][k] = temp[k];
			temp[k] = 0;
		}
	}
	if (!Stop())
	{
		if (For_Null())
		{
			Rand();
		}
	}
}

void setOver()
{
	for (int i = 0; i < 4; ++i)
	{
		for (int j = 0; j < 4; ++j)
		{
			over[i][j] = arr[i][j];
		}
	}
}

bool GameOver()
{
	for (int i = 0; i < 4; ++i)
	{
		for (int j = 0; j < 4; ++j)
		{
			if (arr[i][j] == 0)
			{
				return false;
			}
			if (over[i][j] != arr[i][j])
			{
				return false;
			}
			if (i >= 0 && i < 3 && j >= 0 && j < 3)
			{
				if (arr[i][j] == arr[i + 1][j] || arr[i][j] == arr[i][j + 1])
				{
					return false;
				}
			}
		}
	}
	if (arr[3][3] == arr[3][2] || arr[3][3] == arr[2][3])
		return false;

	return true;
}
