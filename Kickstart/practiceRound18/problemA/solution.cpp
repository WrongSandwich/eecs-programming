#include <iostream>
using namespace std;
int main()
{
	int t, n, p, x, count;
	int* bus = nullptr;
	cin >> t; //Number of test cases
	for(int i = 1; i <= t; i++)
	{
		cin >> n;
		n = n*2;
		bus = new int[n];
		for (int j = 0; j < n; i++)
		{
			cin >> bus[j];
		}
		cin >> p;
		cout << "Case #" << i << ": ";
		for (int j = 0; j < p; j++)
		{
			cin >> x;
			count = 0;
			for (int a = 0; a < n; a = a+2)
			{
				if (x >= bus[a] && x <= bus[a+1])
				{
					count++;
				}
			}
			cout << count << " ";
		}
		cout << '\n';
		delete[] bus;
		bus = nullptr;
	}
	return 0;
}
