#pragma once
#include <iostream>
#include <iomanip>
#include <ctime>
#include <conio.h>
using namespace std;

#ifndef __cplusplus
extren "C" {
#endif

	//随机位置产生数字
	void Rand();

	//初始化
	void InIt();

	//打印
	void Print();

	//上
	void Up();

	//左
	void left();

	//下
	void down();

	//右
	void right();

	//判断二维数组中是否还有空位
	bool For_Null();

	//给判断能否移动的数组赋值
	void setDontMove();

	//判断是否能够移动
	bool Stop();

	//给判断游戏结束的数组赋值
	void setOver();

	//判断是否游戏结束
	bool GameOver();


#ifndef __cplusplus
}
#endif