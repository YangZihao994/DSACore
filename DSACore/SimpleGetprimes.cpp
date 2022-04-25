#include"SimpleGetprimes.h"

static const int N = 1e6 + 10;	//�������ķ�Χ

static int cnt = 0;				//��¼����������
static int primes[N];			//��������
static bool st[N];				//�ж��Ƿ�������

int SimpleGetprimes(int n)		//����ɸ�����㷨����
{
	for (int i = 2; i <= n; i ++ )
	{
		if (!st[i]) primes[cnt ++ ] = i;
		for (int j = i + i; j <= n; j += i)
		{
			st[j] = true;
		}
	}
	return cnt;
}