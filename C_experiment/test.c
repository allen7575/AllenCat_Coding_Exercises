#include <stdio.h>

#define ABC(format, arg...) printf(format, ##arg)

void test(char str[100]){
    printf("%d\n",sizeof(str)); //'sizeof' array function parameter will return sizeof 'char *'
}

void test2(char (*str)[100]){
    printf("%d\n",sizeof(str));
}

char *mystrstr(char *str1, char *str2){
	char *temp1, *temp2;
	int i = 0;
	
	temp1 = str1;
	temp2 = str2;
	
	while(*(temp1+i) != '\0' && *(temp2+i) != '\0'){

		for(i=0 ; *(temp1+i) != '\0' && *(temp2+i) != '\0' ; i++){
			if(*(temp1+i) != *(temp2+i)){
				temp1 += 1;
				break;
			}
		}
		
	}
	
	return temp1;
}


int main(){
    int a[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    char str[103]; //correct, str has type char *
	char (*str2)[100]; //correct
	//char (*str2)[101]; //compile error: 'str2' has type 'char (*)[101]', but argument of test2 need type 'char (*) [100]'

	char mystr1[20]="Hello World";
	char *mystr2 = "ell";
	char *mystr3 = NULL;
	
	
    printf("a = %X\n", a);
    printf("&a = %X\n", &a);

    printf("size of a = %d\n", sizeof(a));
    printf("size of &a = %d\n", sizeof(&a));

    printf("a+1 = %X\n", a+1);
    printf("&a+1 = %X\n", &a+1);

    test(str);
	
	test2(str2);

	
	printf("mystr1 is %s\n",mystr1);
	printf("mystr2 is %s\n",mystr2);
	
	mystr3 = mystrstr(mystr1, mystr2);
	
	printf("mystr3 is %s\n",mystr3);

    ABC("%s %d\n", "This is a book", a[9]);

    return 0;
}