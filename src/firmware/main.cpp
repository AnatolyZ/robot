#include "../../thirdparty/raspicam/src/raspicam.h"
#include <chrono>
#include <iostream>
#include <filesystem>
#include <fstream>
#include <thread>

int main()
{
	raspicam::RaspiCam Camera; //Cmaera object
	//Open camera
	std::cout << "Opening Camera..." << std::endl;
	if (!Camera.open())
	{
		std::cerr << "Error opening camera" << std::endl;
		return -1;
	}
	//wait a while until camera stabilizes
	std::cout << "Sleeping for 3 secs" << std::endl;
	std::this_thread::sleep_for(std::chrono::seconds(3));
	//capture
	Camera.grab();
	//allocate memory
	unsigned char* data = new unsigned char[ Camera.getImageTypeSize ( raspicam::RASPICAM_FORMAT_RGB )];
	//extract the image in rgb format
	Camera.retrieve ( data,raspicam::RASPICAM_FORMAT_RGB );
	//get camera image
	//save
	std::ofstream out_file ("raspicam_image.ppm", std::ios::binary);
	out_file << "P6\n" << Camera.getWidth() << " " << Camera.getHeight() <<" 255\n";
	out_file.write ( (char* ) data, Camera.getImageTypeSize ( raspicam::RASPICAM_FORMAT_RGB ) );
	std::cout << "Image saved at raspicam_image.ppm" << std::endl;
	//free resrources
	delete[] data;
	return 0;
}
