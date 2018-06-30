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
#define pb push_back
#define mkp make_pair
#define rep(i,a,b) for (int i=(a);i<(b);i++)
#define per(i,a,b) for (int i=(b)-1;i>=(a);i--)
#define REP(i,a,b) for (int i=(a);i<=(b);i++)
#define PER(i,a,b) for (int i=(b);i>=(a);i--)
#define de(x) cout<<">> "<<#x<<" = "<<x<<endl;
using namespace std;
typedef long long LL;

const int INF = 0x3f3f3f3f;
const int MAXN = 1000005; // 1e6;
int n,k,m;
vector<int> A[MAXN];
int main()
{
	// freopen("in.txt","r",stdin);
	cin>>n>>k>>m;
	rep(i, 1, n+1)
	{
		int x;cin>>x;
		A[x%m].pb(x);
	}
	rep(i, 0, m)
	{
		if (A[i].size()>=k)
		{
			printf("Yes\n");
			rep(j,0,k) printf("%d%c",A[i][j]," \n"[j==k-1]);
			return 0;
		}
	}
	puts("No");
	return 0;
}

