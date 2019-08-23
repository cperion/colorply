/* This file contains the projection functions*/

#include "Eigen/Dense"
#include "Image.hpp"
#include <numeric>
#include "ioimage.hpp"
#include "ioply.hpp"

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
    int n = imgv.size();
    std::vector<int> out;
    out.reserve(n);
    for (int i = 0; i < n; i++)
    {
        Eigen::Matrix<double, 1, 3> k{0, 0, 1};
        Eigen::Vector3d F = imgv[i].getCam()->getF();
        Eigen::Matrix3d R = imgv[i].getR();
        Eigen::Vector3d S = imgv[i].getS();
        double a = k * F;
        a = a / (k*(R * (M - S)));
        Eigen::Vector3d m = F - a * R * (M - S);
        m = applyDist(m, imgv[i].getCam()->getdistcenter(), imgv[i].getCam()->getdistcoefs());
        int x = (m[0]) + 0.5;
        int y = (m[1]) + 0.5;
        if ((0 <= x) & (x < imgv[i].width()) & (0 <= y) & (y < imgv[i].height())) {
            out.emplace_back(imgv[i](x, y));
        }
        else {
            out.push_back(-1);
        }
    }
    return agrf(out);
}

std::vector<int> projv(std::vector<Eigen::Vector3d> const & pointv, std::vector<Image> &imgv, int (*argf)(std::vector<int>) = mean) {
    std::vector<int> out;
    out.reserve(pointv.size());
    for (int i = 0; i < pointv.size(); i++) {
        out.emplace_back(proj(pointv[i], imgv, argf));
    }
    return out;
}

#if 0
int main() {
    std::vector<Eigen::Vector3d> pointv = readply("test/C3DC_MicMac_1bandeAllCampariGCP_5images.ply");
    Camera cam("test/Ori-1bande_All_CampariGCP/AutoCal_Foc-4000_Cam-SequoiaSequoia-GRE.xml");
    auto imgv = load_images("test/GRE", "test/Ori-1bande_All_CampariGCP", &cam);
    projv(pointv, imgv);
}
#endif