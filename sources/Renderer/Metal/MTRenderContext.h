/*
 * MTRenderContext.h
 * 
 * This file is part of the "LLGL" project (Copyright (c) 2015-2018 by Lukas Hermanns)
 * See "LICENSE.txt" for license information.
 */

#ifndef LLGL_MT_RENDER_CONTEXT_H
#define LLGL_MT_RENDER_CONTEXT_H


#import <MetalKit/MetalKit.h>

#include <LLGL/Window.h>
#include <LLGL/RenderContext.h>


namespace LLGL
{


class MTRenderContext : public RenderContext
{

    public:

        /* ----- Common ----- */

        MTRenderContext(
            id<MTLDevice>                   device,
            RenderContextDescriptor         desc,
            const std::shared_ptr<Surface>& surface
        );

        ~MTRenderContext();

        void Present() override;
    
        /* ----- Extended functions ----- */
    
        void SetCommandBufferForPresent(id<MTLCommandBuffer> commandBuffer);

    private:
    
        bool OnSetVideoMode(const VideoModeDescriptor& videoModeDesc) override;
        bool OnSetVsync(const VsyncDescriptor& vsyncDesc) override;

        MTKView*                view_           = nullptr;
        id<MTLCommandBuffer>    commandBuffer_  = nil;

};


} // /namespace LLGL


#endif



// ================================================================================