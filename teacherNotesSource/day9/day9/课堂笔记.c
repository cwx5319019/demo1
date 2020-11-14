


/*
	冒泡排序：遍历-判断-交换，整个逻辑完成一次，就会有1个数就位，那么需要如此遍历len-1次
	
//----------------------------
void bubble_sort(int* arr,int len){
	int i = 0,j = 0;
	int temp = 0;
	for(i=0;i<len-1;i++){
		for(j=0;j<len-1;j++){
			if(arr[j] > arr[j+1]){
				temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
			}
		}
	}
}

//----------------------------

	选择排序:使用一整次循环，去寻找当前范围内的最小值，找到最小值后记录，并与当前范围内最左值做交换。一整次循环1个数会就位，所以需要len-1次寻找最小值并交换的操作
	
//-----------------------------------
void select_sort(int* arr,int len){
	int i = 0,j = 0;
	int min = 0;
	int temp = 0;
	for(i=0;i<len-1;i++){
		min = i;
		for(j=i;j<len;j++){
			if(arr[j] < arr[min]){
				min = j;
			}
		}
		temp = arr[min];
		arr[min] = arr[i];
		arr[i] = temp;
	}
}

//------------------------------------------
	
	快速排序
//--------------------------------------

	// 6 1 2 7 9 3 4 5 10 8

void quick_sort(int* arr,int left,int right){
	if(left>=right){return ;}
	int l = left;
	int r = right;
	int key = arr[left];
	int temp = 0;
	while(l<r){
		while(l<r){
			if(arr[r]<key){
				break;
			}
			r--;
		}
		while(l<r){
			if(arr[l]>key){
				break;
			}
			l++;
		}
		temp = arr[l];
		arr[l] = arr[r];
		arr[r] = temp;
	}
	temp = arr[left];
	arr[left] = arr[l];
	arr[l] = temp;
	quick_sort(arr,left,l-1);
	quick_sort(arr,l+1,right);
}
//---------------------------------------------
int compare(const void* a,const void* b){
	return *(int*)a - *(int*)b;
}

//-------------------------------------------------

/*  
//-------------------主调用函数
int main(){
	srand(time(0));
	int len = 10;
	int arr[len];
	int i = 0;
	for(i=0;i<len;i++){
		arr[i] = rand()%100;
	}
	print_data(arr,len);
	printf("\n");
	//bubble_sort(arr,len);
	//select_sort(arr,len);
	//quick_sort(arr,0,len-1);
	qsort(arr,10,4,compare);
	print_data(arr,len);
	return 0;
}
*/

/*
	二维数组：在一个数组内存放了另一个数组的形式，这样的一个数组我们称为二维数组
	二维数组的声明方式：最终存放的数据类型 + 数组名[外层数组容量][内层数组容量]
	
//----------------------------------
#include<stdio.h>

void print_arr(int(* arr)[3]){
	int i = 0,j = 0;
	for(i=0;i<5;i++){
		for(j=0;j<3;j++){
			printf("%d ",arr[i][j]);
		}
		printf("\n");
	}
}

int main(){
	int arr[5][5] = {
						{1 ,2 ,3 ,4 ,1 },    //注意逗号表达式 (1,2,3,4),只会读取最后一个
						{4 ,2 ,6 ,2 ,8 },
						{7 ,8 ,3 ,10,11},
						{10,4,12,4,14},
						{5,14,15,16,5},
					};
	printf("%d\n",arr[0][2]);//9
	printf("%d\n",arr[4][2]);
	printf("%d\n",arr[0][14]);
	//print_arr(arr);
	
	return 0 ;
 }
	
//------------------------------
*/
//---------------二维数组练习-------------
//----------------------------------------
		//二维数组对角线之和
	int i = 0, j = 0;
	int res = 0;
	for(i=0;i<5;i++){
		for(j=0;j<5;j++){
			if(i==j||i+j==4){
				res = res + arr[i][j];
			}
		}
	}
	
//-----------------------------------------
	//二维数组四条边之和
	
	printf("res = %d\n",res);
	res = 0;
	for(i=0;i<5;i++){
		for(j=0;j<5;j++){
			if(i==0||i==4||j==0||j==4){
				res = res + arr[i][j];
			}
		}
	}
	printf("res = %d\n",res);

//-------------------------------------------


	//使用二维数组，输出一个10层的杨辉三角形
	//输出格式为:printf("%6d",data)


#include<stdio.h>

