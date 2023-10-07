#include"headers.h"
#include"declarations.h"
//int fd = 0;
void* readDev(void* arg)
{
  char rbuff[20];
  int fd,ret;
  fd = *(int*)arg;

  printf("%s:Begin.\n",__func__);
  ret = read(fd,rbuff,20);
  printf("%d\n",ret);
  printf("%s\n",rbuff);
  //printf("%d\n",sizeof(rbuff));
  if(ret == -1)
  {
    perror("read");
    (*fptr[0])((void*)"failure");
  }
  printf("%s:End.\n",__func__);
  return 0;
}
