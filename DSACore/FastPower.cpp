#include"FastPower.h"

int FastPower(int m, int k, int p)  	//�������㷨����
{
    int res = 1 % p, t = m;

    while (k)
    {
        if (k & 1) res = res * t % p;
        t = t * t % p;
        k >>= 1;
    }
    return res;
}