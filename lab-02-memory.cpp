
#include "pch.h"
#include <intrin.h>
#pragma intrinsic(__rdtsc)
#include <algorithm>
#include <iostream>
#include <ctime>
#include <vector>
using namespace std;
//для измерения числа тактов операции
unsigned __int64 HightTime() {
	_asm {rdtsc
	}
}

_int64 pft_start;
_int64 pft_finish;

#define SPEED_START_CONSOLE pft_start = HightTime();
#define SPEED_FINISH_CONSOLE pft_finish = HightTime(); cout <<"Ticks:"<< (pft_finish - pft_start)/2600000000 << endl;// переводим такты в секунды 

int main()
{
	int HEATING=0;// переменная разогрева 
	int a=0;// переменная прямого обхода 
	int b=0; //переменная обратного обхода
	int c = 0;//переменная рандомного обхода
	int d=0;

	cout << "HEATING : " << endl; 	cin >> HEATING; //разогрев
	vector<int> myvector(HEATING);
	SPEED_START_CONSOLE // прямой обход
		for (int h = 0; h < myvector.size(); h++)
		{
			myvector[h] = h;
			cout << "HEATING"<< endl;
		}
	SPEED_FINISH_CONSOLE

	cout << "enter a : " << endl; 	cin >> a; // прямой обход
	vector<int> myvectora(a);
	SPEED_START_CONSOLE
	for (int i = 0; i < myvectora.size(); i++)
	{
		myvectora[i] = i;
		cout << "value : " << myvectora[i] << endl;
	} 
	SPEED_FINISH_CONSOLE

		cout << "Enter b : " << endl; 	cin >> b;// обратный  обход
	vector<int> myVectorb(b);
		SPEED_START_CONSOLE
	for (int j = myVectorb.size()-1; j>=0; j--) {

		myVectorb[j] = j;
		cout << "Value : " << myVectorb[j] << endl;
	}
		SPEED_FINISH_CONSOLE

	vector<int> myVector ;
	back_insert_iterator<vector<int> > p = back_inserter(myVector);
	cout << "Enter d : " << endl; 	cin >> d;//рандомный  обход
	SPEED_START_CONSOLE
		for (int k = 0; k <d ; ++k) 
		{
			*p = k;
		random_shuffle(myVector.begin(), myVector.end());
		cout << "Value :" << c<<endl;
	}
	SPEED_FINISH_CONSOLE
	

	return 0;
}
