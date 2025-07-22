int countDigits(int num) {
    int cnt=0;
    int org=num;
    while(num>0)
    {
        int r=num%10;
        if(org%r==0)
        {
            cnt++;
        }
        num/=10;
    }
    return cnt;
}