#include "math.h"
#include <cmath>
#include "iostream"
#include <string>
#include <iomanip>
#include <algorithm>
#include <fstream>
#include <stdio.h>

using namespace std;

/*Задание.
	Массив боссов и среди них с максимальной зарплатой
*/

int q = 1000000;
int* p = new int[q];

class Sotrudnik
{
public:
	int zarplata;
	void display_1()
	{
		cout << "\tZarplata: " << zarplata << endl;
	}

};
class Boss : public Sotrudnik
{
public:
	int nadbavka;
	void display_2()
	{
		cout << "\nZarplata sotrudnica: " << zarplata << endl;
		cout << "Zarplata bossa: " << zarplata + nadbavka << endl;
	}
};

class Srav : public Boss
{
public:
	Srav(int pr)
	{
		price = pr;
	}

	void displ1(int i)
	{
		if (price > 0)
		{
			cout << i+1 <<" boss price > " << i+2 << " boss price.\n";

		}
		else if (price < 0)
		{
			cout << i + 1 << " boss price < " << i + 2 << " boss price.\n";
		}
		else
		{
			cout << i + 1 << " boss price = " << i + 2 << " boss price.\n";
		}
	}
	int price;
};

Srav operator - (Srav c1, Srav c2)
{
	return Srav(c1.price - c2.price);
}

void Otdel(int f)
{
	int pr;
	int nad;
	for (int i = 0; i < f; i++)
	{
		cout << "\n-------- " << i+1 << " otdel --------";

		cout << "\nVvedite zarplatu sotrudnica:\t";
		cin >> pr;

		cout << "\nVvedite nadbavku bossa:\t";
		cin >> nad;

		Boss sotr;
		sotr.zarplata = pr;
		sotr.nadbavka = nad;
		sotr.display_2();
		p[i] = pr + nad;
	}

	for (int i = 0; i < f-1; i++)
	{
		Srav c1(p[i]);
		Srav c2(p[i + 1]);
		Srav c3 = c1 - c2;
		c3.displ1(i);
	}
}

int main()
{
	int col;
	cout << "Vvedite col-vo otdelod: ";
	cin >> col;
	Otdel(col);

	int max = p[0];
	for (int i = 0; i < col; i++)
	{
		if (max < p[i])
		{
			max = p[i];
		}
		else
		{
			max = max;
		}
	}
	cout << "\nMaximalnaya zarplata - " << max << endl;
}