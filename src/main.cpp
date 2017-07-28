#include "stdafx.h"


using namespace cimg_library;

char* in;
std::string s_in;
const char* newname;
int pct1;
int pct2;
int d_pct1;
int d_pct2;
char* sw;
const float color[] = { 150.,150.,150. };

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
			std::cout << "Switches: -r (resize image to %), -p (resize image to amount of pixels)" << std::endl;
			break;
		}

		if (!(boost::filesystem::is_regular_file(s_in))) {
			std::cout << "File not found!" << std::endl;
			break;
		}
		boost::filesystem::path path(s_in);
		std::string ext = boost::filesystem::extension(s_in);
		std::string pre = path.stem().string();
		std::string r_sw = sw;
		d_pct1 = pct1;
		d_pct2 = pct2;

		if (r_sw == "-p") {
			if (pct1 < 0) pct1 = pct1 - pct1 * 2;
			if (pct2 < 0) pct2 = pct2 - pct2 * 2;
			s_in = pre + "_" + std::to_string(d_pct1) + "px_" + std::to_string(d_pct2) + "px" + ext;
		}

		else {
			if (pct1 > 0) pct1 = pct1 - pct1 * 2;
			if (pct2 > 0) pct2 = pct2 - pct2 * 2;
			s_in = pre + "_" + std::to_string(d_pct1) + "pct_" + std::to_string(d_pct2) + "pct" + ext;
		}
	

		newname = s_in.c_str();

		CImg<unsigned char> image(in);
		 image.resize(pct1, pct2, -100, -100, 3);
		 image.normalize(0, 255);
		 image.save(newname);
		return 0;
	}
}