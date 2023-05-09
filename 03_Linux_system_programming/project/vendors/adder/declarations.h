typedef struct
{
    /* data */
    Request req;
    Result *res;
    int pfd;
}DataToProcess;

void* vThreadAdder(void *arg);