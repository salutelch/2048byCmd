#include "My2048.h"

//ȫ�ֱ���
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

//���λ�ò�������
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

//��ʼ��
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
	//���һ�����긽��ֵ
	int x = rand() % 4;
	int y = rand() % 4;
	arr[x][y] = rand() % 10 ? 2 : 4;

	//���һ�����겢�ж��Ƿ������ֺ���ֵ
	if (For_Null())
		Rand();
}

//��ӡ
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

//��
void Up()
{
	bool flag = false;
	int index = 0;
	setDontMove();
	for (int i = 0; i < 4; ++i)
	{
		for (int j = 0; j < 4; ++j)
		{
			//��������Ϊ0������
			if (arr[j][i] == 0)
			{
				continue;
			}

			//����flagΪfalse˵���ǵ�һ��������
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

//��
void left()
{
	bool flag = false;
	int index = 0;
	setDontMove();
	for (int i = 0; i < 4; ++i)
	{
		for (int j = 0; j < 4; ++j)
		{
			//��������Ϊ0������
			if (arr[i][j] == 0)
			{
				continue;
			}

			//����flagΪfalse˵���ǵ�һ��������
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

//��
void down()
{
	bool flag = false;
	int index = 3;
	setDontMove();
	for (int i = 0; i < 4; ++i)
	{
		for (int j = 3; j >= 0; --j)
		{
			//��������Ϊ0������
			if (arr[j][i] == 0)
			{
				continue;
			}

			//����flagΪfalse˵���ǵ�һ��������
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

//��
void right()
{
	bool flag = false;
	int index = 3;
	setDontMove();
	for (int i = 0; i < 4; ++i)
	{
		for (int j = 3; j >= 0; --j)
		{
			//��������Ϊ0������
			if (arr[i][j] == 0)
			{
				continue;
			}

			//����flagΪfalse˵���ǵ�һ��������
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
