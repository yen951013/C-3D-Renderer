#ifndef _3DR_OBJ_PARSER_H
#define _3DR_OBJ_PARSER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "model.h"

typedef struct _3DR_Model _3DR_Model;

_3DR_Model _3DR_Model_loadModel(const char *filePath);
void _3DR_Model_deleteModel(_3DR_Model *model);

#endif  // _3DR_OBJ_PARSER_H