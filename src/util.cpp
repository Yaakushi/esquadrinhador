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


}
