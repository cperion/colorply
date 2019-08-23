#include "Eigen/Dense"
#include "Image.hpp"
#include <numeric>
#include "ioimage.hpp"
#include "ioply.hpp"

int mean(std::vector<int> v);
Eigen::Vector3d applyDist(Eigen::Vector3d m, Eigen::Vector3d distcenter, std::vector<double> distcoefs);
int proj(Eigen::Vector3d const &M, std::vector<Image> &imgv, int (*agrf)(std::vector<int>) = mean);
std::vector<int> projv(std::vector<Eigen::Vector3d> const & pointv, std::vector<Image> &imgv, int (*argf)(std::vector<int>) = mean);
