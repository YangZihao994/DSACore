#include "Dijkstra.h"
static const int N = 510;	//点数量的最大值

static int n, m;			// n表示点, m表示边
static int dist[N];			// 1号点到每个点的距离          边权若要为浮点型改为double即可
static int g[N][N];			//邻接矩阵
static bool st[N];			//判断当前点是否是最短路

int ImplementDijkstra()		//Dijkstra算法实现
{
	memset(dist, 0x3f, sizeof dist);

	dist[1] = 0;

	for (int i = 0; i < n; i ++ )
	{
		int t = -1;

		for (int j = 1; j <= n; j ++ )
			if (!st[j] && (t == -1 || dist[t] > dist[j]))
				t = j;

		st[t] = true;

		for (int j = 1; j <= n; j++)
			dist[j] = std::min(dist[j], dist[t] + g[t][j]);
	}

	if (dist[n] == 0x3f3f3f3f) return -1;
	
	return dist[n];
}

int Dijkstra()				// Dijkstra算法主体
{
	scanf_s("%d%d", &n, &m);

	memset(g, 0x3f, sizeof g);

	while (m -- )
	{
		int x, y, z;
		scanf_s("%d%d%d", &x, &y, &z);
		
		g[x][y] = std::min(g[x][y], z);
	}

	return ImplementDijkstra();
}