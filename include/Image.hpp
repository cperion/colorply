#pragma once
#include <string>
#include "Camera.hpp"
#include "Eigen/Dense"
#include "CImg.h"


class Image {
    private:
        cimg_library::CImg<unsigned int> cimg;
        std::string name;
        std::string channel;
        Camera *camera;
        Eigen::Vector3d S;
        Eigen::MatrixXd R;
    public:
        Image(const char *fpath,const char* xmlpath,Camera* camera);
        Eigen::Vector3d getS();
        Eigen::MatrixXd getR();
        Camera* getCam();
        int width();
        int height();
        unsigned int operator()(int x, int y);
};