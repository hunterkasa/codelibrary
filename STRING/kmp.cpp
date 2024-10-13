vector<int> prefix_function(string s) {
    int n = (int)s.length();
    vector<int> pi(n);
    for (int i = 1; i < n; i++) {
        int j = pi[i-1];
        while (j > 0 && s[i] != s[j])
            j = pi[j-1];
        if (s[i] == s[j])
            j++;
        pi[i] = j;
    }
    return pi;
}
 
vector<int> Counting_occurrences( vector<int> &lps, string &s ){
    int n = s.size();
    vector<int> ans(n + 1);
    for (int i = 0; i < n; i++)
        ans[lps[i]]++;
    for (int i = n-1; i > 0; i--)
        ans[lps[i-1]] += ans[i];
    for (int i = 0; i <= n; i++)
        ans[i]++;
    return ans;
}
