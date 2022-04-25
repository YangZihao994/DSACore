#include "MyHash.h"

int HashTable::InitHashTable() //构造一个空hash表  
{
    int i;
    count = 0;
    size = 0; //初始化容量为hashsize[0]=11  
    Hash_length = hashsize[0];
    elem = new Elemtype[Hash_length];
    if (!elem)
    {
        cout << "内存申请失败" << endl;
        exit(0);
    }
    for (i = 0; i < Hash_length; i++)
        elem[i].key = NULLKEY;
    return 1;
}

void HashTable::DestroyHashTable()
{
    delete[]elem;
    elem = NULL;
    count = 0;
    size = 0;
}

unsigned HashTable::Hash(KeyType k) 
{
    return k % Hash_length;
}

void HashTable::Collision(int& p, int d) //解决冲突  
{
    p = (p + d) % Hash_length; //采用开放地址法里的线性探测  
}

bool HashTable::SearchHash(KeyType k, int& p)  
{
    c = 0;
    p = Hash(k); //求hash地址  
    while (elem[p].key != NULLKEY && elem[p].key != k)
    {
        c++;
        if (c < Hash_length)
            Collision(p, c);
        else
            return 0; //表示查找不成功  
    }
    if (elem[p].key == k)
        return 1;
    else
        return 0;

}

int HashTable::InsertHash(Elemtype e) //插入  
{
    //在查找不成功的情况下将k插入到hash表中  
    int p;
    if (SearchHash(e.key, p))
        return -1; //表示该元素已在hash表中  
    else if (c < hashsize[size] / 2) //冲突次数未达到上限  
    {
        //插入e  
        elem[p] = e;
        count++;
        return 1;
    }
    else
        ReCreateHashTable(); // 重建hash表  
    return 0; //插入失败  
}

void HashTable::ReCreateHashTable() //重建hash表  
{
    int i, count2 = count;
    Elemtype* p, * elem2 = new Elemtype[count];
    p = elem2;
    cout << "____重建hash表_____" << endl;
    for (i = 0; i < Hash_length; i++) //将原有元素暂存到elem2中  
        if (elem[i].key != NULLKEY)
            *p++ = *(elem + i);
    count = 0; delete[]elem;
    size++; //hash容量增大  
    Hash_length = hashsize[size];
    p = new Elemtype[Hash_length];
    if (!p)
    {
        cout << "空间申请失败" << endl;
        exit(0);
    }
    elem = p;
    for (i = 0; i < Hash_length; i++)
        elem[i].key = NULLKEY;
    for (p = elem2; p < elem2 + count2; p++) //将原有元素放回新表  
        InsertHash(*p);
}

void HashTable::TraverseHashTable()
{
    cout << "哈希地址0->" << Hash_length - 1 << endl;
    for (int i = 0; i < Hash_length; i++)
        if (elem[i].key != NULLKEY)
            cout << "元素的关键字值和它的标志分别是：" << elem[i].key << "  " << elem[i].ord << endl;

}

void HashTable::GetData(int p)
{
    cout << "元素的关键字值和它的标志分别是：" << elem[p].key << "  " << elem[p].ord << endl;
}