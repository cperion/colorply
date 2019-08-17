#pragma once
#include "ioxml.hpp"
#include "ioply.hpp"
#include "Eigen/Dense"
#include "pugixml.hpp"
#include <utility>
#include <vector>


class Camera {
    private:
    std::string name;
    std::pair<int, int> size;
    Eigen::Vector3d center;
    Eigen::Vector3d distcenter;
    Eigen::Vector3d F;
    std::vector<double> distcoefs;

    public:
    Camera(const char  * fpath);
    Eigen::Vector3d getF();
    Eigen::Vector3d getdistcenter();
    std::vector<double> getdistcoefs();
};