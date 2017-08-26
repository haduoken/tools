#include "stdafx.h"
//如何比较两个牌的大小
#include <iostream>
using namespace std;
enum cardtype
{
	danzhang=1,
	duizi,
	shunzi,
	jinghua,
	jinghuashun,
	baozi,
};
enum huase
{
	heitao = 0,
	hongtao = 1,
	meihua = 2,
	fangkuai = 3
};
class card {
public:
	int yanse;
	int point;
	card(int i) {
		yanse = (i-1) / 13;
		point = i - yanse * 13;
	}
	card(int i, int j) {
		yanse = i;
		point = j;
	}

};
void paixu(card &a1, card &a2, card &a3);
void duizifenli(card a1, card a2, card a3,int *duipoint);
int convertCardtoint(card a1);
int convertCardtoint(card a1)
{
	return a1.yanse*13 + a1.point;
}
void duizifenli(card a1, card a2, card a3,int *duipoint)
{
	if (a1.point == a2.point || a1.point == a3.point)
		*duipoint = a1.point;
	else 
		*duipoint = a2.point;
}
bool isSunZhi(card a1, card a2,card a3)
{
	paixu(a1, a2, a3);
	if (a1.point == a2.point - 1 && a2.point == a3.point - 1)
		return true;
	return false;
}
cardtype CardType(card a1,card a2,card a3)
{
	if (a1.point == a2.point && a2.point == a3.point)
		return baozi;
	if (a1.yanse == a2.yanse && a2.yanse == a3.yanse)
	{
		if (isSunZhi(a1, a2, a3))	return jinghuashun;
		return jinghua;
	}
	if (isSunZhi(a1, a2, a3)) return shunzi;
	if (a1.point == a2.point || a2.point == a3.point || a1.point == a3.point)
		return duizi;
	return danzhang;
}
void paixu(card &a1, card &a2, card &a3)
{
	if (a1.point > a2.point)
	{
		swap(a1.point, a2.point);
	}
	if (a2.point > a3.point)
	{
		swap(a2.point, a3.point);
	}
	if (a1.point > a2.point)
	{
		swap(a1.point, a2.point);
	}
}
bool compareTwoType(card a1, card a2, card a3, card b1, card b2, card b3)
{
	cardtype atype = CardType(a1, a2, a3);
	cardtype btype = CardType(b1, b2, b3);
	if (atype != btype)
	{
		return atype > btype;
	}
	paixu(a1, a2, a3);
	paixu(b1, b2, b3);
	if (atype !=duizi)
	{	
		if (a3.point != b3.point)
			return a3.point > b3.point;
		if (a2.point != b2.point)
			return a2.point > b2.point;
		else
			return a1.point >= b1.point;
	}
	int aduipoint, bduipoint;
	duizifenli(a1, a2, a3, &aduipoint);
	duizifenli(b1, b2, b3, &bduipoint);
	return aduipoint > bduipoint;		
}
void printlevel(card a1, card a2, card a3)
{
	bool cardmap[52];
	for (int h = 0; h < 52; h++)
		cardmap[h] = true;
	cardmap[convertCardtoint(a1)] = false;
	cardmap[convertCardtoint(a2)] = false;
	cardmap[convertCardtoint(a3)] = false;
	double small = 0, big = 0;
	for(int i=1;i<=50;i++)
		for(int j=i+1;j<=51;j++)
			for (int k = j + 1; k <= 52; k++)
			{
				if (cardmap[i] && cardmap[j] && cardmap[k])
				{
					card tmp1(i);
					card tmp2(j);
					card tmp3(k);
					if (compareTwoType(a1, a2, a3, tmp1, tmp2, tmp3))
						big++;
					else small++;
				}
			}
	cout << "the card is the " << big / (big + small)*100<<"% " << endl;
}
int main()
{
	card a1(heitao,4);
	card a2(hongtao,4);
	card a3(heitao,7);
	printlevel(a1, a2, a3);
}
