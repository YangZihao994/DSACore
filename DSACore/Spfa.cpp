#include "Spfa.h"
#include <cstdio>
#include <cstring>
#include <queue>

static const int N = 1e5 + 10;

static int n, m;
static int h[N], w[N], e[N], ne[N], idx;	// �ڽӾ���洢����ͼ
static int dist[N];							// ��������
static bool st[N];							// �жϵ�ǰ���Ƿ��ڶ��е���

void Add(int a, int b, int c)				//�ڽӾ���
{
	e[idx] = b; 
	w[idx] = c;   
	ne[idx] = h[a];
	h[a] = idx;
	idx ++ ;
}

int ImplementSpfa()							//Spfa�㷨ʵ��
{
	memset(dist, 0x3f, sizeof dist);

	dist[1] = 0;

	std::queue<int> q;
	q.push(1);
	st[1] = true;

	while (q.size())
	{
		int t = q.front();
		q.pop();

		st[t] = false;

		for (int i = h[t]; i != -1; i = ne[i])
		{
			int j = e[i];
			if (dist[j] > dist[t] + w[i])
			{
				dist[j] = dist[t] + w[i];

				if (!st[j])
				{
					q.push(j);
					st[j] = true;
				}
			}
		}
	}

	return dist[n];
}

int Spfa()									//Spfa�㷨����
{
	scanf_s("%d%d", &n, &m);

	memset(h, -1, sizeof h);

	while (m -- )
	{
		int a, b, c;
		scanf_s("%d%d%d", &a, &b, &c);
		Add(a, b, c);
	}

	int t = ImplementSpfa();

	if (t == 0x3f3f3f3f) return -1;

	return t;
}