#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
char a[1005][1005];
struct cc{
    int _0,_1;
}num[1005];
char b[1005];
int cnt[1005];
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
    {
        scanf("%s",a[i]+1);
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(a[i][j]=='0') num[i]._0++;
            if(a[i][j]=='1') num[i]._1++;
        }
    }
    int q;
    scanf("%d",&q);
    while(q--)
    {
        scanf("%s",b+1);
        int l=0;
        int _0=0,_1=0;
        for(int i=1;i<=m;i++)
        {
            if(b[i]=='0')
            {
                _0++;
                l++;
                cnt[l]=i;
            }
            if(b[i]=='1')
            {
                _1++;
                l++;
                cnt[l]=i;
            }
        }
        int ans=0;
        for(int j=1;j<=n;j++)
        {
            if(num[j]._0<_0||num[j]._1<_1) continue;
            bool flag=1;
            for(int k=1;k<=l;k++)
            {
                if(b[cnt[k]]!=a[j][cnt[k]])
                {
                    flag=0;
                    break;
                }
            }
            if(flag) ans++;
        }
        printf("%d\n",ans);
    }
}