int main(){
	int arr[10][10] = {0};
	int i = 0,j = 0;

	for(i=0;i<10;i++){
		for(j=0;j<10;j++){
			if(j==0 || j==i){
				arr[i][j] = 1;
			}
		}
	}

	for(i=0;i<10;i++){
		for(j=0;j<10;j++){
			if(i>1 && j<i){
				arr[i][j] = arr[i-1][j] + arr[i-1][j-1];
			}
		}
	}

	for(i=0;i<10;i++){
		for(j=0;j<10-i;j++){
			printf("   ");
		}
		for(j=0;j<i+1;j++){
			printf("%6d",arr[i][j]);
		}
		printf("\n");
	}
	return 0;
}





//---------------增删改查遍历----------------
#include<stdio.h>

void print_data(int* arr,int len){
	int i = 0;
	for(i=0;i<len;i++){
		printf("%d ",arr[i]);
	}
	printf("\n");
}

int find_data(int* arr,int data,int len){
	int i = 0;
	for(i=0;i<len;i++){
		if(arr[i] == data){
			return i;
		}
	}
	return -1;
}

void insert_data(int* arr,int* len){//{1,3,5,7,9}
	int data = 0;
	printf("请输入要添加的数据:");
	scanf("%d",&data);
	while(getchar()!=10);

	int res = find_data(arr,data,*len);
	if(res>=0){
		printf("该数据已存在\n");
		return ;
	}
	arr[*len] = data;
	(*len)++;
}

void update_data(int* arr,int len){
	int data = 0;
	printf("请输入要修改的数据:");
	scanf("%d",&data);
	while(getchar()!=10);
	int res = find_data(arr,data,len);
	if(res==-1){
		printf("查无此数\n");
		return ;
	}
	printf("请输入修改后的数据:");
	scanf("%d",&data);
	while(getchar()!=10);
	arr[res] = data;
}

void remove_data(int* arr,int* len){
	int data = 0;
	printf("请输入要删除的数据:");
	scanf("%d",&data);
	while(getchar()!=10);
	int res = find_data(arr,data,*len);
	if(res==-1){
		printf("查无此数\n");
		return ;
	}
	int i = 0;
	for(i=res;i<*len-1;i++){
		arr[i] = arr[i+1];
	}
	arr[i] = 0;
	(*len)--;
}

void remove_data_pro(int* arr,int* len){
	int data = 0;
	printf("请输入要删除的数据:");
	scanf("%d",&data);
	while(getchar()!=10);
	int res = 0;
	while(1){
		res = find_data(arr,data,*len);
		if(res==-1){
		//	printf("查无此数\n");
			return ;
		}
		int i = 0;
		for(i=res;i<*len-1;i++){
			arr[i] = arr[i+1];
		}
		arr[i] = 0;
		(*len)--;		
	}
}

void remove_data_pro2(int* arr,int* len){
	int data = 0;
	printf("请输入要删除的数据:");
	scanf("%d",&data);
	while(getchar()!=10);
	int i = 0,j = 0;
	for(i=0;i<*len;){
		if(arr[i]==data){
			for(j=i;j<*len-1;j++){
				arr[j] = arr[j+1];
			}
			arr[j] = 0;
			(*len)--;
		}else{
			i++;
		}
	}
}

int main(){
	int arr[10] = {1,1,1,3,3,5,7,7,9,10};
	int len = 10;
	print_data(arr,len);
	
	while(len){
		remove_data_pro2(arr,&len);
		print_data(arr,len);
	}
	return 0;
}

//----------------------------------------

//---------------项目---------------------
/*
	学生管理系统：
		将管理员的账号设置成：123，密码也是:123
		管理登录成功后，显示界面：
			1：添加学生
				输入学生的学号，三科成绩，并且将学生的登录密码全都统一初始化成123456
			2：删除学生
				输入学生的学号，寻找到之后删除该学生
			3：排序学生
				① 按语数外三门成绩分别排序
				③ 按总分排序
			4：查看单一学生信息
			5：修改学生单科成绩
				选择要修改成绩的科目，确定之后修改该学生的该成绩
		学生：可以使用自己的学号作为账号，默认密码登录系统，登录后显示
			1：查看成绩
				查看成绩的同时，应该显示自己的总分排名以及各科成绩的排名
			2：修改密码
	学生的成绩和学号应该全都存在一个二维数组中
	学生的密码应该存放在另一个独立的一位数组中
	举例：3个学生，学号分别问190801,02,03,密码分别为：111,222,333，成绩分别为：{80,81,82}，{70,71,72}，{60,61,62}
	{
		{0,190801,190802,190803},
		{80,81,82},
		{90,91,92},
		{60,61,62}
	}

	{0,111,222,333}
*/
