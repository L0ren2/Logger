#include "Logger.hpp"

int main()
{
  /// LVL::INFO will output to stdout
  Logger("TEST") << LVL::INFO << "Logging INFO on TEST trace" << std::endl;
  /// LVL::ERROR will output to stderr
  Logger("NOEXIST") << LVL::ERROR << "Logging ERROR on NOEXIST trace\n";
  return 0;
}

