int sumOfSquares(int n) {
    int sum = 0;
    while (n > 0) {
        int digit = n % 10;
        sum += digit * digit;
        n /= 10;
    }
    return sum;
}

bool isVisited(int visited[], int size, int n) {
    for (int i = 0; i < size; i++) {
        if (visited[i] == n) return true;
    }
    return false;
}

bool isHappy(int n) {
    int visited[1000]; // store previously seen numbers
    int count = 0;

    while (n != 1) {
        if (isVisited(visited, count, n)) {
            return false; // cycle detected
        }
        visited[count++] = n;
        n = sumOfSquares(n);
    }

    return true;
}