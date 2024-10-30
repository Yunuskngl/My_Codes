#include "Crypto.h"
#include "GrayscaleImage.h"


std::vector<int> Crypto::extract_LSBits(SecretImage& secret_image, int message_length) {
    std::vector<int> LSB_array;
    
    // 1. Reconstruct the SecretImage to a GrayscaleImage.
    GrayscaleImage grayscale_img = secret_image.reconstruct();
    
    // 2. Calculate the image dimensions.
    int width = grayscale_img.get_width();
    int height = grayscale_img.get_height();
    
    // 3. Determine the total bits required based on message length (7 bits per character).
    int total_bits_needed = message_length * 7;

    // 4. Ensure the image has enough pixels to store the message.
    if (width * height < total_bits_needed) {
        throw std::runtime_error("Image does not have enough pixels for the message.");
    }
    
    // 5. Extract LSBs from the image pixels and store in LSB_array.
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            if (LSB_array.size() >= total_bits_needed) break; // Ensure we stop when we have enough bits
            
            int pixel_value = grayscale_img.get_pixel(i, j);
            int LSB = pixel_value & 1; // Get the least significant bit
            LSB_array.push_back(LSB);
        }
    }
    
    return LSB_array;
}




std::string Crypto::decrypt_message(const std::vector<int>& LSB_array) {
    std::string message;

    // 1. Verify that the LSB array size is a multiple of 7.
    if (LSB_array.size() % 7 != 0) {
        throw std::runtime_error("LSB array size is not a multiple of 7.");
    }

    // 2. Convert each group of 7 bits into an ASCII character.
    for (size_t i = 0; i < LSB_array.size(); i += 7) {
        int char_value = 0;
        for (int j = 0; j < 7; ++j) {
            char_value |= (LSB_array[i + j] << (6 - j)); // Combine the bits to form the character
        }
        message += static_cast<char>(char_value); // Convert to ASCII and append to message
    }

    // 3. Return the resulting message.
    return message;
}


// Encrypt message by converting ASCII characters into LSBs
std::vector<int> Crypto::encrypt_message(const std::string& message) {
    std::vector<int> LSB_array;

    // 1. Convert each character of the message into a 7-bit binary representation.
    for (char c : message) {
        std::bitset<7> bits(static_cast<int>(c)); // Convert character to 7-bit binary
        for (int i = 6; i >= 0; --i) {
            LSB_array.push_back(bits[i]); // Collect bits into LSB_array
        }
    }

    // 2. Return the array of bits.
    return LSB_array;
}


// Embed LSB array into GrayscaleImage starting from the last bit of the image
SecretImage Crypto::embed_LSBits(GrayscaleImage& image, const std::vector<int>& LSB_array) {
    // 1. Ensure the image has enough pixels to store the LSB array.
    int total_pixels = image.get_width() * image.get_height();
    if (LSB_array.size() > total_pixels) {
        throw std::runtime_error("Image does not have enough pixels to store the message.");
    }

    // 2. Iterate over the image pixels, embedding LSBs from the array.
    int bit_index = 0;
    for (int i = 0; i < image.get_height() && bit_index < LSB_array.size(); ++i) {
        for (int j = 0; j < image.get_width() && bit_index < LSB_array.size(); ++j) {
            int pixel_value = image.get_pixel(i, j);
            int new_pixel_value = (pixel_value & ~1) | LSB_array[bit_index]; // Embed LSB into pixel
            image.set_pixel(i, j, new_pixel_value);
            ++bit_index;
        }
    }

    // 3. Return a SecretImage object constructed from the given GrayscaleImage.
    return SecretImage(image);
}

