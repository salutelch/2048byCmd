#pragma once
#include <iostream>
#include <iomanip>
#include <ctime>
#include <conio.h>
using namespace std;

#ifndef __cplusplus
extren "C" {
#endif

	//���λ�ò�������
	void Rand();

	//��ʼ��
	void InIt();

	//��ӡ
	void Print();

	//��
	void Up();

	//��
	void left();

	//��
	void down();

	//��
	void right();

	//�ж϶�ά�������Ƿ��п�λ
	bool For_Null();

	//���ж��ܷ��ƶ������鸳ֵ
	void setDontMove();

	//�ж��Ƿ��ܹ��ƶ�
	bool Stop();

	//���ж���Ϸ���������鸳ֵ
	void setOver();

	//�ж��Ƿ���Ϸ����
	bool GameOver();


#ifndef __cplusplus
}
#endif