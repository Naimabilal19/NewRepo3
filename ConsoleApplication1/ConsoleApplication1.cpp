#include <iostream>
#include <cstring>
using namespace std;

class MyString
{
	char* str; // указатель на строку
	int length; // длина строки
	static int count;
public:
	MyString();
	MyString(const char* string);
	MyString(const MyString&);
	~MyString();
	void Print();
	void Input();
	static void Obj3count();
	void MyStrcpy(MyString& obj1);
	bool MyStrStr(const char* str);
	int  MyChr(char c);
	int MyStrLen();
	void MyStrCat(MyString& b);
	void MyDelChr(char c);
	int MyStrCmp(MyString& b);

};
int MyString::count = 0;

MyString::MyString()
{
	const int length = 81;
	char* str[length];
	count++;

}

MyString::MyString(const char* string)
{
	str = new char[strlen(string) + 1];
	strcpy_s(str, strlen(string) + 1, string);
	length = strlen(string);
	count++;
}

MyString::MyString(const MyString& obj1)
{
	str = new char[strlen(obj1.str) + 1];
	strcpy_s(str, strlen(obj1.str) + 1, obj1.str);
	length = strlen(obj1.str);
	count++;
}

MyString::~MyString()
{
	delete[]str;
}

void MyString::Obj3count()
{
	cout << "Obj3count" << Obj3count << endl;
}

void MyString::Input()
{
	char* st = new char[length];
	cout << "Enter String :";
	cin >> str;
	if (str != nullptr)
	{
		delete[]str;
	}
	str = new char[strlen(st) + 1];
	strcpy_s(str, strlen(st) + 1, st);
	length = strlen(st);
	count++;
	delete[]st;
}

void MyString::Print()
{
	cout << "String:" << str << endl;
	cout << "Length:" << length << endl;
}

void MyString::MyStrcpy(MyString& obj)
{
	if (str != nullptr)
	{
		delete[]str;
	}
	strcpy_s(str, strlen(obj.str) + 1, obj.str);
	length = strlen(obj.str);
	count++;
}

bool MyString::MyStrStr(const char* string)
{
	return strstr(str, string);
}

int MyString::MyChr(char c)
{
	for (int i = 0; i < strlen(str); i++)
	{
		if (str[i] == c)
		{
			cout << i << "";
		}
		else
		{
			continue;
		}
	}
	return 0;
}

int MyString::MyStrLen()
{


	return strlen(str);
}

void MyString::MyStrCat(MyString& b)
{
	strcat_s(str, strlen(str) + strlen(b.str) + 1, b.str);
	length = strlen(str);
}

void MyString::MyDelChr(char c)
{
	int count = 0;
	for (int i = 0; i < strlen(str);i++)
	{
		if (str[i] == c)
		{
			continue;
		}
		else
		{
			count++;
		}
	}
	count++;
	char* buff = new char[count];
	int count1 = 0;
	for (int i = 0; i < strlen(str); i++)
	{
		if (str[i] == c)
		{
			continue;
		}
		else
		{
			buff[count1] = str[i];
			count1++;
		}
	}
	delete[]str;
	str = new char[count];
	strcpy_s(str, strlen(buff) + 1, buff);
	length = strlen(str);
	delete[]buff;
}

int MyString::MyStrCmp(MyString& b)
{

	if (strlen(str) < strlen(b.str))
	{
		cout << "-1";
	}
	if (strlen(str) > strlen(b.str))
	{
		cout << "1";
	}
	else
	{
		cout << "0";
	}
}



int main()
{
	MyString obj1("Naima");
	MyString obj2("Bilal");
	obj1.Print();

	obj2.Print();
	MyString::Obj3count();



}