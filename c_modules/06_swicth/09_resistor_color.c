#include<stdio.h>
int main()
{
    char ch;
    printf("Enter the color code from the following list: \n");
    printf("B: for Black\n");
    printf("W: for Brown\n");
    printf("R: for Red\n");
    printf("O: for Orange\n");
    printf("Y: for Yellow\n");
    printf("G: for Green\n");
    printf("L: for Blue\n");
    printf("V: for Violet\n");
    printf("E: for Grey\n");
    printf("H: for White\n");
    scanf("%c",&ch);
    switch(ch)
    {
        case 'B':
            printf("Color Value is 0\n");
            break;
        case 'W':
            printf("Color Value is 1\n");
            break;
        case 'R':
            printf("Color Value is 2\n");
            break;
        case 'O':
            printf("Color Value is 3\n");
            break;
        case 'Y':
            printf("Color Value is 4\n");
            break;
        case 'G':
            printf("Color Value is 5\n");
            break;
        case 'L':
            printf("Color Value is 6\n");
            break;
        case 'V':
            printf("Color Value is 7\n");
            break;
        case 'E':
            printf("Color Value is 8\n");
            break;
        case 'H':
            printf("Color Value is 9\n");
            break;
        default:
            printf("Wrong Choice!\n");
            break;
    }
    return 0;
}