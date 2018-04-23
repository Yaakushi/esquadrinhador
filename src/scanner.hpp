#ifndef SCANNER_HPP_
#define SCANNER_HPP_

#include <string>

#define SOCK_TIMEOUT        2
#define SOCK_MILITIMEOUT    0
#define MAXBUF              (2<<10)

struct ScanResult
{
    bool isOpen;
    std::string banner;
};

namespace Scanner
{
    struct ScanResult scan(std::string host, int port, bool debugMode);
}

#endif 
