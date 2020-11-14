#include<stdio.h>
#include<string.h>
#define X 30


#if 1
//----------------- 作业------------


char* my_strcpy(char* ch1,char* ch2){
	if(ch1 == NULL){
		printf("指针为空！");
		return ch1;
	}
	int i =0;
	while((ch1[i] = ch2[i]) != '\0' ){
		i++;
	}
	return ch1;


}

int main()
{
	int i = 0;
	//char ch1[20] = {'\0'};
	//char ch2[20] = {'\0'};
	char ch3[3][6] ={};
	//for(i = 0;i<3;i++){
		//memset (ch3[i],0,6);
	//}
#if 0
	printf("请输入名字：");
	fgets(ch1,sizeof(ch1),stdin);
	fputs(ch1,stdout);
	my_strcpy(ch2,ch1);
	fputs(ch2,stdout);
#endif	
	printf("请输入名字：");
	for(i = 0; i<3; i++){
		scanf("%s",&ch3[i][6]);            //输入有问题？？？？？？？？？？？？？？？？？？
		while(getchar() != 10);
		//fgets(ch3[i],sizeof(ch3[i]),stdin);
	}
	for(i = 0;i< 3;i++){
		printf("%s\n",ch3[i]);
		//fputs(ch3[i],stdout);	
	}








	return 0;
}

#endif

#if 0
void func(char* ch , char* ch_x, char star , char end ){
	int i = 0,j = 0;

	for (i = 0; i< strlen(ch) ;i++){  //strlen(ch)计算数组长度；不能用sizeof（ch）这个算得是指针的长度
		if(ch [i] >= star && ch[i] <= end){
			ch_x[j] = ch[i];
			j++;
		}
	}
	printf("%s\n",ch_x);
}

#endif
//---------------mystrlen----
#if 1	
int mystrlen(const char* s){
	if(s == NULL){
		return 1;
	}
	int i = 0;
	while(s[i] != '\0'){
		i++;
	}
	return i;
}
	printf("%d\n",mystrlen(ch1));
#endif

//--------------mystrcpy----------

#if 1
char* mystrcpy(char* dest,  const char* src){
	if(dest == NULL || src == NULL){
		printf("指针为0");
		 return dest;
	}
	int i = 0;
	/*
	for(i = 0; dest[i] != 0; i++){
		dest[i] = src[i];
	}
	dest[i] = '\0';
	*/
	while((dest[i] = src[i]) != '\0'){
		i++;
	}
	
	return dest;

}
#endif	

//------------------mystrncp------------
#if 0
char* mystrncpy(char* dest, const char* src,int len){
	if(dest == NULL || src == NULL){
		printf("指针为0");
		 return dest;
	}
	int i = 0;
	/*
	for(i = 0; dest[i] != 0; i++){
		dest[i] = src[i];
	}
	dest[i] = '\0';
	*/
	while((i<len) ?(dest[i] = src[i]):(dest[i] != '\0')){
		i++;
	}
	return dest;

}
#endif	
//--------------mystrncpy----------

#if 0
char* mystrcpy(char* dest, const char* src){
	if(dest == NULL || src == NULL){
		printf("指针为0");
		 return dest;
	}
	int i = 0;
	/*
	for(i = 0; dest[i] != 0; i++){
		dest[i] = src[i];
	}
	dest[i] = '\0';
	*/
	while((dest[i] = src[i]) != '\0'){
		i++;
		if (i ==2){
			src[i] = '\0';
		}
	}
	return dest;

}
#endif



#if 1
//---------------mystrcat--------------

char* mystrcat(char* dest, const char* src){
	if(dest ==NULL || src == NULL){
		return dest;
	}
	int i = 0,j=0;
	while(dest[i] != '\0'){
		i++;
	}
	/*
	if(dest[i] == '\0'){
		while(src[j]){
			dest[i] = src[j];
			i++;j++;
		}
	}
	*/
	while(src[j] != '\0'){
		dest[i+j] = src[j];
		j++;
	}
	return dest;
}
#endif
#if 0
int mystrcmp(const char* s1 , const char* s2){
	if(s1 ==NULL || s2 == NULL){
		printf("null\n");
		return -2;
	}
	int i = 0;
	while(s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0'){
		i++;
	}
	if(s1[i]-s2[2]>0){
		return 1;
	}else if(s1[i]-s2[2]<0){
		return -1;
	}else{
		return 0;
	}
}

