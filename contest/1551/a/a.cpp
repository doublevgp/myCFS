#include <stdio.h>
int main() {
	int t;
	scanf("%d", &t);
	while(t--){
		int n;
		scanf("%d", &n);
		int a, b;
		a = b = n / 3;
		if(a + 2 * b == n){
			printf("%d %d\n", a, b);
			continue;
		}
		if(a + 1 + 2 * b == n){
			printf("%d %d\n", a+1, b);
			continue;
		}
		printf("%d %d\n", a, b+1);
	}
	return 0;
}