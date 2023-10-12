// https://gist.github.com/Muaath5/4b688bddf69757e8114848fd6a1659df
// Muaath's Segment Tree Template
// This is a customizable segment tree class that supports lazy propagation, in an STD-similar way.

// Version: 2.2

// Last commit: Fix styling

// What's new?
// Fixing the lazy update
// Optimizations for lazy update
// Adding overloads that doesn't need range
// Adding time in tests
// Example
// #include <bits/stdc++.h>
// using namespace std;
// // Put the segment tree templete code here..
// using namespace alg;

// segment_tree<int, merge_min> st;

// // Solution for RMQ problem
// int main() {
//     int n, q;
//     cin >> n;
//     st.set_out(INT_MAX);
//     st.resize(n);
//     for (int i = 0; i < n; cin >> st.values[i++]);
//     st.build();
//     cin >> q;
//     while (q--) {
//         int l, r;
//         cin >> l >> r;
//         l--, r--; // Zero based
//         cout << st.get(l, r) << '\n';
//     }
// }
// TODO
// Adding compare function for binary_search
// Optimizing the update_util & get_util, by making it iterative instead of recursive.
// Usage
// Initialization
// alg::segment_tree<Type, MergeFunc, UpdateType, LazyUpdate, ExpandLazy> NAME;

// Type: For example (int, long long)
// MergeFunc: A function that should merge two types (there is predefined ones like merge_sum, merge_max)
// UpdateType: The type that stores the update for a segement (could be int, or a custom struct that you define)
// LazyUpdate: Update a value of a segment depending on an UpdateType. in the form of Type LazyUpdate(Type x, UpdateType upd)
// ExpandLazy: Getting the UpdateType from a big segment into smaller segment. in the form of UpdateType ExpandLazy(UpdateType cur, UpdateType prev)
// Functions
// int size(): Returns size of the array values
// void resize(int sz): Resize the array values
// void clear(): Clear the segment tree, lazy, and values
// void set_out(Type out): The default value that shouldn't affect the merge function (for example: INT_MIN in case of finding the maximum)
// void set_out_update(UpdType out): The value that shouldn't be applied when lazy update runs (The value of lazy[node] if there is no update should be applied on node)
// int binary_search(int k): Returns index of first element which has get() >= k
// Type get(range q): Returns the merge function of the range. O(log2(size()))
// void build(): Builds the segment tree. O(size())
// void update(int idx, Type value): Updates a value in the array & segment tree. O(log2(size()))
// void lazy_update(range q, UpdType value): Updates a range. O(log2(size()))
// Constants
// maxST = 2e5+1 Edit this constant to edit the size of the tree

// Notes
// The ranges must be zero based
// Use the namespace alg
// Use set_out and set_out_update before resize
// Don't forget to use build
// Edit maxST if you will use a segment tree with a bigger size
// You can use range structure
// Testing
// SPOJ: HORRIBLE (in 0.24s), RMQSQ (in 0.21s)
// Codeforces: 52C Circular RMQ (in 0.358s)
// CSES: Range Queries (first 6 problems), Hotel Queries, and Range Updates and Sums (in 0.54s)

#include <algorithm>
namespace alg {

using std::max;
using std::min;
//using std::cin;
const int maxST = 2e5 + 1;

struct range {
	range(int idx) : left(idx), right(idx) {}
	range(int l, int r) : left(l), right(r) {}
	int left, right;
	int size() { return right - left + 1; }
	int mid() { return (left + right) / 2; }
	//inline void input() { std::cin >> left >> right; }
	bool out(range q) {
		return (q.left > right || q.right < left);
	}
	bool contains(range q) {
		return (left <= q.left && q.right <= right);
	}
	range lhalf() { return range(left, mid()); }
	range rhalf() { return range(mid() + 1, right); }
};

template<class Type, class _UpdTy>
Type lazy_increment(Type original, _UpdTy update, range r)
{
	return original + update;
}

template<class Type, class _UpdTy>
Type lazy_set(Type original, _UpdTy update, range r)
{
	return update;
}

template<class Type>
Type merge_sum(Type l, Type r)
{
	return l + r;
}

template<class Type>
Type merge_max(Type l, Type r)
{
	return max(l, r);
}

template<class Type>
Type merge_min(Type l, Type r)
{
	return min(l, r);
}
template<class UpdType>
UpdType expand_lazy_inc(UpdType lazy, UpdType upd)
{
	return lazy + upd;
}

template<class UpdType>
UpdType expand_lazy_set(UpdType lazy, UpdType upd)
{
	return upd;
}

template <class Type = int,
	Type merge(Type l, Type r) = merge_min,
	class UpdType = int,
	Type lazy_upd(Type original, UpdType update, range r) = lazy_increment,
	UpdType expand_lazy(UpdType lazy, UpdType upd) = expand_lazy_inc
>
class segment_tree // version=2.2
{
public:
	segment_tree() {
		use_lazy = false;
	}

