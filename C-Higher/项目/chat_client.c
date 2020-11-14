#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include "protocol.h"
int main(void)
{
  //int socket(int domain, int type, int protocol);
   //功能：创建一个套接字
   //返回值:文件描述符--代表网络链接
   int fd;
   /**************第一步:创建套接字************/
   //创建一个基于TCP的IPV4套接字
   fd = socket(AF_INET,SOCK_STREAM,0);
   printf("fd=%d\n",fd);
   /**************第二步：连接服务器*****************/
   int retval = 0;
   struct sockaddr_in server;
   server.sin_family = AF_INET;
   server.sin_port = htons(8990);
   server.sin_addr.s_addr = inet_addr("192.168.91.129");
   //int connect(int sockfd, const struct sockaddr *addr,socklen_t addrlen);
   retval = connect(fd,(struct sockaddr*)&server,sizeof(struct sockaddr_in));
   printf("retval=%d\n",retval);
   if(retval==-1)
   {
     perror("connect failed...");
     goto out;
   }
   char buf[1000]="";
   /****************第三步：与服务器通信*****************/
   retval = read(fd,buf,100);
   printf("从服务器读到%d字节:%s\n",retval,buf);
   memset(buf,0,100);
   int choice=0xff;
   while(1)
   {
      puts("*********欢迎来到xxx聊天室*********");
      puts("**************1:注册*********");
      puts("**************2:登录*********");
      puts("**************0:退出*********");
      scanf("%d",&choice);
      switch(choice)
      {
         case 1://注册
            {//语句块
              protocol pack;//定义协议包变量
              memset((void*)&pack,0,sizeof(protocol));//清空结果体
              printf("请输入用户名:");
              scanf("%s",pack.name);
              while(getchar()!=10);//吸收换行符
              printf("请输入密码:");
              scanf("%s",pack.passwd);
              while(getchar()!=10);//吸收换行符
              printf("你输入的用户名是:%s,密码是:%s\n",pack.name,pack.passwd);
              pack.type = TYPE_REG;//设置包类型
              //发送注册包到服务器
              retval = write(fd,(void*)&pack,sizeof(protocol));
              printf("发送了%d字节到服务器:username=%s,passwd=%s,type=%d\n",retval,pack.name,pack.passwd,pack.type);
              memset((void*)&pack,0,sizeof(protocol));//清空结果体
              retval = read(fd,(void*)&pack,sizeof(protocol));
              printf("从服务器读到%d字节:type=%d\n",retval,pack.type);
              if(pack.type==TYPE_OK)
              {
                 puts("注册成功...");
              }else{
                 puts("注册失败...");
              }
            }
            break;
         case 2://登录
            break;
         case 0://退出
            break;
         default://错误情况
            printf("请输入正确的选项编号\n");
            break;
      }
   }
out://标号
   printf("goto here....\n");
   close(fd);//关闭套接字
   return 0;
}












