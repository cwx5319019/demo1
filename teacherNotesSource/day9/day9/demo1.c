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
