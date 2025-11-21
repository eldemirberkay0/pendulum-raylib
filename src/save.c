#include <stdio.h>
#include "save.h"
#include "cJSON.h"
#include "game.h"
#include "gui.h"

void Save(const char* path)
{
    SaveFileText(path, CreateJSON(headCircle, isLineActive, isOutlineActive));
}

char* CreateJSON(Circle* headCircle, bool isLineActive, bool isOutlineActive)
{
    cJSON* root = cJSON_CreateObject();
    if (root == NULL) { return NULL; }
    cJSON* circleArray = cJSON_CreateArray();
    if (circleArray == NULL) 
    {
        cJSON_Delete(root);
        return NULL;
    }

    Circle* currentCircle = headCircle;
    while (currentCircle != NULL) 
    {
        cJSON *circleObject = CreateCirlceObject(currentCircle);
        cJSON_AddItemToArray(circleArray, circleObject);
        currentCircle = currentCircle->next;
    }

    cJSON_AddBoolToObject(root, "isLineActive", isLineActive);
    cJSON_AddBoolToObject(root, "isOutlineActive", isOutlineActive);
    cJSON_AddItemToObject(root, "circles", circleArray);

    char *json_output = cJSON_Print(root);
    cJSON_Delete(root);
    return json_output;
}

cJSON* CreateCirlceObject(Circle* circle)
{
    cJSON *circleJSON = cJSON_CreateObject();
    if (circleJSON == NULL) { return NULL; }

    cJSON *centerJSON = cJSON_CreateObject();
    cJSON_AddNumberToObject(centerJSON, "x", circle->center.x);
    cJSON_AddNumberToObject(centerJSON, "y", circle->center.y);
    cJSON_AddItemToObject(circleJSON, "center", centerJSON);

    cJSON *colorJSON = cJSON_CreateObject();
    cJSON_AddNumberToObject(colorJSON, "r", circle->color.r);
    cJSON_AddNumberToObject(colorJSON, "g", circle->color.g);
    cJSON_AddNumberToObject(colorJSON, "b", circle->color.b);
    cJSON_AddNumberToObject(colorJSON, "a", circle->color.a);
    cJSON_AddItemToObject(circleJSON, "color", colorJSON);

    cJSON_AddNumberToObject(circleJSON, "radius", circle->radius);
    cJSON_AddNumberToObject(circleJSON, "angularSpeed", circle->angularSpeed);

    return circleJSON;
}

void Load(const char* path)
{
    char *fileContent = LoadFileText(path);
    cJSON *root = cJSON_Parse(fileContent);
    if (root == NULL) return;

    isLineActive = cJSON_IsTrue(cJSON_GetObjectItemCaseSensitive(root, "isLineActive"));
    isOutlineActive = cJSON_IsTrue(cJSON_GetObjectItemCaseSensitive(root, "isOutlineActive"));

    cJSON* circles = cJSON_GetObjectItemCaseSensitive(root, "circles");
    cJSON* circleObject = NULL;
    /*
    cJSON_ArrayForEach(circleObject, circles)
    {

    }
    */
}