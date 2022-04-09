#include "types.h"
#include "stat.h"
#include "user.h"
#include "mmu.h"

//  different situation in different area

int
main(int argc, char *argv[])
{
  char * x = sbrk(0);
  sbrk(PGSIZE);
  *x = 100;
  mprotect(x, 1) ;
  int z = fork();
  if(z == 0){                                            
    printf(1, "Protected the value: %d \n", *x);
    munprotect(x, 1);
    *x = 10;
    printf(1, "Unprotecting it: %d \n", *x);
    exit();
  }
  else if(z > 0){
    wait();
    printf(1, "errrrror... \n");
    *x = 10;
    exit();
  }
 exit();
}