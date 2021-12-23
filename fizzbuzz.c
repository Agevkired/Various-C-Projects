#include <stdio.h>
#include <strings.h>
#include <stdlib.h>

int main() {
    char fizz[] = "fizz ";
    char buzz[] = "buzz";
    int n = 1;
    char numstr[3];
    while(n <= 100)
    {
        sprintf(numstr, "%d", n * (n % 3 != 0) * (n % 5 != 0));
        numstr[0] = numstr[0] * (numstr[0] != '0');
        fizz[0] = 'f' * (n % 3 == 0);
        buzz[0] = 'b' * (n % 5 == 0);
        printf("%s%s%s\n", numstr, fizz, buzz);
        n += 1;
    }
    
    return 0;
}
