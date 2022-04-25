#include <iostream>
#include <cstdlib>
using namespace std;
template <class T> //ģ����
class Link //����������
{
public:
    T data; //���������
    Link<T>* next; //ָ����һ����ָ��
    Link(const T info, Link<T>* nextValue = NULL) //����Ԫ�����ݺ���һ���ָ��Ĺ��캯������һ����ָ��ΪĬ�ϲ�������������Ĭ��Ϊ��
    {
        data = info;
        next = nextValue;
    }
    Link(const Link<T>* nextValue) //������һ���ָ��Ĺ��캯��
    {
        next = nextValue;
    }
    Link() //�޲����Ĺ��캯��
    {
        next = NULL;
    }
    //������������ΪLink�Ĺ��캯����������
};
template <class T>
class InkList //��������
{
private:
    Link<T>* head, * tail; //ͷָ���βָ�룬����ͷָ�벻����Ԫ��
    int curLen; //������ǰԪ����
    Link<T>* setPos(const int i); //�����±�Ϊi��Ԫ�ص�ַ����������ΪLink<T>��ָ������
public:
    InkList() //��������޲������캯�����캯��
    {
        head = tail = new Link<T>;
        curLen = 0;
    }
    ~InkList() //���������������
    {
        Link<T>* tmp;
        while (head != NULL) //��ͷ��㿪ʼ���ɾ�����
        {
            tmp = head;
            head = head->next;
            delete tmp;
        }
    }
    bool isEmpty(); //������Ϊ�գ�����true
    void clear(); //�����������ͷ���
    int length(); //��������洢Ԫ�ظ���
    bool insFirst(const T value); //��value��������ͷ���֮��
    bool append(const T value); //��value��������β�ڵ�֮��
    bool delFirst(); //ɾ��ͷ���֮��ĵ�һ��Ԫ��
    bool delEnd(); //ɾ��β�ڵ���ָ���Ԫ��
    void returnEnd(T& value); //�ñ���value����β����Ԫ��ֵ
    bool insert(const int p, const T value); //���±�Ϊp��λ�ò���value
    bool deleteElem(const int p); //ɾ���±�Ϊpλ�õ�Ԫ��
    bool getValue(const int p, T& value); //�ñ���value�����±�Ϊp��Ԫ��
    bool setValue(const int p, const T value); //�����±�Ϊp��Ԫ��ֵΪvalue
    bool getPos(int& p, const T value); //�ñ���p���ص�һ��Ԫ��ֵΪvalue��Ԫ���±�
    void display(); //��������Ԫ�ظ�����ÿ��Ԫ�ص�ֵ
};
template <class T>
Link<T>* InkList<T>::setPos(const int i) //�����±�Ϊi��Ԫ�ص�ַ
{
    //������ⲿʵ����ĺ���ʱ��Ҫ��   �������� ����::������(����)   �ķ�ʽʵ��
    int coun = -1; //��������ʼ��Ϊ-1����iΪ-1��ֱ�ӷ���ͷ���
    Link<T>* p;
    p = head;
    while (p != NULL && coun < i) //��ͷ�ڵ㿪ʼ�������ֱ���޽��ɷ��ʻ��ҵ�i���
    {
        p = p->next;
        coun++;
    }
    if (coun == i) //���ҵ�i��㣬��������ָ��
        return p;
    else //û�ҵ�����NULL
        return NULL;
}
template <class T>
bool InkList<T>::isEmpty() //������Ϊ�գ�����true
{
    if ((head->next) == NULL) //ͷβ�ڵ���ͬ����ʾû��Ԫ�أ�����true
        return true;
    else
        return false;
    //����������ʵ�ַ�������curLenΪ0����true
}
template <class T>
void InkList<T>::clear() //�����������ͷ���
{
    Link<T>* p, * q; //pָ��Ҫɾ���Ľ�����һ��㣬qָ��Ҫɾ���Ľ��
    p = head->next; //ͷ��㲻Ҫɾ����p����ָ���һ��Ԫ��
    head->next = NULL;
    tail = head;
    curLen = 0;
    while (p != NULL)
    {
        q = p; //�Ƚ�p�ĵ�ַ����q������pָ����һ��㣬���ɾ��qָ���Ԫ��
        p = p->next;
        delete q;
    }
}
template <class T>
int InkList<T>::length() //��������洢Ԫ�ظ���
{
    return curLen;
}
template <class T>
bool InkList<T>::insFirst(const T value) //��value��������ͷ���֮��
{
    if ((head->next) == NULL) //����Ϊ��ʱ������Ԫ�غ�Ҫ�޸�βָ��
    {
        Link<T>* p = new Link<T>(value); //pָ��һ���½���Link��������ֵΪvalue
        head->next = p;
        tail = p;
    }
    else //������ʱ������Ԫ�ص�nextָ��Ҫָ��ǰ��һ��Ԫ��
    {
        Link<T>* p = new Link<T>(value, head->next);
        head->next = p;
    }
    curLen++; //������+1
    return true;
}
template <class T>
bool InkList<T>::append(const T value) //��value��������β�ڵ�֮��
{
    Link<T>* p = new Link<T>(value);
    tail->next = p;
    tail = p;
    curLen++;
    return true;
}
template <class T>
bool InkList<T>::delFirst() //ɾ��ͷ���֮��ĵ�һ��Ԫ��
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
bool InkList<T>::delEnd() //ɾ��β�ڵ���ָ���Ԫ��
{
    if (tail == head)
    {
        cout << "The link is empty" << endl;
        return false;
    }
    else
    {
        Link<T>* p, * q; //pָ�����һ����㣬qָ������ǰ��
        p = head;
        while (p->next != NULL)
        {
            q = p;
            p = p->next;
        }
        //��һ��ʵ�ַ���
        //p=tail;
        //q=setPos(curLen-2);
        delete p;
        tail = q; //β�ڵ�Ԫ�ر�ɾ����q��Ϊ�µ�β�ڵ�
        q->next = NULL; //��q��next�ÿ�
        curLen--;
        return true;
    }
}
template <class T>
void InkList<T>::returnEnd(T& value) //�ñ���value����β����Ԫ��ֵ
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
bool InkList<T>::insert(const int i, const T value) //���±�Ϊp��λ�ò���value
{
    if (i<0 || i>curLen - 1) //�ж�λ���Ƿ�Ϸ�
    {
        cout << "Illegal insert position" << endl;
        return false;
    }
    Link<T>* p, * q; //qΪ�²����㣬pΪ����ǰ��
    p = setPos(i - 1);
    q = new Link<T>(value, p->next);//�Ƚ�q��nextָ��p��next�����޸�p��next
    p->next = q;
    if (p == tail)
        tail = q;
    curLen++;
    return true;
}
template <class T>
bool InkList<T>::deleteElem(const int i) //ɾ���±�Ϊpλ�õ�Ԫ��
{
    Link<T>* p, * q; //qΪҪɾ���Ľ�㣬pΪ����ǰ��
    if ((p = setPos(i - 1)) == NULL || p == tail)
    {
        cout << "Illegal delete position" << endl;
        return false;
    }
    else
    {
        q = p->next;
        if (q == tail) //��ɾ����Ϊβ�ڵ㣬�޸�βָ��
            tail = p;
        p->next = q->next; //�Ƚ�p��next�޸�Ϊq��next����ɾ��q
        delete q;
        curLen--;
        return true;
    }
}
template <class T>
bool InkList<T>::getValue(const int i, T& value) //�ñ���value�����±�Ϊp��Ԫ��
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
bool InkList<T>::setValue(const int i, const T value) //�����±�Ϊp��Ԫ��ֵΪvalue
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
bool InkList<T>::getPos(int& i, const T value) //�ñ���p���ص�һ��Ԫ��ֵΪvalue��Ԫ���±�
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
void InkList<T>::display() //��������Ԫ�ظ�����ÿ��Ԫ�ص�ֵ
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
    ���������Ϊ �������clear�������������ȣ�length�����ж������Ƿ�Ϊ�գ�isEmpty��
        1.���Ƶ����������������ֻ�ܹ�ʹ�� ͷ�巨��insFirst��/push��ɾ����һ��Ԫ�أ�delFirst��/pop��
          �����׸�Ԫ�ص�ֵ��getValue(0,T &value)��/top
          �������Ϊջ
        2.���Ƶ����������������ֻ�ܹ�ʹ�� β�巨��insEnd��/push��ɾ����һ��Ԫ�أ�delFirst��/pop��
          �����׸�Ԫ�ص�ֵ��getValue(0,T &value)��/front������ĩβԪ�ص�ֵ��returnEnd��
          �������Ϊ����

*/