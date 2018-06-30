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
const int MAXN = 300; // 1e6;
const int MAXK = 14;
int n, a, b, m;
string l[MAXN], r[MAXN];
set<int> hs[MAXN][MAXK];
int get_int(string p)
{
	int ret = 0;
	rep(i, 0, p.length())
	{
		ret = ret*2 + (p[i]-'0');
	}
	return ret;
}
void get_hs(string &str, int p)
{
	rep(k, 1, MAXK)
	{
		for (int i = 0; i + k <= str.length(); i++)
		{
			int t = get_int(str.substr(i, k));
			hs[p][k].insert(t); 
		}
	}
}
int main()
{
	// freopen("in.txt","r",stdin);
	cin>>n;
	rep(i, 1, n+1) 
	{
		cin>>l[i];get_hs(l[i], i);
		if (l[i].length() > MAXK) 
			r[i]=l[i].substr(l[i].length()-MAXK,MAXK), l[i]=l[i].substr(0,MAXK);
		else r[i]=l[i];
	}
	cin>>m;
	rep(i, 1, m+1) 
	{
		cin>>a>>b;
		string s = r[a]+l[b];

		if (l[a].length()<MAXK) 
		{
			if (s.length() >= MAXK)
			l[i+n]=s.substr(0,MAXK);
			else l[i+n]=s;
		}
		else l[i+n]=l[a];
		if (r[b].length()<MAXK)
		{ 
			if (s.length() >= MAXK)
			r[i+n]=s.substr(s.length()-MAXK,MAXK);
			else r[i+n]=s;
		}
		else r[i+n]=r[b];
		rep (j, 1, MAXK)
		{
			// de("insrt")
			// de(j)
			for (auto &x: hs[a][j]) 
			{
				// de(x)
				hs[i+n][j].insert(x);
			}

			for (auto &x: hs[b][j]) 
			{
				// de(x)
				hs[i+n][j].insert(x);
			}
		}
		get_hs(s, i+n);
		// de(i)
		rep(j, 1, MAXK)
		{
			if (hs[i+n][j].size() < (1<<j))
			{
				printf("%d\n",j-1);
				break;
			}
		}
	}
	return 0;
}

