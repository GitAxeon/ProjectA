#include "LayerStack.hpp"

#include <iostream>

namespace ProjectA
{
    void LayerStack::Clear()
    {
        for(Layer* layer : m_Layers)
        {
            delete layer;
        }

        m_Layers.clear();
    }

    Layer* LayerStack::Push(Layer* layer)
    {
        m_Layers.push_back(layer);
        return layer;
    }

    void LayerStack::Pop()
    {
        if(m_Layers.size() == 0)
            return;
            
        m_Layers[m_Layers.size() - 1]->OnDetach();
        m_Layers.pop_back();
    }
}