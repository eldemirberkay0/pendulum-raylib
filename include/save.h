#ifndef SAVE_H
#define SAVE_H

#include <stdbool.h>
#include "circle.h"
#include "cJSON.h"

void Save(const char* path);
char* CreateJSON(Circle* headCircle, bool isLineActive, bool isOutlineActive);
cJSON* CreateCirlceObject(Circle* circle);
void Load(const char* path);

#endif