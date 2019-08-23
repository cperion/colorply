/*This file contains the functions that allow us to read and write ply files*/
#include "ioply.hpp"

std::vector<Eigen::Vector3d> readply(const char * fname) {
    std::vector<Eigen::Vector3d> outv;
    happly::PLYData inply(fname);
    std::vector<float> X = inply.getElement("vertex").getProperty<float>("x");
    std::vector<float> Y = inply.getElement("vertex").getProperty<float>("y");
    std::vector<float> Z = inply.getElement("vertex").getProperty<float>("z");
    int n = X.size();
    for (int i=0; i<n; i++) {
        outv.push_back(Eigen::Vector3d(X[i], Y[i], Z[i]));
    }
    return outv;
}

int writetoply(happly::PLYData &ply, std::vector<int> const &channelv, std::string channelname, std::string fname) {
    if (ply.getElement("vertex").getProperty<float>("x").size() != channelv.size()) {
        std::cout << "input ply and channel data do not have the same size";
        return 1;
    }
    ply.getElement("vertex").addProperty<int>(channelname, channelv);
    ply.write(fname);
    return 0;
}

/* int main() {

    return 0;
} */