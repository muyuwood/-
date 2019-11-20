#include<iostream>
#include<cstdio>
#include<bits/stdc++.h>
using namespace std;
class Poit
{
    double x;
    double y;

public:
    Poit();
    Poit(double n,double m);
    Poit(const Poit& r);
    double GetX();
    double GetY();
    void SetX(double ax);
    void SetY(double ay);
    void SwapPoint(double& xa,double & xb);
    friend double GetLength(Poit& A, Poit& B);
    ~Poit();
};
Poit::Poit()//�޲ι���
{

}
Poit::Poit(double n,double m)//�вι���
{
    x = n;
    y = m;
}
Poit::Poit(const Poit &r)//��������
{
    this->x = r.x;
    this->y = r.y;
}
Poit::~Poit()//�⹹����
{

}

double Poit::GetX()//��ȡx����
{
    return x;
}
double Poit::GetY()//��ȡy����
{
    return y;
}

void Poit::SetX(double ax)//�޸�x����
{
    x = ax;
}
void Poit::SetY(double ay)//�޸�y����
{
    y = ay;
}
void Poit:: SwapPoint(double& xa,double& xb)//��������ֵ
{
    double tmp = xa;
    xa = xb;
    xb = tmp;
}
double GetLength(Poit& A, Poit& B)
{
    return sqrt((A.x - B.x)*(A.x - B.x) + (A.y - B.y)*(A.y - B.y));
}
int main()
{

    Poit *array_stack=new Poit[10];
    Poit *array_heap=new Poit[10];

    printf("n = 10\n");

    printf("������ջ�����xֵ��yֵ��\n");
    for(int i = 0 ; i < 10 ; i ++)
    {
        double x,y;
        cin>>x>>y;
        Poit input(x,y);
        array_stack[i] = input;
    }
    printf("������������xֵ��yֵ��\n");
    for(int i = 0 ; i < 10 ; i ++)
    {
        double x,y;
        cin>>x>>y;
        Poit input(x,y);
        array_heap[i] = input;
    }
    for(int i = 0 ; i < 10 ; i ++)
    {
        cout<<GetLength(array_stack[i],array_heap[i])<<endl;
    }
}
