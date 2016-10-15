// Entry Point.

#include <stdio.h>
#include "github.com/ricallinson/teststruct/account.h"

int main() {
    Account a = AccountCreate("James", "Jones");
    Account b = AccountCreate("Rob", "Red");
    char *s;
    AccountToString(s, &b);
    printf("%s\n", s);
    return 0;
}
