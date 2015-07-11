
#include <algorithm> 
#include <iostream> 
#include <sstream> 
#include <string> 
#include <vector> 
#include <queue> 
#include <set> 
#include <map> 
#include <cstdio> 
#include <cstdlib> 
#include <cctype> 
#include <cmath> 
using namespace std; 

#define FOR(i,n) for (int i=0;i<(n);i++) 
#define P(x) cerr<<#x<<" = "<<x<<endl; 
#define pb push_back 

typedef long long ll; 
typedef vector <int> vi; 

const ll mod=1234567891; 

inline ll gcd(ll a, ll b, ll &x, ll &y) { 
  if (!b) { 
    x=1; y=0; 
    return a; 
  } 
  ll ret=gcd(b, a%b, y, x); 
  y-=x*(a/b); 
  return ret; 
} 

ll invtable[200000]; 

inline ll inverse(ll x) { //return y so that x*y==1 
  if (x<=100000) return invtable[x]; 
  ll y, k; 
  gcd(x,mod, y,k); //x*y+mod*k==1, gcd must return 1 
  return (y%mod+mod)%mod; 
} 
inline ll inverse1(ll x) { //return y so that x*y==1 
  ll y, k; 
  gcd(x,mod, y,k); //x*y+mod*k==1, gcd must return 1 
  return (y%mod+mod)%mod; 
} 

inline ll mydivide(ll x, ll y) { 
  return (x*inverse(y))%mod; 
} 

int m; 
int n; 

void fix(ll &x) { 
  x%=mod; 
  x+=mod; 
  x%=mod; 
} 

ll C(int n, int r) { 
  if (n<r) return 0; 
  if (n<0 || r<0) return 0; 

  if (n==0) return 1; 
  if (r==0) return 1; 

  if (r*2>n) r=n-r; 
  ll prod=1; 
  for (int i=1; i<=r; i++) { 
    prod=prod*(n-r+1); 
    prod%=mod; 
    prod=mydivide(prod, i); 
  } 
  return prod; 
} 

ll docount(vi check, int s) { 
  ll prod=1; 
  FOR (i,m) { 
    prod*=C(s,check[i]); 
    prod%=mod; 
    s-=check[i]; 
  } 
  return prod; 
} 

ll countall(vi check) { 
  return docount(check, n*n); 
} 

ll counthalf(vi check) { 
  int nodd=0; 
  int oddi=0; 
  FOR (i,m) if (check[i]%2) {nodd++; oddi=i;} 
  if (nodd>1) return 0; 
  if (n%2==0) {  //n even 
    if (nodd) return 0; 
  } else { //n odd 
    if (nodd) check[oddi]--; 
  } 
  FOR (i,m) check[i]/=2; 
  return docount(check, n*n/2); 
} 

ll countfull(vi check) { 
  int nodd=0; 
  int oddi=0; 
  FOR (i,m) if (check[i]%4) { 
    if (check[i]%4!=1) return 0; 
    nodd++; oddi=i; 
  } 
  if (nodd>1) return 0; 
  if (n%2==0) {  //n even 
    if (nodd) return 0; 
  } else { //n odd 
    if (nodd) check[oddi]--; 
  } 
  FOR (i,m) check[i]/=4; 
  return docount(check, n*n/4); 
} 

class TheBeautifulBoard { 
public: 
  int count(int nn, vector <int> checkers) { 
    for (int i=0;i<=100000;i++) invtable[i]=inverse1(i); 
    n=nn; 
    vi check=checkers; 

    m=check.size(); 
    int cnt=0; 
    FOR (i,m) cnt+=check[i]; 
    if (cnt>n*n) return 0; 

    ll a=countall(check); 
    ll b=counthalf(check); 
    ll c=countfull(check); 

    b=b-c; 
    fix(b); 
    //b=mydivide(b,2); 
     
    ll ans=a + b + 3*c;  //a+2*b+3*c 
    fix(ans); 

    ans=mydivide(ans,4); 

    return ans; 
  } 


}; 

