class Solution {
    public int triangleNumber(int[] arr) {
        int n=arr.length;
        Arrays.sort(arr);
        int count=0;
        for(int k=n-1;k>=0;k--){
            int i=0, j=k-1;
            while(i<j){
                int sum=arr[i]+arr[j];
                if(sum>arr[k]){
                    count+=(j-i);
                    j--;
            }
            else i++;
    }
    }
    return count;
}
}