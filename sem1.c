#include <malloc.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>


void func(int number) {
    if (number!=0) {
        func (number/2);
        printf("%d",number % 2);
    }
}

int main(void) {
    int *array=(int *)malloc(sizeof(int));
    int index=0,
        jndex=0;
    char input;
    while ((input = getchar()) != EOF) {
        if (input!=' ' && input!='\n') {
            index=10*index+(input-48);
        }
        else {
            array=realloc(array,(jndex+1)*sizeof(int));
            array[jndex] = index;
            index=0;
            jndex++;
            if (input=='\n') break;
        }
    }

    for (index=0;index<jndex;index++) {
        int number = array[index];
        if (number==0)
            printf("%d",number % 2);
        else
        func(number);
        printf(" ");
    }
    printf("\n");

    for (index=0;index<jndex;index++) {
        printf("%d ",array[index]);
    }

    return 0;
}
