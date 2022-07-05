// Ploblema dos pares mais proximos
//
// 35063e
pair<int, int> closestPair(vector<Point<long long>> &p) {
	auto sqDist = [](Point<long long> pt) { return pt * pt; };
	long long dist = sqDist(p[0] - p[1]);
	pair<int, int> ans(0, 1);
	int n = (int) p.size();
	vector<int> v(n);
	iota(v.begin(), v.end(), 0);
	sort(v.begin(), v.end(), [&](int a, int b) { return p[a].x < p[b].x; });
	set<pair<long long, long long>> st;
	auto sq = [](long long x) { return x * x; };
	for (int l = 0, r = 0; r < n; r++) {
		while (sq(p[v[l]].x - p[v[r]].x) > dist) {
			st.erase(pll(p[v[l]].y, v[l]));
			l++;
		}
		long long delta = (long long) sqrt(dist) + 1;
		auto il = st.lower_bound(pll(p[v[r]].y - delta, -1));
		auto ir = st.lower_bound(pll(p[v[r]].y + delta, n + 1));
		for (auto it = il; it != ir; it++) {
			long long distNow = sqDist(p[v[r]] - p[it->second]);
			if (distNow < dist) {
				dist = distNow;
				ans = pair<int, int>(v[r], it->second);
			}
		}
		st.insert(pair<long long, long long>(p[v[r]].y, v[r]));
	}
	if (ans.first > ans.second)
		swap(ans.first, ans.second);
	return ans;
}