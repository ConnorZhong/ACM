class Solution {
public:
    vector<vector<int>> G,ans;
    vector<int> now;

    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        ans.clear();
	int aim = graph.size();G = graph;
	dfs(0);
	return ans;	
    }	
    void dfs(int u)
    {
        now.push_back(u);
 	if (u == G.size()-1)  ans.push_back(now);
        for (auto x:G[u]) dfs(x);
        now.pop_back(u);
    }
};