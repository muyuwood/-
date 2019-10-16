#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<vector>
using namespace std;
vector<int>vec[1005];
int num[1005];
int n,m;
bool ok;
void dfs(int x)
{
    if(ok==1) return;
    if(x>n)
    {
        ok=1;
        return;
    }
    for(int i=1;i<=3;i++)
    {
        num[x]=i;
        bool flag=1;
        for(int i=0;i<vec[x].size();i++)
        {
            if(num[vec[x][i]]==num[x])
            {
                flag=0;
                break;
            }
        }
        if(flag==0)
        {
            num[x]=0;

            continue;
        }
        dfs(x+1);

        num[x]=0;
    }
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {

        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++) vec[i].clear();
        memset(num,0,sizeof(num));
        for(int i=1;i<=m;i++)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            x++,y++;
            vec[x].push_back(y);
            vec[y].push_back(x);
        }

        ok=0;
        dfs(1);
        if(ok) printf("Y\n");
        else printf("N\n");
    }
    return 0;
}
