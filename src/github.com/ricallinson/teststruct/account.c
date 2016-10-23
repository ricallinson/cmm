// Module Account.

#include <stdlib.h>
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

// Returns a pointer that needs freeing after use.
char *AccountToChars(Account *account) {
    char *s = malloc(30); // Get length of memory required for string.
    sprintf(s, "%d: %s %s", account->id, account->firstname, account->lastname);
    return s;
}
