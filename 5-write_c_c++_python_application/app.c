#include<stdio.h>
#include<stdlib.h>

#define PATH            "/dev/test_device_file"
void Write_To_File(void)
{
    char str[100]={};
    FILE *fptr;
    fptr = fopen(PATH,"w");
    if(fptr == NULL)
    {
        return ;
    }
    printf("Enter the data \n");
    scanf("%100[a-zA-Z0-9 ]",str);
    fprintf(fptr,"%s",str);
    
    fclose(fptr);
}

void Read_From_File(void)
{
    char str[100]={};
    FILE *fptr;
    fptr = fopen(PATH,"r");
    if(fptr == NULL)
    {
        return ;
    }

    fscanf(fptr,"%[^\n]",str);

    printf("the message is %s \n",str);

    fclose(fptr);

}


int main(void)
{
    Write_To_File();
    Read_From_File();

    return 0;
}