#include<iostream>
#include<cstdio>
#include<cstring>
#include<ctime>
#include<cstdlib>
using namespace std;

class School//学校类
{
public:
    School(string x)
    {
        schoolname = x;
    }
    string schoolname;
};

class Date//出生日期类
{
public:
    Date(int x,int y,int z)
    {
        year = x;
        month = y;
        day = z;
    }
    int year,month,day;
};



class Rand//随机函数类
{
public:
    double run()
    {
        return (double)0.01*(rand()%400+1);
    }
};

class Student//学生类
{

public:
    static int num;//当前已创建的学生类的对象的个数

    void play()//输出绩点
    {
        GPA = x.run();
        cout<<name<<"'s GPA is "<<GPA<<endl;
    }
    Student(string a,bool b,string c,int x,int y,int z,string s):date(x,y,z),school(s)//构造函数
    {
        name = a;
        gender = b;
        id = c;
        num++;
        cout<<"当前已构建的学生类对象的个数: "<<num<<endl;
    }
    ~Student();//析构函数
    const void GetDate();//输出出生日期和年龄
    friend void GetSchool(Student x);//输出学校名称

private :
    string name;
    bool gender;
    string id;
    double GPA;
    Rand x;
    Date date;
    School school;
};
int Student::num = 0;

Student::~Student()
{

}

const void Student::GetDate()
{
    cout<<name<<"的出生日期为 ";
    cout<<date.year<<"-"<<date.month<<"-"<<date.day<<endl;
    cout<<name<<"的年龄为 ";
    cout<<2019-date.year<<endl;

}

void GetSchool(Student x)
{
    cout<<x.name<<"的学校是 ";
    cout<<x.school.schoolname<<endl;
}
int main()
{
    srand(time(0));
    Student A("TOM",1,"001",1999,2,3,"SDNU");
    A.play();
    A.GetDate();
    GetSchool(A);

    Student B("Jerry",0,"002",2000,12,12,"PKU");
    B.play();
    B.GetDate();
    GetSchool(B);
}
