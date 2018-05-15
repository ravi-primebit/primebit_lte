#include <iostream>
//#include "../rrc/inc/rrc.h
#include "rrc/inc/rrc.h"
#include "srv/inc/srv.h"

using namespace std;

int main()
{
  printf("starting project");
  /**project starts to compile from here**/
#ifdef STUBS_FRAMEWORK

printf("stubs running");

#endif // STUBS_FRAMEWORK

MSG_O(LTE_INIT);


  rrc_init();
  /**rrc_init function is called which is defined in RRC layer**/
}

