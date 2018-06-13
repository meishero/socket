#include<iostream>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<unistd.h>
#include<string.h>
#include<netinet/in.h>

int main()
{
    int clientfd = socket(AF_INET, SOCK_STREAM, 0);

    sockaddr_in servsock;
    bzero(&servsock, sizeof(servsock));
    servsock.sin_family = AF_INET;
    servsock.sin_port = htons(8888);
    servsock.sin_addr.s_addr= inet_addr("127.0.0.1");


    if (connect(clientfd,(sockaddr*)&servsock, sizeof(servsock)) != -1)
    {
        char msg[] = "hello socket";
        std::cout<<"have send msg"<<std::endl;
        write(clientfd, msg, sizeof(msg));
    }

    close(clientfd);
    return 0;
}
