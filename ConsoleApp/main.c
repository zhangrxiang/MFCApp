#include <stdio.h>
#include <string.h>
int main() {

	int arr[10] = {-1}, i = 0;
	memset(arr,-1,sizeof(arr));
	for (i = 0; i < 5; i++)
	{
		arr[i] = i;
	}
	for ( i = 0; i < 10; i++)
	{
		printf("%d\n",arr[i]);
	}
	system("pause");
}