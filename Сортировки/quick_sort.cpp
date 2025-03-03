#include <iostream>
#include <vector>

using namespace std;



vector<int> sum_of_array(vector<int> a, vector<int> b, int value)
{
	int n = a.size() + b.size() + 1;
	vector<int> res;
	for (int i = 0; i < n; i++)
		if (i < a.size())
			res.push_back(a[i]);
		else if (i == a.size())
			res.push_back(value);
		else
			res.push_back(b[i - a.size() - 1]);
	return res;

}

vector<int> quick_sort(vector<int> arr)
{
	if (arr.size() <= 1)
		return arr;

	int ind = 0;
	int value = arr[ind];
	vector <int> left, right;

	for (int i = 1; i < arr.size(); i++)
	{
		if (arr[i] > value)
			right.push_back(arr[i]);
		else
			left.push_back(arr[i]);
	}

	return sum_of_array(quick_sort(left), quick_sort(right), value);
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	vector<int> arr(n);
	for (int i = 0; i < n; i++) cin >> arr[i];
	
	vector<int> res = quick_sort(arr);

	for (int i = 0; i < res.size(); i++)
	{
		cout << res[i] << ' ';
	}

}
