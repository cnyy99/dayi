#include <stdio.h>

int A[100];

void print_subset(int n, int * A, int cur)
{
	if(cur==n)
	{
		for(int i=0;i<n;i++)
			if(A[i]) printf("%d ", i);
		printf("\n");
		return;
	}
	A[cur] = 1;  //选第cur个元素
	print_subset(n,A,cur+1);
	A[cur] = 0;
	print_subset(n,A,cur+1);
	
}

int main() {
  int n;
  scanf("%d", &n);
  print_subset(n,A,0);
  
  return 0;
}
