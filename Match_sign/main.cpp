#include <stdio.h>
#include "match.h"
void main()
{
	char *arr = "2+(5+2-5)*3-8/2";
	char *arr1 = "671-3*+82/+";
	printf("%d\n",calculate(arr1));
}