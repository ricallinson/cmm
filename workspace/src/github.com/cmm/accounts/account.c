// Module Accounts.

#include <stdlib.h>
#include <stdio.h>
#include "github.com/cmm/math/math.h"
#include "github.com/cmm/strings/strings.h"

typedef struct {
    unsigned long id;
    char *firstname;
    char *lastname;
} AccountsAccount;

AccountsAccount AccountsCreateAccount(char *firstname, char *lastname) {
    AccountsAccount a = {
        .id = MathNext(),
        .firstname = firstname,
        .lastname = lastname
    };
    return a;
}

int AccountsDestroyAccount(AccountsAccount *account) {
    // Free all memory used.
    return 0;
}

// Returns a pointer that needs freeing after use.
char *AccountsToChars(AccountsAccount *account) {
    char *id = StringsFormatUlong(account->id);
    char *name = StringsJoin(account->firstname, account->lastname, " ");
    char *res = StringsJoin(id, name, ": ");

    // Free local scope memory.
    free(id);
    free(name);

    return res;
}
