#include "uniform_texture.hh"
#include "color.hh"

TextureInfos UniformTexture::GetTextureInfos(Point3 point)
{
    return TextureInfos {color, diffuse, 0};
}