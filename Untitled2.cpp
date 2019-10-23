#include<iostream>
#include<cstdio>
using namespace std;
class AA
{
private:
    int m = 2011;
    const double PI=3.14;
public:
    void Get();
};
void AA::Get()
{
    printf("%d %.2f\n",m,PI);
}
int main()
{
    AA x;
    x.Get();
    //cout<<x.PI<<endl;
}
