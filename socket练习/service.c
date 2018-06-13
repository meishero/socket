#include<iostream>
#include<sstream>
#include<assert.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<string.h>
#include<arpa/inet.h>
#include<unistd.h>
#include<cstdlib>

using namespace std;

int main()
{
    int sockfd;
    assert( (sockfd = socket(AF_INET,SOCK_STREAM, 0)) > 0 );
   // std::cout<<"->>>>>>>>>"<<sockfd<<endl;
    sockaddr_in local;
    bzero(&local, sizeof(local));
    
    std::stringstream ss;
    
    const char* _ip = "127.0.0.1";
    int port = 1080;
    
    local.sin_family = AF_INET;
    local.sin_port = htons(8888);
    local.sin_addr.s_addr = inet_addr(_ip);

    if ( bind(sockfd, (sockaddr*)&local, sizeof(local)) < 0 )
    {
        std::cout<<"bind error"<<endl;
    //    exit(1);
    }
    //assert( (listen(sockfd, 5)) > 0 );
    if ( listen(sockfd,5)< 0)
    {
        std::cout<<"listen error"<<endl;
    }

    int opt = 1;
    setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));
    
    while(true)
    {
        //std::cout<<"ready to accept"<<endl;
        int clientfd = accept(sockfd, NULL, NULL);
        char buffer[512];
        //std::cout<<"haved  accept";
        cout<<"chat begin"<<endl;

        string msg;
        //while(cin >> msg)
        //{
        //    write(clientfd, msg.c_str(), msg.length());
        //}
        read(clientfd, buffer, sizeof(buffer)-1);//read  is block ?
        std::cout<<buffer<<endl;
        close(clientfd);
    }
    close(sockfd);

    return 0;
}
