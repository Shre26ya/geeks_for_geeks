int firstElementKTime(int n, int k, int a[]) {
    unordered_map<int, int> firstOccurrence;
    int ans = -1; // Initialize ans
    for(int i = 0; i < n; i++) {
        if (++firstOccurrence[a[i]] == k) {
            ans = a[i];
            break;
        }
    }
    return ans; // Return the first element that appears k times, or -1 if no such element is found
}
