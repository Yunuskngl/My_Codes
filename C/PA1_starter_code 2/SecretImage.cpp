#include "SecretImage.h"
#include <fstream>
#include <stdexcept>
#include <cstring>  // For memcpy

// Constructor: split image into upper and lower triangular arrays
SecretImage::SecretImage(const GrayscaleImage& image) : width(image.get_width()), height(image.get_height()) {
    // 1. Dynamically allocate the memory for the upper and lower triangular matrices.
    upper_triangular = new int[width * height / 2 + height]; // Upper triangular includes diagonal
    lower_triangular = new int[width * height / 2];          // Lower triangular excludes diagonal

    int upper_index = 0;
    int lower_index = 0;

    // 2. Fill both matrices with the pixels from the GrayscaleImage.
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            if (j >= i) {
                upper_triangular[upper_index++] = image.get_pixel(i, j); // Upper triangle
            } else {
                lower_triangular[lower_index++] = image.get_pixel(i, j); // Lower triangle
            }
        }
    }
}

// Constructor: instantiate based on data read from file
SecretImage::SecretImage(int w, int h, int* upper, int* lower) : width(w), height(h) {
    // Dynamically allocate memory for the upper and lower triangular matrices
    upper_triangular = new int[w * h / 2 + h];
    lower_triangular = new int[w * h / 2];

    // Copy the provided arrays into the instance variables
    std::memcpy(upper_triangular, upper, (w * h / 2 + h) * sizeof(int));
    std::memcpy(lower_triangular, lower, (w * h / 2) * sizeof(int));
}

// Destructor: free the arrays
SecretImage::~SecretImage() {
    // Simply free the dynamically allocated memory for the upper and lower triangular matrices.
    delete[] upper_triangular;
    delete[] lower_triangular;
}

// Reconstructs and returns the full image from upper and lower triangular matrices.
GrayscaleImage SecretImage::reconstruct() const {
    GrayscaleImage image(width, height);
    int upper_index = 0;
    int lower_index = 0;

    // Reconstruct the image from the triangular arrays
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            if (j >= i) {
                image.set_pixel(i, j, upper_triangular[upper_index++]);
            } else {
                image.set_pixel(i, j, lower_triangular[lower_index++]);
            }
        }
    }

    return image;
}

// Save the filtered image back to the triangular arrays
void SecretImage::save_back(const GrayscaleImage& image) {
    int upper_index = 0;
    int lower_index = 0;

    // Update the triangular matrices with the new image
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            if (j >= i) {
                upper_triangular[upper_index++] = image.get_pixel(i, j);
            } else {
                lower_triangular[lower_index++] = image.get_pixel(i, j);
            }
        }
    }
}

// Save the upper and lower triangular arrays to a file
void SecretImage::save_to_file(const std::string& filename) {
    std::ofstream file(filename);

    if (!file) {
        throw std::runtime_error("Error: Could not open file " + filename);
    }

    // 1. Write width and height
    file << width << " " << height << "\n";

    // 2. Write upper_triangular array
    for (int i = 0; i < (width * height / 2 + height); ++i) {
        file << upper_triangular[i] << " ";
    }
    file << "\n";

    // 3. Write lower_triangular array
    for (int i = 0; i < (width * height / 2); ++i) {
        file << lower_triangular[i] << " ";
    }
    file << "\n";

    file.close();
}

// Static function to load a SecretImage from a file
SecretImage SecretImage::load_from_file(const std::string& filename) {
    std::ifstream file(filename);

    if (!file) {
        throw std::runtime_error("Error: Could not open file " + filename);
    }

    // 1. Open the file and read width and height from the first line
    int w, h;
    file >> w >> h;

    int* upper = new int[w * h / 2 + h];
    int* lower = new int[w * h / 2];

    // 2. Read the upper_triangular array from the second line
    for (int i = 0; i < (w * h / 2 + h); ++i) {
        file >> upper[i];
    }

    // 3. Read the lower_triangular array from the third line
    for (int i = 0; i < (w * h / 2); ++i) {
        file >> lower[i];
    }

    file.close();
    return SecretImage(w, h, upper, lower);
}

// Returns a pointer to the upper triangular part of the secret image.
int* SecretImage::get_upper_triangular() const {
    return upper_triangular;
}

// Returns a pointer to the lower triangular part of the secret image.
int* SecretImage::get_lower_triangular() const {
    return lower_triangular;
}

// Returns the width of the secret image.
int SecretImage::get_width() const {
    return width;
}

// Returns the height of the secret image.
int SecretImage::get_height() const {
    return height;
}
