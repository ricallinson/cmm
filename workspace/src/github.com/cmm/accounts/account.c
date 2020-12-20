// Module Accounts.

#include <stdlib.h>
#include <stdio.h>
#include "github.com/cmm/math/math.h"

typedef struct {
    int id;
    char *firstname;
    char *lastname;
} AccountsAccount;

AccountsAccount AccountsMallocAccount(char *firstname, char *lastname) {
    AccountsAccount a = {
        .id = MathNext(),
        .firstname = firstname,
        .lastname = lastname
    };
    return a;
}

int AccountsFreeAccount(AccountsAccount *account) {
    // Free all memory used.
    return 0;
}

// Returns a pointer that needs freeing after use.
char *AccountsToChars(AccountsAccount *account) {
    char *s = malloc(30); // Get length of memory required for string.
    sprintf(s, "%d: %s %s", account->id, account->firstname, account->lastname);
    return s;
}
