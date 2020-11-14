#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include <pthread.h>
#include "protocol.h"
void* do_server(void* arg)
{
         int retval;
         int clientfd = *((int*)arg);
         printf("%s ,clientfd=%d\n",__FUNCTION__,clientfd);
         protocol pack;
         memset((void*)&pack,0,sizeof(protocol));
         while(1)
         {
            retval = read(clientfd,(void*)&pack,sizeof(protocol));
	    printf("从%d #客户端读到 %d 字节:type=%d\n",clientfd,retval,pack.type);
            if(retval==0)
            {
               printf("%d# 客户端已断开...\n",clientfd);
               break;
            }
            switch(pack.type)
            {
                case TYPE_REG:// 处理注册包
                   //遍历链表，检查是否有已经注册的用户
                  // if(check_name()==0)//没有注册，则返回TYPE_OK
                   {
                     pack.type = TYPE_OK;
                     retval = write(clientfd,(void*)&pack,sizeof(protocol));
                     printf("发送了%d字节到客户端\n",retval);  
                  // }else{//该用户存在，返回TYPE_ERR
                   }
                   break;
                case TYPE_LOGIN://处理登录包
                   break;
                case TYPE_EXIT:
                   break;
                default:
                   printf("接收的包类型有误....\n");
                   break;
            }
         }
   close(clientfd);
   
   return NULL;
}
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
   //  int setsockopt(int sockfd, int level, int optname,const voi    d *optval, socklen_t optlen); 
    int on = 1;
    setsockopt(fd,SOL_SOCKET,SO_REUSEADDR,&on,sizeof(int));

   /**************第二步：绑定*****************/
   //int bind(int sockfd, const struct sockaddr *addr,socklen_t addrlen);
   struct sockaddr_in server;
   server.sin_family = AF_INET;// 设置IPV4地址 
   server.sin_port = htons(8990);//host short  把端口号转为网络字节序
   server.sin_addr.s_addr = inet_addr("192.168.91.129"); //设置IP地址
   int retval;
   retval = bind(fd,(struct sockaddr*)&server,(socklen_t)sizeof(struct sockaddr_in));
   printf("bind的返回值=%d\n",retval);
   if(retval==-1)
   {
     perror("bind failed...");
     goto out;
   }
   /******************第3步：监听********************/
   //  int listen(int sockfd, int backlog);  
   retval = listen(fd,10);//设置监听队列的长度
   printf("listen的返回值=%d\n",retval);
   if(retval==-1)
   {
     perror("listen failed...");
   }
   /****************第4步：接收(接收客户端的链接)****************/
   int clientfd;
   struct sockaddr_in client;//用于保存客户端的IP地址和端口号
   socklen_t len=0;
    pthread_t thread[100];
    int client_no = 0;
    pthread_attr_t attr[100];
   //int accept(int sockfd, struct sockaddr *addr, socklen_t *addrlen);
   while(1){
	   printf("accept...\n");
	   clientfd = accept(fd,(struct sockaddr*)&client,&len); 
	   printf("客户端fd=%d:IP=%s,PORT=%d\n",clientfd,inet_ntoa(client.sin_addr),ntohs(client.sin_port)); 
	   /****************第五步：与客户端通信*****************/
	   char *str = "欢迎光临...";
	   retval = write(clientfd,str,strlen(str));
	   printf("发送%d字节到客户端...\n",retval);
           
           pthread_attr_init(&attr[client_no]);
           pthread_attr_setdetachstate(&attr[client_no],PTHREAD_CREATE_DETACHED);
           pthread_create(&thread[client_no],&attr[client_no],do_server,(void*)&clientfd);
           client_no++;
   }
out://标号
   printf("goto here....\n");
   close(fd);//关闭套接字
   return 0;
}












