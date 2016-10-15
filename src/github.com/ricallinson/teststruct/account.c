// Module Account.

#include <stdio.h>
#include "github.com/ricallinson/testlib/math.h"

typedef struct {
    int id;
    char *firstname;
    char *lastname;
} Account;

Account AccountCreate(char *firstname, char *lastname) {
    Account a = {
        .id = MathNext(),
        .firstname = firstname,
        .lastname = lastname
    };
    return a;
}

void AccountToString(Account *account, char *s) {
    sprintf(s, "%d: %s %s", account->id, account->firstname, account->lastname);
}
