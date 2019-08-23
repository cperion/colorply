#include "ioxml.hpp"
#include "pugixml.hpp"
#include "Eigen/Dense"
#include <iostream>
#include "functions.hpp"
std::pair<Eigen::Vector3d,Eigen::MatrixXd> getorifromxml(pugi::xml_document const &doc) {
    Eigen::MatrixXd R(3,3);
    Eigen::Vector3d S;
    std::string centre_str = doc.select_node("/ExportAPERO/OrientationConique/Externe/Centre").node().child_value();
    std::string L1 = doc.select_node("/ExportAPERO/OrientationConique/Externe/ParamRotation/CodageMatr/L1").node().child_value();
    std::string L2 = doc.select_node("/ExportAPERO/OrientationConique/Externe/ParamRotation/CodageMatr/L2").node().child_value();
    std::string L3 = doc.select_node("/ExportAPERO/OrientationConique/Externe/ParamRotation/CodageMatr/L3").node().child_value();
    std::vector<std::string> centre_strv = splitstr(centre_str, std::string(" "));
    std::vector<std::string> L1v = splitstr(L1, std::string(" "));
    std::vector<std::string> L2v = splitstr(L2, std::string(" "));
    std::vector<std::string> L3v = splitstr(L3, std::string(" "));
    S(0)=std::stod(centre_strv[0]);
    S(1)=std::stod(centre_strv[1]);
    S(2)=std::stod(centre_strv[2]);
    R(0,0) = std::stod(L1v[0]);
    R(0,1) = std::stod(L1v[1]);
    R(0,2) = std::stod(L1v[2]);
    R(1,0) = std::stod(L2v[0]);
    R(1,1) = std::stod(L2v[1]);
    R(1,2) = std::stod(L2v[2]);
    R(2,0) = std::stod(L3v[0]);
    R(2,1) = std::stod(L3v[1]);
    R(2,2) = std::stod(L3v[2]);
    return std::pair<Eigen::Vector3d,Eigen::MatrixXd>(S, R);
}

Eigen::Vector3d getcenterfromxml(pugi::xml_document const &doc) {
    Eigen::Vector3d out;
    std::string ppstring = doc.select_node("/ExportAPERO/CalibrationInternConique/PP").node().child_value();
    std::vector<std::string> ppstringv = splitstr(ppstring, std::string(" "));
    double x = std::stod(ppstringv[0]);
    double y = std::stod(ppstringv[1]);
    out(0)=x;
    out(1)=y;
    out(2)=0.0;
    return out;
}

Eigen::Vector3d getdistcenterfromxml(pugi::xml_document const &doc) {
    Eigen::Vector3d out;
    std::string ppstring = doc.select_node("/ExportAPERO/CalibrationInternConique/CalibDistortion/ModRad/CDist").node().child_value();
    std::vector<std::string> ppstringv = splitstr(ppstring, std::string(" "));
    double x = std::stod(ppstringv[0]);
    double y = std::stod(ppstringv[1]);
    out(0)=x;
    out(1)=y;
    out(2)=0.0;
    return out;
}

std::vector<double> getdistcoefsfromxml(pugi::xml_document const &doc) {
    std::vector<double> out;
    pugi::xml_node node = doc.select_node("/ExportAPERO/CalibrationInternConique/CalibDistortion/ModRad").node();
    node = node.first_child();
    node = node.next_sibling();
    double a = std::stod(node.child_value());
    node = node.next_sibling();
    double b = std::stod(node.child_value());
    node = node.next_sibling();
    double c = std::stod(node.child_value());
    out.push_back(a);
    out.push_back(b);
    out.push_back(c);
    return out;
}

Eigen::Vector3d getFfromxml(pugi::xml_document const &doc) {
    Eigen::Vector3d F = getcenterfromxml(doc);
    F(2) = std::stod(doc.select_node("/ExportAPERO/CalibrationInternConique/F").node().child_value());
    return F;
}

std::pair<int, int> getsizefromxml(pugi::xml_document const &doc) {
    
    std::string szim = doc.select_node("/ExportAPERO/CalibrationInternConique/SzIm").node().child_value();
    std::vector<std::string> szimstrv = splitstr(szim, std::string(" "));
    int x = std::stoi(szimstrv[0]);
    int y = std::stoi(szimstrv[1]);
    return std::pair<int, int>(x,y);
}

/* int main() {
    pugi::xml_document doc;
    pugi::xml_parse_result result = doc.load_file("test/camtest.xml");
    auto out = getsize(doc);
    std::cout << "end" << std::endl;
} */