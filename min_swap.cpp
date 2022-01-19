#include<bits/stdc++.h>
using namespace std;

int minSwaps(int arr[], int n)
{
	pair<int, int> ap[n];
	for (int i = 0; i < n; i++)
	{
		ap[i].first = arr[i];
		ap[i].second = i;
	}

	sort(ap, ap + n);
	vector<bool> visited(n, false);

	int result = 0;
    
	for (int i = 0; i < n; i++)
	{
	
		if (visited[i] || ap[i].second == i)
			continue;

		int cycle_size = 0;
		int node = i;
		while (!visited[node])
		{
			visited[node] = true;
			node = ap[node].second;
			cycle_size++;
		}

		if (cycle_size > 0)
		{
			result += (cycle_size - 1);
		}
	}

	return result;
}


int main()
{
	int arr[] = {4, 5, 1, 3, 2};
	int n = (sizeof(arr) / sizeof(int));
	cout << minSwaps(arr, n);
	return 0;
}
