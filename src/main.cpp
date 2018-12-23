// Alisher A. Khassanov <a.khssnv@gmail.com>

#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>
#include <experimental/filesystem>
#include <iostream>

namespace fs = std::experimental::filesystem::v1;

auto main(int argc, char** argv) -> int
{
  cv::Mat img(100, 100, CV_8UC3);
  cv::randu(img, cv::Scalar(0, 0, 0), cv::Scalar(255, 255, 255));
  fs::path img_dir_path = fs::temp_directory_path() / "imgrandom";
  fs::create_directories(img_dir_path);
  fs::path img_path = img_dir_path / "output.tiff";
  cv::imwrite(img_path, img);
  std::cout << img_path;
}
