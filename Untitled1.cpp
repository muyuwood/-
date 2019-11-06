#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
char a[1000000+10];
long long sum[1000000+10];
int main()
{
    long long T;
    scanf("%lld",&T);
    while(T--)
    {
        long long n,k;
        scanf("%lld%lld",&n,&k);
        scanf("%s",a+1);
        long long last = -1;
        for(long long i = 1 ; i <= n ; i++)
        {
            if(a[i] == '1' && last == -1)
            {
                last = i;
            }
            sum[i] = sum[i - 1];
            if(a[i] == '1') sum[i] ++;
        }
        for(long long i = 1 ; i <= n ; i++)
        {
           // cout<<sum[i]<< " " <<i<<endl;
            if(a[i] == '0')
            {
                if(sum[i] > 0 && k - sum[i] >= 0)
                {
                    k -= sum[i];
                    swap(a[i],a[last]);
                    last++;
//                    for(long long  j = 1 ; j <= n ; j++)
//                    {
//                        printf("%c",a[j]);
//                    }
//                    printf("\n");
                }
                else if(sum[i] > 0 && k && k - sum[i] < 0)
                {
                    swap(a[i],a[i - k]);
                    k = 0;
                }
            }
        }
        for(long long i = 1 ; i <= n ; i++)
        {
            printf("%c",a[i]);
        }
        printf("\n");

    }
}
