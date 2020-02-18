#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <map>
#include <cstdlib>
#include <cmath>
#include <string>
#include <algorithm>
#include <set>
#include <stack>
#include <queue>
#include <utility>
#include <cassert>
#include <bitset>
#define all(x) (x).begin(),(x).end()
#define SZ(x) ((int)(x).size())
#define fi first
#define se second
#define pb push_back
#define mkp make_pair
#define rep(i,a,b) for (int i=(a);i<(b);i++)
#define per(i,a,b) for (int i=(b)-1;i>=(a);i--)
#define REP(i,a,b) for (int i=(a);i<=(b);i++)
#define PER(i,a,b) for (int i=(b);i>=(a);i--)
#define de(x) cout<<">> "<<#x<<" = "<<x<<endl;
using namespace std;
typedef long long LL;
LL powmod(LL a,LL b,LL mod) {LL res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
LL gcd(LL a, LL b) {if (b==0)return a;else return gcd(b,a%b);}
const int INF = 0x3f3f3f3f;
const int MAXN = 1000005; // 1e6;
int T, n, a[MAXN],x;
int gao()
{
        rep(i, 0, n){
                if (x==a[i]) return true;
        }
        return false;
}
int main()
{
        // freopen("in.txt","r",stdin);
        scanf("%d",&T);
        rep(cas, 1, T+1){
                scanf("%d%d",&n,&x);
                rep(i, 0, n) scanf("%d",a+i);
                sort(a, a+n);
                int step = a[n-1];
                int t = x/step;
                if (x%step > 0)
                {
                        if (t == 0){
                                if (gao());
                                else t+=1;
                        }
                        t += 1;
                }
                printf("%d\n",t);
        }
        return 0;
}

