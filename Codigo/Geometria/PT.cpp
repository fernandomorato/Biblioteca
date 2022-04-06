// Ponto 2D
//
// template <typename T>
struct PT {
	#define T long long
	T x, y;
	PT(T _x = 0, T _y = 0): x(_x), y(_y) {}
	PT operator + (const PT &p)		const { return PT(x + p.x, y + p.y); }
	PT operator - (const PT &p) 	const { return PT(x - p.x, y - p.y); }
	PT operator * (T c)				const { return PT(c * x, c * y); }
	T operator * (const PT &p) 		const { return x * p.x + y * p.y; }
	T operator % (const PT &p) 		const { return x * p.y - y * p.x; }
	bool operator < (const PT &p) 	const { return x == p.x ? y < p.y : x < p.x; }
	bool operator == (const PT &p) 	const { return x == p.x && y == p.y; }

	friend std::ostream& operator << (std::ostream &os, const PT &p) {
		return os << p.x << ' ' << p.y;
	}
	friend std::istream& operator >> (std::istream &is, PT &p) {
		return is >> p.x >> p.y;
	}
};