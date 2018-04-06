#include <iostream>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include "scanner.hpp"

namespace Scanner
{
  std::string scan(std::string host, int port, bool debugMode)
  {
    int sockid; // FD do socket (wow).
    char buf[MAXBUF+1];
    struct sockaddr_in addr;

    if((sockid = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {
      std::cerr << "Não foi possível abrir o socket." << std::endl;
      return NULL;
    }

    addr.sin_family = AF_INET;
    addr.sin_port = port;
    inet_aton(host.c_str(), &(addr.sin_addr));

    if(connect(sockid, (sockaddr *) &addr, sizeof(addr)) != 0)
    {
    }

  }
}
