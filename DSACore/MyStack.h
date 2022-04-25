#pragma once
#include <iostream>
#include <cassert>
using namespace std;

template <typename T>
class MyStack
{
public:
	MyStack(int size);
	~MyStack();
	bool stackEmpty();//ÅÐ¿Õ
	bool stackFull();//ÅÐÂú
	void clearStack();//Çå¿Õ
	int stackLength();//³¤¶È
	bool push(T elem);//Ñ¹Õ»
	bool pop(T& elem);//³öÕ»
	bool stackTop(T& elem);//·µ»ØÕ»¶¥
	void stackTranverse();//±éÀúÕ»

private:
	T* m_pStack;//Õ»Ö¸Õë
	int m_iSize;//Õ»ÈÝÁ¿
	int m_iTop;//Õ»¶¥
};

template <typename T>
MyStack<T>::MyStack(int size)
{
	m_iSize = size;
	m_pStack = new T[m_iSize];
	m_iTop = 0;
}
template <typename T>
MyStack<T>::~MyStack()
{
	delete m_pStack;
	m_pStack = NULL;
}
template <typename T>
bool MyStack<T>::stackEmpty() {//ÅÐ¿Õ
	return m_iTop == 0 ? true : false;
}
template <typename T>
bool MyStack<T>::stackFull() {//ÅÐÂú
	return m_iTop == m_iSize ? true : false;
}
template <typename T>
int MyStack<T>::stackLength() {//Õ»³¤¶È
	return m_iTop;
}
template <typename T>
void MyStack<T>::clearStack() {//Çå¿Õ
	m_iTop = 0;
}
template <typename T>
bool MyStack<T>::push(T elem) {//Ñ¹Õ»
	if (stackFull()) {
		return false;
	}
	else {
		m_pStack[m_iTop++] = elem;
		return true;
	}
}
template <typename T>
bool MyStack<T>::pop(T& elem) {//³öÕ»
	if (stackEmpty())
	{
		return false;
	}
	else {
		elem = m_pStack[--m_iTop];
		return true;
	}
}
template <typename T>
bool MyStack<T>::stackTop(T& elem) {//·µ»ØÕ»¶¥ÔªËØ
	if (stackEmpty())
	{
		return false;
	}
	else {
		elem = m_pStack[m_iTop - 1];
		return true;
	}
}
template <typename T>
void MyStack<T>::stackTranverse() {//±éÀúÕ»
	int i = 0;
	for (i = 0; i < m_iTop; i++) {
		cout << m_pStack[i];
	}
}