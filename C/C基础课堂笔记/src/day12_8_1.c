/*
	编写一个水果管理系统，要求：
		系统中有两种身份的人
		①摊主
			摊主拥有功能：摊主使用固定的账号和密码登录系统
				1：上架水果
				2：修改水果单价
				3：补充水果库存
				4：下架水果
				5：根据销量最高的水果排序
				6：查看已经上架在售水果
		②用户
			用户拥有功能：
				1：注册登录
				2：查看所有在售水果列表
				3：选择在售水果列表中的某一个水果，具体重量加入购物车
				4：修改购物车中购买的水果重量
				5：删除购物车中某个水果
				6：结算购物车
*/
/*
	这个项目，总共需要3个数组来实现：
		① 摊主上架的水果信息
		② 用户的账号密码
		③ 用户的水果购物车
	其中，数组②相对独立，数组①和数组③联系较大
*/

#include<stdio.h>
#include<user.h>
#include<string.h>
#include<stdlib.h>

typedef struct Fruit {
	char name[20] ;
	float  price;
	float  kilogram ;
}fruit;
typedef int (*cmp_t)(fruit,fruit);

typedef struct Store{
	char name[20];
	float kilogram;
	float price;
}store;

void getstring(char* str,int len){
	fgets(str,len,stdin);

	int pos = strlen(str);
	if(str[pos-1] == '\n'){
		str[pos-1] = 0;
	}
}
void adm_login(){
	while(1){
		printf("请输入帐号：");
		char ch[20] = {0};
		int num = 0;
		getstring(ch,20);
		if(strcmp (ch,"admin")==0){
			printf("请输入密码：");
			scanf("%d",&num);
			while(getchar() != 10);
			if(num == 123456){
				printf("登录成功\n");
				break;
			}else{
				printf("密码错误\n");
			}
		}else{
			printf("帐号错误\n");
		}
	}
}

void adm_add(fruit* fruitDB,int* len){
	printf("请输入添加的水果名称：");
	fruit newFruit = {0};
	char ch[20] = {0};
	float sal = 0.0,kg = 0.0;
	getstring(ch,20);
	strcpy(newFruit.name,ch);
	printf("请输入水果重量(kg)和单价(元/kg)：");
	scanf("%f%f",&kg,&sal);
	while(getchar() != 10);
	newFruit.kilogram = kg;
	newFruit.price = sal;
	fruitDB[*len] = newFruit;
	(*len)++;
}
int adm_find(fruit* fruitDB, int len,char* str){
	int i = 0;
	for(i = 0;i<len;i++){
		if(strcmp(fruitDB[i].name , str)==0){
			return i;
		}
	}
	return -1;
}
void adm_updata_kg(fruit* fruitDB,int len){
	float kg = 0;
	printf("请输入要增加的水果名称:");
	char ch[20] = {0};
	getstring(ch,20);
	int res = adm_find(fruitDB,len,ch); 
	if(res <0){
		adm_add(fruitDB,&len);
	}else{
		printf("请输入增加的重量：");
		scanf("%f",&kg);
		while(getchar() != 10);
		fruitDB[res].kilogram += kg; 
	}
}

void adm_updata_sal(fruit* fruitDB,int len){
	printf("请输入要更新单价的水果名称:");
	char ch[20] = {0};
	getstring(ch,20);
	int res = adm_find(fruitDB,len,ch);
	if(res < 0){
		printf("该水果不存在\n");
		return ;
	}
	printf("请输入更改的单价：");
	float num = 0;
	scanf("%f",&num);
	while(getchar() != 10);
	fruitDB[res].price = num;
}

void adm_delete(fruit* fruitDB, int* len){
	printf("请输入要下架的水果名称：");
	char ch[20] = {0};
	getstring(ch,20);
	int res = adm_find(fruitDB,*len,ch);
	if(res <0){
		printf("该水果已下架\n");
		return ;
	}
	int i = 0;
	for(i = res;i<*len;i++){
		fruitDB[i] = fruitDB[i+1];
	}
	//fruitDB[*len-1]= {0}; //**************
	memset(&fruitDB[*len-1],0,sizeof(fruit));
	(*len)--;

}

