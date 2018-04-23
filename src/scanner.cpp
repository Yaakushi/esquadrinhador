#include <iostream>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/time.h>
#include <unistd.h>
#include <cstring>
#include <cerrno>
#include "scanner.hpp"

namespace Scanner
{
    struct ScanResult scan(std::string host, int port, bool debugMode)
    {
        int sockid; // FD do socket (wow).
        char buf[MAXBUF+1];
        struct sockaddr_in addr;

        struct ScanResult ret;
        ret.isOpen = false;
        ret.banner = "";

        if((sockid = socket(AF_INET, SOCK_STREAM, 0)) < 0)
        {
            std::cerr << "Não foi possível abrir o socket." << std::endl;
            close(sockid);
            return ret;
        }

        struct timeval tv;
        tv.tv_sec = SOCK_TIMEOUT;
        tv.tv_usec = SOCK_MILITIMEOUT * 1000;
        setsockopt(sockid, SOL_SOCKET, SO_RCVTIMEO, (const char*)&tv, sizeof(tv));
        setsockopt(sockid, SOL_SOCKET, SO_SNDTIMEO, (const char*)&tv, sizeof(tv));

        addr.sin_family = AF_INET;
        addr.sin_port = htons(port);

        if(inet_aton(host.c_str(), &(addr.sin_addr)) == 0)
        {
            std::cerr << "Houve um erro ao tentar converter o enredeço IP." << std::endl;
            close(sockid);
            return ret;
        }

        if(connect(sockid, (sockaddr *) &addr, sizeof(addr)) != 0)
        {
            if(debugMode) std::cerr << "[DEBUG] ERRNO: " << std::strerror(errno) << std::endl;
            close(sockid);
            return ret;
        }

        ret.isOpen = true;

        if(recv(sockid, buf, MAXBUF, 0) != -1)
        {
            std::string tmp = buf;
            size_t nlpos = tmp.find('\n'), crpos = tmp.find('\r'), minpos = nlpos;
            if(crpos < nlpos) minpos = crpos;
            ret.banner = tmp.substr(0, minpos);
        }

        if(close(sockid) == -1) std::cerr << "???";
        return ret;
    }
}
