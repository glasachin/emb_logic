#include"headers.h"
#include"declarations.h"
int readfd,writefd;
void* mainMenu(void* arg)
{
  int i,ret;
  pthread_t thid;

  printf("%s:Begin.\n",__func__);
  printf("%s: Device Menu\n",__func__);
  printf("%s: 1. Open Device for Write\n",__func__);
  printf("%s: 2. Open Device for Read\n",__func__);
 // printf("%s: 3. Release Device\n",__func__);
 // printf("%s: 3. Read Device\n",__func__);
 // printf("%s: 4. Write Device\n",__func__);
  printf("%s: 0. Exit Application\n",__func__);
  scanf("%d",&i);
  if(i == 0)
  {
    ret = pthread_create(&thid,0,fptr[i+1],(void*)"success");
    if(ret == -1)
    {
      perror("pthread_create");
      (*fptr[i+1])((void*)"failure");
    }
  }
  if(i==1)
  {
    ret = pthread_create(&thid,0,fptr[i+1],(void*)"writing");
    if(ret == -1)
    {
      perror("pthread_create");
      (*fptr[1])((void*)"failure");
    }
  }
  if(i==2)
  {
    ret = pthread_create(&thid,0,fptr[i+1],(void*)"reading");
    if(ret == -1)
    {
      perror("pthread_create");
      (*fptr[1])((void*)"failure");
    }
  }
  /*if((i>=3) && (i<=4))
  {
    ret = pthread_create(&thid,0,fptr[i+1],(void*)"writing");
    if(ret == -1)
    {
      perror("pthread_create");
      (*fptr[1])((void*)"failure");
    }
  }*/
  printf("%s:End.\n",__func__);
  return 0;
}


