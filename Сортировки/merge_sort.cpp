#include <iostream>
#include <vector>

using namespace std;

#define IN for(int i = 0; i < n; i++) cin >> arr[i];
#define OUT for(int  i = 0; i < n; i++) cout << arr[i] << ' ';

vector<int> merge(vector<int>&left, vector<int>&right)
{
	vector<int> merged;

	int left_index = 0, right_index = 0;

	while(left_index < left.size() && right_index < right.size())
		if (left[left_index] <= right[right_index])
		{
			merged.push_back(left[left_index++]);
		}
		else
			merged.push_back(right[right_index++]);

	while (left_index < left.size())
	{
		merged.push_back(left[left_index++]);
	}

	while (right_index < right.size())
		merged.push_back(right[right_index++]);

	return merged;
}



void merge_sort(vector<int>& arr)
{
	if (arr.size() <= 0)
		return;

	vector <int> left, right;
	int n = arr.size() / 2;

	for (int i = 0; i < n; i++)
		left.push_back(arr[i]);

	for (int i = n; i < arr.size(); i++)
		right.push_back(arr[i]);

	merge_sort(left);
	merge_sort(right);

	arr = merge(left, right);

}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	vector<int> arr(n);
	IN;
	merge_sort(arr);
	OUT;

}
