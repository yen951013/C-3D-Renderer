#include "obj_parser.h"
#include "../utils/vector.h"

_3DR_Model _3DR_Model_loadModel(const char *filePath) {
    FILE *fpt = fopen(filePath, "r");
    if (fpt == NULL) {
        printf("OBJ_newModel(): File not found.\n");
        return (_3DR_Model){0};
    }

    char line[128];
    _3DR_Model model = {0, 0, 0, 0, NULL, NULL, NULL, NULL};
    
    // 第一次遍歷：統計數量
    while (fgets(line, sizeof(line), fpt) != NULL) {
        if (strncmp(line, "v ", 2) == 0) {
            model.v_count++;
        } else if (strncmp(line, "vt ", 3) == 0) {
            model.vt_count++;
        } else if (strncmp(line, "vn ", 3) == 0) {
            model.vn_count++;
        } else if (strncmp(line, "f ", 2) == 0) {
            model.f_count++;
        }
    }

    // 分配記憶體
    model.vertices = malloc(model.v_count * sizeof(Vec3));
    model.normals = malloc(model.vn_count * sizeof(Vec3));
    model.faces = malloc(model.f_count * sizeof(_3DR_Face));

    if (!model.vertices || !model.normals || !model.faces) {
        printf("OBJ_newModel(): Memory allocation failed.\n");
        _3DR_Model_deleteModel(&model);
        fclose(fpt);
        return (_3DR_Model){0};
    }

    // 第二次遍歷：讀取檔案
    rewind(fpt);

    int vi = 0, vti = 0, vni = 0, fi = 0, faceNormalIndex;
    while (fgets(line, sizeof(line), fpt) != NULL) {
        if (strncmp(line, "v ", 2) == 0) {
            sscanf(line, "v %f %f %f", &model.vertices[vi].x, &model.vertices[vi].y, &model.vertices[vi].z);
            vi++;
        } else if (strncmp(line, "vt ", 3) == 0) {

        } else if (strncmp(line, "vn ", 3) == 0) {
            sscanf(line, "vn %f %f %f", &model.normals[vni].x, &model.normals[vni].y, &model.normals[vni].z);
            vni++;
        } else if (strncmp(line, "f ", 2) == 0) {
            // 讀取面，格式為 f v1/vt1/vn1 v2/vt2/vn2 v3/vt3/vn3
            sscanf(line, "f %d/%*d/%*d %d/%*d/%*d %d/%*d/%d",
                    &model.faces[fi].p1, &model.faces[fi].p2, &model.faces[fi].p3, &model.faces[fi].n1);
            
            model.faces[fi].p1--, model.faces[fi].p2--, model.faces[fi].p3--;
            model.faces[fi].n1--;
            fi++;
        }
    }

    // 當面朝normal方向時，確保頂點為逆時針
    for (int i = 0; i < model.f_count; i++) {
        Vec3 p1 = model.vertices[model.faces[i].p1];
        Vec3 p2 = model.vertices[model.faces[i].p2];
        Vec3 p3 = model.vertices[model.faces[i].p3];

        Vec3 u = {p2.x - p1.x, p2.y - p1.y, p2.z - p1.z};
        Vec3 v = {p3.x - p1.x, p3.y - p1.y, p3.z - p1.z};

        Vec3 normal = _3DR_Vec3_crossProduct(u, v);
        // 如果兩者「方向相同」（點積 > 0），則頂點順序應該是順時針 (CW)，需要交換 v2 和 v3
        // 如果兩者「方向相反」（點積 < 0），則頂點順序已經是逆時針 (CCW)
        if (_3DR_Vec3_dotProduct(normal, model.normals[model.faces[i].n1]) > 0) {
            int temp = model.faces[i].p2;
            model.faces[i].p2 = model.faces[i].p3;
            model.faces[i].p3 = temp;
        }
    }

    // 關閉檔案
    fclose(fpt);

    return model;
}

void _3DR_Model_deleteModel(_3DR_Model *model) {
    // 釋放記憶體
    free(model->vertices);
    free(model->normals);
    free(model->faces);
}