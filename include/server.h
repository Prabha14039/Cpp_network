#pragma once
#include<iostream>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>

class Server{
    private:
        struct sockaddr_in client_addr,server_addr;
    public:
        Server(in_port_t port=3000)
        {
            server_addr.sin_family = AF_INET;
            server_addr.sin_addr.s_addr = INADDR_ANY;
            server_addr.sin_port = htons(port);
        }
        void start();
};

void inline Server::start()
{
    auto const server_sock = socket(AF_INET,SOCK_STREAM,0);
    if (server_sock == -1)
    {
        std::cerr<<"Socket creation failed\n";
    }

    if (bind(server_sock,(struct sockaddr*) &server_addr,sizeof(server_addr))==-1)
    {
        std::cerr<<"Socket binding failed\n";
    }

    if (listen(server_sock,5)==-1)
    {
        std::cerr<<"Sock listening failed\n";
    }

    socklen_t client_addr_len = sizeof(client_addr);
    int client_conn = accept(server_sock,(struct sockaddr*) &client_addr,&client_addr_len);

    if (client_conn ==-1)
    {
        std::cerr<<"error connecting to the client\n";
    }
    std::cout<<"client connected\n";
}

