#include <vector>
#include <cassert>
template <class T> struct FenwickTree {
public:
  FenwickTree() : _n(0) {}
  explicit FenwickTree(int n) : _n(n), data(n) {}
  void add(int p, T x) {
    assert(0 <= p && p < _n);
    p++;
    while (p <= _n) {
      data[p - 1] += x;
      p += p & -p;
    }
  }
  T sum(int l, int r) {
    assert(0 <= l && l <= r && r <= _n);
    return sum(r) - sum(l);
  }

private:
  int _n;
  std::vector<T> data;
  T sum(int r) {
    T s = 0;
    while (r > 0) {
      s += data[r - 1];
      r -= r & -r;
    }
    return s;
  }
};