#endif



//--------------------main 函数-----------
#if 0
int main(void)
{
	char ch1[20] = "abcqwe";  //ch1 它是个常量  
	char ch2[20] = "123456";
	int len = 0;
	char ch3[1024];
	memset(ch3,0,sizeof(ch3));//初始化为0
	
	ch1[3] = '4';
	printf("char:%s",ch1);
	
	//printf("%d\n",'a'-'g');
	//printf("%d\n",strlen(ch1));	
	//printf("%s\n",mystrcpy(ch1,ch2));
	//printf("%s\n",strcat(ch1,ch2));
	printf("%d\n",strcmp(ch1,ch2));


	
	printf("%s\n",strcpy(ch1,ch2));
	//printf("%s\n",strncpy(ch1,ch2,2));
	//printf("%s\n",mystrncpy(ch1,ch2,2));
	
	//printf("%s\n",strcat(ch1,ch2));
	//printf("%s\n",strncat(ch1,ch2,2));
	
	//printf("%d\n",strcmp(ch1,ch2));	
	//printf("%d\n",strncmp(ch1,ch2,2));	





	return 0;
}

#endif


#if 0
	printf("please input:");
	char ch_1[20] = {} ;
	char ch_2[20] = {};
	char ch_3[20] = {};
	char ch_4[20] = {};
	scanf("%s",ch_1);
	while(getchar() != 10);
	
#endif	
#if 0
//-------------字符串排序
	
	int i = 0,temp = 0,j = 0;
	for (i = 0; i< 19 ;i++){
		for(j = 0; j<19;j++){
			if(ch_1[j+1] == '\0')break; //等于'\0'（结束符）退出
			if( ch_1[j] >  ch_1[j+1]  ){
				temp = ch_1[j];
				ch_1[j] = ch_1[j+1];
				ch_1[j+1] = temp;
			}
		}	
	}
	printf("%s\n",ch_1);
	/*
	for(i = 0; i<20; i++){
		if(ch_1[i] != '\0'){
			printf("%c",ch_1[i]);
		}
	}
	printf("\n");
	*/
#endif	

//------------------分离数字大写小写字符
#if 0
	func(ch_1,ch_2,'a','z');
#endif
#if 0	
	int i = 0,j = 0 ,m = 0,n = 0;
	for (i= 0; i< sizeof(ch_1);i++){
		if (ch_1[i] >= 'A' && ch_1[i] <= 'Z'){
			ch_2[j] = ch_1[i];
			j++;
		}else if(ch_1[i] >= '0' && ch_1[i] <= '9'){
			ch_3[m] = ch_1[i];
			m++;
		}else if(ch_1[i] >= 'a' && ch_1[i] <= 'z'){
			ch_4[n] = ch_1[i];
			n++;
		}
	}
	
	printf("%s\n",ch_1);
	printf("%s\n",ch_2);
	printf("%s\n",ch_3);
	printf("%s\n",ch_4);	
	
#endif


# if 0
	char string1[20] = {};  //初始化常用
	printf("%s\n",string1);
	
	int i = 0;
	char string2[] = {'H','e','l','l','o','\0',' ','w','o','r','d','\0'};
	printf("%s %d \n",string2,sizeof(string2));
	
	//sizeof(string2)/sizeof(string[0] 计算数组长度
	for(i = 0;i<sizeof(string2)/sizeof(string[0]);i++){
		printf("%c",string2[i]);
	}
	printf("\n");


	char string3[20] = "";
	printf("please input:");
	scanf("%s",string3);
	while(getchar() != 10);
	printf("%s\n",string3);
	
	char string4[] = "hellAw6rld!";    //初始化常用
	printf("%s %d\n",string4,sizeof(string4));
	
	char string5[1024];
	memset (string5,0,sizeof(string5));
	
	printf("please input:");
	gets(string5);
	puts(string5);

	
#endif		

	
