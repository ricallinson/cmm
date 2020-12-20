// Entry Point.

#include <stdlib.h>
#include <stdio.h>
#include "github.com/cmm/math/math.h"
#include "github.com/cmm/accounts/account.h"

int main() {
    AccountsAccount a = AccountsMallocAccount("James", "Jones");
    char *s1 = AccountsToChars(&a);    
    printf("%s\n", s1);
    AccountsFreeAccount(&a);
    free(s1);
    MathNext();
    AccountsAccount b = AccountsMallocAccount("Rob", "Red");
    char *s2 = AccountsToChars(&b);
    printf("%s\n", s2);
    AccountsFreeAccount(&b);
    free(s2);
    return 0;
}
