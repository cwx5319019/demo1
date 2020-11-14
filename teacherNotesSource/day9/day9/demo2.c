#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void print_data(int* arr,int len){
	int i = 0;
	for(i=0;i<len;i++){
		printf("%d ",arr[i]);
	}
	printf("\n");
}

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
/*
	6 1 2 7 9 3 4 5 10 8
*/

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

int compare(const void* a,const void* b){
	return *(int*)a - *(int*)b;
}

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
