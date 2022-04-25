#pragma once

template <typename T> void Swap(T array_1[], int a, int b);
template <typename T, typename S> T Min(T a, S b);
template <typename T, typename S> void BubbleSort(T array_1[], S array_2[]);
template <typename T, typename S> void InsertSort(T array_1[], S array_2[]);
template <typename T, typename S> void ShellSort(T array_1[], S array_2[]);
template <typename T, typename S> void Heapify(T array_1[], S array_2[], int i);
template <typename T, typename S> void HeapSort(T array_1[], S array_2[]);
template <typename T, typename S> void MergeSort(T array_1[], S array_2[]);
template <typename T> void QuickSort(T array_1[], int l, int r);


template<typename T>
void Swap(T array_1[], int a, int b)
{
	auto t = array_1[a];
	array_1[a] = array_1[b];
	array_1[b] = t;
}

template<typename T, typename S>
T Min(T a, S b)
{
	return a < b ? a : b;
}

template<typename T, typename S>
void BubbleSort(T array_1[], S array_2[])
{
	int len = array_2 - array_1;
	for (int i = 0; i < len - 1; i++)
	{
		for (int j = 0; j < len - i - 1; j++)
		{
			if (array_1[j] > array_1[j + 1])
			{
				Swap(array_1, j, j + 1);
			}
		}
	}
}

template<typename T, typename S>
void InsertSort(T array_1[], S array_2[])
{
	int len = array_2 - array_1;
	for (int i = 1; i < len; i++)
	{
		auto key = array_1[i];
		int j = i - 1;
		while (j >= 0 && array_1[j] > key)
		{
			array_1[j + 1] = array_1[j];
			j--;
		}
		array_1[j + 1] = key;
	}
}

template<typename T, typename S>
void ShellSort(T array_1[], S array_2[])
{
	int len = array_2 - array_1;
	int gap, i, j;
	T temp;
	for (gap = len >> 1; gap > 0; gap >>= 1)
		for (i = gap; i < len; i++) {
			temp = array_1[i];
			for (j = i - gap; j >= 0 && array_1[j] > temp; j -= gap)
				array_1[j + gap] = array_1[j];
			array_1[j + gap] = temp;
		}
}

template<typename T, typename S>
void Heapify(T array_1[], S array_2[], int i)                   //Î¬»¤¶Ñ
{
	int n = array_2 - array_1;
	int largest = i;
	int lson = i * 2 + 1;
	int rson = i * 2 + 2;

	if (lson < n && array_1[largest] < array_1[lson])
		largest = lson;
	if (rson < n && array_1[largest] < array_1[rson])
		largest = rson;
	if (largest != 1)
	{
		Swap(array_1, largest, i);
		Heapify(array_1, array_2, largest);
	}
}

template<typename T, typename S>
void HeapSort(T array_1[], S array_2[])
{
	int n = array_2 - array_1;
	int i;

	for (i = n / 2 - 1; i >= 0; i--)
		Heapify(array_1, array_1 + i, i);

	for (i = n - 1; i > 0; i--)
	{
		int j = n - 1;
		Swap(array_1, i, 0);
		Heapify(array_1, j--, 0);
	}
}

template<typename T, typename S>
void MergeSort(T array_1[], S array_2[])
{
	int len = array_2 - array_1;
	T* a = array_1;
	T* b = new T[len];
	for (int seg = 1; seg < len; seg += seg) {
		for (int start = 0; start < len; start += seg + seg) {
			int low = start, mid = Min(start + seg, len), high = Min(start + seg + seg, len);
			int k = low;
			int start1 = low, end1 = mid;
			int start2 = mid, end2 = high;
			while (start1 < end1 && start2 < end2)
				b[k++] = a[start1] < a[start2] ? a[start1++] : a[start2++];
			while (start1 < end1)
				b[k++] = a[start1++];
			while (start2 < end2)
				b[k++] = a[start2++];
		}
		T* temp = a;
		a = b;
		b = temp;
	}
	if (a != array_1) {
		for (int i = 0; i < len; i++)
			b[i] = a[i];
		b = a;
	}
	delete[] b;
}

template<typename T>
void QuickSort(T array_1[], int l, int r)
{
	if (l >= r)
		return;
	int i = l - 1, j = r + 1, w = array_1[(r + l) / 2];
	while (i < j)
	{
		do i++; while (array_1[i] < w);
		do j--; while (array_1[j] > w);
		if (i < j)
		{
			Swap(array_1, i, j);
		}
	}
	QuickSort(array_1, l, j), QuickSort(array_1, j + 1, r);
}

