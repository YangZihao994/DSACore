#include "Dijkstra.h"
static const int N = 510;	//�����������ֵ

static int n, m;			// n��ʾ��, m��ʾ��
static int dist[N];			// 1�ŵ㵽ÿ����ľ���          ��Ȩ��ҪΪ�����͸�Ϊdouble����
static int g[N][N];			//�ڽӾ���
static bool st[N];			//�жϵ�ǰ���Ƿ������·

int ImplementDijkstra()		//Dijkstra�㷨ʵ��
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

int Dijkstra()				// Dijkstra�㷨����
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