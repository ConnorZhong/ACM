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
int fix0,fix1,Xor;
int main()
{
	// freopen("in.txt","r",stdin);
	int n;
	scanf("%d",&n);
	rep(i, 1, n+1)
	{
		char op[5];
		int num;
		scanf("%s%d",op,&num);
		if (op[0] == '|') fix1 |= num, fix0 &= (~num), Xor &= ~(num);
		if (op[0] == '&') fix0 |= (~num), fix1 &= num, Xor &= num;
		if (op[0] == '^')
		{
			rep(i,0,10)
			{
				if (num>>i&1)
				{
					if (fix1 >> i & 1) fix1 &= ~(1<<i), fix0 |= 1<<i;
					else if (fix0 >> i & 1) fix0 &= ~(1<<i), fix1 |= 1<<i;
					else 
					{
						Xor ^= 1<<i;
					}
				}
			}
		} 
 	}
 	printf("3\n");
 	printf("| %d\n& %d\n^ %d\n",fix1 & (1023),(~fix0)&(1023),Xor&(1023));

	return 0;
}

