// https://www.codechef.com/viewsolution/19245214 - solution by cnavjot908

#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod (ll)1000000007
#define mod2 (ll)1000000006
ll fact[5005];

void factorial()
{
  fact[0]=1;
  fact[1]=1;
  for (ll i=2;i<=5004;i++)
    fact[i]=(fact[i-1]*i)%mod2;
}

ll pwr(ll base, ll p,ll md)
{
    ll ans = 1;
    while(p)
    {
        if(p & 1)   ans = (ans * base) % md;
        base = (base * base) % md;
        p /= 2;
    }
    return ans%md;
}




int main()
{
    ll t;
    cin>>t;
    factorial();
    ll c[5001][5001];
    for (ll i=1;i<=5000;i++)
    {
      c[i][1]=i;
      c[i][0]=1;
    }
    for (ll i=0;i<=5000;i++)
      for (ll j=2;j<=5000;j++)
      {
        if(i==j&&i!=0)
        {
          c[i][j]=1;
          continue;
        }
        if(i==0&&j==0)
        {
          c[i][j]=0;
          continue;
        }
        if(j>i)
        {
          c[i][j]=0;
          continue;
        }
        c[i][j]=(c[i-1][j]+c[i-1][j-1])%mod2;
      }
    while(t--)
    {
      ll n,k;
      cin>>n>>k;
      ll a[n+1];
      for (ll i=1;i<=n;i++)
        cin>>a[i];
      sort(a+1,a+n+1);
      ll count[n+1];
      count[1]=0;
      count[n]=0;
      memset(count,0,sizeof(count));
        for (ll i=2;i<=n-1;i++)
        {
          for(ll j=1;j<=k-2;j++)
          {
            if(j==i)
              break;
              count[i]=(count[i]+(c[i-1][j]*c[n-i][k-j-1])%mod2)%mod2;
            }
        }
        ll ans=1;
        for(ll i=2;i<=n-1;i++)
        {
           ans=(ans*pwr(a[i],count[i],mod))%mod;
        }
        cout<<ans<<endl;
    }
  return 0;
}