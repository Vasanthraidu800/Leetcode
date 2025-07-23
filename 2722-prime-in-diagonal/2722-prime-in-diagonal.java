class Solution {
    
    static boolean isPrime(int num) {
        if (num <= 1) return false;
        if (num == 2) return true;
        if (num % 2 == 0) return false;
        for (int i = 3; i <= Math.sqrt(num); i += 2) {
            if (num % i == 0) return false;
        }
        return true;
    }

    public int diagonalPrime(int[][] nums) {
        int n = nums.length;
        int maxPrime = 0;

        for (int i = 0; i < n; i++) {
            int a = nums[i][i];                 
            int b = nums[i][n - i - 1];         

            if (isPrime(a)) maxPrime = Math.max(maxPrime, a);
            if (isPrime(b)) maxPrime = Math.max(maxPrime, b);
        }

        return maxPrime;
    }
}
