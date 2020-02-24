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
int n, k;
int p[MAXN];
int main()
{
        // cout<<(1<<30)<<endl;
        // freopen("in.txt","r",stdin);
        scanf("%d%d",&n,&k);
        int cnt = 0;
        rep(i, 0, 30){
                if (n >> i & 1) p[cnt++] = (1<<i);
        }
        if (cnt > k || k > n) return 0*puts("NO");
        else puts("YES");
        int now = 0;
        while (k > cnt)
        {
                if (p[now] > 1) p[cnt++] = p[now]>>1, p[now] >>= 1;
                else now++;
        }
        rep(i, 0, cnt) printf("%d%c",p[i]," \n"[i==cnt-1]);
        return 0;
}

