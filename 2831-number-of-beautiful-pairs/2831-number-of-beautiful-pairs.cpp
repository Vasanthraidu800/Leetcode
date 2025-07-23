class Solution {
public:
    int gcd(int a, int b)
{
    int result = min(a, b);
    while (result > 0) {
        if (a % result == 0 && b % result == 0) {
            break;
        }
        result--;
    }
    return result;
}
    int firstDigit(int n)
{
    while (n >= 10)
        n /= 10;
    return n;
}
 
int lastDigit(int n)
{
    return (n % 10);
}
    int countBeautifulPairs(vector<int>& nums) {
        int n = nums.size();
        int ans =0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int last = lastDigit(nums[j]),first = firstDigit(nums[i]);
                if(gcd(last,first) == 1) ans++;
                
            }
        }
        return ans;
        
    }
};