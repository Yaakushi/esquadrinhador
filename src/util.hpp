#ifndef UTIL_HPP_
#define UTIL_HPP_

#define MAX_PORT			65535
#define DEFAULT_MAX_PORT	1024
#define DEBUG_SHORT_PARAM   "-d"
#define DEBUG_LONG_PARAM    "--debug"

#include <string>

typedef struct {
  std::string startip, endip;
  int startport, endport;
} iparg_t;

namespace Util
{
  bool hasDebugFlag(int argc, char *argv[]);
  iparg_t parseInput(int argc, char *argv[]);
  std::string nextIp(std::string currentIp);
}

#endif
