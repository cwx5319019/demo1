#include<stdio.h>

typedef struct Human{
	int age;
	int weight;
	int height;
	char name[20];
	char sex;
}human_t;

int main(){
	int age = 10;
	int weight = 50;
	int height = 150;
	char name[20] = "张三";
	char sex = 'M';	
	struct Human zhangsan = {age,weight,height,"张三",sex};
	human_t lisi = {0};
	//printf("姓名:%s\n",zhangsan.name);
	//printf("年龄:%d\n",zhangsan.age);
	//printf("性别:%c\n",zhangsan.sex);
	lisi = zhangsan;
	//shuman_t temp = {0};
	//lisi = temp;
	//memset(&lisi,0,sizeof(lisi));
	printf("姓名:%s\n",lisi.name);
	printf("年龄:%d\n",lisi.age);
	printf("性别:%c\n",lisi.sex);
	return 0;
}
