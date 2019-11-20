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
Poit::Poit()//无参构造
{

}
Poit::Poit(double n,double m)//有参构造
{
    x = n;
    y = m;
}
Poit::Poit(const Poit &r)//拷贝函数
{
    this->x = r.x;
    this->y = r.y;
}
Poit::~Poit()//解构函数
{

}

double Poit::GetX()//获取x坐标
{
    return x;
}
double Poit::GetY()//获取y坐标
{
    return y;
}

void Poit::SetX(double ax)//修改x坐标
{
    x = ax;
}
void Poit::SetY(double ay)//修改y坐标
{
    y = ay;
}
void Poit:: SwapPoint(double& xa,double& xb)//交换坐标值
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

    printf("请输入栈数组的x值和y值：\n");
    for(int i = 0 ; i < 10 ; i ++)
    {
        double x,y;
        cin>>x>>y;
        Poit input(x,y);
        array_stack[i] = input;
    }
    printf("请输入堆数组的x值和y值：\n");
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
