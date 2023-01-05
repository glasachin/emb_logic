#include"headers.h"
#include"declarations.h"

dis* getInput()
{
    dis *d;

    #ifdef DEBUG
        printf("Start Function: %s\n", __func__);
    #endif

    d = (dis*)malloc(sizeof(dis));
    //allocate space for other two distance structures
    d->dfi = (dis_feet_inch*)malloc(sizeof(dis_feet_inch));
    d->dm = (dis_m_cm*)malloc(sizeof(dis_m_cm));
    d->dfi->ft = (int*)malloc(sizeof(int));
    d->dfi->inch = (int*)malloc(sizeof(int));
    d->dm->m = (int*)malloc(sizeof(int));
    d->dm->cm = (float*)malloc(sizeof(float));
    
    if(d==NULL)
    {
        perror("error");
        exit(EXIT_FAILURE);
    }

    printf("Enter distance in Feet: \n");
    scanf("%d", d->dfi->ft);
    printf("Enter distance in Inches: \n");
    scanf("%d", d->dfi->inch);
    
    #ifdef DEBUG
        printf("Ending Function: %s\n", __func__);
    #endif

    return d;
}