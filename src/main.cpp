#include "stdafx.h"


using namespace cimg_library;

char* in;
std::string s_in;
std::string new_path;
const char* new_name;
int pct1;
int pct2;
int d_pct1;
int d_pct2;
char* sw;

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

		// check if file exists
		if (!(boost::filesystem::is_regular_file(s_in))) {
			std::cout << "File not found!" << std::endl;
			break;
		}

		boost::filesystem::path path(s_in);
		// extension
		std::string ext = boost::filesystem::extension(s_in);
		// filename without the extension
		std::string pre = path.stem().string();
		// switch in string form so that it could be used in if/else cases.
		std::string r_sw = sw;
		// store resize values in order to be used in new filename
		d_pct1 = pct1;
		d_pct2 = pct2;

		// switch between percentage scaling and pixel scaling, convert numbers accordingly for it to work with the CImg resize function
		// CImg resize function uses negative numbers (0 to -100) for percentage scaling, and positive numbers for pixel scaling.

		// Ensure that the given numbers can't be less than 0 if pixel scaling is chosen.
		if (r_sw == "-p") {
			if (pct1 < 0) pct1 = pct1 - pct1 * 2;
			if (pct2 < 0) pct2 = pct2 - pct2 * 2;
			s_in = pre + "_" + std::to_string(d_pct1) + "px_" + std::to_string(d_pct2) + "px" + ext;
		}

		// Convert positive numbers to negative numbers since positive numbers are for pixel scaling, and we need negative numbers for percentage scaling.
		else {
			if (pct1 > 0) pct1 = pct1 - pct1 * 2;
			if (pct2 > 0) pct2 = pct2 - pct2 * 2;
			s_in = pre + "_" + std::to_string(d_pct1) + "pct_" + std::to_string(d_pct2) + "pct" + ext;
		}
	
		// new name in char* format for CImg save function
		new_path = path.parent_path().string() + s_in;
		std::cout << "Saved to: " + new_path;
		new_name = new_path.c_str();

		// create a CImg object with the selected image, resize, normalize, and save it. -100 is default value for
		// Z and V axis scaling, 3 is for linear interpolation as resizing type.
		 CImg<unsigned char> image(in);
		 image.resize(pct1, pct2, -100, -100, 3);
		 image.normalize(0, 255);
		 image.save(new_name);
		return 0;
	}
}