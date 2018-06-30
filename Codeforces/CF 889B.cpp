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
int n, l[MAXN];
string s[MAXN];
int tot;
int cnt[26],all[26];
set<string> oo;
int find_pos(string &p, char ch)
{
	// de("===")
	// de(p) de(ch)
	rep(i, 0, p.length()) if (p[i] == ch) return i;
	return INF;
}
int main()
{
	// freopen("in.txt","r",stdin);
	cin>>n;
	rep(i,1,n+1) 
	{
		cin>>s[i];
		// de(s[i])
		memset(cnt,0,sizeof cnt);
		rep(j, 0, s[i].length()) 
		{
			cnt[s[i][j]-'a']++;
			if (cnt[s[i][j]-'a']>=2) return 0*puts("NO");
		}
		bool flag = true;
		// de(i)
		stack<string> e;
		for (auto x : oo)
		{
			// de(x)
			memset(cnt,0,sizeof cnt);
			for (char ch: s[i]) cnt[ch-'a']++;
			for (char ch: x) cnt[ch-'a']++;
			int p1 = INF, p2 = INF;
			if (x.find(s[i])!= string::npos) 
			{
				flag = false;
				break;
			}
			else if (s[i].find(x) != string ::npos) e.push(x);
			else {
				rep(k,0,26)
				{
					if (cnt[k] == 2)
					{
						p1 = min(p1,find_pos(x, k+'a'));
						p2 = min(p2,find_pos(s[i],k+'a'));
					}
					else if (cnt[k] > 2) return 0*puts("NO");
				}
				// de(p1) de(p2)
				if (p1 == INF && p2 == INF);
				else if (p1 == 0)
				{
					if (s[i].substr(p2, s[i].length()-p2) != x.substr(0, s[i].length()-p2)) return 0*puts("NO");
					else s[i]=s[i].substr(0,p2)+x;
					e.push(x);
				}
				else if (p2 == 0)
				{
					if (x.substr(p1, x.length()-p1) != s[i].substr(0, x.length()-p1)) return 0*puts("NO");
					else s[i]=x.substr(0,p1)+s[i];
					e.push(x);
				}
				else return 0*puts("NO");
			}
			// de(x) de(s[i])

		}
		while(!e.empty()) oo.erase(e.top()), e.pop();
		if (flag) oo.insert(s[i]);
	}
	sort(s+1,s+n+1);
	for (auto x:oo) cout<<x;
	return 0;
}

