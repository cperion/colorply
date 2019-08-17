#include "Image.hpp"
#include "functions.hpp"
#include "Eigen/Dense"
#include "ioxml.hpp"
#include "functions.hpp"
#include "CImg.h"
#include "Camera.hpp"



Image::Image(const char * fpath,const char * xmlpath, Camera * camptr) {
    this->cimg.load(fpath);
    pugi::xml_document doc;
    doc.load_file(xmlpath);
    this->name = getfname(fpath);
    std::pair<Eigen::Vector3d, Eigen::MatrixXd> ori = getorifromxml(doc);
    this->S = ori.first;
    this->R = ori.second.reverse();
    this->camera = camptr;
}

Eigen::Vector3d Image::getS() {
    return this->S;
}

Eigen::MatrixXd Image::getR() {
    return this->R;
}

Camera* Image::getCam() {
    return this->camera;
}

unsigned int Image::operator()(int x, int y) {
    assert(x < this->cimg.width());
    assert(y < this->cimg.height());
    return this->cimg(x, y);
}

int Image::width() {
    return this->cimg.width();
}

int Image::height() {
    return this->cimg.height();
}

#if 0
int main() {
    const char* impath = "test/GRE/IMG_190716_082134_0016_GRE.TIF";
    const char *xmlpath = "test/Ori-1bande_All_CampariGCP/Orientation-IMG_190716_082134_0016_GRE.TIF.xml";
    Camera cam("test/Ori-1bande_All_CampariGCP/AutoCal_Foc-4000_Cam-SequoiaSequoia-GRE.xml");
    Image im(impath, xmlpath, &cam);
    std::cout << im(23,34) << std::endl;
    std::cout << "end" << std::endl;
}
#endif