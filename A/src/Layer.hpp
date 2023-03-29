#pragma once

namespace ProjectA
{
    class Layer
    {
        virtual void OnDetach()     {}
        virtual void OnAttach()     {}

        virtual void OnEvent()      {}
        virtual void OnUpdate()     {}

        virtual void OnRender()     {}
        virtual void OnUIRender()   {}
    }
}