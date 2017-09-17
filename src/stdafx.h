#pragma once
// add jpg support to CImg, note that this requires the libjpeg library to work
#define cimg_use_jpeg
#define cimg_use_png
#include "CImg.h"
#include <jpeglib.h>
#include <png.h>
#include <iostream>
#include <string>
#include <boost/filesystem.hpp>
