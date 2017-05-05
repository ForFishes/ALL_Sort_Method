#pragma once
#include<vector>
using namespace std;
class CSort
{
public:
	CSort();
	CSort(std::vector<int>& _vec) :m_vec(_vec){};
	~CSort();
	void merge(vector<int>& a, int low, int high, int mid);
	void merge_sort(vector<int>& a, int low, int hi);
	std::vector<int> m_vec;
};

