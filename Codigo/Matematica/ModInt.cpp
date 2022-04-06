// Inteiro Modular
//
template <class T>
T fexp(T b, long long e) {
	T ans = T(1);
	for (; e > 0; e /= 2) {
		if (e & 1ll)
			ans *= b;
		b *= b;
	}
	return ans;
}

// maybe store factorial inverses to reduce division cost (?)
template <int mod = MOD>
struct Mint {
	int val;

	Mint(int x = 0): val(x < 0 ? x + mod : x) {}

	void operator += (Mint<mod> o) { *this = *this + o; }
	void operator -= (Mint<mod> o) { *this = *this - o; }
	void operator *= (Mint<mod> o) { *this = *this * o; }
	void operator /= (Mint<mod> o) { *this = *this / o; }
	Mint<mod> operator + (Mint<mod> o) { return val + o.val >= mod ? val + o.val - mod : val + o.val; }
	Mint<mod> operator - (Mint<mod> o) { return val - o.val < 0 ? val - o.val + mod : val - o.val; }
	Mint<mod> operator * (Mint<mod> o) { return (int) (1ll * val * o.val % mod); }
	Mint<mod> operator / (Mint<mod> o) { return *this * fexp(o, mod - 2); }

	friend ostream& operator << (ostream &os, const Mint<mod> &p) {
		return os << p.val;
	}

	friend istream& operator >> (istream &is, Mint<mod> &p) {
		return is >> p.val;
	}
};