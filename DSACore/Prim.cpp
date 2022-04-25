#include "Prim.h"

#include <cstdio>
#include <algorithm>

static const int N = 510, INF = 0x3f3f3f3f;

static int n, m;
static int g[N][N];				// �洢����ͼ         ��Ȩ��ҪΪ�����͸�Ϊdouble����
static int dist[N];				// ��������
static bool st[N];				// �ж��Ƿ�����С��������

int ImplementPrim()				//Prim�㷨ʵ��
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

int Prim()						//Prim�㷨����
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