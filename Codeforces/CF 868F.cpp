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
#include <bitset>
#define fi first
#define se second
#define mkp make_pair
#define pb push_back
#define rep(i,a,b) for (int i=(a);i<(b);i++)
#define per(i,b,a) for (int i=(b)-1;i>=(a);i--)
#define REP(i,a,b) for (int i=(a);i<=(b);i++)
#define PER(i,b,a) for (int i=(b);i>=(a);i--)
#define de(x) cout <<" >> "<< #x << " = " << x << endl;
using namespace std;
typedef long long LL;

const int INF = 0x3f3f3f3f;

const int MAXN = 1e5+10; // 1e6;
LL dp[2][MAXN], now;
int n,k;
LL w[MAXN];
int a[MAXN];
namespace TotalMonotonicity
{
        /*O(nlogn) 复杂度从一个矩阵中求出每一列中的最小值所对应的位置*/
        int argMin[MAXN],minVal[MAXN];//取 min 的位置，也就是返回的答案。argmin
        void TM_go(int L, int R ,int l, int r)
        {
        	de("============")
        	de(L) de(R) de(l) de(r)
                if (R-L<=0) return;
                int M = (L+R)>>1, m = -1, val = 0;
                if (R-L==1) M=L;
                map<int, int> H;
                memset(w, 0, sizeof (LL)* (r-l+2));
                for (int i = R; i >= l; i--)
                {
                	H[a[i]]++;
                	int t = H[a[i]];
                	w[i - l] = w[i - l + 1] + 1ll*t*(t-1)/2 - 1ll*(t-1)*(t-2)/2;
                	// de(a[i])
                	// de(i) de(w[i-l])

                }
                for (int i = l; i < r && i < M-1; i++)
                {
                        int t = dp[now][i] + w[i-l];
                        // de(t)
                        if (m==-1||t<val) val=t, m = i;
                }
                de(val) de(M) de(m)
                argMin[M]=m;
                dp[now^1][M]=val;
                de("----")
                if (R-L>1)
                {
                        TM_go(L,M,l,m+1);TM_go(M,R,m,r);
                }
        }
}
using namespace TotalMonotonicity;
int main()
{
	freopen("in.txt","r",stdin);
        
        scanf("%d%d",&n,&k);
        rep(i, 1, n+1) scanf("%d",a+i);
//        scanf("%d%d",&n,&k);
        memset(dp,INF,sizeof dp);
        dp[now][0]=0;
        rep(i,1,k+1)
        {
                TM_go(1,n+1,0,n+1);
                de(i)
                rep(j,0,n+1) de(dp[now^1][j])
                now^=1;
        }
        printf("%lld\n",dp[now][n]);
}