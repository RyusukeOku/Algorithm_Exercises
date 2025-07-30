#include <stdio.h>
#include <stdlib.h>
 
int
main(int argc, char *argv[])
{
        int a[3] = {
                1,
                2,
                3
        };
        (void)printf("%lu\n", sizeof(a) );	// 配列のサイズ
        (void)printf("%lu\n", ( sizeof(a) / sizeof(int) ) );	// 配列の要素数
        exit(EXIT_SUCCESS);
}