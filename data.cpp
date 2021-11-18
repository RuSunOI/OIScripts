#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <set>
#include <vector>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
LL rd(LL l, LL r)
{
	LL res = 1;
	while (res < (r - l + 1))
		res *= rand();
	return l + res % (r - l + 1);
}
struct Edge
{
	int u, v;
	LL w;
};
/// m ranges in 1...n
struct Range
{
	int n, m;
	vector<PII> v;
	Range() {}
	Range(int _n, int _m)
	{
		n = _n;
		m = _m;
		for (int i = 0; i < m; i++)
		{
			v.push_back(make_pair(rd(1, n), rd(1, n)));
			if (v[i].first > v[i].second)
				swap(v[i].first, v[i].second);
		}
	}
	void print()
	{
		printf("%d %d\n", n, m);
		for (PII i : v)
			printf("%d %d\n", i.first, i.second);
	}
};
/// n-node tree (with weight in l...r)
/// type 0 : normal
/// type 1 : chain
/// type 2 : flower
struct Tree
{
	int n, type;
	bool withWeight;
	vector<Edge> edg;
	Tree() {}
	Tree(int _n, int _type)
	{
		n = _n;
		type = _type;
		withWeight = false;
		for (int i = 2; i <= n; i++)
		{
			int fa;
			if (type == 0)
				fa = rd(1, i - 1);
			else if (type == 1)
				fa = i - 1;
			else if (type == 2)
				fa = 1;
			if (rd(0, 1))
				edg.push_back({fa, i, 0});
			else
				edg.push_back({i, fa, 0});
		}
		random_shuffle(edg.begin(), edg.end());
	}
	Tree(int _n, int _type, LL _l, LL _r)
	{
		n = _n;
		type = _type;
		withWeight = true;
		Tree t(n, type);
		edg = t.edg;
		for (Edge i : edg)
			i.w = rd(_l, _r);
	}
	void print()
	{
		printf("%d\n", n);
		for (Edge i : edg)
		{
			printf("%d %d", i.u, i.v);
			if (withWeight)
				printf(" %lld", i.w);
			puts("");
		}
	}
};
/// n-node m-edge map (with weight in l...r)
/// type 0 : normal
/// type 1 : chain
/// type 2 : flower
struct Map
{
	int n, m, type;
	bool withWeight;
	vector<Edge> edg;
	set<Edge> Hash;
	Map() {}
	Map(int _n, int _m, int _type)
	{
		n = _n;
		m = _m;
		type = _type;
		withWeight = false;
		Tree t(n, type);
		edg = t.edg;
		for (Edge i : edg)
			Hash.insert({i.u, i.v, 0});
		for (int i = n - 1; i < m; i++)
		{
			int u, v;
			do
			{
				u = rd(1, n);
				v = rd(1, n);
			} while (u == v || Hash.count({u, v, 0}));
			edg.push_back({u, v, 0});
			Hash.insert({u, v, 0});
		}
		random_shuffle(edg.begin(), edg.end());
	}
	Map(int _n, int _m, int _type, LL _l, LL _r)
	{
		n = _n;
		m = _m;
		type = _type;
		withWeight = true;
		Map t(n, m, type);
		edg = t.edg;
		for (Edge i : edg)
			i.w = rd(_l, _r);
	}
	void print()
	{
		printf("%d %d\n", n, m);
		for (Edge i : edg)
		{
			printf("%d %d", i.u, i.v);
			if (withWeight)
				printf(" %lld", i.w);
			puts("");
		}
	}
};
int main()
{
	freopen("test.in", "w", stdout);
	srand(time(NULL));

	return 0;
}