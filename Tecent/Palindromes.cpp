#include<iostream>
#include<string>

using namespace std;

int LcsLength(string str)
{
	int n = str.length();
	int res = n;
	int **a = new int*[n+1];
	for (int i = 0; i < n + 1; i++) 
	{
		a[i] = new int[n + 1];
	}
	for (int i = 0; i < n + 1; i++)
	{
		a[i][0] = 0;
		a[0][i] = 0;
	}
	for (int i = 1; i < n + 1; i++)
	{
		for (int j = 1; j < n + 1; j++)
		{
			if (str[i-1]==str[n-j])
			{
				a[i][j] = a[i - 1][j - 1] + 1;
			}
			else
			{
				a[i][j] = (a[i - 1][j] > a[i][j - 1] ? a[i - 1][j] : a[i][j - 1]);
			}
		}
	}
	res = res - a[n][n];

	for (int i = 0; i < n + 1; i++)
	{
		delete[] a[i];
	}
	delete[] a;
	return res;
}
//int main()
//{
//	string str;
//	while (cin >> str)
//	{
//		cout << LcsLength(str) << endl;
//	}
//	return 0;
//}