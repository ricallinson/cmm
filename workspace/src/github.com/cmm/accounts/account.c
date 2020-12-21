// Module Accounts.

#include <stdlib.h>
#include <stdio.h>
#include "github.com/cmm/math/math.h"
#include "github.com/cmm/strings/main.h"
#include "github.com/cmm/strconv/main.h"

typedef struct {
    unsigned long id;
    char *firstname;
    char *lastname;
} AccountsAccount;

AccountsAccount AccountsCreate(char *firstname, char *lastname) {
    AccountsAccount a = {
        .id = MathNext(),
        .firstname = StringsCreate(firstname),
        .lastname = StringsCreate(lastname)
    };
    return a;
}

int AccountsDestroy(AccountsAccount *account) {
    // Free all memory used.
    StringsDestroy(account->firstname);
    StringsDestroy(account->lastname);
    return 0;
}

// Returns a pointer that needs freeing after use.
char *AccountsToString(AccountsAccount *account) {
    char *id = StringsFormatUlong(account->id);
    char *name = StringsJoin(account->firstname, account->lastname, " ");
    char *res = StringsJoin(id, name, ": ");

    // Free local scope memory.
    StringsDestroy(id);
    StringsDestroy(name);

    return res;
}
