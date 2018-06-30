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
int n,ans;
int a[MAXN];

int main()
{
	// freopen("in.txt","r",stdin);
	scanf("%d",&n);
	rep(i,1,n+1) scanf("%d",a+i);
	rep(i,2,n) if ((a[i] < a[i-1] && a[i] < a[i+1])||(a[i]>a[i-1]&&a[i]>a[i+1])) ans++;
	printf("%d\n",ans);
	return 0;
}

