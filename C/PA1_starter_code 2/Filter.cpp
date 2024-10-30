#include "Filter.h"
#include <algorithm>
#include <cmath>
#include <vector>
#include <numeric>
#include <math.h>

// Helper clamp function for C++11
template <typename T>
T clamp(T value, T min, T max) {
    if (value < min) return min;
    if (value > max) return max;
    return value;
}

// Mean Filter
void Filter::apply_mean_filter(GrayscaleImage& image, int kernelSize) {
    // 1. Copy the original image for reference.
    GrayscaleImage original_image = image;

    // 2. Define the kernel radius.
    int radius = kernelSize / 2;

    // 3. For each pixel in the image, calculate the mean of its neighbors.
    for (int i = 0; i < image.get_height(); ++i) {
        for (int j = 0; j < image.get_width(); ++j) {
            int sum = 0;
            int count = 0;

            // Iterate over the kernel area.
            for (int ki = -radius; ki <= radius; ++ki) {
                for (int kj = -radius; kj <= radius; ++kj) {
                    int ni = i + ki;
                    int nj = j + kj;

                    // Ensure that the neighbor pixel is within the image bounds.
                    if (ni >= 0 && ni < image.get_height() && nj >= 0 && nj < image.get_width()) {
                        sum += original_image.get_pixel(ni, nj);
                        count++;
                    }
                }
            }

            // 4. Calculate the mean value and update the pixel.
            int mean_value = sum / count;
            image.set_pixel(i, j, mean_value);
        }
    }
}

// Gaussian Smoothing Filter
void Filter::apply_gaussian_smoothing(GrayscaleImage& image, int kernelSize, double sigma) {
    // 1. Create the Gaussian kernel based on the given sigma.
    int radius = kernelSize / 2;
    std::vector<std::vector<double>> kernel(kernelSize, std::vector<double>(kernelSize));
    double sum = 0.0;

    // Calculate Gaussian kernel values.
    for (int i = -radius; i <= radius; ++i) {
        for (int j = -radius; j <= radius; ++j) {
            double exponent = -(i * i + j * j) / (2 * sigma * sigma);
            kernel[i + radius][j + radius] = std::exp(exponent);
            sum += kernel[i + radius][j + radius];
        }
    }

    // 2. Normalize the kernel.
    for (int i = 0; i < kernelSize; ++i) {
        for (int j = 0; j < kernelSize; ++j) {
            kernel[i][j] /= sum;
        }
    }

    // 3. Apply the Gaussian filter.
    GrayscaleImage original_image = image;
    for (int i = 0; i < image.get_height(); ++i) {
        for (int j = 0; j < image.get_width(); ++j) {
            double weighted_sum = 0.0;

            // Iterate over the kernel area.
            for (int ki = -radius; ki <= radius; ++ki) {
                for (int kj = -radius; kj <= radius; ++kj) {
                    int ni = i + ki;
                    int nj = j + kj;

                    // Ensure that the neighbor pixel is within the image bounds.
                    if (ni >= 0 && ni < image.get_height() && nj >= 0 && nj < image.get_width()) {
                        weighted_sum += original_image.get_pixel(ni, nj) * kernel[ki + radius][kj + radius];
                    }
                }
            }

            // Update the pixel with the smoothed value.
            image.set_pixel(i, j, static_cast<int>(std::round(weighted_sum)));
        }
    }
}


// Unsharp Masking Filter
void Filter::apply_unsharp_mask(GrayscaleImage& image, int kernelSize, double amount) {
    // 1. Apply Gaussian smoothing to create the blurred image.
    GrayscaleImage blurred_image = image;
    apply_gaussian_smoothing(blurred_image, kernelSize, 1.0); // Default sigma 1.0

    // 2. Apply the unsharp mask formula: original + amount * (original - blurred).
    for (int i = 0; i < image.get_height(); ++i) {
        for (int j = 0; j < image.get_width(); ++j) {
            int original_pixel = image.get_pixel(i, j);
            int blurred_pixel = blurred_image.get_pixel(i, j);
            int sharpened_pixel = original_pixel + static_cast<int>(amount * (original_pixel - blurred_pixel));

            // 3. Clip the values to ensure they are within the range [0-255].
            sharpened_pixel = clamp(sharpened_pixel, 0, 255);

            // Update the image with the sharpened pixel value.
            image.set_pixel(i, j, sharpened_pixel);
        }
    }
}

