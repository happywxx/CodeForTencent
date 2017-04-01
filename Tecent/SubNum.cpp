#include<vector>
#include<iostream>
#include <algorithm>

using namespace std;

void test3() {
	int n,tmp;
	int minNum = 0, maxNum = 0;
	cin >> n;
	vector<int> a;
	for (int i = 0; i < n; i++) {
		cin >> tmp;
		a.push_back(tmp);
	}
	sort(a.begin(), a.end());
	if (a[0] == a[n - 1])
	{
		minNum = maxNum = (n - 1)*n / 2;
	}
	else
	{
		int m1 = 0, m2 = 0;
		for (int i = 0; i<n; i++) {
			if (a[i] == a[0]) {
				m1++;
			}
			else {
				break;
			}
		}
		for (int i = n - 1; i >= 0; i--) {
			if (a[i] == a[n - 1]) {
				m2++;
			}
			else {
				break;
			}
		}
		maxNum = m1*m2;
		int min = a[1]-a[0];
		for (int i = 2; i < n; i++)
		{
			if (a[i] - a[i - 1] < min)
			{
				min = a[i] - a[i - 1];
			}
		}
		if (min==0)
		{
			for (int i = 0; i < n; i++)
			{
				int j = i + 1;
				while (j<n && a[j]==a[i])
				{
					j++;
				}
				minNum += (j - i)*(j - i - 1) / 2;
				i = j - 1;
			}
		}
		else
		{
			for (int i = 1; i < n; i++)
			{
				if (a[i + 1] - a[i] == min) 
				{
					minNum++;
				}
			}
		}
	}
	cout << minNum << ' ' << maxNum << endl;
	
}
//int main()
//{
//	test3();
//	system("pause");
//	return 0;
//}