#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<string.h>
#include<unistd.h>
int main(void){
	int fd = open("./10.txt",O_RDONLY);
	if(fd == -1){
		perror("open error");
		exit(1);
	}
	int i = 0;
	int intarr[14] = {0};
	char buf[20] = "";
	FILE* fp = fdopen(fd,"r");
	while(fgets(buf,20,fp) != NULL){
		intarr[i++] = atoi(buf);
		memset(buf,0,sizeof(buf));  
	}
	int x = 0,j= 0,temp = 0;
	for(x = 0;x<sizeof(intarr)/4-1;x++){
		for(j = 0;j<sizeof(intarr)/4-1;j++){
			if(intarr[j] > intarr[j+1]){
				temp = intarr[j];
				intarr[j] = intarr[j+1];
				intarr[j+1] = temp;
			}
		}
	}
	FILE* newfp = fopen("./10_1.txt","w");	
	for(x = 0;x<sizeof(intarr)/4;x++){
		fprintf(newfp,"%d\n",intarr[x]);
	}
	close(fd);
	fclose(fp);
	fclose(newfp);
	return 0;
}








