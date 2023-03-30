#include "A.hpp"

namespace ProjectA
{
    std::forward_list<Window*> g_Windows;
    Configuration g_Configuration;
    bool g_KeepOpen = true;
    size_t g_WindowCount = 0;
}