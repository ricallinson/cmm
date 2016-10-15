#include <stdio.h>

#include "github.com/ricallinson/teststruct/account.h"

int main() {
    Account a = AccountCreate(1, 2);
    Account b = AccountCreate(3, 4);
    printf("Account ID: %d\n", b.id);
    return 0;
}
