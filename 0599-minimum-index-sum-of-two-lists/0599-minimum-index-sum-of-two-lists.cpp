class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        int n = list1.size();
        int m = list2.size();
        int min = INT_MAX;
        vector<string>ans;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(list1[i]==list2[j]) 
                {
                    if(i+j<=min) {
                        if(i + j == min && min > 0) {
                            ans.push_back(list1[i]);
                        }
                        else {
                            if(ans.size() > 0)ans.pop_back();
                            ans.push_back(list1[i]);
                        }
                        min = i + j;
                    }
                }
            }
        }
        return ans;
    }
};