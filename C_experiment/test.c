#include <stdio.h>

#define ABC(format, arg...) printf(format, ##arg)

void test(char str[100]){
    printf("%d\n",sizeof(str));
}

int main(){
    int a[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    char str[101];

    printf("a = %X\n", a);
    printf("&a = %X\n", &a);

    printf("size of a = %d\n", sizeof(a));
    printf("size of &a = %d\n", sizeof(&a));

    printf("a+1 = %X\n", a+1);
    printf("&a+1 = %X\n", &a+1);

    test(str);


    ABC("%s %d\n", "This is a book", a[9]);

    return 0;
}