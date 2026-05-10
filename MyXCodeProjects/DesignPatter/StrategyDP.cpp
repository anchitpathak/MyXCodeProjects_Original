#include<iostream>
using namespace std;
// Using Strategy DP to design Bokeh solution to design strategy to select Face detection and Blur applying menthod.
class BlurRendering
{
public:
    virtual void rendering() = 0;
    virtual ~BlurRendering(){};
};

class ManualRendering : public BlurRendering
{
public:
    void rendering() override
    {
        cout<<"This is Manual Blur Rendering"<<endl;
    }
};

class E2ERendering : public BlurRendering
{
public:
    void rendering() override
    {
        cout<<"This is End-To-End Blur Rendering"<<endl;
    }
};

class FaceDetection
{
public:
    virtual void detectFace() = 0;
    virtual ~FaceDetection(){};
};

class FaceLandmarkFD : public FaceDetection
{
public:
    void detectFace() override
    {
        cout<<"Face Detected from FDLD"<<endl;
    }
};

class BeautyFD : public FaceDetection
{
public:
    void detectFace() override
    {
        cout<<"Face Detected from Beauty"<<endl;
    }
};

class BokehSolution
{
    BlurRendering* blurRendering;
    FaceDetection* faceDetection;
public:
    BokehSolution(BlurRendering* blurRendering, FaceDetection* faceDetection): blurRendering(blurRendering), faceDetection(faceDetection){}
    void detectFace()
    {
        faceDetection->detectFace();
    }
    
    void applyBlur()
    {
        blurRendering->rendering();
    }
    
    virtual void bokehEffect() = 0;
    virtual ~BokehSolution(){}
};

class CameraPortrait : public BokehSolution
{
public:
    CameraPortrait(BlurRendering* blurRendering, FaceDetection* faceDetection): BokehSolution(blurRendering, faceDetection){}
    void bokehEffect() override
    {
        cout<<"Apply Blur on image captured from Camera"<<endl;
    }
};

class GalleryPortrait : public BokehSolution
{
public:
    GalleryPortrait(BlurRendering* blurRendering, FaceDetection* faceDetection): BokehSolution(blurRendering, faceDetection){}
    void bokehEffect() override
    {
        cout<<"Apply Blur on image taken from Gallery"<<endl;
    }
};

//int main() //client
//{
//    BlurRendering* blurRendering = new ManualRendering();
//    FaceDetection* faceDetection = new FaceLandmarkFD();
//    BokehSolution* bokehSolution = new CameraPortrait( blurRendering, faceDetection);
//    bokehSolution->detectFace();
//    bokehSolution->applyBlur();
//    bokehSolution->bokehEffect();
//    return 0;
//}
