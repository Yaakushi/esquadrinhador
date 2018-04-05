#include <string>

#define MAXBUF (2<<10)

namespace Scanner
{
  std::string scan(std::string host, int port, bool debugMode);
}
