/*
	从键盘输入三角形的3条边
	首先判断是否能够构成三角形
		如果能够构成三角形，再判断是等腰还是普通三角形
			如果是等腰三角形再判断是否为等边
		同时判断该三角形是直角，钝角，锐角
*/
#include<stdio.h>

int main(){
	int x = 0,y = 0,z = 0;
	scanf("%d %d %d",&x,&y,&z);
	while(getchar()!=10);
	int bigger = (x>y)?x:y;
	int c = (bigger>z)?bigger:z;
	
	int smaller = (x<y)?x:y;
	int a = (smaller<z)?smaller:z;
	
	int b = x + y + z - a - c;
	if(a+b>c){
		if(a==b||a==c||b==c){
			if(a==b&&b==c){
				printf("等边");
			}else{
				printf("等腰");
			}
		}
		if(a*a+b*b==c*c){
			printf("直角");
		}else if(a*a+b*b<c*c){
			printf("钝角");
		}else{
			printf("锐角");
		}
		printf("三角形\n");
	}else{
		printf("不能构成三角形\n");
	}
	return 0;
}
