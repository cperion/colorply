#pragma once
#include <utility>
#include "Eigen/Dense"
#include "pugixml.hpp"
#include <vector>


std::pair<Eigen::Vector3d,Eigen::MatrixXd> getorifromxml(pugi::xml_document const &doc); 

Eigen::Vector3d getcenterfromxml(pugi::xml_document const & doc);

Eigen::Vector3d getdistcenterfromxml(pugi::xml_document const &doc) ;

std::vector<double> getdistcoefsfromxml(pugi::xml_document const &doc) ;

Eigen::Vector3d getFfromxml(pugi::xml_document const &doc) ;

std::pair<int, int> getsizefromxml(pugi::xml_document const &doc) ;