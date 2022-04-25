#include <iostream>
#include <cstdlib>
using namespace std;
template <class T> //模板类
class Link //单链表结点类
{
public:
    T data; //结点数据域
    Link<T>* next; //指向下一结点的指针
    Link(const T info, Link<T>* nextValue = NULL) //带有元素内容和下一结点指针的构造函数，下一结点的指针为默认参数，若不输入默认为空
    {
        data = info;
        next = nextValue;
    }
    Link(const Link<T>* nextValue) //带有下一结点指针的构造函数
    {
        next = nextValue;
    }
    Link() //无参数的构造函数
    {
        next = NULL;
    }
    //上述三个函数为Link的构造函数及其重载
};
template <class T>
class InkList //单链表类
{
private:
    Link<T>* head, * tail; //头指针和尾指针，其中头指针不储存元素
    int curLen; //单链表当前元素数
    Link<T>* setPos(const int i); //返回下标为i的元素地址，函数类型为Link<T>的指针类型
public:
    InkList() //单链表的无参数构造函数构造函数
    {
        head = tail = new Link<T>;
        curLen = 0;
    }
    ~InkList() //单链表的析构函数
    {
        Link<T>* tmp;
        while (head != NULL) //从头结点开始逐个删除结点
        {
            tmp = head;
            head = head->next;
            delete tmp;
        }
    }
    bool isEmpty(); //若链表为空，返回true
    void clear(); //清空链表，保留头结点
    int length(); //返回链表存储元素个数
    bool insFirst(const T value); //将value插入链表头结点之后
    bool append(const T value); //将value插入链表尾节点之后
    bool delFirst(); //删除头结点之后的第一个元素
    bool delEnd(); //删除尾节点所指向的元素
    void returnEnd(T& value); //用变量value返回尾结点的元素值
    bool insert(const int p, const T value); //在下标为p的位置插入value
    bool deleteElem(const int p); //删除下标为p位置的元素
    bool getValue(const int p, T& value); //用变量value返回下标为p的元素
    bool setValue(const int p, const T value); //设置下标为p的元素值为value
    bool getPos(int& p, const T value); //用变量p返回第一个元素值为value的元素下标
    void display(); //输出链表的元素个数和每个元素的值
};
template <class T>
Link<T>* InkList<T>::setPos(const int i) //返回下标为i的元素地址
{
    //在类的外部实现类的函数时，要用   函数类型 类名::函数名(参数)   的方式实现
    int coun = -1; //计数器初始化为-1，若i为-1，直接返回头结点
    Link<T>* p;
    p = head;
    while (p != NULL && coun < i) //从头节点开始逐个访问直到无结点可访问或找到i结点
    {
        p = p->next;
        coun++;
    }
    if (coun == i) //若找到i结点，返回它的指针
        return p;
    else //没找到返回NULL
        return NULL;
}
template <class T>
bool InkList<T>::isEmpty() //若链表为空，返回true
{
    if ((head->next) == NULL) //头尾节点相同，表示没有元素，返回true
        return true;
    else
        return false;
    //还有其他种实现方法，如curLen为0返回true
}
template <class T>
void InkList<T>::clear() //清空链表，保留头结点
{
    Link<T>* p, * q; //p指向要删除的结点的下一结点，q指向要删除的结点
    p = head->next; //头结点不要删除，p首先指向第一个元素
    head->next = NULL;
    tail = head;
    curLen = 0;
    while (p != NULL)
    {
        q = p; //先将p的地址赋给q，在让p指向下一结点，最后删除q指向的元素
        p = p->next;
        delete q;
    }
}
template <class T>
int InkList<T>::length() //返回链表存储元素个数
{
    return curLen;
}
template <class T>
bool InkList<T>::insFirst(const T value) //将value插入链表头结点之后
{
    if ((head->next) == NULL) //链表为空时，插入元素后要修改尾指针
    {
        Link<T>* p = new Link<T>(value); //p指向一个新建的Link对象，它的值为value
        head->next = p;
        tail = p;
    }
    else //链表不空时，插入元素的next指针要指向当前第一个元素
    {
        Link<T>* p = new Link<T>(value, head->next);
        head->next = p;
    }
    curLen++; //链表长度+1
    return true;
}
template <class T>
bool InkList<T>::append(const T value) //将value插入链表尾节点之后
{
    Link<T>* p = new Link<T>(value);
    tail->next = p;
    tail = p;
    curLen++;
    return true;
}
template <class T>
bool InkList<T>::delFirst() //删除头结点之后的第一个元素
{
    if (head->next != NULL)
    {
        Link<T>* p;
        p = head->next;
        if (tail == p)
            tail = head;
        head->next = p->next;
        delete p;
        curLen--;
        return true;
    }
    else
    {
        cout << "The link is empty" << endl;
        return false;
    }
}
template <class T>
bool InkList<T>::delEnd() //删除尾节点所指向的元素
{
    if (tail == head)
    {
        cout << "The link is empty" << endl;
        return false;
    }
    else
    {
        Link<T>* p, * q; //p指向最后一个结点，q指向它的前驱
        p = head;
        while (p->next != NULL)
        {
            q = p;
            p = p->next;
        }
        //另一种实现方法
        //p=tail;
        //q=setPos(curLen-2);
        delete p;
        tail = q; //尾节点元素被删除，q成为新的尾节点
        q->next = NULL; //将q的next置空
        curLen--;
        return true;
    }
}
template <class T>
void InkList<T>::returnEnd(T& value) //用变量value返回尾结点的元素值
{
    if (tail == head)
    {
        cout << "The List is empty" << endl;
        return;
    }
    else
    {
        value = tail->data;
    }
}
template <class T>
bool InkList<T>::insert(const int i, const T value) //在下标为p的位置插入value
{
    if (i<0 || i>curLen - 1) //判断位置是否合法
    {
        cout << "Illegal insert position" << endl;
        return false;
    }
    Link<T>* p, * q; //q为新插入结点，p为它的前驱
    p = setPos(i - 1);
    q = new Link<T>(value, p->next);//先将q的next指向p的next，再修改p的next
    p->next = q;
    if (p == tail)
        tail = q;
    curLen++;
    return true;
}
template <class T>
bool InkList<T>::deleteElem(const int i) //删除下标为p位置的元素
{
    Link<T>* p, * q; //q为要删除的结点，p为它的前驱
    if ((p = setPos(i - 1)) == NULL || p == tail)
    {
        cout << "Illegal delete position" << endl;
        return false;
    }
    else
    {
        q = p->next;
        if (q == tail) //若删除的为尾节点，修改尾指针
            tail = p;
        p->next = q->next; //先将p的next修改为q的next，再删除q
        delete q;
        curLen--;
        return true;
    }
}
template <class T>
bool InkList<T>::getValue(const int i, T& value) //用变量value返回下标为p的元素
{
    Link<T>* p;
    if ((p = setPos(i)) != NULL)
    {
        value = p->data;
        return true;
    }
    else
    {
        cout << "Illegal inquire position" << endl;
        return false;
    }
}
template <class T>
bool InkList<T>::setValue(const int i, const T value) //设置下标为p的元素值为value
{
    Link<T>* p;
    if ((p = setPos(i)) != NULL)
    {
        p->data = value;
        return true;
    }
    else
    {
        cout << "Illegal modify position" << endl;
        return false;
    }
}
template <class T>
bool InkList<T>::getPos(int& i, const T value) //用变量p返回第一个元素值为value的元素下标
{
    if (head->next == NULL)
    {
        cout << "The list is empty" << endl;
        return false;
    }
    Link<T>* p;
    p = head->next;
    int coun = 0;
    while (p->next != NULL && (p->data) != value)
    {
        p = p->next;
        coun++;
    }
    if ((p->data) == value)
    {
        i = coun;
        return true;
    }
    else
    {
        cout << "non-existed" << endl;
        return false;
    }
}
template <class T>
void InkList<T>::display() //输出链表的元素个数和每个元素的值
{
    Link<T>* p;
    p = head;
    int coun = 0;
    cout << "length:" << curLen << endl;
    while (p->next != NULL)
    {
        p = p->next;
        cout << coun++ << ":" << p->data << endl;
    }
    cout << "tail:" << tail->data << endl;
}
/*
    设基本操作为 清空链表（clear）、返回链表长度（length）、判断链表是否为空（isEmpty）
        1.限制单链表除基本操作外只能够使用 头插法（insFirst）/push、删除第一个元素（delFirst）/pop、
          返回首个元素的值（getValue(0,T &value)）/top
          则单链表变为栈
        2.限制单链表除基本操作外只能够使用 尾插法（insEnd）/push、删除第一个元素（delFirst）/pop、
          返回首个元素的值（getValue(0,T &value)）/front、返回末尾元素的值（returnEnd）
          则链表变为队列

*/