#include"headers.h"
#include"declarations.h"
 int fd = 0;
void* openDev(void* arg)
{
  char ch;
  pthread_t thid;
  printf("%s:Begin.\n",__func__);
  //int fd;
   //fd = open("../mydev",O_WRONLY);
  //printf("%d\n",fd);
  //if(fd<0)
  //{
   // perror("OpenDev");
    //(*fptr[1])((void*)"failure");
 // }
/*  while(read(fd,&ch,1)!=0)
  {
    printf("%c",ch);
  }*/
 // printf("%d\n",fd);
  int ret;
  if(strncmp((char*)arg, "writing",7) == 0)
  {
    fd = open("../mydev",O_WRONLY);
    ret = pthread_create(&thid,0,fptr[5],(void*)&fd);
    if(ret == -1)
    {
      perror("pthread_create");
      (*fptr[1])((void*)"failure");
    }
  }
  else if(strncmp((char*)arg, "reading",7) == 0)
  {
    fd = open("../mydev",O_RDONLY);
    pthread_create(&thid,0,fptr[4],(void*)&fd);
    if(ret == -1)
    {
      perror("pthread_create");
      (*fptr[1])((void*)"failure");
    }
  }
  printf("%s:End.\n",__func__);
  return 0;
}
