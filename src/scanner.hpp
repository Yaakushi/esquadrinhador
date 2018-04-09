#ifndef SCANNER_HPP_
#define SCANNER_HPP_

#include <string>

#define MAXBUF (2<<10)

namespace Scanner
{
  std::string scan(std::string host, int port, bool debugMode);
}

#endif 
