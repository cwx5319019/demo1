/*
	编写一个通用冒泡排序，选择排序
*/

#include<stdio.h>
#include<string.h>

#define BSORT(arr,len,type) {int i = 0,j =0;type temp;for(i=0;i<len-1;i++){for(j=0;j<len-1;j++){if(arr[j]<arr[j+1]){temp = arr[j];arr[j] = arr[j+1];arr[j+1] = temp;}}}}

void print_int(void* data){
	printf("%d ",*(int*)data);
}

void print_char(void* data){
	printf("%c ",*(char*)data);
}

void print_double(void* data){
	printf("%g ",*(double*)data);
}

void print_str(void* data){
	printf("%s ",*(char**)data);
}

void print_data(void* arr,int len,int size,void (*print)(void*)){
	int i = 0;
	for(i=0;i<len;i++){
		print(arr+i*size);
	}
	printf("\n");
}

int comp_int(void* a, void* b){
	return *(int*)a - *(int*)b;
}

int comp_char(void* a, void* b){
	return *(char*)a - *(char*)b;
}

int comp_double(void* a, void* b){
	if(*(double*)a - *(double*)b < 0){
		return -1;
	}else{
		return 1;
	}
}

int comp_str(void* a, void* b){
	return strcmp(*(char**)a,*(char**)b);
}

void bubblesort(void* arr,int len,int size,int (*compare)(void*,void*)){
	char temp[size];
	int i = 0,j = 0;
	for(i=0;i<len-1;i++){
		for(j=0;j<len-1;j++){
			if(compare((char*)arr+j*size,(char*)arr+(j+1)*size)<0){//arr[i]<arr[i+1] -> arr[i] - arr[i+1] < 0
				// -> *((int*)arr + i) - *((int*)arr + i+1) < 0
				/*temp = arr[i];
				arr[i] = arr[i+1];
				arr[i+1] = temp;*/
				memcpy(temp,arr+j*size,size);
				memcpy(arr+j*size,arr+(j+1)*size,size);
				memcpy(arr+(j+1)*size,temp,size);
			}
		}
	}
}

void selectsort(void* arr,int len,int size,int (*compare)(void*,void*)){
	int i = 0,j = 0;
	int max = 0;
	char temp[size];
	for(i=0;i<len-1;i++){
		max = i;
		for(j=i;j<len;j++){
			if(compare(arr+j*size,arr+max*size)>0){//arr[j] > arr[max]
				max = j;
			}
		}
		/*temp = arr[max];
		arr[max] = arr[i];
		arr[i] = temp;*/
		memcpy(temp,arr+max*size,size);
		memcpy(arr+max*size,arr+i*size,size);
		memcpy(arr+i*size,temp,size);
	}
}

void quicksort(void* arr,int len,int size,int (*compare)(void*,void*)){
	char* left = (char*)arr;
	char* right = (char*)arr + (len-1)*size;
	if(left>=right){return;}
	char* l = left;
	char* r = right;
	char* key = l;
	char temp[size];
	while(l<r){
		while(l<r){
			if(compare(r,key)>0){
				break;
			}
			r = r - size;
		}
		while(l<r){
			if(compare(l,key)<0){
				break;
			}
			l = l + size;
		}
		memcpy(temp,l,size);
		memcpy(l,r,size);
		memcpy(r,temp,size);
	}
	memcpy(temp,l,size);
	memcpy(l,key,size);
	memcpy(key,temp,size);
	quicksort(arr,(l-left)/size,size,compare);
	quicksort(l+size,(right-l)/size,size,compare);
}

int main(){
	int arr[5] = {1,3,5,7,9};
	char str[6] = "world";
	double drr[5] = {1.6,2.1,3.5,4.3,5.7};
	char* ptr[5] = {"hello","china","1908","shanghai","iotek"};
/*
	降序排序:
		思路：
			1 先将冒泡排序写出来
			2 然后将数组访问方式，改写成通用指针的偏移访问方式
			3 最后确定哪一部分的代码相同，哪一部分不同，不同部分封装函数传入
*/
	//bubblesort(arr,5,4,comp_int);
	//selectsort(arr,5,4,comp_int);
	//quicksort(arr,5,4,comp_int);
	BSORT(arr,5,int);
	print_data(arr,5,4,print_int);

	//bubblesort(str,5,1,comp_char);
	//selectsort(str,5,1,comp_char);
	//quicksort(str,5,1,comp_char);
	BSORT(str,5,char);
	print_data(str,5,1,print_char);

	//bubblesort(drr,5,8,comp_double);
	//selectsort(drr,5,8,comp_double);
	//quicksort(drr,5,8,comp_double);
	BSORT(drr,5,double);
	print_data(drr,5,8,print_double);

	//bubblesort(ptr,5,8,comp_str);
	//selectsort(ptr,5,8,comp_str);
	//quicksort(ptr,5,8,comp_str);
	//print_data(ptr,5,8,print_str);
	return 0;
}
