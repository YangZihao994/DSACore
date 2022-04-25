#include "MyHash.h"

int HashTable::InitHashTable() //����һ����hash��  
{
    int i;
    count = 0;
    size = 0; //��ʼ������Ϊhashsize[0]=11  
    Hash_length = hashsize[0];
    elem = new Elemtype[Hash_length];
    if (!elem)
    {
        cout << "�ڴ�����ʧ��" << endl;
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

void HashTable::Collision(int& p, int d) //�����ͻ  
{
    p = (p + d) % Hash_length; //���ÿ��ŵ�ַ���������̽��  
}

bool HashTable::SearchHash(KeyType k, int& p)  
{
    c = 0;
    p = Hash(k); //��hash��ַ  
    while (elem[p].key != NULLKEY && elem[p].key != k)
    {
        c++;
        if (c < Hash_length)
            Collision(p, c);
        else
            return 0; //��ʾ���Ҳ��ɹ�  
    }
    if (elem[p].key == k)
        return 1;
    else
        return 0;

}

int HashTable::InsertHash(Elemtype e) //����  
{
    //�ڲ��Ҳ��ɹ�������½�k���뵽hash����  
    int p;
    if (SearchHash(e.key, p))
        return -1; //��ʾ��Ԫ������hash����  
    else if (c < hashsize[size] / 2) //��ͻ����δ�ﵽ����  
    {
        //����e  
        elem[p] = e;
        count++;
        return 1;
    }
    else
        ReCreateHashTable(); // �ؽ�hash��  
    return 0; //����ʧ��  
}

void HashTable::ReCreateHashTable() //�ؽ�hash��  
{
    int i, count2 = count;
    Elemtype* p, * elem2 = new Elemtype[count];
    p = elem2;
    cout << "____�ؽ�hash��_____" << endl;
    for (i = 0; i < Hash_length; i++) //��ԭ��Ԫ���ݴ浽elem2��  
        if (elem[i].key != NULLKEY)
            *p++ = *(elem + i);
    count = 0; delete[]elem;
    size++; //hash��������  
    Hash_length = hashsize[size];
    p = new Elemtype[Hash_length];
    if (!p)
    {
        cout << "�ռ�����ʧ��" << endl;
        exit(0);
    }
    elem = p;
    for (i = 0; i < Hash_length; i++)
        elem[i].key = NULLKEY;
    for (p = elem2; p < elem2 + count2; p++) //��ԭ��Ԫ�طŻ��±�  
        InsertHash(*p);
}

void HashTable::TraverseHashTable()
{
    cout << "��ϣ��ַ0->" << Hash_length - 1 << endl;
    for (int i = 0; i < Hash_length; i++)
        if (elem[i].key != NULLKEY)
            cout << "Ԫ�صĹؼ���ֵ�����ı�־�ֱ��ǣ�" << elem[i].key << "  " << elem[i].ord << endl;

}

void HashTable::GetData(int p)
{
    cout << "Ԫ�صĹؼ���ֵ�����ı�־�ֱ��ǣ�" << elem[p].key << "  " << elem[p].ord << endl;
}