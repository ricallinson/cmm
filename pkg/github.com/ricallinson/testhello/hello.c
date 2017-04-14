// Entry Point.

#include <stdlib.h>
#include <stdio.h>
#include "github.com/ricallinson/testlib/math.h"
#include "github.com/ricallinson/teststruct/account.h"

int main() {
    Account a = AccountCreate("James", "Jones");
    char *s1 = AccountToChars(&a);    
    printf("%s\n", s1);
    free(s1);
    MathNext();
    Account b = AccountCreate("Rob", "Red");
    char *s2 = AccountToChars(&b);
    printf("%s\n", s2);
    free(s2);
    return 0;
}
