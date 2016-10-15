// Module Account.

#include "github.com/ricallinson/testlib/math.h"

typedef struct {
    int id;
    int firstname;
    int lastname;
} Account;

Account AccountCreate(int firstname, int lastname) {
    Account a = {
        .id = MathNext(),
        .firstname = firstname,
        .lastname = lastname
    };
    return a;
}
