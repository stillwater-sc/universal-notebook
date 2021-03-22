#pragma once

// Set include paths
#pragma cling add_include_path("/home/jovyan/universal/include")

// Include main header files
#include "/home/jovyan/universal/include/number/fixpnt/fixpnt"
#include "/home/jovyan/universal/include/number/posit/posit"

// Custom mime type image::png
#include <string>
#include <fstream>
#include "xtl/xbase64.hpp"
namespace image
{
    struct png
    {
        inline png(const std::string& filename)
        {
            std::ifstream fin(filename, std::ios::binary);
            m_buffer << fin.rdbuf();
        }

        std::stringstream m_buffer;
    };

    LibKet::utils::json mime_bundle_repr(const png& i)
    {
        auto bundle = LibKet::utils::json::object();
        bundle["image/png"] = xtl::base64encode(i.m_buffer.str());
        return bundle;
    }
}
