
//-------------------管道---------------------

//命令：cat > 1.txt    
//ctrl + d 退出,会把写入的内容传到1.txt

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>

int main(void){
	FILE* fp = NULL;
	fp = popen("cat > 7.txt","w");
	char *str = "1234567890\n";
	fwrite(str,13,1,fp);
	
	pclose(fp);
	return 0;
}









