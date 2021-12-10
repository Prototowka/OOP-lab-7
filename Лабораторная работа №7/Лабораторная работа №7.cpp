#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <locale>

using namespace std;

class Word
{
	friend void reverse(Word& a);
public:
	string word;

	string SetWord(string a)
	{
		word = a;
		return word;
	}
};

void reverse(Word &a)
{
	int i;
	string buf = a.word;
	cout << "Your word:" << buf << endl;
	reverse(buf.begin(), buf.end());
	cout << "Reverse word:" << buf << endl;
}

class B1
{
	int a;
public:
	B1() { };
	B1(int x) { a = x; }
	void show_B1() { cout << "B1= " << a << "\n"; }
};
class B2
{
	int b;
public:
	B2() { };
	B2(int x) { b = x; }
	void show_B2() { cout << "B2= " << b << "\n"; }
};
class D1: private B1, public B2
{
	int c;
public:
	D1(int x, int y, int z) : B1(y), B2(z) { c = x; }
	void show_D1() { cout << "D1= " << c << "\n"; show_B2();	}
};
class D2: public B1, private B2
{
	int d;
public:
	D2(int x, int y, int z) : B1(y), B2(z) { d = x; }
	void show_D2() { cout << "D2= " << d << "\n"; show_B2();	}
};
class D3: private D1, public D2
{
	int e;
public:
	D3(int x, int y, int z, int i, int j, int k, int g) : D1(y,z,k), D2(i,j,g) { e = x; }
	void show_D3() { cout << "D3= " << e << "\n"; show_D1(); show_D2(); }
};

int main()
{
	setlocale(LC_ALL, "ru");
	Word one;
	one.SetWord("Hello world!");
	reverse(one);

	D3 temp(1, 2, 3, 4, 5, 6, 7);
	cout << endl << "D3 temp(1, 2, 3, 4, 5, 6, 7)" << endl;
	cout << "Следуя иерархии класса D3:" << endl;
	temp.show_D3();

	return 0;
}