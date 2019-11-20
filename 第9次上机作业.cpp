#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
class Graduate
{
private:
    char *name;
    bool gender;
    char id[20];
    double score;
    string research;
    string tutor;

public:
    Graduate();
    Graduate(char *name,bool gender,char id[20], double score,string research, string tutor);
    Graduate(const Graduate& other);
    ~Graduate();

    static double average;

    void Getname();
    void Getgender();
    void Getid();
    void Getscore();
    void Getresearch();
    void Gettutor();

    const void CGetname();
    const void CGetgender();
    const void CGetid();
    const void CGetscore();
    const void CGetresearch();
    const void CGettutor();

    void calc();

    friend void judge(Graduate x);
};
Graduate::Graduate()//无参构造
{

}
Graduate::Graduate(char *name1,bool gender1,char id1[20], double score1,string research1, string tutor1)//有参构造
{
    name = new char[strlen(name1) + 1];
    strcpy(name,name1);

    this->gender = gender1;


    strcpy(id,id1);

    this->score = score1;

    this->research = research1;

    this-> tutor = tutor1;
}
Graduate::Graduate(const Graduate &r)//拷贝函数
{
    this->name = r.name;
    for(int i = 0 ; i < strlen(r.id) ; i ++)
    {
        id[i] = r.id[i];
    }
    this->score = r.score;

    this->research = r.research;

    this-> tutor = r.tutor;
}
Graduate::~Graduate()//解构函数
{

}
void Graduate::Getname()//返回姓名
{
    cout<<name<<endl;
}
void Graduate::Getid()//返回学号
{

    for(int i = 0 ; i < strlen(id) ; i ++)
    {
        cout<<id[i];
    }
    cout<<endl;
}
void Graduate::Getgender()//返回性别
{
    if(gender == 1) cout<<"男"<<endl;
    else cout<<"女"<<endl;
}
void Graduate::Getscore()//返回成绩
{
    cout<<score<<endl;
}
void Graduate::Getresearch()//返回研究领域
{
    cout<<research<<endl;
}
void Graduate::Gettutor()//返回指导教师
{
    cout<<tutor<<endl;
}
const void Graduate::CGetname()//返回姓名
{
    cout<<name<<endl;
}
const void Graduate::CGetid()//返回学号
{

    for(int i = 0 ; i < strlen(id) ; i ++)
    {
        cout<<id[i];
    }
    cout<<endl;
}
const void Graduate::CGetgender()//返回性别
{
    if(gender == 1) cout<<"男"<<endl;
    else cout<<"女"<<endl;
}
const void Graduate::CGetscore()//返回成绩
{
    cout<<score<<endl;
}
const void Graduate::CGetresearch()//返回研究领域
{
    cout<<research<<endl;
}
const void Graduate::CGettutor()//返回指导教师
{
    cout<<tutor<<endl;
}

double Graduate::average = 0;//初始化

void Graduate::calc()//统计平均值
{
    if(Graduate::average - 0 < 1e-5)
    {
        Graduate::average += score;
    }
    else
    {
        Graduate::average += score;
        Graduate::average /= 2.0;
    }

}

void judge(Graduate x)//计算成绩
{
    if(x.score >= 90)
        printf("A\n");
    else if(x.score >= 80)
        printf("B\n");
    else if(x.score >= 70)
        printf("C\n");
    else if(x.score >= 60)
        printf("D\n");
    else
        printf("E\n");
}
int main()
{

    Graduate A("dalao",1,"001",80.0,"IT","julao");
    A.Getname(); A.Getgender(); A.Getid(); A.Getscore(); A.Getresearch(); A.Gettutor();
    cout<<endl<<endl<<endl<<endl;
    A.CGetname(); A.CGetgender(); A.CGetid(); A.CGetscore(); A.CGetresearch(); A.CGettutor();

    Graduate B("dalao",1,"001",70.0,"IT","julao");
    cout<<endl<<endl<<endl<<endl;

    A.calc();
    B.calc();
    cout<<A.average<<endl;
    cout<<endl<<endl<<endl<<endl;

    judge(A);
    judge(B);
}
