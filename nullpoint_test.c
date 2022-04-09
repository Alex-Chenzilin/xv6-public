#include "types.h"
#include "stat.h"
#include "user.h"

int
main(int argc, char *argv[])
{
   int pid = getpid();
   if (fork() == 0) {
      uint * np = (uint*) 0;
      printf(1, "Null pointer: ");
      printf(1, "%x %x\n", np, *np);
      printf(1, "Failed\n");
      kill(pid);
      exit();
   } else {
      wait();
   }
   printf(1, "Passed\n");
   exit();
}