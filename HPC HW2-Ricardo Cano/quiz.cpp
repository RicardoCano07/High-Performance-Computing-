#include <stdio.h>

int main()
	{
	float i, n, t1 = 0, t2 = 1, nextTerm;

	printf("Enter the number of terms: ");
	scanf("%f", &n);

	printf("Fibonacci Series: ");

	for (i = 1; i <= n; ++i)
	{
		printf("%f, ", t2/t1);
		nextTerm = t1 + t2;
		t1 = t2;
		t2 = nextTerm;
	}
	return 0;
	}