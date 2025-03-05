#include "model.h"

void _3DR_addModelToScene(_3DR_SceneModels *sceneModels, const char *filePath, Vec3 position, Vec3 rotation) {
    if (sceneModels->count >= MAX_MODELS) {
        return;
    }

    _3DR_Model model = _3DR_Model_loadModel(filePath);
    if (model.v_count == 0) {
        return;
    }

    // 初始化
    model.update = true;
    model.position = position;
    model.thetaX = rotation.x;
    model.thetaY = rotation.y;
    model.thetaZ = rotation.z;

    // 新增至場景
    sceneModels->models[sceneModels->count] = model;
    sceneModels->count++;
}