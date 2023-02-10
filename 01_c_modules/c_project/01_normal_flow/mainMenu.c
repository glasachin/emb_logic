#include "headers.h"
#include "declarations.h"

int mainMenu()
{
    int choice;
    #ifdef DEBUG
        printf("Running function: %s\n", __func__);
    #endif

    do
    {
      printf("Welcome to File Compresseion Program. Please Select Your Choice: \n");
      printf("1: Compress File.\n");
      printf("2: Compression Statistics.\n");
      printf("3: Decompress File.\n");
      printf("4: Decompress Statistics.\n");
      printf("0: Exit Program\n");
      scanf("%d",&choice);
      
      switch (choice)
        {
            case 1:
                compression();
                break;
            case 2:
                compStats();
                break;
            case 3:
                deCompression();
                break;
            case 4:
                deCompStats();
                break;
            case 0:
                exitProgram("success");
                break;
            default:
                printf("Wrong Choice. Select Option Again.\n");
                break;
        }
    } while (choice != 0);
    
    return choice;
}