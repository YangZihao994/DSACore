#include"LinearGetprimes.h"

static const int N = 1e6 + 10;      //正整数的范围

static int cnt;
static int primes[N];
static bool st[N];

int LinearGetprimes(int n)     	    //线性筛质数算法主体
{
    for (int i = 2; i <= n; i ++ )
    {
        if (!st[i]) primes[cnt ++ ] = i;
        for (int j = 0; primes[j] * i <= n; j ++ )
        {
            st[primes[j] * i] = true;
            if (i % primes[j] == 0) break;
        }
    }
    return cnt;
}