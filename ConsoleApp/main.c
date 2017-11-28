#include <stdio.h>
#include <string.h>
int now = 0;
int a[300] = { 0 };
void one() 
{
	int arr[10] = { -1 }, i = 0;
	memset(arr, -1, sizeof(arr));
	for (i = 0; i < 5; i++)
	{
		arr[i] = i;
	}
	for (i = 0; i < 10; i++)
	{
		printf("%d\n", arr[i]);
	}
}

int two(int l) {
	int length = l;
	int temp = now, total;
	total = length + temp;
	for (; now< total; now++)
	{
		a[now] = now;
		printf("%d\t", a[now]);
		/*if(a[now] % 30 == 1 && a[now] > 1){	   
			printf("\nnow ---> %d  \n", now);
		}*/
	}
	printf("\nnow ---> %d  \n", now);
}
int main() {

	int length = 10;
	for (int i = 0; i < length; i++)
	{
		//two((i + 1) * 30);
		two(30);
	}
	system("pause");
}