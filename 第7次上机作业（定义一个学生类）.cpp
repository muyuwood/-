// ConsoleApplication1.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include<cstdio>
#include<string>
#include<algorithm>
using namespace std;
class Student {
private:

	char *name;
	char id[100];
	int age;
	string address;
public:
	Student();
	Student(char *name, char id[100],int age,string address);
	Student(const Student& other);

	~Student();
	void Get(char *, char[100], int, string);
	void Change(char *, char [100], int, string);
	void Output();
};
Student::Student()
{
	cout << "++无参构造函数被自动调用++" << endl;
}
Student::Student(char *name, char id[100], int age, string address)
{
	cout << "++有参构造函数被自动调用++" << endl;
	
	this->name = name;
	this->age = age;
	this->address = address;
	for (int i = 0; i < strlen(id); i++)
	{
		this->id[i] = id[i];
	}
}

Student::Student(const Student &r)
{
	cout << "++拷贝构造函数被自动调用++" << endl;
	this->name = r.name;
	this->age = r.age;
	this->address = address;
	for (int i = 0; i < strlen(r.id); i++)
	{
		this->id[i] = r.id[i];
	}
}

Student::~Student()
{
	cout << "--析构函数被自动调用--" << endl;
}

void Student::Get(char *name, char id[100], int age, string address)
{
	printf("获得学生信息\n");
	this->name = name;
	this->age = age;
	this->address = address;
	for (int i = 0; i < strlen(id); i++)
	{
		this->id[i] = id[i];
	}
}
void Student::Change(char *name, char id[100], int age, string address)
{
	printf("修改学生信息\n");
	this->name = name;
	this->age = age;
	this->address = address;
	for (int i = 0; i < strlen(id); i++)
	{
		this->id[i] = id[i];
	}
}
void Student::Output()
{
	printf("输出学生信息\n");
	printf("%s %s %d ", name,id,age);
	std::cout << address << endl;
}
int main()
{
	Student A;//无参构造函数
	char *name;
	char hh[] = "Tom";
	name = hh;
	char id[100] = "00001";
	int age = 14;
	string address = "China";
	
	Student B(name,id,age,address);//有参构造函数
	Student C(B);//拷贝函数

	Student D;
	char hh2[] = "Dio";
	name = hh2;
	char id2[100] = "00002";
	int age2 = 17;
	string address2 = "American";
	D.Get(name, id2, age2, address2);//获得学生信息
	D.Output();

	char hh3[] = "Len";
	name = hh3;
	char id3[] = "00003";
	int age3 = 2;
	string address3 = "Mars";
	D.Change(name,id3,age3,address3);//修改学生信息
	D.Output();
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门提示: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
