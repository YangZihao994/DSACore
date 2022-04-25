#include "Kruskal.h"

#include <cstdio>
#include <algorithm>

static const int N = 1e5 + 10;				//点数量的最大值
static const int M = 200010;				//边数量的最大值
static const int INF = 0x3f3f3f3f;			//模拟无穷大

static int n, m;							//n个顶点 m条询问
static int p[N];							//并查集数组         加快查找速度

struct Edge
{
	int a, b, w;

	bool operator< (const Edge &W)const
	{
		return w < W.w;
	}
}edges[M];

int Find(int x)								// 并查集模板
{
	if (p[x] != x) p[x] = Find(p[x]);
	return p[x];
}

int ImplementKruskal()						//Kruskal算法实现
{
	std::sort(edges, edges + m);

	for (int i = 1; i <= n; i ++ )
		p[i] = i;

	int res = 0, cnt = 0;

	for (int i = 0; i < m; i ++ )
	{
		int a = edges[i].a;
		int b = edges[i].b;
		int w = edges[i].w;

		a = Find(a);
		b = Find(b);

		if (a != b)
		{
			p[a] = b;
			res += w;
			cnt ++ ;
		}
	}

	if (cnt < n - 1) return INF;

	return res;
}

int Kruskal()								//Kruskal算法主体
{
	scanf_s("%d%d", &n, &m);

	for (int i = 0; i < n; i ++ )
	{
		int a, b, w;
		scanf_s("%d%d%d", &a, &b, &w);
		edges[i] = { a, b, w };
	}

	int t = ImplementKruskal();

	if (t == INF) return -1;
	else return t;
}