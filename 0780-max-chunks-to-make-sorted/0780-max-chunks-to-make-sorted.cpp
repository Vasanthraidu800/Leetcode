class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n = arr.size();
        int sum=0;
        int cnt=0;
        for(int i=0; i <n;i++)
        {
            arr[i]+=sum;
            sum=arr[i];
            if((i*(i+1)/2)==sum) cnt++;
        }
        return cnt;
    }
};