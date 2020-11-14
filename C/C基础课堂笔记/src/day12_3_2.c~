
#if 0
//-----指针偏移大小根据数据类型!---------

#include<stdio.h>
int main(){
	int arr[10] = {1,3,5,7,9,2,4,6,8,99};
/*
	要求，只偏移两次，每次都只能偏移1个模块，访问到数据：
		7,9,3,0
*/
	printf("%d\n",*((int*)((double*)(arr+1))+1));	
	printf("%d\n",*((int*)((double*)arr+1+1)));
	printf("%d\n",*((int*)((short*)arr+1+1)));
	printf("%d\n",*((int* )(&arr+1)-1));   // 指针指向不要乱

}

#endif

#if 0

/*
	要求，使用arr，访问数据，1,3,6,17,20
*/
#include<stdio.h>
int main(){
	int a1[5] = {1,3,5,7,9};
	int a2[5] = {2,4,6,8,10};
	int* ar[2] = {a1,a2};

	int b1[5] = {11,13,15,17,19};
	int b2[5] = {12,14,16,18,20};
	int* br[2] = {b1,b2};
	
	int** arr[2] = {ar,br};

	//int temp =  ***arr;
	//int temp =  *(**arr+1);
	//int temp =  *(*(*arr+1)+2);   //记住arr == &br 加个星 *arr = *&br 就成了 br
	//int temp =  *(**(arr+1)+3);
	int temp =   *(*(*(arr+1)+1)+4);
	
	printf("%d\n",temp);


}

#endif

#if 0
#include<stdio.h>
int main(){
	char* c[4]={"ENTER","NEW","POINT","FIRST"};
	char** cp[4]={c+3,c+2/*c+1*/,c+1,c};
	char*** cpp=cp;

	//printf("%s\n",**++cpp);
	//printf("%s\n",*--*cpp+++1);
	//printf("%s\n",*cpp[-2]+3);
	//printf("%s\n",cpp[-1][-1]+1);
	
//------------求上面输出的值--------------	
	
	printf("%s\n",**++cpp);
	
/*
	cpp      &(c+3)
	++cpp    &(c+3)+1    // &(c+2)
	*++cpp   *&(c+2)     c+2      &"POINT"
	**++cpp  *&"POINT"   "POINT"

*/

	printf("%s\n",*--*cpp+++1);  //* 优先级最低
	
/*

	cpp         &(c+2) 
	cpp++       &(c+2)     // &(c+2)+1  &c+1 
	*cpp++      *&(c+2)  c+2     
	--*cpp++    c+2      c+1
	*--*cpp++   *(c+1)   *(&"NEW")
	*--*cpp+++1  'EW'  
	
*/	
	//char* c[4]={"ENTER","NEW","POINT","FIRST"};
	//char** cp[4]={c+3,c+2/*c+1*/,c+1,c};
	//char*** cpp=cp;
	printf("%s\n",*cpp[-2]+3); //**(cpp-2)+3
/*
	cpp        &(c+1) 
	cpp[-2]    *(&(c+1)-2)   c+3  &"FIRST"
	*cpp[-2]   "FIRST"
	*cpp[-2]+3  "ST"



*/
	printf("%s\n",cpp[-1][-1]+1);   //*
	
/*
	cpp             &(c+1) 
	cpp[-1]         *(&(c+1) -1)  c+1  
	cpp[-1][-1]     *(&"NEW"-1)  "ENTER"
	cpp[-1][-1]+1   "NTER"

*/
	
	

	return 0;
}

#endif
#if 0
#include<stdio.h>

int main(){
	int a = 5;
	char b = 'x';
	int* pa = &a;
	char* pb = &b;
	void* vpa = pa;
	void* vpb = pb;

	//printf("%d\n",*pa);
	//printf("%c\n",*pb);

	//printf("%d\n",*(int*)vpa);
	//printf("%c\n",*(char*)vpb);

	void* vppa = &pa;

	void** vvpa = &vpa;
	void* vvvpa = &vvpa;
/*
	使用vvvpa访问到a的值
*/
	int temp = *(int*)*(void**)*(void***)vvvpa;  //void 输出必须时候必须强制转换类型
	printf("%d\n",temp);

	return 0;
}

#endif
#if 1
	/*
	封装一个函数：要求，它能够传入任意类型的数组。在函数内部，手动输入想要访问的数组的下标，然后返回该下标的地址
	函数外部，根据传入不同的数组返回的地址，打印相应数据类型的数据
	举例：{1,3,5,7,9},内部输入了3，则应该返回&7，外部将数据7打印出来
		"hello",内部输入4，则应该返回&o，外部将数据'o'打印出来
	注意，该函数写好之后不能改变
*/
void* func(void* str,int n)
{
	int num = 0;
	printf("请输入下标：");
	scanf("%d",&num);
	while(getchar()!= 10);
	
	return (char*)str+num*n;	


}
	

int main()
{
	


	return 0;
}



#endif









