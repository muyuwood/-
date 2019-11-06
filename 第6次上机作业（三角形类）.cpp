#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
class Triangle
{
private:
    int a,b,c;
public:
    void SetTriangle(int ,int, int);//初始化
    bool JudgeTriangle();//判断三角形是否成立
    int GetPerimeter();//计算周长
    double Getarea();//计算面积
    int JudgeKind();//判断三角形种类
};
void Triangle::SetTriangle(int x,int y,int z)
{
    if(x>y&&x>z) swap(x,z);
    if(y>x&&y>z) swap(y,z);//c为最大边


    a = x;
    b = y;
    c = z;
    cout<<&a<<' '<<&b<<' '<<&c<<endl;
}
bool Triangle::JudgeTriangle()
{
    if(a+b>c) return true;
    else return false;
}
int Triangle::GetPerimeter()
{
    return a+b+c;
}
double Triangle::Getarea()
{
    double p = 1.0*(a+b+c)/2;
    double area=1.0*sqrt(p*(p-a)*(p-b)*(p-c));
    return area;
}
int Triangle::JudgeKind()
{
    if(a*a+b*b > c*c) return 1;//锐角
    if(a*a+b*b == c*c) return 2;// 直角
    if(a*a+b*b < c*c) return 3;//钝角
}
int main()
{

//    x.SetTriangle(3,4,5);
   // 12个字节，正好三个整形变量。

   Triangle x,y,z;
   x.SetTriangle(3,4,5);
  // cout<<sizeof(x)<<endl;//
 //  y.SetTriangle(3,4,5);
  // z.SetTriangle(3,4,5);
  // cout<<&x<<" "<<&y<<" "<<&z<<endl;

}
