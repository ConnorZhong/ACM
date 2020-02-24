class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        double p[200][200];
        memset(p,0,sizeof p);
        p[0][0]=poured;
        for (int i=0;i<100;i++) for (int j=0;j<100;j++)
        {
            if (p[i][j] > 1)
            {
                double t = (p[i][j]-1)/2;
                p[i+1][j] += t, p[i+1][j+1] += t;
                p[i][j]=1;
            }
        }
        return p[query_row][query_glass];
    }
};