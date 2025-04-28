#include "master.h"
#include "operation.h"
#include "file_manage.h"

using namespace std;

int main()
{
    openFiles();
    welcome();
    sign();
    submitInformation();
    endMessage();
    return 0;
}