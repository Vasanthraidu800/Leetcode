class Solution {
    public int findMinFibonacciNumbers(int k) {
        ArrayList<Integer> fib = new ArrayList<>();
        fib.add(1);
        fib.add(1);
        while (fib.get(fib.size() - 1) < k) {
            int n = fib.size();
            fib.add(fib.get(n - 1) + fib.get(n - 2));
        }

        int count = 0;

        //picking largest possible fib number
        for (int i = fib.size() - 1; i >= 0; i--) {
            while (k >= fib.get(i)) {
                k -= fib.get(i);
                count++;
            }
        }

        return count;
    }
}