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
    void SetTriangle(int ,int, int);//��ʼ��
    bool JudgeTriangle();//�ж��������Ƿ����
    int GetPerimeter();//�����ܳ�
    double Getarea();//�������
    int JudgeKind();//�ж�����������
};
void Triangle::SetTriangle(int x,int y,int z)
{
    if(x>y&&x>z) swap(x,z);
    if(y>x&&y>z) swap(y,z);//cΪ����


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
    if(a*a+b*b > c*c) return 1;//���
    if(a*a+b*b == c*c) return 2;// ֱ��
    if(a*a+b*b < c*c) return 3;//�۽�
}
int main()
{

//    x.SetTriangle(3,4,5);
   // 12���ֽڣ������������α�����

   Triangle x,y,z;
   x.SetTriangle(3,4,5);
  // cout<<sizeof(x)<<endl;//
 //  y.SetTriangle(3,4,5);
  // z.SetTriangle(3,4,5);
  // cout<<&x<<" "<<&y<<" "<<&z<<endl;

}
