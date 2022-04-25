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
	bool stackEmpty();//�п�
	bool stackFull();//����
	void clearStack();//���
	int stackLength();//����
	bool push(T elem);//ѹջ
	bool pop(T& elem);//��ջ
	bool stackTop(T& elem);//����ջ��
	void stackTranverse();//����ջ

private:
	T* m_pStack;//ջָ��
	int m_iSize;//ջ����
	int m_iTop;//ջ��
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
bool MyStack<T>::stackEmpty() {//�п�
	return m_iTop == 0 ? true : false;
}
template <typename T>
bool MyStack<T>::stackFull() {//����
	return m_iTop == m_iSize ? true : false;
}
template <typename T>
int MyStack<T>::stackLength() {//ջ����
	return m_iTop;
}
template <typename T>
void MyStack<T>::clearStack() {//���
	m_iTop = 0;
}
template <typename T>
bool MyStack<T>::push(T elem) {//ѹջ
	if (stackFull()) {
		return false;
	}
	else {
		m_pStack[m_iTop++] = elem;
		return true;
	}
}
template <typename T>
bool MyStack<T>::pop(T& elem) {//��ջ
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
bool MyStack<T>::stackTop(T& elem) {//����ջ��Ԫ��
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
void MyStack<T>::stackTranverse() {//����ջ
	int i = 0;
	for (i = 0; i < m_iTop; i++) {
		cout << m_pStack[i];
	}
}