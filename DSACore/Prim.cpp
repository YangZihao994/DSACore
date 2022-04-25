#include "Prim.h"

#include <cstdio>
#include <algorithm>

static const int N = 510, INF = 0x3f3f3f3f;

static int n, m;
static int g[N][N];				// 存储无向图         边权若要为浮点型改为double即可
static int dist[N];				// 距离数组
static bool st[N];				// 判断是否在最小生成树中

int ImplementPrim()				//Prim算法实现
{
	memset(dist, 0x3f, sizeof dist);

	int res = 0;

	for (int i = 0; i < n; i++)
	{
		int t = -1;

		for (int j = 1; j <= n; j ++ )
			if (!st[j] && (t == -1 || dist[t] > dist[j]))
				t = j;
	
		if (i && dist[t] == INF) return INF;

		if (i) res += dist[t];
		st[t] = true;

		for (int j = 1; j <= n; j ++ )
			dist[j] = std::min(dist[j], g[t][j]);
	}

	return res;
}

int Prim()						//Prim算法主体
{
	scanf_s("%d%d", &n, &m);

	memset(g, 0x3f, sizeof g);

	while (m -- ) 
	{
		int a, b, c;
		scanf_s("%d%d%d", &a, &b, &c);
		g[a][b] = g[b][a] = std::min(g[a][b], c);
	}

	int t = ImplementPrim();

	if (t == INF) return -1;
	else return t;
}