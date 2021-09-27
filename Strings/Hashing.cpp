struct Hash {
    const int p[2] = {31, 37};
    const int m[2] = {(int) 1e9 + 7, (int) 1e9 + 9};

    int n;
    bool single;
    vector<int> h[2], pw[2];

    Hash(string &s, bool fs = false) {
        n = (int) s.size();
        single = fs;
        for (int k : {0, 1}) {
            h[k] = pw[k] = vector<int>(n);
            pw[k][0] = 1;
            h[k][0] = (int) s[0];
            for (int i = 1; i < n; i++) {
                h[k][i] = (1ll * h[k][i - 1]  * p[k] + 1ll * (int) s[i]) % m[k];
                pw[k][i] = 1ll * pw[k][i - 1] * p[k] % m[k];
            }
            if (single) break;
        }
    }

    pair<int, int> substring(int l, int r) {
        if (l > r)
            swap(l, r);
        pair<int, int> ans = {0, 0};
        for (int k : {0, 1}) {
            int val = h[k][r] - (l > 0 ? 1ll * h[k][l - 1] * pw[k][r - l + 1] % m[k] : 0);
            val %= m[k];
            if (val < 0)
                val += m[k];
            if (!k) ans.first = val;
            else ans.second = val;
            if (single) break;
        }
        return ans;
    }
};