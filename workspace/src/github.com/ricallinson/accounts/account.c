// Module Accounts.

#include <stdlib.h>
#include <stdio.h>
#include "github.com/ricallinson/math/main.h"

typedef struct {
    int id;
    char *firstname;
    char *lastname;
} _Account;

Account _AccountMalloc(char *firstname, char *lastname) {
    _Account a = {
        .id = MathNext(),
        .firstname = firstname,
        .lastname = lastname
    };
    return a;
}

int _AccountFree(_Account *account) {
    // Free all memory used.
    return 0;
}

// Returns a pointer that needs freeing after use.
char *_AccountToChars(_Account *account) {
    char *s = malloc(30); // Get length of memory required for string.
    sprintf(s, "%d: %s %s", account->id, account->firstname, account->lastname);
    return s;
}
