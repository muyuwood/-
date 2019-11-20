#include<iostream>
#include<cstdio>
#include<cstring>
#include<ctime>
#include<cstdlib>
using namespace std;

class School//ѧУ��
{
public:
    School(string x)
    {
        schoolname = x;
    }
    string schoolname;
};

class Date//����������
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



class Rand//���������
{
public:
    double run()
    {
        return (double)0.01*(rand()%400+1);
    }
};

class Student//ѧ����
{

public:
    static int num;//��ǰ�Ѵ�����ѧ����Ķ���ĸ���

    void play()//�������
    {
        GPA = x.run();
        cout<<name<<"'s GPA is "<<GPA<<endl;
    }
    Student(string a,bool b,string c,int x,int y,int z,string s):date(x,y,z),school(s)//���캯��
    {
        name = a;
        gender = b;
        id = c;
        num++;
        cout<<"��ǰ�ѹ�����ѧ�������ĸ���: "<<num<<endl;
    }
    ~Student();//��������
    const void GetDate();//����������ں�����
    friend void GetSchool(Student x);//���ѧУ����

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
    cout<<name<<"�ĳ�������Ϊ ";
    cout<<date.year<<"-"<<date.month<<"-"<<date.day<<endl;
    cout<<name<<"������Ϊ ";
    cout<<2019-date.year<<endl;

}

void GetSchool(Student x)
{
    cout<<x.name<<"��ѧУ�� ";
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
