// MergeSort.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"


// SortTemplate.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include"Sort.h"
#include<assert.h>
#include<ctime>
#include<iostream>
#include<random>
using namespace std;

void merge(vector<int>& a, int low, int high, int mid)
{
	int i = low, j = mid+1;
	vector<int> temp_vec;
	temp_vec.resize(a.size());
	//进行复制数据
	for (int k = low; k <= high; ++k)
	{
		//temp_vec.push_back(a[k]);
		temp_vec[k] = a[k];
	}
	for (int k = low; k <= high; ++k)
	{
		if (i > mid)a[k] = temp_vec[j++];
		else if (j > high)a[k] = temp_vec[i++];
		else if (temp_vec[j] < temp_vec[i])a[k] = temp_vec[j++];
		else a[k] = temp_vec[i++];
	}

}


void merge_sort(vector<int>& a, int low, int hi)
{
	if (hi <= low)return;
	int mid = low + (hi - low) / 2;
	merge_sort(a, low, mid);
	merge_sort(a, mid + 1, hi);
	merge(a, low, hi, mid);
}
//判断是否排序,从小到大进行排序
bool isSort(vector<int>& a)
{
	for (size_t i = 0; i < a.size(); i++)
	{
		if (a[i] < a[i - 1])return false;
	}
	return true;
}

int main()
{

	static default_random_engine e(time(0));
	static uniform_int_distribution<int> u(1, 1000000000);
	vector<int>vec;
	for (size_t i = 0; i < 5; i++)
	{
		vec.push_back(u(e));
	}

	//for (auto ele : vec)
	//{
	//	cout << ele << endl;
	//}

	merge_sort(vec, 0, vec.size()-1);

	for (auto ele :vec)
	{
		cout << ele << endl;
	}
	  
	return 0;
}
