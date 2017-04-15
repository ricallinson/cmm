// Entry Point.

#include <stdlib.h>
#include <stdio.h>
#include "github.com/ricallinson/math/main.h"
#include "github.com/ricallinson/accounts/account.h"

int main() {
    Account a = AccountsAccountMalloc("James", "Jones");
    char *s1 = AccountsAccountToChars(&a);    
    printf("%s\n", s1);
    free(s1);
    TestlibNext();
    Account b = AccountsAccountMalloc("Rob", "Red");
    char *s2 = AccountsAccountToChars(&b);
    printf("%s\n", s2);
    free(s2);
    return 0;
}
