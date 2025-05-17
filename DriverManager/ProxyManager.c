#include <config.h>
#include "drivermanager.h"
#include <string.h>

ProxyManager* pm = NULL;

void InitPM() 
{
    pm = (ProxyManager*)malloc(sizeof(ProxyManager));
    pm -> size = 2;
    pm -> conns = (DMHDBC*)malloc(sizeof(DMHDBC) * pm -> size);
    pm -> stmts = (DMHSTMT*)malloc(sizeof(DMHSTMT) * pm -> size);
}