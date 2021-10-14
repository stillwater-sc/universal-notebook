#pragma once

#include <iostream>
#include <iomanip>

// Set include paths
#pragma cling add_include_path("/home/jovyan/universal/include/")

// Custom mime type image::png
#include <string>
#include <fstream>
#include "xtl/xbase64.hpp"
#include "nlohmann/json.hpp"

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

    nl::json mime_bundle_repr(const png& i)
    {
        auto bundle = nl::json::object();
        bundle["image/png"] = xtl::base64encode(i.m_buffer.str());
        return bundle;
    }
}
