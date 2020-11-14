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

int main(){
	int arr[5] = {0};
	int len = 0;
insert_data(arr,&len);
insert_data(arr,&len);
insert_data(arr,&len);
insert_data(arr,&len);
insert_data(arr,&len);
	print_data(arr,len);
	
	update_data(arr,len);
	print_data(arr,len);
	return 0;
}
