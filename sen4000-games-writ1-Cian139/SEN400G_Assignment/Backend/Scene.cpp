#include "Scene.h"
#include <iostream>

void Scene::addCamera(const Camera& camera) 
{
    cameras.push_back(camera);
}

void Scene::printCameras() const {
    if (cameras.empty()) {
        std::cout << "No cameras in scene.\n";
        return;
    }

    for (size_t i = 0; i < cameras.size(); ++i) {
        std::cout << "\nCamera " << i + 1 << ":\n";
        cameras[i].print();
    }
}

std::vector<Camera>& Scene::getCameras() {
    return cameras;
}

const std::vector<Camera>& Scene::getCameras() const {
    return cameras;
}

/////////Lights////////////

void Scene::addLight(const Light& light) 
{
    lights.push_back(light);
}

void Scene::printLights() const
{
    if (lights.empty()) {
        std::cout << "No lights in scene.\n";
        return;
    }

    for (size_t i = 0; i < lights.size(); ++i) {
        std::cout << "\nLight " << i + 1 << ":\n";
        lights[i].print();
    }
}

std::vector<Light>& Scene::getLights() {
    return lights;
}

const std::vector<Light>& Scene::getLights() const {
    return lights;
}


