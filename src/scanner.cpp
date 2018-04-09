#include <iostream>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <cstring>
#include <cerrno>
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
      return "";
    }

    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);
    
	if(inet_aton(host.c_str(), &(addr.sin_addr)) == 0)
	{
		std::cerr << "Houve um erro ao tentar converter o enredeço IP." << std::endl;
		return "";
	}

    if(connect(sockid, (sockaddr *) &addr, sizeof(addr)) != 0)
	{
		std::cerr << "DEU RUIM!" << std::endl;
		if(debugMode) std::cerr << "[DEBUG] ERRNO: " << std::strerror(errno) << std::endl;
		return "";
	}
	
	std::cerr << "DEU BOA!" << std::endl;

	return "";
  }
}
