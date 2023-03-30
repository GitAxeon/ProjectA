#include "LayerStack.hpp"

#include <iostream>

namespace ProjectA
{
    void LayerStack::Clear()
    {
        std::cout << "Clearing layerstack\n";

        for(Layer* layer : m_Layers)
        {
            layer->OnDetach();
            delete layer;
        }
    }

    void LayerStack::Push(Layer* layer)
    {
        m_Layers.push_back(layer);
        layer->OnAttach();
    }

    void LayerStack::Pop()
    {
        if(m_Layers.size() == 0)
            return
            
        m_Layers[m_Layers.size() - 1]->OnDetach();
        m_Layers.pop_back();
    }

    
}