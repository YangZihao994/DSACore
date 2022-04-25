#pragma once
#include<iostream>  
using namespace std;

typedef int KeyType; //设关键字域为整形,需要修改类型时，只需修改这里就可以  
const int NULLKEY = 0; //NULLKEY表示该位置无值  
int c = 0; //用来统计冲突次数  

struct Elemtype //数据元素类型  
{
    KeyType key;
    int ord;
};
int hashsize[] = { 11,19,29,37,47 }; //hash表容量递增表  
int Hash_length = 0;//hash表表长  

class HashTable
{
private:
    Elemtype* elem; //数据元素数组,动态申请  
    int count;// 当前数据元素个数  
    int size; //决定hash表的容量为第几个,hashsize[size]为当前hash容量  
public:

    int InitHashTable();

    void DestroyHashTable();

    unsigned Hash(KeyType k); //hash函数的一种(取模法)  

    void Collision(int& p, int d); //解决冲突   采用开放地址法里的线性探测  

    bool SearchHash(KeyType k, int& p); //查找   //在开放地址hash表中查找关键字等于k的元素  
                                                 //若找到用p表示待查数据,查找不成功时，p指向的是可插入地址  
    

    int InsertHash(Elemtype e); //插入  

    void ReCreateHashTable(); //重建hash表  

    void TraverseHashTable();

    void GetData(int p);

};