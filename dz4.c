#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct Arr {
	int v;
	int s;
};

void ShellSort (struct Arr array[], int size)              
{
	int step, i, j;
	struct Arr tmp;
	

	for (step = size / 2; step > 0; step /= 2)

		for (i = step; i < size; i++) 

			for (j = i - step; j >= 0 && array[j].s > array[j + step].s; j -= step)
			{
				tmp = array[j];
				array[j] = array[j + step];
				array[j + step] = tmp;
			}
}

int main() {
	struct Arr *p;
	int n;
	int a;
    printf("Enter the number of graph vertices: ");
    scanf("%d",&n);
	p = malloc((n)*sizeof(struct Arr));
	for (int i=0;i<n;i++) {
		p[i].v=i+1;
		p[i].s=0;
	}
	for (int i=0;i<n;i++) {
		for (int j=i+1;j<n;j++) {
			printf("%d -- %d?\n(1/0)",i+1,j+1);
			scanf("%d",&a);
			if (a == 1) {
				p[i].s++;
				p[j].s++;
			}
		}
	}
	ShellSort(p,n);
	for (int i=n-1;i>=0;i--) {
		if (p[i].s % 2 ==0) 
		printf("%d-%d\n",p[i].v,p[i].s);
	}
}

	