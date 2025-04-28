#ifndef CAMERA_H
#define CAMERA_H

#include "Vector3.h"

class Camera {
private:
    Vector3 position;
    Vector3 rotation;
    float fov;

public:
    //  The constructors
    Camera();
    Camera(const Vector3& pos, const Vector3& rot, float fovVal);

    // Print the camera details
    void print() const;  // <-- BE SURE TO ADD THIS

    //  The getters
    Vector3 getPosition() const;
    Vector3 getRotation() const;
    float getFOV() const;

    //  The setters
    void setPosition(const Vector3& pos);
    void setRotation(const Vector3& rot);
    void setFOV(float fovVal);
};

#endif // Camera_H
