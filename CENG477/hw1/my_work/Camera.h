#ifndef _CAMERA_H_
#define _CAMERA_H_

#include "Ray.h"
#include "defs.h"

// Structure for holding variables related to the image plane
typedef struct ImagePlane
{
	float left;     // "u" coordinate of the left edge
	float right;    // "u" coordinate of the right edge
	float bottom;   // "v" coordinate of the bottom edge
	float top;      // "v" coordinate of the top edge
    float distance; // distance to the camera (always positive)
    int nx;         // number of pixel columns
    int ny;         // number of pixel rows
} ImagePlane;

class Camera
{
public:
  char imageName[32];
  int id;
  ImagePlane imgPlane;     // Image plane

	Camera(int id,                      // Id of the camera
           const char* imageName,       // Name of the output PPM file 
           const Vector3D& pos,         // Camera position
           const Vector3D& gaze,        // Camera gaze direction
           const Vector3D& up,          // Camera up direction
           const ImagePlane& imgPlane); // Image plane parameters

    // Computes the primary ray through pixel (row, col)
	Ray getPrimaryRay(int row, int col) const;

private:
    //
	// You can add member functions and variables here
    //

	Vector3D pos;
	Vector3D gaze;
	Vector3D up;
	Vector3D right;

	Vector3D up_left_corner;

	Vector3D r_l_nx;
	Vector3D t_b_ny;
};

#endif
