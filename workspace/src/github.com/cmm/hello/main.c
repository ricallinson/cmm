// Entry Point.

#include <stdlib.h>
#include <stdio.h>
#include "github.com/cmm/math/math.h"
#include "github.com/cmm/accounts/account.h"

int main() {
    // Create an Account object.
    AccountsAccount a1 = AccountsCreate("James", "Jones");

    // Print a string version of the account and clean up memory.
    char *str1 = AccountsToString(&a1);    
    printf("%s\n", str1);
    StringsDestroy(str1);
    
    // Clean up the memory used by the Account object.
    AccountsDestroy(&a1);

    // Create a second Account object.
    AccountsAccount a2 = AccountsCreate("Rob", "Red");

    // Print a string version of the account and clean up memory.
    char *str2 = AccountsToString(&a2);
    printf("%s\n", str2);
    StringsDestroy(str2);
    
    // Clean up the memory used by the second Account object.
    AccountsDestroy(&a2);
    
    return 0;
}
