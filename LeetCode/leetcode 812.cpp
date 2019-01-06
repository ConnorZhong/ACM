class Solution {
public:
    double largestTriangleArea(vector<vector<int>>& p) {
        int n=p.size();
        int p = 0;
        for (int i=0;i<n;i++)
        for (int j=i+1;j<n;j++)
       	for (int k=j+1;k<n;k++)
       	{
       		double ax = p[j][0]-p[i][0];
       		double ay = p[j][1]-p[i][1];
       		double bx = p[k][0]-p[i][0];
       		double by = p[k][1]-p[i][1];
       		p = max(p, abs(ax*by-ay*bx));
       	}
       	return p/2.0;
    }
};