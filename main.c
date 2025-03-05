#include <stdio.h>
#include <stdint.h>
#include "config.h"

int main() {
    _3DR_FrameBuffer frameBuffer = _3DR_FB_newFrameBuffer(_3DR_SCREEN_WIDTH, _3DR_SCREEN_HEIGHT);
    _3DR_init(_3DR_SCREEN_WIDTH, _3DR_SCREEN_HEIGHT);

    _3DR_SceneModels sceneModels = {0};

    _3DR_addModelToScene(&sceneModels, "models/cube.obj", (Vec3){0, 0, -10}, (Vec3){0, 0, 0});

    Matrix4x4 projectionMat = _3DR_Mat_newProjectionMat4x4(_3DR_NEAR_PLANE, _3DR_FAR_PLANE, _3DR_FOV_DEGREE, _3DR_ASPECT);
    Matrix4x4 viewportTransformMat = _3DR_Mat_newViewportTransformMat4x4(_3DR_SCREEN_WIDTH, _3DR_SCREEN_HEIGHT);

    while (_3DR_isRunning()) {
        // _3DR_eventHandler();
        
        for (int i = 0; i < sceneModels.count; i++) {
            _3DR_Model *model = &sceneModels.models[i];
            if (model->update) {
                Matrix4x4 translation = _3DR_Mat_newTranslationMat4x4(model->position.x, model->position.y, model->position.z);
                Matrix4x4 rotationZ = _3DR_Mat_newRotationMat4x4_Z(model->thetaZ);
                Matrix4x4 rotationY = _3DR_Mat_newRotationMat4x4_Y(model->thetaY);
                Matrix4x4 rotationX = _3DR_Mat_newRotationMat4x4_X(model->thetaX);
                
                model->modelTransform = _3DR_Mat_multiplyMatrix4x4(&translation, &rotationZ);
                model->modelTransform = _3DR_Mat_multiplyMatrix4x4(&model->modelTransform, &rotationY);
                model->modelTransform = _3DR_Mat_multiplyMatrix4x4(&model->modelTransform, &rotationX);
                model->update = false;
            }

            // MVP = Projection * View * Model
            // TODO: viewMatrix
            Matrix4x4 MVP = _3DR_Mat_multiplyMatrix4x4(&projectionMat, &model->modelTransform);

            for (int j = 0; j < model->v_count; j++) {
                model->transformedVertices[j] = (Vec4){0, 0, 0, 0};
                model->transformedVertices[j] = _3DR_Trans_transformVertex((Vec4){model->vertices[j].x, model->vertices[j].y, model->vertices[j].z, 1}, &MVP);
        
                // 透視除法
                if (model->transformedVertices[j].w != 0) {
                    model->transformedVertices[j].x /= model->transformedVertices[j].w;
                    model->transformedVertices[j].y /= model->transformedVertices[j].w;
                    model->transformedVertices[j].z /= model->transformedVertices[j].w;
                }
                model->transformedVertices[j].w = 1;
        
                // 視口變換
                model->transformedVertices[j] = _3DR_Trans_transformVertex(model->transformedVertices[j], &viewportTransformMat);
            }

            for (int j = 0; j < model->f_count; j++) {
                _3DR_drawTriangle(
                    &frameBuffer,
                    model->transformedVertices[model->faces[j].p1].x,
                    model->transformedVertices[model->faces[j].p1].y,
                    model->transformedVertices[model->faces[j].p2].x,
                    model->transformedVertices[model->faces[j].p2].y,
                    model->transformedVertices[model->faces[j].p3].x,
                    model->transformedVertices[model->faces[j].p3].y,
                    0xFF1111EE
                );
            }

            model->thetaY += 2;
            model->update = true;
        }
        _3DR_render(&frameBuffer);
        _3DR_FB_clear(&frameBuffer);
        SDL_Delay(100);
    }

    // _3DR_drawTriangle(&frameBuffer, 100, 100, 500, 150, 200, 350, 0xFF1111EE);

    _3DR_render(&frameBuffer);

    SDL_Delay(4000);
    _3DR_quit();

    return 0;
}