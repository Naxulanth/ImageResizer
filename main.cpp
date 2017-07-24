#include "stdafx.h"


using namespace cimg_library;

char* in;
std::string s_in;
const char* newname;
int pct;
const float color[] = { 255.,255.,255. };

int main(int argc, char* argv[]) {

	while (1)
	{
		if (argc == 3) {
			in = (argv[1]);
			pct = std::stoi(argv[2]);
			s_in = in;
		}

		else {
			std::cout << "Usage: imageresizer <filename> <% to be resized to>" << std::endl;
			break;
		}

		if (pct > 0) pct = pct - (2 * pct);
		if (pct < 0) pct = 0;
		if (pct > 100) pct = 100;

		std::size_t dot = s_in.find(".");
		s_in = s_in.substr(0, dot) + "_thumb" + s_in.substr(dot, s_in.length());
		newname = s_in.c_str();

		CImg<unsigned char> image(in);
		image.resize(pct, pct);
		image.draw_point(50, 50, color);
		image.normalize(0, 255);
		image.save(newname);
		return 0;
	}
}