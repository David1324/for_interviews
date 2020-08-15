#include <stdio.h>

void f(int n, int m)
{
	int i;

	printf("n=%d, m=%d\n",n,m);

	if (n==0)
	{
		printf("%d\n",m);
		return;
	}

	for (i=0 ; i<m ; i++)
	{
		n=n+1;
	}

	f((n-m)/2,n-m);
}

int main()
{
	//f(4,0);

	int x=1, y=5;
	int *p;
	printf("%d %p\n", y, &p);
	p = &y;
	*p = 10;
	printf("%d\n", y);
	y++;
	x = *p;
	*p = x;
	printf("%d %p\n", x, p);
	//p++;
	printf("%d %p\n", y, &p);

	p++;
	printf("%d %p\n", y, &p);

	getchar();
	return 0;
}