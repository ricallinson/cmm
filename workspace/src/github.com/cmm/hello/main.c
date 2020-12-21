// Entry Point.

#include <stdlib.h>
#include <stdio.h>
#include "github.com/cmm/math/math.h"
#include "github.com/cmm/accounts/account.h"

int main() {
    AccountsAccount a1 = AccountsCreateAccount("James", "Jones");
    char *str1 = AccountsToChars(&a1);    
    printf("%s\n", str1);
    free(str1);
    AccountsDestroyAccount(&a1);

    MathNext();

    AccountsAccount a2 = AccountsCreateAccount("Rob", "Red");
    char *str2 = AccountsToChars(&a2);
    printf("%s\n", str2);
    free(str2);
    AccountsDestroyAccount(&a2);
    
    return 0;
}
