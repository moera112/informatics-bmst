#include <iostream>
#include <vector>

using namespace std;

#define IN for(int i = 0; i < n; i++) cin >> arr[i]
#define OUT for(int i = 0; i < n; i++) cout << res[i] << ' ';


void counting_sort(vector<int>arr)
{
	int min = arr[0], max = arr[0];
	for (int i = 0; i < arr.size(); i++)
	{
		if (arr[i] > max)
			max = arr[i];
		if (arr[i] < min)
			min = arr[i];
	}

	vector <int> res(max - min + 1);

	for (int i = 0; i < arr.size(); i++)
		res[arr[i] - min]++;

	for (int i = 0; i < res.size(); i++)
	{
		for (int j = 0; j < res[i]; j++)
			cout << i + min << ' ';

	}


}


int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	vector<int> arr(n);

	IN;

	counting_sort(arr);
}
