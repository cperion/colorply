#include "Camera.hpp"
#include "ioxml.hpp"
#include "functions.hpp"

Camera::Camera(const char * fpath) {
    this->name = getfname(fpath);
    pugi::xml_document doc;
    doc.load_file(fpath);
    this->center = getcenterfromxml(doc);
    this->distcenter = getdistcenterfromxml(doc);
    this->distcoefs = getdistcoefsfromxml(doc);
    this->F = getFfromxml(doc);
    this->size = getsizefromxml(doc);
}

Eigen::Vector3d Camera::getF() {
    return this->F;
}

Eigen::Vector3d Camera::getdistcenter() {
    return this->distcenter;
}

std::vector<double> Camera::getdistcoefs() {
    return this->distcoefs;
}



#if 0
int main() {
    char * fname = "test/camtest.xml";
    pugi::xml_document doc;
    doc.load_file(fname);
    Camera cam(doc, std::string("test"));
    std::cout << "end" << std::endl;
}
#endif