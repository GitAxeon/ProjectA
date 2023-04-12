#pragma once

#include <stb_image.h>
#include <string>

#include <cstdint>

enum class PixelFormat
{
    None,
    RGBA32
};

class Image
{
public:
    Image() :
        m_Width(0), m_Height(0), m_Channels(0), m_PixelFormat(PixelFormat::None), m_Pixels(nullptr)
    {
        
    }

    Image(uint32_t width, uint32_t height, int channels, PixelFormat format, uint8_t* pixels)
        : m_Width(width), m_Height(height), m_Channels(channels), m_PixelFormat(format), m_Pixels(pixels)
    {

    }

    ~Image()
    {
        delete m_Pixels;
    }

    uint32_t Width() const { return m_Width; }
    uint32_t Height() const { return m_Height; }
    uint8_t* GetPixels() const { return m_Pixels; }

private:
    uint32_t m_Width;
    uint32_t m_Height;
    int m_Channels;
    PixelFormat m_PixelFormat;
    
    uint8_t* m_Pixels;
};