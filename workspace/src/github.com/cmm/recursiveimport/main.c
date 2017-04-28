#include <stdio.h>
#include "github.com/cmm/import/import.h"
#include "github.com/cmm/recursiveimport/other.h"

int main() {
	ImportPrint();
    OtherPublicPrint();
    return 0;
}

void privatePrint() {
	printf("%s\n", "recursive import");
}

void PublicPrint() {
    privatePrint();
}
