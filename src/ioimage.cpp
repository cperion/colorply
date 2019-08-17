#include "Image.hpp"
#include <vector>
#include "functions.hpp"
#include <filesystem>
#include "Camera.hpp"



std::vector<Image> load_images(char *  imdir, char * oridir, Camera* cam) {
    std::vector<Image> out;
    std::vector<std::string> exts = {".TIF"};
    std::vector<std::string> imgls = lsimages(imdir, exts);
    for (int i = 0; i < imgls.size(); i++) {
        std::string imgpath = imgls[i];
        std::string xmlpath = oridir;
        if (xmlpath[xmlpath.size()-1] != "/"[0]) {
            xmlpath.append("/");
        }
        xmlpath.append("Orientation-" + getfname(imgpath.c_str()) + std::string(".xml"));
        if (std::filesystem::exists(xmlpath)) {
            Image img(imgpath.c_str(), xmlpath.c_str(), cam);
            out.push_back(img);
        }
    }
    return out;
}

#if 0
int main() {
    Camera cam("test/Ori-1bande_All_CampariGCP/AutoCal_Foc-4000_Cam-SequoiaSequoia-GRE.xml");
    auto imgv =load_images("test/GRE", "test/Ori-1bande_All_CampariGCP", &cam);
    std::cout << "end" << std::endl;
}
#endif