	segment_tree(int sz) {
		use_lazy = false;
		resize(sz);
	}

	Type values[maxST];
	inline void clear()
	{
		for (int i = 0; i < maxST; i++)
			values[i] = OUT;
		for (int i = 0; i < 4 * maxST; i++) {
			tree[i] = OUT;
			lazy[i] = OUTUPD;
		}
		n = 0;
	}
	inline void resize(int sz)
	{
		clear();
		n = sz;
	}
	inline void set_out(Type outside)
	{
		OUT = outside;
	}
	inline void set_out_update(UpdType outside)
	{
		OUTUPD = outside;
	}
	inline int size()
	{
		return n;
	}
	inline range all()
	{
		return range(0, n - 1);
	}
	inline void build()
	{
		build_util(all());
	}
	inline Type get(range r)
	{
		return get_util(r, all());
	}
	inline Type get(int l, int r)
	{
		return get_util(range(l, r), all());
	}

	inline void update(int index, Type value)
	{
		update_util(index, value, all());
	}

	inline void lazy_update(int l, int r, UpdType value)
	{
		use_lazy = true;
		lazy_update_util(range(l, r), all(), value);
	}
	inline void lazy_update(range r, UpdType value)
	{
		use_lazy = true;
		lazy_update_util(r, all(), value);
	}

	// returns index of first element which has get() >= k, if there is no element it returns n-1
	inline int binary_search(int k)
	{
		range rng = all();
		int node = 1;
		while (rng.size() > 1) {
			node *= 2;
			if (tree[node] >= k) {
				rng = rng.lhalf();
			}
			else {
				rng = rng.rhalf();
				node++;
			}
		}
		return rng.left;
	}
private:
	int n;
	bool use_lazy;
	Type tree[4 * maxST], OUT;
	UpdType lazy[4 * maxST], OUTUPD;

	inline void expand_lazy_util(int pos, range arr)
	{
		if (lazy[pos] != OUTUPD) {
			tree[pos] = lazy_upd(tree[pos], lazy[pos], arr);
			if (arr.size() == 1) {
				values[arr.left] = tree[pos];
			}
			else {
				lazy[pos * 2] = expand_lazy(lazy[pos], lazy[pos * 2]);
				lazy[pos * 2 + 1] = expand_lazy(lazy[pos], lazy[pos * 2 + 1]);
			}
			lazy[pos] = OUTUPD;
		}
	}

	Type get_util(range q, range arr, int pos = 1)
	{
		if (use_lazy)
			expand_lazy_util(pos, arr);

		if (q.out(arr))
			return OUT;

		if (q.contains(arr))
			return tree[pos];

		Type c1 = get_util(q, arr.lhalf(), pos * 2);
		Type c2 = get_util(q, arr.rhalf(), pos * 2 + 1);
		return merge(c1, c2);
	}

	void lazy_update_util(range q, range arr, UpdType upd, int pos = 1)
	{
		expand_lazy_util(pos, arr);

		if (q.out(arr)) return;

		if (q.contains(arr))
		{
			lazy[pos] = expand_lazy(lazy[pos], upd);
			expand_lazy_util(pos, arr);
			return;
		}

		lazy_update_util(q, arr.lhalf(), upd, pos * 2);
		lazy_update_util(q, arr.rhalf(), upd, pos * 2 + 1);
		tree[pos] = merge(tree[pos * 2], tree[pos * 2 + 1]);
	}

	void update_util(int idx, Type value, range arr, int pos = 1)
	{
		if (arr.left == arr.right)
		{
			values[arr.left] = value;
			tree[pos] = values[arr.left];
			return;
		}

		if (idx <= arr.mid())
			update_util(idx, value, arr.lhalf(), pos * 2);
		else
			update_util(idx, value, arr.rhalf(), pos * 2 + 1);

		tree[pos] = merge(tree[pos * 2], tree[pos * 2 + 1]);
	}

	void build_util(range arr, int pos = 1)
	{
		if (arr.left == arr.right)
		{
			tree[pos] = values[arr.left];
			return;
		}
		build_util(arr.lhalf(), pos * 2);
		build_util(arr.rhalf(), pos * 2 + 1);
		tree[pos] = merge(tree[pos * 2], tree[pos * 2 + 1]);
	}
};

} // namespace alg