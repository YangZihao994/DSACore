#include"Gcd.h"

int Gcd(int a, int b)   // ŷ������㷨����
{
    return b ? Gcd(b, a % b) : a;
}