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
Graduate::Graduate()//�޲ι���
{

}
Graduate::Graduate(char *name1,bool gender1,char id1[20], double score1,string research1, string tutor1)//�вι���
{
    name = new char[strlen(name1) + 1];
    strcpy(name,name1);

    this->gender = gender1;


    strcpy(id,id1);

    this->score = score1;

    this->research = research1;

    this-> tutor = tutor1;
}
Graduate::Graduate(const Graduate &r)//��������
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
Graduate::~Graduate()//�⹹����
{

}
void Graduate::Getname()//��������
{
    cout<<name<<endl;
}
void Graduate::Getid()//����ѧ��
{

    for(int i = 0 ; i < strlen(id) ; i ++)
    {
        cout<<id[i];
    }
    cout<<endl;
}
void Graduate::Getgender()//�����Ա�
{
    if(gender == 1) cout<<"��"<<endl;
    else cout<<"Ů"<<endl;
}
void Graduate::Getscore()//���سɼ�
{
    cout<<score<<endl;
}
void Graduate::Getresearch()//�����о�����
{
    cout<<research<<endl;
}
void Graduate::Gettutor()//����ָ����ʦ
{
    cout<<tutor<<endl;
}
const void Graduate::CGetname()//��������
{
    cout<<name<<endl;
}
const void Graduate::CGetid()//����ѧ��
{

    for(int i = 0 ; i < strlen(id) ; i ++)
    {
        cout<<id[i];
    }
    cout<<endl;
}
const void Graduate::CGetgender()//�����Ա�
{
    if(gender == 1) cout<<"��"<<endl;
    else cout<<"Ů"<<endl;
}
const void Graduate::CGetscore()//���سɼ�
{
    cout<<score<<endl;
}
const void Graduate::CGetresearch()//�����о�����
{
    cout<<research<<endl;
}
const void Graduate::CGettutor()//����ָ����ʦ
{
    cout<<tutor<<endl;
}

double Graduate::average = 0;//��ʼ��

void Graduate::calc()//ͳ��ƽ��ֵ
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

void judge(Graduate x)//����ɼ�
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
