#ifndef SCENELOADER_H
#define SCENELOADER_H

#include <string>
#include "Scene.h"

class SceneLoader {
public:
    bool loadScene(const std::string& filename, Scene& scene);
    bool saveScene(const std::string& filename, const Scene& scene);
};

#endif //SceneLoader.H
