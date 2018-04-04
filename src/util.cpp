#include "util.hpp"
#include <string>
#include <arpa/inet.h>

namespace Util
{
  bool hasDebugFlag(int argc, char *argv[])
  {
    for(int i = 1; i < argc; i++)
    {
      std::string tmp = argv[i];
      if(tmp == DEBUG_SHORT_PARAM || tmp == DEBUG_LONG_PARAM)
        return true;
    }

    return false;
  }

  iparg_t parseInput(int argc, char *argv[])
  {
    iparg_t ret = {"", "", 1, DEFAULT_MAX_PORT};
    bool foundIp = false;

    for(int i = 1; i < argc; i++)
    {
      std::string tmp = argv[i];
      if(tmp[0] == '-') continue;

      size_t dashpos = tmp.find("-");

      if(!foundIp)
      {
        if(dashpos == std::string::npos)
          ret.startip = ret.endip = tmp;
        else
        {
          ret.startip = tmp.substr(0, dashpos);
          std::string lastoctet = tmp.substr(dashpos+1);
          ret.endip = ret.startip.substr(0, ret.startip.rfind(".")+1) + lastoctet;
        }

        foundIp = true;
      }
      else
      {
        if(dashpos == std::string::npos)
          ret.startport = ret.endport = std::stoi(tmp);
        else
        {
          ret.startport = std::stoi(tmp.substr(0, dashpos));
          ret.endport = std::stoi(tmp.substr(dashpos+1));
        }
        return ret;
      }
    }

    return ret;
  }

  std::string nextIp(std::string currentIp)
  {
    std::string next, tmp;
    int curval;
    size_t last_dot_pos = currentIp.rfind(".");

    if(last_dot_pos == std::string::npos)
      return std::to_string(std::stoi(currentIp) + 1);

    tmp = currentIp.substr(last_dot_pos + 1);
    curval = (std::stoi(tmp) + 1) % 256; // % 255 cuz we don't want the broadcast addresses.
    next = currentIp.substr(0, last_dot_pos);
    if(curval == 0)
    {
      curval = 1;
      next = nextIp(next);
    }

    next = next + "." + std::to_string(curval);
      
    return next;
  }

}
