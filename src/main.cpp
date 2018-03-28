#include <iostream>
#include "util.hpp"


int main(int argc, char *argv[]) {
	bool debugMode = Util::hasDebugFlag(argc, argv);
	iparg_t iparg = Util::parseInput(argc, argv);
	std::cout << "IP inicial: [" << iparg.startip << "] // IP final: [" << iparg.endip << "]" << std::endl;
	std::cout << "Porta inicial: [" << iparg.startport	 << "] // Porta final: [" << iparg.endport << "]" << std::endl;
	return 0;
}
