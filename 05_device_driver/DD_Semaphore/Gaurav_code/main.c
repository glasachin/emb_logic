#include"headers.h"
#include"declarations.h"
void* main(void* arg)
{
  printf("%s:Begin.\n",__func__);
  init();
  while(1)
  {
   (*fptr[0])(0);
  }
  
  printf("%s:End.\n",__func__);
  return 0;
}  
