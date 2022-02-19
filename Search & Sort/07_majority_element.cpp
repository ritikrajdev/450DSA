int majorityElement(int a[], int n)
{
    int cnt = 0, majority;
    for (int i = 0; i < n; i++) {
        if (cnt == 0) majority = a[i], cnt = 1;
        else if (a[i] == majority)
            cnt++;
        else
            cnt--;
    }
    
    // Verify
    cnt = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] == majority) cnt ++;
    }
    
    if (cnt > n/2)
        return majority;
    else
        return -1;
}
