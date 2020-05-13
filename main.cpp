#include <iostream>
#include "IO.h"

using namespace std;

int main(int argc, char const *argv[]) {
  IO* io = new IO();
  io->prompt();
  return 0;
}
