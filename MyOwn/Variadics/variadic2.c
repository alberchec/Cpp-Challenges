#include <stdio.h>
#include <stdarg.h>

void sum_all(int count,...){
	va_list args;
	va_start(args,count);

	int result;

	while(count--){
		int i = va_arg(args,int);
		result += i;
	}
	va_end(args);

	printf("%d\n",result);

}

int main(){
	sum_all(13,3,4,5,342,34,4,2343,34,4,32,34,32,4);
}