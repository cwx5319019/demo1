/*
	编写一个注册登录系统：
		首先明确一件事情：所有注册成功的账号和密码都会分别保存在一个long long int 的nameDB 和 pswdDB当中，如何保存呢？这里限制输入的账号和密码只能是3位整型数
		举例说明，当输入的账号 name = 123的时候，那么就应该将name保存到nameDB中的第0个位置上，保存形式就是nameDB = 1230,当第二次注册账号成功后,比方说name = 456,那么就应该将 name = 456 保存到nameDB中的第1个位置上去，也就是说nameDB = 12304561
		密码保存方式同理

		基本要求：
			注册的时候，当用户输入想要注册的账号之后，首先判断nameDB中是否已经存在该账号，如果存在则注册失败，不存在则注册成功
			登录的时候，当用户输入想要登录的账号之后，首先判断nameDB是否存在该账户，如果存在，则继续输入密码，不存在则登录失败
			密码还需要判断是否正确

		进阶要求：登录时，账号允许无限次错误。密码如果输入错误3次以上，再次输入密码的时候要求输入验证码，验证码为随机生成的4位整型数，错误6次以上直接退出程序(验证码错误也算作密码错误)
 		分析：①注册函数②登录函数③查找账号函数
*/
#include<stdio.h>

typedef long long int lli;

int find_data(int name,lli nameDB){
	int i = 0;
	for(i=nameDB;i>0;i/=10000){//12304561
		if(name == i%10000/10){
			return i%10;
		}
	}
	return -1;
}

void regist(lli* nameDB,lli* pswdDB,int* len){
	int name = 0,pswd = 0;
	printf("请输入账号:");
	scanf("%d",&name);
	while(getchar()!=10);
	//查看name在nameDB中是否存在
	int res = find_data(name,*nameDB);
	if(res >= 0){
		printf("该账号已存在\n");
		return ;
	}
	*nameDB = *nameDB*10000 + name*10 + *len;
	printf("请输入密码:");
	scanf("%d",&pswd);
	while(getchar()!=10);
	*pswdDB = *pswdDB*10000 + pswd*10 + *len;
	(*len)++;
}

int login(lli nameDB,lli pswdDB){
	int name = 0,pswd = 0;
	printf("请输入账号:");
	scanf("%d",&name);
	while(getchar()!=10);
	int res = find_data(name,nameDB);
	if(res == -1){
		printf("该账号不存在\n");
		return 0;
	}
	printf("请输入密码:");
	scanf("%d",&pswd);
	while(getchar()!=10);
	pswd = pswd*10 + res;
	int i = 0;
	for(i=pswdDB;i>0;i/=10000){
		if(pswd == i%10000){
			return 1;
		}
	}
	return 0;
}

int main(){
	lli nameDB = 0;
	lli pswdDB = 0;
	int len = 0;
	int ch = 0;
	int res = 0;
	while(1){
		printf("1:注册\n");
		printf("2:登录\n");
		printf("3:查看数据库\n");
		printf("请选择");
		scanf("%d",&ch);
		while(getchar()!=10);
		switch(ch){
			case 1:
				regist(&nameDB,&pswdDB,&len);
				break;
			case 2:
				res = login(nameDB,pswdDB);
				if(res == 1){
					printf("登录成功\n");
				}
				break;
			case 3:
				printf("nameDB = %lld\n",nameDB);
				printf("pswdDB = %lld\n",pswdDB);
				break;
			default:
				break;
		}
	}
	return 0;
}
