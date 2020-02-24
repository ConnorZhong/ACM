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
double dp[105][105];
class Solution {
public:
    double largestSumOfAverages(vector<int>& a, int k) {
        memset(dp,0,sizeof dp);
        int n = a.size();
        double tot=0;
        for (int i=0;i<n;i++) tot+=a[i],dp[i][1]=p/(i+1);
        for (int i=0;i<n;i++)
        {
        	double p = 0;
        	for (int t=i;t>=0;t--)
        	{
        		p+=a[t];
        		for (int j=2;j<=k;j++)
        		{
        			dp[i][j]=max(dp[i][j], (t>0?dp[t-1][j-1]:0)+p/(i-t+1));
        		}
        	}
        }
        return dp[n-1][k];
    }
};
int main()
{
	freopen("in.txt","r",stdin);
	return 0;
}

