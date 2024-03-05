int maxIndexDiff(int a[], int n) {
    int max_diff = 0;
    int max_right[n];
    
    // Preprocess to store maximum index of max element from right
    max_right[n - 1] = n - 1;
    for (int i = n - 2; i >= 0; i--) {
        if (a[i] > a[max_right[i + 1]]) {
            max_right[i] = i;
        } else {
            max_right[i] = max_right[i + 1];
        }
    }
    
    // Calculate maximum index difference
    int i = 0, j = 0;
    while (i < n && j < n) {
        if (a[i] <= a[max_right[j]]) {
            max_diff = max(max_diff, j - i);
            j++;
        } else {
            i++;
        }
    }
    
    return max_diff;
}

