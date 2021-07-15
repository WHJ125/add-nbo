#include <stddef.h> // for size_t
#include <stdint.h> // for uint8_t
#include <stdio.h> // for printf
#include <stdlib.h>
#include <netinet/in.h>

int main(int argc, char** argv) {

#define size 8
    FILE *fp;
    uint8_t* ptr;
    uint16_t sum[2];
    uint16_t result;
    if(argc <= 2){
        fprintf(stderr, "Error : Please input at least 2 Files !\n");
        return 1;
    }
    for(int i = 1; i < argc; i++)
    {
        fp = fopen(argv[i], "r");
        ptr = (uint8_t*)malloc(sizeof(8) * size);
        fread(ptr, 4, size, fp);
        uint16_t* p = reinterpret_cast<uint16_t*>(ptr);
        sum[i-1] = ntohs(p[1]);
    }
    result = sum[0] + sum[1];
    printf("%d(0x%x) + %d(0x%x) = %d(0x%x)\n", sum[0], sum[0], sum[1], sum[1], result, result);

    free(ptr);
    fclose(fp);
    return 0;

}
