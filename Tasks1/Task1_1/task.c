#include <stdio.h>
#include <math.h>

int main()
{
	int x = 2.0;
	float y = 0.7;
	int z = -1;

	double a = powl(x * y * z + abs(z * sin(y)), 1 / 3);
	double b = y * cos(x * z * sin(y)) + 3;

	printf("%f", a);
	printf("\n");
	printf("%f", b);
}
