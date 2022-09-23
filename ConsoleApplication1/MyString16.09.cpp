#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <initializer_list>
#include <cstring>
using namespace std;

class MyString
{
	char* str; // указатель на строку
	int length; // длина строки
	static int count;
	int size;
	int* strr;
public:
	MyString();
	MyString(const char* string);

	~MyString()
	{
		delete[]str;
	}

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


	MyString(const MyString& obj2) = delete;
	//MyString& operator = (const MyString& obj2) = delete;
	MyString(MyString&& obj)
	{
		cout << "Constructor MOVE\n";
		str = obj.str; // 
		obj.str = nullptr;

		length = obj.length;
		obj.length = 0;
	}
	/*MyString& operator =(MyString&& obj2)
	{
		if (str != nullptr)
		{
			delete[] str;
		}
		cout << "= MOVE\n";
		str = obj2.str; // 
		obj2.str = nullptr;

		length = obj2.length;

		return *this;
	}*/
	MyString(initializer_list<int> a)// 1 2 3 4 5 
	{
		cout << "Initializer_list constructor\n";
		cout << a.size() << endl;
		size = a.size(); // получаем размер 
		strr = new int[size];
		for (auto x = a.begin(); x != a.end(); x++)
		{
			*strr = *x;
			strr++;
		}
		strr -= size;// смещение указател€ на начало массива 

	}
	MyString(int ar[], int Size)
	{
		cout << "Construct array\n";
		size = Size;
		strr = new int[size];
		for (int i = 0;i < size;i++)
		{
			strr[i] = ar[i];
		}
	}
	void Output()
	{
		for (int i = 0; i < size; i++)
		{
			cout << strr[i] << "\t";
			cout << *(strr + i) << "\t";

			cout << *strr << "\t";
			strr++;
		}
		strr -= size;
		cout << endl;
	}


	//-------------------------------------------------------- 16.09.22
	MyString& operator=(const MyString& obj) //=
	{
		if (this == &obj)
		{
			return *this;
		}
		if (str != nullptr)
		{
			delete[] str;
			this->~MyString();
		}

		str = new char[strlen(obj.str) + 1];
		strcpy_s(str, strlen(obj.str) + 1, obj.str);
		length = obj.length;

		return *this;
	}
	char operator[](int index) //[] получение символа
	{
		if (index >= 0 && index < strlen(str))
		{
			return str[index];
		}
		return '\0';
	}
	void operator() ()
	{
		cout <<"Str & length: "<< str << ", " << length << endl;
	}
	operator int()  //преобразование типа int
	{
		return length;
	}
	operator char* () //преобразование типа char
	{
		return str;
	}
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
}
/*MyString::MyString(const MyString& obj1)
{
	str = new char[strlen(obj1.str) + 1];
	strcpy_s(str, strlen(obj1.str) + 1, obj1.str);
	length = strlen(obj1.str);
	count++;
}*/
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
		return -1;
	}
	if (strlen(str) > strlen(b.str))
	{
		cout << "1";
		return 1;
	}
	else
	{
		cout << "0";
		return 0;
	}
}
MyString ByValue()
{
	MyString obj("BMW");

	return obj; // rvalue ref. &&
}


int main()
{

	MyString a("Naima");

	int length = a;
	cout <<"Str length: "<< length << endl;
	char* str = a;
	cout <<"Str: "<< str << endl;
	a();

	for (int i = 0; i < 10; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;
}