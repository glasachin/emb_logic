#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<string.h>
#include<unistd.h>
#include<time.h>

int main()
{
    int fd, ret, i;
    char ch;
    printf("%s: Started \n", __func__);

    fd = open("./mySerialDev", O_WRONLY); // we need to provide the node name here
    if(fd < 0)
    {
        perror("Open");
        goto out;
    }

    ch = 'S';
    for(i = 0; i < 26; i++)
    {
        ch = i+65;
        printf("Writing: %c\n", ch);
        ret = write(fd, &ch, 1);
        sleep(1);
    }
    // ret = write(fd, &ch, 1);
    // printf("%s: wrote %d bytes\n", __func__, ret);
    
    close(fd);
    
    printf("%s: End\n", __func__);
    return 0;
out:
    return -1;
}