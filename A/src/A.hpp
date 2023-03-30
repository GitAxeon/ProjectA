#pragma once
#include "Application.hpp"
#include "Window.hpp"
#include "Layer.hpp"
#include "LayerStack.hpp"
#include "Rendering.hpp"
#include "Color.hpp"

#include <forward_list>

namespace ProjectA
{
    extern std::forward_list<Window*> g_Windows;
    extern Configuration g_Configuration;
    extern bool g_KeepOpen;
    extern size_t g_WindowCount;
}