#include<cstdio>

int main() {
	FILE * fread = fopen("test.txt", "r");
	FILE * fwrite = fopen("answer.txt", "w");
	int n,m,temp;
	int sum = 0;
	fscanf(fread, "%d", &n);
	while (n--){
		fscanf(fread, "%d", &m);
		for (int i = 1; i <= m; i++){
			fscanf(fread, "%d", &temp);
			sum += temp;
		}
		fprintf(fwrite, "%d\n", sum);
		sum = 0;
	}

	fclose(fwrite);
	fclose(fread);

	return 0;
}
