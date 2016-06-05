//
//  Image.hpp
//  lab8
//
//  Created by Asjad Athick on 11/05/2016.
//  Copyright © 2016 Asjad Athick. All rights reserved.
//

#ifndef Image_h
#define Image_h

#include <iostream>
#include <fstream>

class Image{
	unsigned int width;
	unsigned int height;
	unsigned int minIntensity;
	unsigned int maxIntensity;
	float avgIntensity;

public:
	Image(std::string);
	void getStats();
	
};

#endif /* Image_hpp */
