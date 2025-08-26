class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int max_dl=0;
        int max_area=0;
        int m = dimensions.size();
        for(int i=0;i<m;i++)
        {
                int a = dimensions[i][0];
                int b = dimensions[i][1];
                int dl = a*a+ b*b ;
                int area = a* b;
                if(dl>max_dl || (dl==max_dl && area > max_area))
                {
                    max_dl=dl;
                    max_area=area;
                }
        }
        return max_area;
    }
};