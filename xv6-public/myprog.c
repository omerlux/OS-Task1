#include "types.h"
#include "stat.h"
#include "user.h"
    
 //passing command line arguments 
    
int main(int argc, char *argv[]) 
{ 
  printf(1, "My first xv6 program!\nNumber of arguments are %d\n", argc); 
      for(int i=0;i<argc;i++)
    {
        printf(1, "%s ",argv[i]);
    }
	printf(1, "\n");
  exit(); 
} 