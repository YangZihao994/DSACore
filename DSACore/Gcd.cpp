#include"Gcd.h"

int Gcd(int a, int b)   // 欧几里得算法主体
{
    return b ? Gcd(b, a % b) : a;
}