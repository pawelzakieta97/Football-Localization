#include<opencv2/opencv.hpp>
#include <Eigen/Dense>
#include<iostream>
#define _USE_MATH_DEFINES
#include<math.h>
#include "Camera.h"
#include "Shape2.h"
#include "Shape3.h"
#include "Line2.h"
#include "Line3.h"
#include "Field.h"

using namespace std;
using namespace cv;
using namespace Eigen;

int main()
{

    Line2 l1(Point(-2, 0), Point(2, 2));
    Line2 l2(Point(0, -2), Point(0, 2));
    Point intersection;
    cout << l1.intersection2(l2, &intersection)<<endl;
    cout << intersection << endl;
    Field field(90, 60, 20, 10, Scalar(255, 255, 255), Scalar(0, 255, 255));
    Camera camera;
    Transform<float, 3, Affine> t(AngleAxisf(-M_PI*0.5, Vector3f(1, 0, 0)));
    camera.pose = t*camera.pose;
    camera.translate(Vector3f(0, 0, 20));
    Shape2 observation = camera.render(field);
    observation.clip(1400, 1400);
    for (int a = 0; a < 10; a++) {
        Shape2 particleView = camera.render(field);
        //particleView.clip(1500, 1500);
        cout << observation.matchTo(particleView)<<endl;
        t = (AngleAxisf(-M_PI * 0.02, Vector3f(0, 0, 1)));
        camera.pose = t * camera.pose;
    }
    t = (AngleAxisf(-M_PI * 0, Vector3f(0, 0, 1)));
    camera.pose = t * camera.pose;
    Mat img = imread("background.jpg");

    auto image = camera.render(field);
    image.clip(1400, 1400);
    image.draw(img);
    
    namedWindow("image", WINDOW_NORMAL);
    imshow("image", img);
    waitKey(0);
}