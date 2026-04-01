#include <iostream>
#include <cstring>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <string>
#include <vector>
#include <mutex>
#include <algorithm>
int main() {

    int sock = socket(AF_INET, SOCK_STREAM, 0);

    sockaddr_in addr{};
    addr.sin_family = AF_INET;
    addr.sin_port = htons(8080);
    addr.sin_addr.s_addr = inet_addr("127.0.0.1");

    connect(sock, (sockaddr*)&addr, sizeof(addr));

    while(true){
      std:: string msg;
      std::getline(std::cin,msg);
      if(msg.empty()){
      continue;
      }
      if(msg=="exit"){
       break;
      }
      send(sock, msg.c_str(),msg.size(), 0);
 
     char buffer[1025] ;

    int n=recv(sock, buffer, 1024, 0);
    if(n<=0)break;
    buffer[n] = '\0';
    std::cout << "server: " << buffer << std::endl;
}
    close(sock);

    return 0;
}