int bubble_price_1(fruit a,fruit b){
	return a.price - b.price;
}
int bubble_kg(fruit a,fruit b){
	return a.kilogram - b.kilogram;
}
int bubble_name(fruit a,fruit b){
	return strcmp(a.name , b.name) ;
}

void adm_bubble(fruit* fruitDB,int len,cmp_t adm_cmp){
	int j = 0,i=0;
	fruit temp = {0};
	for(j = 0;j<len- 1;j++){
		for(i =0;i<len-1;i++){
			if(adm_cmp(fruitDB[i],fruitDB[i+1])>0){   //fruitDB[i] 相当与 int[i] 这是整数值
				temp = fruitDB[i];
				fruitDB[i] = fruitDB[i+1] ;
				fruitDB[i+1] = temp;
			}
		}
	}
}

void adm_look(fruit* fruitDB,int len){
	int i = 0;
	for(i = 0;i<len;i++){
		printf("************************\n");
		printf("水果名称：%s  \n",fruitDB[i].name);
		printf("水果剩余：%.2f kg\n",fruitDB[i].kilogram);
		printf("水果单价：%.2f 元/kg\n",fruitDB[i].price);
		printf("************************\n\n");	
	}
}

void custom_memory(fruit* fruitDB,store* storeDB,int len ,int* len_1){
	printf("请输入添加的水果：");
	char ch[20] = {0};
	getstring(ch,20);
	int res = adm_find(fruitDB,len,ch);
	if(res < 0){
		printf("无此水果 \n");
		//return ;
	}
	store mystore = {0};
	strcpy(mystore.name ,fruitDB[res].name );
	printf("请输入要买的重量：");
	float num = 0;
	scanf("%f",&num);
	while(getchar() != 10);
	
	//printf("%d\n",fruitDB.kilogram);
	if(num > fruitDB[res].kilogram){
		printf("没有那么多\n");
		return ;
	}
	mystore.kilogram = num;
	fruitDB[res].kilogram -= num;
	mystore.price = fruitDB[res].price;
	
	storeDB[*len_1] = mystore;
	(*len_1)++;
}

void custom_look_store(store* storeDB ,int len){
	int i = 0;
	for(i = 0;i<len ; i++){
		printf("***********************************\n");
		printf("水果名称：%s\n", storeDB[i].name);
		printf("水果重量：%.2f\n", storeDB[i].kilogram);
		printf("总   计：%.2f 元 \n", storeDB[i].price * storeDB[i].kilogram);
		printf("***********************************\n");	
	}
}

void custom_bill(store* storeDB,int len){
	int i = 0;
	float sum = 0.0;
	for(i = 0;i<len ;i++){
		sum += storeDB[i].price * storeDB[i].kilogram;
	}
	printf("%f\n",sum);
}

int custom_find(store* storeDB,char* ch,int len){
	int i = 0;
	for(i =0 ; i<len ; i++){
		if (storeDB[i].name == ch ){
			return i;
		}	
	}
	return -1;
}

void custom_updata(store* storeDB , int len){
	printf("请输入修改的水果名称:");
	char ch[20] = {0};
	getstring(ch,20);
	int res = custom_find(storeDB,ch,len);
	if(res <0){
		printf("无此水果\n");
		return ;
	}
	printf("请输入购买重量：");
	float num = 0.0;
	scanf("%f",&num);
	while(getchar() != 10);
	storeDB[res].kilogram = num;
}

void custom_delete(store* storeDB , int* len){
	printf("请输入删除的水果\n");
	char ch[20] = {0};
	getstring(ch,20);
	int res = custom_find(storeDB, ch,*len);
	if(res < 0){
		printf("无此水果\n");
		return ;
	}
	int i = 0;
	for(i = res;i<*len;i++){
		storeDB[i] = storeDB[i+1];
	}
	memset(storeDB,0,sizeof(store));
	(*len)--;
}

