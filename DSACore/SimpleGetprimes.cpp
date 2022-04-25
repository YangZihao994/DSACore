#include"SimpleGetprimes.h"

static const int N = 1e6 + 10;	//正整数的范围

static int cnt = 0;				//记录质数的数量
static int primes[N];			//数量数组
static bool st[N];				//判断是否是质数

int SimpleGetprimes(int n)		//朴素筛质数算法主体
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