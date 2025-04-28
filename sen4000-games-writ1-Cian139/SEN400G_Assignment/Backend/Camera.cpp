#include "Camera.h"
#include <iostream> 


Camera::Camera() : position(Vector3()), rotation(Vector3()), fov(90.0f) {}

// Parameterized constructors
Camera::Camera(const Vector3& pos, const Vector3& rot, float fovVal)
    : position(pos), rotation(rot), fov(fovVal) {}

// Print the camera details
void Camera::print() const {
    std::cout << "Position: " << position.toString() << "\n";
    std::cout << "Rotation: " << rotation.toString() << "\n";
    std::cout << "FOV: " << fov << "\n";
}

// The getter functions 
Vector3 Camera::getPosition() const { return position; }
Vector3 Camera::getRotation() const { return rotation; }
float Camera::getFOV() const { return fov; }

// The setter functions
void Camera::setPosition(const Vector3& pos) { position = pos; }
void Camera::setRotation(const Vector3& rot) { rotation = rot; }
void Camera::setFOV(float fovVal) { fov = fovVal; }
