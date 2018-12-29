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
char s[MAXN];
int status = 0;
int main()
{
        // freopen("in.txt","r",stdin);
        scanf("%d",&n);
        scanf("%s",s);
        int ans = 0;
        bool flag = false;
        int l = 0, r = 0;
        rep(i, 0, n)
        {
                if (s[i] == '(') l++;
                else r ++;
        }
        if (abs(l-r) != 2) return 0*puts("0");
        // de(1)
        ans = l = r = 0;
        int can = 0;
        rep(i, 0, n)
        {
                if (s[i] == '(') status++, l++;
                else status --, r++;

                if (status <= 1) can = 0;
                if (status > 1 && s[i] == '(') can ++;

                if (status < 0 && !flag) ans = r, flag = true, status += 2;
                else if (status < 0 && flag) return 0*puts("0");
        }
        // de(status)
        if (status == 2 && !flag) printf("%d\n", can);
        else if (status == 0) printf("%d\n",ans);
        else printf("%d\n",0);
        return 0;
}

