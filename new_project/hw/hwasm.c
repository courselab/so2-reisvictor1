#include <stdio.h>
#include <string.h>


int main(int argc, char **argv){

    if(argc != 3){
        printf("Quantidade errada de parâmetros\n");
        return 1;
    } 

    char file_name[10];

    strcpy(file_name, argv[2]);

    FILE *newfile = fopen(file_name, "wb");

    int code[] = {
        0xB4, 0x0E,
        0xB0, 0x48, /* 'H' */
        0xCD, 0x10,
        0xB0, 0x65, /* 'E' */
        0xCD, 0x10,
        0xB0, 0x6C, /* 'L' */
        0xCD, 0x10,
        0xB0, 0x6C, /* 'L' */
        0xCD, 0x10,
        0xB0, 0x6F, /* 'O' */
        0xCD, 0x10,
        0xB0, 0x20, /* ' ' */
        0xCD, 0x10,
        0xB0, 0x57, /* 'W'  */
        0xCD, 0x10,
        0xB0, 0x6F, /* 'O' */
        0xCD, 0x10,
        0xB0, 0x72, /* 'R' */
        0xCD, 0x10,
        0xB0, 0x6C, /* 'L' */
        0xCD, 0x10,
        0xB0, 0x0D, /* 'D' */
        0xCD, 0x10,
        0XF4,
        0XEB, 0XF4
    };

    fwrite(code, 1, 49, newfile);

    int i ;
    for(i = 0; i < 512 - 49 -2; i++){
        short zero = 0x00;
        fwrite(&zero, 1, 1, newfile);
    } 

    /* Agora vamos dar o boot */
    short make_boot = 0xAA55;
    fwrite(&make_boot, 1, 1, newfile);

    fclose(newfile);

    return 0;

}