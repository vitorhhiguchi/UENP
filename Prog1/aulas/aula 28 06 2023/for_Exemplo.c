#include <stdio.h>
int main(){

    int x, y, n;
    scanf("%d%d", &x, &y);

    for(n = x + 1; n < y; n++){
        printf("%d\n", n);
    }

    printf("  ------     -------      |----        |--------- \n");
    printf(" /          /       \     |    \       |          \n");
    printf("/           |        |    |     |      | ------   \n"); 
    printf("\           |        |    |     /      |          \n"); 
    printf(" \          \        /    |    /       |          \n"); 
    printf("  ------      -------     |----        |--------- \n");  

    return 0;
}