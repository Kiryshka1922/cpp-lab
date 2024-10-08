#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//basic recursive function
int get_diff(int i, int n, int array [], int first_sum, int second_sum)
{
	if ((i == n) || array[i] == 0)
		return abs(first_sum - second_sum);
	else
	{
		int masha = get_diff(i + 1, n, array, first_sum + array[i], second_sum); 
		int petya = get_diff(i + 1, n, array, first_sum, second_sum + array[i]); 
		if (masha < petya)
			return masha;
		else 
			return petya;
	}
}
int main()
{
	
	clock_t start, stop;
	int n;
	double time_spent = 0.0;
	scanf("%d", &n); 
	int array[32];
	for (int i = 0; i < n; i++){
		scanf("%d", &array[i]);} 
	
	start = clock();
	int difference = get_diff(0, n, array, 0, 0);
	
	printf("%d\n", difference);
	stop = clock();
	time_spent += (double)(stop - start) / CLOCKS_PER_SEC;
 
    printf("The elapsed time is %f seconds", time_spent);
	return 0;
}