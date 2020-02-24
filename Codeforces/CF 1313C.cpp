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
int n;
int m[MAXN];
LL lef[MAXN];
LL righ[MAXN];

stack<int> s;
int L[MAXN],R[MAXN];
int pos[MAXN];

int main()
{
        // freopen("in.txt","r",stdin);
        scanf("%d",&n);
        rep(i, 1, n+1) scanf("%d",m+i);
        rep(i, 1, n+1){
                while (!s.empty() && m[s.top()]>m[i]){
                        s.pop();
                }
                if (s.empty()) L[i]=0;
                else L[i]=s.top();
                s.push(i);
                // de(L[i])
        }
        while(!s.empty()) s.pop();
        per(i, 1, n+1) 
        {
                while (!s.empty() && m[s.top()]>m[i]){
                        s.pop();
                }
                if (s.empty()) R[i]=n+1;
                else R[i]=s.top();
                s.push(i);
                // de(R[i])
        }
        rep(i, 1, n+1){
                int l = L[i];
                lef[i]=lef[l]+1ll*(i-l-1)*m[i]+m[l];
                // de(lef[i])
        }
        per(i, 1, n+1){
                int r = R[i];
                righ[i]=righ[r]+1ll*(r-1-i)*m[i]+m[r];
                // de(righ[r])
                // de(righ[i])
                // de(m[r])
        }
        LL ans = 0;
        LL p = 0;
        rep(i, 1, n+1){
                LL tmp = righ[i]+lef[i]+m[i];
                // de(tmp)de(righ[i])de(lef[i])
                if (ans < tmp) ans = tmp, p = i;
        }
        // de(ans)
        // de(p)
        pos[p]=m[p];
        // de(pos[p])
        rep(i, p+1, n+1){
                pos[i]=min(m[i],pos[i-1]);
        }
        per(i, 1, p){
                pos[i]=min(m[i],pos[i+1]);
        }
        rep(i, 1, n+1) printf("%d%c",pos[i]," \n"[i==n]);
        // printf("%lld\n",ans);
        return 0;
}

