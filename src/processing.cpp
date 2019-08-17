/* This file contains the projection functions*/

#include "Eigen/Dense"
#include "Image.hpp"
#include <numeric>

int mean(std::vector<int> v) {
    return std::accumulate(v.begin(), v.end(), 0) / v.size();
}

Eigen::Vector3d applyDist(Eigen::Vector3d m, Eigen::Vector3d distcenter, std::vector<double> distcoefs) {
    double r = (m - distcenter).norm();
    double rsq = r * r;
    double poly = distcoefs[2];
    poly = poly * rsq + distcoefs[1];
    poly = poly * rsq + distcoefs[0];
    poly = poly * rsq;
    Eigen::Vector3d dr = poly * (m - distcenter);
    return m + dr;
}

int proj(Eigen::Vector3d const &M, std::vector<Image> &imgv, int (*agrf)(std::vector<int>) = mean )
{
    /* Computes a list of radiometric values by projecting the point in the images */
    std::vector<int> out;
    Eigen::Vector3d m;
    for (int i = 0; i < imgv.size(); i++) {
        Image img = imgv[i];
        Eigen::Vector3d k{0, 0, 1};
        k.transposeInPlace();
        Eigen::Vector3d F = img.getCam()->getF();
        Eigen::MatrixXd R = img.getR();
        Eigen::Vector3d S = img.getS();
        m = k.dot(F)*(R * (M - S));
        double d = k.dot(R * (M - S));
        m = F - m / d ;
        m = applyDist(m, img.getCam()->getdistcenter(), img.getCam()->getdistcoefs());
        int x = m[0] + 0.5;
        int y = m[0] + 0.5;
        if ( x < img.width() & y < img.height()) {
            out.push_back(img(x, y));
        }
    }
    return agrf(out);
}


#if 0
int main() {

    Eigen::Vector3d point{2.86285281181335449, 904.19775390625, 686.24530029296875};
}
#endif