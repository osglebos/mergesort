#include <stdio.h>

void PrintArr(int *A, int len)
{
	for (int i = 0; i < len; i++)
		printf("%i ", A[i]);
	printf("\n");
}

void Merge(int *A, int p, int q, int r)
{
	int *arr = new int[r-p+1];
	int i = p, j = q;
	int k;

	for (k = 0; k < r - p + 1; k++)
	{
		if (i < q && j <= r)
		{
			if (A[i] <= A[j]) arr[k] = A[i++];
			else if (A[i] >= A[j]) arr[k] = A[j++];
			else i++;
		}
		else if (i >= q) arr[k] = A[j++];
		else if (j > r)arr[k] = A[i++];		
	}

	for (k = 0; k < r - p + 1; k++)A[p + k] = arr[k];
	
}

void Sort(int *A, int p, int r)
{
	if (p < r)
	{
		int half_len = (p+r+1)/2 - 1;
		Sort(A, p, half_len);
		Sort(A, half_len + 1, r);
		Merge(A, p, half_len + 1, r);
	}
}

int main(void)
{
	int A[8] = {5, 2, 4, 6, 1, 3, 2, 6};
	int Length_A = 8;
	
	PrintArr(A, Length_A);
	Sort(A, 0, Length_A-1);
	PrintArr(A, Length_A);

	scanf("%c");

	return 0;
}