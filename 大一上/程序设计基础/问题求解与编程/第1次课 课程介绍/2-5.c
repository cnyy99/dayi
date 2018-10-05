#include<stdio.h>
int main(){
  int i, j, n, S = 0;
  scanf("%d", &n);
  for(i = 1; i <= n; i++){
    int factorial = 1;
    for(j = 1; j <= i; j++)
      factorial *= j;
    S += factorial;
  }
  printf("%d\n", S % 1000000);
  return 0;
}


#include <stdio.h>

int factorial(int n){
	if (n == 1) return 1;
	else return (n*factorial(n - 1))%1000000;
}

int add_fac(int n){
	if (n == 1) return 1;
	else return (factorial(n) + add_fac(n - 1))%1000000;
}

int main(){
	int n;
	scanf("%d", &n);
	printf("%d", add_fac(n));
	return 0;
}
