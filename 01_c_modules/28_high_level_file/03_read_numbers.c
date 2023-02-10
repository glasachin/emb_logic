#include<stdio.h>
#include<stdlib.h>

FILE* create_file(char*);
void write_file(char*,int);
void read_even_no(char* , FILE* ,int);
void read_odd_no(char* , FILE* ,int);

int main()
{
    FILE *fp, *fodd, *feven;
    int n;
    char fn[20] = "sachin_test.txt";
    char fe[20] = "odd_txt.txt";
    char fo[20] = "even_txt.txt";
    printf("Enter, how mnay number you want to wrie: ");
    scanf("%d",&n);
    // printf("Enter file name: ");
    // scanf("%s",&fn);
    write_file(fn,n);
    fodd = create_file(fe);
    feven = create_file(fo);
    read_even_no(fn,feven,n);
    read_odd_no(fn,fodd,n);

    // fclose(fp);
    fclose(fodd);
    fclose(feven);
}

void write_file(char *fn, int n)
{
    FILE *fp;
    int i;
    fp = fopen(fn,"w");
    if(fp == NULL)
    {
        perror("Error in File Open\n");
        exit(EXIT_FAILURE);
    }

    for(i = 0; i < n; i++)
    {
        fprintf(fp,"%d\n",i);
    }
    fclose(fp);
    // return fp;
}

FILE* create_file(char *fn)
{
    FILE *fp;
    fp = fopen(fn,"w");
    if(fp == NULL)
    {
        perror("Error: \n");
        exit(EXIT_FAILURE);
    }
    return fp;
}

void read_even_no(char *fn, FILE* feven, int n)
{
    int i, val;
    FILE *fp;
    fp = fopen(fn,"r");
    while(1)
    // for(i = 0; i < n; i++)
    {
        // fscanf(fp,"%d",&val);
        // printf("%d\n",val);

        if(fscanf(fp,"%d",&val) < 0)
        {
            printf("%d\n",val);
            break;
        }
        
        if(val%2 == 0)
            fprintf(feven,"%d\n",val);
    }
    fclose(fp);
}

void read_odd_no(char *fn, FILE* fodd, int n)
{
    int i, val;
    FILE *fp;
    fp = fopen(fn,"r");
    while(1)
    {
        if(fscanf(fp,"%d",&val) < 0)
        {
            printf("%d\n",val);
            break;
        }
        
        if(val%2 == 1)
            fprintf(fodd,"%d\n",val);
    }
    fclose(fp);
}