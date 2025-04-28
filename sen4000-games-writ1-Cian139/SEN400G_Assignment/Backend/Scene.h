#ifndef SCENE_H
#define SCENE_H

#include <vector>
#include "Camera.h"
#include "Light.h"

class Scene {
private:
    std::vector<Camera> cameras;
    std::vector<Light> lights;

public:
    // Camera-related
    void addCamera(const Camera& camera);
    void printCameras() const;
    std::vector<Camera>& getCameras();
    const std::vector<Camera>& getCameras() const;

    // Light-related
    void addLight(const Light& light);
    void printLights() const;
    std::vector<Light>& getLights();
    const std::vector<Light>& getLights() const;
};

#endif // Scene_h
