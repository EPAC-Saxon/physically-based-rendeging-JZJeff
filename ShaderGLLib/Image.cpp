#include "Image.h"

#include <algorithm>
#include <fstream>
#include <vector>
#include <tuple>
#include <assert.h>
#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>

namespace sgl {

	Image::Image(const std::string& file)
	{
		int width_pointer;
		int height_pointer;
		int channel_size ;
		int desired_channel = STBI_rgb_alpha;

		image_ = stbi_load(file.c_str(), &width_pointer, &height_pointer, &channel_size, desired_channel);

		if (image_ == NULL) {
			throw std::runtime_error("Image null");
		}
	
		dx_ = static_cast<size_t>(width_pointer);
		dy_ = static_cast<size_t>(height_pointer);

	}

	Image::~Image()
	{
		stbi_image_free(image_);
	}

}	// End namespace sgl.
