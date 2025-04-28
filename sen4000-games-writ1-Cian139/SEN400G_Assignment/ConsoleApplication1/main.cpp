#include <iostream>
#include <cstdlib>
#include "Camera.h"
#include "Vector3.h"
#include "Scene.h"
#include "SceneLoader.h"

void showMenu() {
    std::cout << "\n--- Scene File Editor ---\n";
    std::cout << "1. View cameras\n";  
    std::cout << "2. Load scene file\n";  
    std::cout << "3. View lights\n"; 
    std::cout << "4. Add camera\n";  
    std::cout << "5. Save scene\n"; 
    std::cout << "6. Add light\n";  
    std::cout << "7. Exit\n"; 
    std::cout << "Select option: ";
}

int main(int argc, char** argv)
{
    Scene scene;
    SceneLoader loader;
    std::string input;
    bool running = true;

    while (running) {
        showMenu();
        std::getline(std::cin, input);

        if (input == "1") {
               scene.printCameras();
        }
        else if (input == "2") {
            std::string filename;
            std::cout << "Enter scene filename to load: ";
            std::getline(std::cin, filename);
            loader.loadScene(filename, scene); 
        }
        else if (input == "3") {
            scene.printLights(); 
        }
        else if (input == "4") {
            float x, y, z, rx, ry, rz, fov;
            std::cout << "Enter position (x y z): ";
            std::cin >> x >> y >> z;
            std::cout << "Enter rotation (x y z): ";
            std::cin >> rx >> ry >> rz;
            std::cout << "Enter FOV: ";
            std::cin >> fov;
            std::cin.ignore(); 
            scene.addCamera(Camera(Vector3(x, y, z), Vector3(rx, ry, rz), fov));
        }
        else if (input == "5") {
            std::string filename;
            std::cout << "Enter filename to save: ";
            std::getline(std::cin, filename);
            loader.saveScene(filename, scene); 
        }
        else if (input == "6") {
            float x, y, z;
            std::cout << "Enter position (x y z): ";
            std::cin >> x >> y >> z;
            std::cin.ignore(); 
            scene.addLight(Light(Vector3(x, y, z)));

        }
        else if (input == "7") {
            running = false;
        }
        else {
            std::cout << "Invalid option.\n";
        }
    }

    return 0;
}
