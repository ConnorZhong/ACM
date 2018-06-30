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
vector<int> res;
int main()
{
	// freopen("in.txt","r",stdin);
	int n,ans=0;
	cin>>n;
	rep(i, 0, min(n,1000))
	{
		int x = n-i;
		int tmp = x;
		while(x) tmp += x%10, x/=10;
		if (tmp == n) 
		{
			ans++;
			res.pb(n-i);
		}
	}
	printf("%d\n",ans);
	sort(res.begin(),res.end());
	for (int x:res)
	{
		printf("%d\n",x);
	}
	return 0;
}

