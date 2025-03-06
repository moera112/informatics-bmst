#include <iostream>
#include <stack>
#include <vector>

using namespace std;


void merge_sort(vector<int>& arr)
{
	if (arr.size() <= 1)
		return ;

	vector<int> left, right;

	int n = arr.size() / 2;

	for (int i = 0; i < arr.size(); i++)
		if (i < n)
			left.push_back(arr[i]);
		else
			right.push_back(arr[i]);

	merge_sort(left);
	merge_sort(right);

	int l_ind = 0, r_ind = 0, ind = 0;

	while(l_ind < left.size() && r_ind < right.size())
		if (left[l_ind] < right[r_ind])
		{
			arr[ind] = left[l_ind];
			ind++;
			l_ind++;
		}
		else
		{ 
			arr[ind] = right[r_ind];
			ind++;
			r_ind++;
		}

	while (l_ind < left.size())
	{
		arr[ind] = left[l_ind];
		ind++;
		l_ind++;
	}

	while (r_ind < right.size())
	{
		arr[ind] = right[r_ind];
		ind++;
		r_ind++;
	}


}
