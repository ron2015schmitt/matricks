#define MATHQ_DEBUG 1


#include "mathq.h"

#include <iostream>
#include <string>

// used to demonstrate how to convert to C++ vectors
#include <vector>




int main()
{
  using namespace mathq;
  using namespace std;
  using namespace display;
  

  int Nex = 1;
  
  mathq_toc();
  CR();CR();
  mdtitle("Vector file I/O");
  mathq_preamble();

  mathq_toc();


  return 0;
}
