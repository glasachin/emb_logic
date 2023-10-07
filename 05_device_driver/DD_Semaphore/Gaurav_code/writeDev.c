#include"headers.h"
#include"declarations.h"
//int fd = 0;
void* writeDev(void* arg)
{
  int fd,ret;
  char buff[] = "Hello Kernel";
  fd = *(int*)arg;
  printf("%s:Begin.\n",__func__);
  ret = write(fd, buff, 12);
  printf("%d.\n",ret);
  if(ret == -1)
  {
    perror("write");
    (*fptr[0])((void*)"failure");

  }
  printf("%s:End.\n",__func__);
  return 0;
}
