// Entry Point.

#include <stdio.h>
#include "github.com/ricallinson/testlib/math.h"
#include "github.com/ricallinson/teststruct/account.h"

int main() {
    AccountCreate("James", "Jones");
    MathNext();
    Account b = AccountCreate("Rob", "Red");
    // char *s;
    // AccountToString(&b, s);
    // printf("%s\n", s);
    return 0;
}
