#include<iostream>
#include<stdio.h>
using namespace std;
int main()
{
	/*int a[5] = { 1,2,3,4,5 };
	int *p = (int *)(&a + 1);
	printf("%d", *(p - 1));*/
	int i = 10;
	int j = 1;
	const int *p1;//(1)
	int const *p2 = &i; //(2)
	p2 = &j;//(3)
	int *const p3 = &i;//(4)
	*p3 = 20;//(5)
	system("pause");
	return 0;
}
