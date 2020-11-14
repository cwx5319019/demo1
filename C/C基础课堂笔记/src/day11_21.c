#include<stdio.h>
#include<math.h>

//-----------三角形-----------
/*
int func(int n){
	int i = 0 ,j=0;
	for (j=0; j<n ; j++){
		for (i=1; i < n-j; i++){
			printf(" ");
		}
		for (i = 0; i < j+1;i++){
			printf("* ");
		}
		printf("\n");
	}
	return 0;
	
}

*/
//--------------质数--
/****
int func2(int n){
	int i = 0,count = 0;
	for(i = 1; i<=n;i++){
		if (n % i == 0){
			count++;
		}
	}
	if (count==2){
		return n;
	}
	return 0;
}
*/

/*
int func3(int n){
	int i = 0,count = 0;
	for(i = 2; i<n;i++){
		if (n % i == 0){
			return 1;
		}
	}
	return 0;
} 
//------------------有问题------------
*/

/*
//---------------指针
void func4(int* pa , int* pb){
	*pa = 30;
	*pb = 50;
	return 0;
}
*/
/*
void func5(int*pa ){
	(*pa)++;
}

*/



int main()
{

/*
	函数（模块）
		1.函数名
		2.函数参数（外部用来修改内部的数据的接口）
		2.函数返回值（向外部输出的接口）
		
	调用函数的目的
		1.实现某一个功能（如：打印n层三角形）
		2.计算一个结果(如：函数计算1～n)
		3.同时实现功能和结果（如：pirntf）
		
	形参改实参
		1.形参改变，然后返回（有缺点：只能返回一个值）
		2.实参地址传给形参，形参本质就是实参地址。
		
	计算自己本身(计数器)
		void func(int*pa ){
			(*pa)++;
		}
		int main(){
			int count = 0;
			func (&count);
			printf("函数共调用%d次",count);
			return 0;
		}
		
	函数调用的三个难点
		1.函数返回值的设计
		2.实参和形参的同步性
		3.函数嵌套调用
		
		
				
*/

/*
//统计封装函数自身被调用的次数
	int a = 0;
	int* p= &a;
	int i=0;
	for( i=0; i<10; i++){
		func5(&a);
	}
	printf("%d\n",func5(&a));
*/

/*+
//--------------指针
	int a = 10;
	int b = 5;
	
	int* pa = &a ;
	int* pb = &b ;
	
	func4(pa,pb);
	printf("%d\n%d\n",a,b);

*/



/*
	
	int num = 0,i=0,res = 0;
	//printf("请输入：");
	//scanf("%d",&num); 
	//while(getchar() != 10);
	//int res = func(num);
	//printf("%d",res);
	for (i= 1; i<101; i++){
		res += func2(i);
	}
	printf("%d\n",res);

*/

/*
// 1 1 2 3 5 8 13
// a b c
//   a b c
//     a b c
//---------------------斐波那契
	int a = 1 ,b = 2, c = 0;
	int i = 0;
	//printf("%d\n%d\n%d\n",a,a,b);
	for (; i <12; i++){
		if(i == 0 || i ==1){
			printf("1\n");
		}else if(i == 2){
			printf("2\n");
		}else{
			c = a+b;
			a = b;
			b = c;
			printf("%d\n",c);		
		}
	}

*/


/*
//---------------倒序--------------
	int num = 0;
	printf("请输入：");
	scanf("%d",&num);
	while(getchar() != 10);
	//1234
	int i = num;
	int res = 0;
	for(;i>0;i/= 10){
		res = res*10+(i%10);  // 5 
	}
	printf("%d\n",res);


//8  2  0
//4  2  0
	int num = 0;
	printf("请输入：");
	scanf("%d",&num);
	while(getchar() != 10);
	int i = num;
	int res = 0;
	int temp = 1;
	for (; i>0; i/=2 ){
		res = res + (i%2)*temp;
		temp *= 10;
	}
	printf("%d\n",res);

*/




//----------------最小公约数和最小公倍数
/*
	int a = 0, b = 0;
	printf("请输入两个数:");
	scanf("%d%d",&a,&b);
	while(getchar() != 10);
	int c = a <b ? a:b ;
	int i = 0;
	for (i = c; i > 0 ; i--){
		if ( c%i==0 && a %i==0){
			printf("%d\n",i);
			return 0 ;
		}
	}
*/	


//-------------1-1/3+1/5-1/7+1/9----------------第二

/*
	int i = 0;
	double res2 = 0,res1 = 0;
	for (i = 1; i<= 101;i+=4){
		res1 += (double)1/i; 
	}
	for (i = 3; i<= 101;i+=4){
		res2 += (double)1/i ;
	}
	printf("%lf\n",res1-res2);
*/








//----------------倒序十进制转二进制----------------------123321回文数

/*	
	int num = 0;
	scanf("%d",&num);
	while(getchar() != 10);
	int i = 0;
	int j = 0;
	int res = 0;
	int temp = 1;
	//8
	
	//0+1*0
	//1+10*1
	//10+100*0
	for (i = num ; i >0 ; i/=2){
		res = res + temp *(i%2);
		temp = temp*10;
	}
	printf("%d\n",res);
*/	

//------------倒序------------	
/*	
	int num = 0;
	scanf("%d",&num);
	while(getchar() != 10);
	int i = 0;
	int res = 0;
	//12345
	for (i = num ; i >0 ; i/=10){
		res = res*10+i%10;   5  
	}
	printf("%d\n",res);
*/


	return 0;
}