void save_adm(fruit* fruitDB, int len){
	FILE* fp = fopen("./day12.txt","w");
	int i = 0;
	for(i = 0;i<len;i++){
		fprintf(fp,"%s %f %f\n", fruitDB[i].name,fruitDB[i].price,fruitDB[i].kilogram);
		//fwrite(&fruitDB[i],sizeof(fruit),1,fp);
	}
	fclose(fp);
}
void load_adm(fruit* ftuitDB,int* len){
	FILE* fp = fopen("./day12.txt","r");
	fruit temp = {0};
	int res = 0;
	if(fp == NULL)return ;
	while(1){
		res = fscanf(fp,"%s %f %f", temp.name,&temp.price,&temp.kilogram);
		//res = fread(&temp,sizeof(fruit),1,fp);  //这个如果没有数据返回值是 0
		if(res == -1)break;
		ftuitDB[*len] = temp;
		(*len)++;
	}
	fclose(fp);
}

int main(){
	int (*bubble[3])(fruit,fruit) = {bubble_name,bubble_kg,bubble_price_1};
	int len = 0;
	//adm_login();
	fruit* fruitDB = calloc(50,sizeof(fruit));
	load_adm( fruitDB,&len );
	while(1){
		printf("1.管理员系统\n");
		printf("2.用户系统\n");
		printf("3.退出\n");	
		printf("请选择系统\n");
		int num1 = 0;
		scanf("%d",&num1);
		while(getchar()!= 10);
		if(num1 == 3 )break;
		if(num1 == 1){
			while(1){
				int num = 0;
				//system("clear");
				printf("\n******************\n");
				printf("1.上架水果\n");
				printf("2.修改水果单价\n");
				printf("3.补充水果库存\n");	
				printf("4.下架水果\n");
				printf("5.根据销量最高的水果排序\n");
				printf("6.查看已经上架在售的水果\n");
				printf("7.退出\n");
				printf("\n******************\n");
				printf("请选择：");
				scanf("%d",&num);
				while(getchar() != 10);
				if(num == 7){
				save_adm(fruitDB,len);
				break;
				}
				switch(num){
					case 1:
						adm_add(fruitDB,&len);
						break;
					case 2:
						adm_updata_sal(fruitDB,len);
						break;
					case 3:
						adm_updata_kg(fruitDB,len);
						break;
					case 4:
						adm_delete(fruitDB,&len);
						break;
					case 5:{
						int num = 0;
						printf("1.按水果名称\n");
						printf("2.按重量\n");
						printf("3.按单价\n");
						printf("4.退出\n");
						printf("请选择排序方式：");
						scanf("%d",&num);
						while(getchar()!= 10);
						if(num == 4) break;
						adm_bubble(fruitDB,len,bubble[num-1]);  //
						}
						break;
					case 6:
						adm_look(fruitDB,len);
						break;
					default :
						break;
				}
			}
		}else if(num1 == 2){
			while(1){
				store* storeDB = calloc(50,sizeof(store));
				int len_1 = 0;
				printf("1.查看在售水果\n");
				printf("2.存放购物车\n");		
				printf("3.查看购物车\n");
				printf("4.结算购物车\n");
				printf("5.退出\n");	
				printf("请选择：");
				int num2 = 0;
				scanf("%d",&num2);
				while(getchar() != 10);
				if(num2 == 5){
				break;
				}
				switch(num2){
					case 1:
						adm_look(fruitDB,len);
						break;
					case 2:
						custom_memory(fruitDB,storeDB,len,&len_1);
						break;
					case 3:{
						int num4 = 0;
						custom_look_store(storeDB,len);
						printf("1.修改水果重量\n");
						printf("2.删除水果\n");
						printf("3.退出\n");
						printf("请选择：");
						scanf("%d",&num4);
						while(getchar() != 10);
						if(num4 == 4)break;
						switch(num4){
							case 1:
								custom_updata(storeDB,len);
								break;
							case 2:
								custom_delete(storeDB,&len);
								break;
							default:
								break;
						}
					}
						break;
					case 4:
						custom_bill(storeDB , len);
						break;
					default :
						break;
				}
			}
		}
	}
	return 0;
}







































