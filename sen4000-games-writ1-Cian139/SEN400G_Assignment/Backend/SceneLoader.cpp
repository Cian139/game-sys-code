#include "SceneLoader.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <algorithm>


std::string ensureSDFExtension(const std::string& filename) {
    if (filename.substr(filename.size() - 4) != ".sdf") {
        return filename + ".sdf";  
    }
    return filename;
}

bool parseVector3(const std::string& line, const std::string& label, Vector3& vec) {
    size_t pos = line.find(label);
    if (pos != std::string::npos) {
        std::string values = line.substr(pos + label.length());
        std::replace(values.begin(), values.end(), ',', ' ');  
        std::istringstream ss(values);

        float x, y, z;
        ss >> x >> y >> z;
        vec.setX(x);
        vec.setY(y);
        vec.setZ(z);

        return true;
    }
    return false;
}



bool SceneLoader::loadScene(const std::string& filename, Scene& scene) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Failed to open file: " << filename << "\n";
        return false;
    }

    std::string line;
    Vector3 pos, rot, lightPos;
    float fov = 60.0f;
    bool readingCamera = false;
    bool readingLight = false;

    while (std::getline(file, line)) {
        // Check for Camera object start
        if (line.find("Camera") != std::string::npos) {
            readingCamera = true;
        }
        else if (readingCamera && line.find("position:") != std::string::npos) {
            parseVector3(line, "position:", pos);
        }
        else if (readingCamera && line.find("rotation:") != std::string::npos) {
            parseVector3(line, "rotation:", rot);
        }
        else if (readingCamera && line.find("fov:") != std::string::npos) {
            std::string val = line.substr(line.find(":") + 1);
            fov = std::stof(val);
        }
        else if (line.find("}") != std::string::npos && readingCamera) {
            scene.addCamera(Camera(pos, rot, fov));
            readingCamera = false;
        }

   
        else if (line.find("Light") != std::string::npos) {
            readingLight = true;
        }
        else if (readingLight && line.find("position:") != std::string::npos) {
            parseVector3(line, "position:", lightPos);
        }
        else if (line.find("}") != std::string::npos && readingLight) {
            scene.addLight(Light(lightPos));
            readingLight = false;
        }
    }

    file.close();
    std::cout << "Scene loaded from " << filename << "\n";
    return true;
}


bool SceneLoader::saveScene(const std::string& filename, const Scene& scene) {
    std::string finalFilename = ensureSDFExtension(filename); 

    std::ofstream file(finalFilename);
    if (!file.is_open()) {
        std::cerr << "Failed to open file for writing: " << finalFilename << "\n";
        return false;
    }

    // Write all cameras
    for (const auto& cam : scene.getCameras()) {
        file << "Camera {\n";
        file << "    position: " << cam.getPosition().toString() << "\n";
        file << "    rotation: " << cam.getRotation().toString() << "\n";
        file << "    fov: " << cam.getFOV() << "\n";
        file << "}\n\n";
    }

    // Write all lights
    for (const auto& light : scene.getLights()) {
        file << "Light {\n";
        file << "    position: " << light.getPosition().toString() << "\n";
        file << "}\n\n";
    }

    file.close();
    std::cout << "Scene saved to " << finalFilename << "\n";
    return true;
}
