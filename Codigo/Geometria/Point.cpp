// Ponto 2D
//
// 5e4062

template <class T>
struct Point {
	// #define T long long
	T x, y;
	Point(): x(0), y(0) {}
	Point(const T &x, const T &y): x(x), y(y) {}

	void swap(Point &other) { std::swap(x, other.x); std::swap(y, other.y); }

	template <class F> explicit operator Point<F> () const {
		return Point<F>(static_cast<F>(x), static_cast<F>(y)); 
	}

	template <class F> Point& operator = (const Point<F> &other) {
		x = other.x, y = other.y; return *this;
	}
	template <class F> Point& operator += (const Point<F> &other) {
		x += other.x, y += other.y; return *this;
	}
	template <class F> Point& operator *= (const F &factor) {
		x *= factor, y *= factor; return *this;
	}
	template <class F> Point& operator /= (const F &factor) {
		x /= factor, y /= factor; return *this;
	}

	friend std::ostream& operator << (std::ostream &os, const Point &p) {
		return os << p.x << ' ' << p.y;
	}
	friend std::istream& operator >> (std::istream &is, Point &p) {
		return is >> p.x >> p.y;
	}
};

template <class F> inline Point<F> makePoint(const F &x, const F &y) { return Point<F>(x, y); }

#define Unary(name, arg, expr) template <class A> inline auto name(const arg) -> decltype(expr) { return expr; }
#define Binary(name, arg1, arg2, expr) template <class A, class B> inline auto name(const arg1, const arg2) -> decltype(expr) { return expr; }
#define Ternary(name, arg1, arg2, arg3, expr) template <class A, class B, class C> inline auto name(const arg1, const arg2, const arg3) -> decltype(expr) { return expr; }

Unary(operator -, Point<A> &point, makePoint(-point.x, -point.y))
Binary(operator +, Point<A> &lhs, Point<B> &rhs, makePoint(lhs.x + rhs.x, lhs.y + rhs.y))
Binary(operator -, Point<A> &lhs, Point<B> &rhs, makePoint(lhs.x - rhs.x, lhs.y - rhs.y))
Binary(operator *, A &factor, Point<B> &rhs, makePoint(factor * rhs.x, factor * rhs.y))
Binary(operator *, Point<A> &lhs, B &factor, makePoint(lhs.x * factor, lhs.y * factor))
Binary(operator /, Point<A> &lhs, B &factor, makePoint(lhs.x / factor, lhs.y / factor))

Binary(operator *, Point<A> &lhs, Point<B> &rhs, lhs.x * rhs.x + lhs.y * rhs.y)
Binary(operator %, Point<A> &lhs, Point<B> &rhs, lhs.x * rhs.y - lhs.y * rhs.x)

Binary(operator ==, Point<A> &lhs, Point<B> &rhs, lhs.x == rhs.x && lhs.y == rhs.y);
Binary(operator !=, Point<A> &lhs, Point<B> &rhs, lhs.x != rhs.x || lhs.y != rhs.y);

Binary(operator <, Point<A> &lhs, Point<B> &rhs, lhs.x < rhs.x || (lhs.x == rhs.x && lhs.y < rhs.y));
Binary(operator >, Point<A> &lhs, Point<B> &rhs, lhs.x > rhs.x || (lhs.x == rhs.x && lhs.y > rhs.y));
Binary(operator <=, Point<A> &lhs, Point<B> &rhs, !(lhs > rhs));
Binary(operator >=, Point<A> &lhs, Point<B> &rhs, !(lhs < rhs));

// < 0 lhs -> rhs is counter-clockwise, 0 collinear, > 0 lhs -> rhs is clockwise
Binary(ccw, Point<A> &lhs, Point<B> &rhs, rhs ^ lhs);
Ternary(ccw, Point<A> &lhs, Point<B> &rhs, Point<C> &origin, ccw(lhs - origin, rhs - origin))

// Angles and Rotations (counter-clockwise)
Unary(angle, Point<A> &point, atan2(point.y, point.x))
Binary(angle, Point<A> &lhs, Point<B> &rhs, atan2(lhs ^ rhs, lhs * rhs))
Ternary(angle, Point<A> &lhs, Point<B> &rhs, Point<C> &origin, angle(lhs - origin, rhs - origin))
Ternary(rotate, Point<A> &point, B &angleSin, C &angleCos,
	makePoint(angleCos * point.x - angleSin * point.y,
			  angleSin * point.x + angleCos * point.y))
Binary(angle, Point<A> &point, B &angle, rotate(point, sin(angle), cos(angle)))
Ternary(angle, Point<A> &point, B &angle, Point<C> &origin, 
		origin + rotate(point - origin, angle))
Unary(perp, Point<A> &point, atan2(-point.y, point.x))

// Distances
Unary(abs, Point<A> &point, point * point)
Unary(norm, Point<A> &point, sqrt(abs(point)))
Binary(dist, Point<A> &lhs, Point<B> &rhs, abs(lhs - rhs))
Binary(dist2, Point<A> &lhs, Point<B> &rhs, norm(lhs - rhs))
Binary(bisector, Point<A> &lhs, Point<B> &rhs, lhs * norm(rhs) + rhs * norm(lhs));

#undef Unary
#undef Binary
#undef Ternary