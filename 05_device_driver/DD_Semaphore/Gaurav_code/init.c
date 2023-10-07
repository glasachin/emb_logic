#include"headers.h"
#include"declarations.h"
#define NOF 7
void* mainMenu(void*);
void* exitApplication(void*);
void* openDevforWrite(void*);
void* openDevforRead(void*);
void* releaseDev(void*);
void* readDev(void*);
void* writeDev(void*);

void* (*fptr[NOF])(void*);

int init()
{
  printf("%s:Begin.\n",__func__);
  fptr[0] = mainMenu;
  fptr[1] = exitApplication;
  fptr[2] = openDevforWrite;
  fptr[3] = openDevforRead;
  fptr[4] = releaseDev;
  fptr[5] = readDev;
  fptr[6] = writeDev;

  printf("%s:End.\n",__func__);
  return 0;
}
