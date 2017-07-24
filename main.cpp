#include "stdafx.h"

//todo, add file checks with boost fs, check if numbers are numbers etc.

using namespace cimg_library;

char* in;
std::string s_in;
const char* newname;
int pct1;
int pct2;
char* sw;
const float color[] = { 255.,255.,255. };

int main(int argc, char* argv[]) {

	while (1)
	{
		if (argc == 5) {
			in = (argv[1]);
			pct1 = std::stoi(argv[2]);
			pct2 = std::stoi(argv[3]);
			sw = argv[4];
			s_in = in;
		}

		else {
			std::cout << "Usage: imageresizer <filename> <X axis> <Y axis> <switch (-r by default)>" << std::endl;
			std::cout << "Switches: -r (resize image by %), -d (resize image to amount of pixels)" << std::endl;
			break;
		}

		if (sw == "-d") {
			if (pct1 < 0) pct1 = pct1 - pct1 * 2;
			if (pct2 < 0) pct2 = pct2 - pct2 * 2;
		}

		else {
			if (pct1 > 0) pct1 = pct1 - pct1 * 2;
			if (pct2 > 0) pct2 = pct2 - pct2 * 2;
		}


		std::size_t dot = s_in.find(".");
		s_in = s_in.substr(0, dot) + "_thumb" + s_in.substr(dot, s_in.length());
		newname = s_in.c_str();

		CImg<unsigned char> image(in);
		image.resize(pct1, pct2);
		image.draw_point(50, 50, color);
		image.normalize(0, 255);
		image.save(newname);
		return 0;
	}
}