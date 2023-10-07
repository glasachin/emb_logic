#include"headers.h"
#include"declarations.h"
void* openDevforWrite(void* arg)
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
    writefd = open("../mydev",O_WRONLY);
    ret = pthread_create(&thid,0,fptr[6],(void*)&writefd);
    if(ret == -1)
    {
      perror("pthread_create");
      (*fptr[1])((void*)"failure");
    }
  }
 // pthread_join(&thid,NULL);
  //close(writefd);
  printf("%s:End.\n",__func__);
  return 0;
}
