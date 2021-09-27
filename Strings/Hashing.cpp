struct Hash {
	#define ll long long
	const ll p[2] = {31, 37};
	const ll m[2] = {(ll) 1e9 + 7, (ll) 1e9 + 9};

	int n;
	vector<ll> h[2], pw[2];

	Hash(string &s) {
		n = (int) s.size();
		for (int k : {0, 1}) {
			h[k] = pw[k] = vector<ll>(n);
			pw[k][0] = 1;
			h[k][0] = (ll) s[0];
			for (int i = 1; i < n; i++) {
				h[k][i] = (h[k][i - 1]  * p[k] + (ll) s[i]) % m[k];
				pw[k][i] = pw[k][i - 1] * p[k] % m[k];
			}
		}
	}

	pair<ll, ll> substring(int l, int r) {
		if (l > r)
			swap(l, r);
		pair<ll, ll> ans = {0, 0};
		for (int k : {0, 1}) {
			ll val = h[k][r] - (l > 0 ? h[k][l - 1] * pw[k][r - l + 1] % m[k] : 0);
			val %= m[k];
			if (val < 0)
				val += m[k];
			if (!k) ans.first = val;
			else ans.second = val;
		}
		return ans;
	}
};