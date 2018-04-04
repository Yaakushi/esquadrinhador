#include <iostream>
#include "util.hpp"

int main(int argc, char *argv[]) {
  bool debugMode = Util::hasDebugFlag(argc, argv);

  if(argc < 2 || (debugMode && argc < 3))
  {
    std::cerr << argv[0] << " [-d] <endereco ip inicial>[-endereco ip final] [[porta inicial]-porta final]" << std::endl;
    std::cerr << std::endl;
    std::cerr << "Para mais informações, consulte a \"man-page\" disponibilizada com o projeto." << std::endl;
    std::cerr << "`man " << argv[0] << ".1`." << std::endl;
    return -1;
  }

  iparg_t iparg = Util::parseInput(argc, argv);
  std::cout << "IP inicial: [" << iparg.startip << "] // IP final: [" << iparg.endip << "]" << std::endl;
  std::cout << "Porta inicial: [" << iparg.startport	 << "] // Porta final: [" << iparg.endport << "]" << std::endl;

  std::string curAddr = iparg.startip;
  std::string endAddr = Util::nextIp(iparg.endip);

  std::cout << endAddr << " (" << iparg.endip << ")." << std::endl;

  do
  {
    if(debugMode) std::cout << "[DEBUG] Scanning " << curAddr << "." << std::endl;

    curAddr = Util::nextIp(curAddr);
    //std::cout << endAddr << " != " << curAddr << std::endl;
  }
  while(curAddr != endAddr);
  return 0;
}
