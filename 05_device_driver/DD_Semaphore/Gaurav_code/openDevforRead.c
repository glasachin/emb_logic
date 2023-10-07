#include"headers.h"
#include"declarations.h"
void* openDevforRead(void* arg)
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
  if(strncmp((char*)arg, "reading",7) == 0)
  {
    readfd = open("../mydev",O_RDONLY);
    ret = pthread_create(&thid,0,fptr[5],(void*)&readfd);
    if(ret == -1)
    {
      perror("pthread_create");
      (*fptr[1])((void*)"failure");
    }
  }
  //pthread_join(&thid,NULL);
  //close(readfd);
  printf("%s:End.\n",__func__);
  return 0;
}
