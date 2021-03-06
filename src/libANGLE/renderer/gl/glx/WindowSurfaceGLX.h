//
// Copyright (c) 2015 The ANGLE Project Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.
//

// WindowSurfaceGLX.h: GLX implementation of egl::Surface for windows

#ifndef LIBANGLE_RENDERER_GL_GLX_WINDOWSURFACEGLX_H_
#define LIBANGLE_RENDERER_GL_GLX_WINDOWSURFACEGLX_H_

#include "libANGLE/renderer/gl/glx/DisplayGLX.h"
#include "libANGLE/renderer/gl/glx/SurfaceGLX.h"
#include "libANGLE/renderer/gl/glx/platform_glx.h"

namespace rx
{

class DisplayGLX;
class FunctionsGLX;

class WindowSurfaceGLX : public SurfaceGLX
{
  public:
    WindowSurfaceGLX(const egl::SurfaceState &state,
                     const FunctionsGLX &glx,
                     DisplayGLX *glxDisplay,
                     Window window,
                     Display *display,
                     glx::FBConfig fbConfig);
    ~WindowSurfaceGLX() override;

    egl::Error initialize(const egl::Display *display) override;
    egl::Error makeCurrent(const gl::Context *context) override;

    egl::Error swap(const gl::Context *context) override;
    egl::Error postSubBuffer(const gl::Context *context,
                             EGLint x,
                             EGLint y,
                             EGLint width,
                             EGLint height) override;
    egl::Error querySurfacePointerANGLE(EGLint attribute, void **value) override;
    egl::Error bindTexImage(const gl::Context *context,
                            gl::Texture *texture,
                            EGLint buffer) override;
    egl::Error releaseTexImage(const gl::Context *context, EGLint buffer) override;
    void setSwapInterval(EGLint interval) override;

    EGLint getWidth() const override;
    EGLint getHeight() const override;

    EGLint isPostSubBufferSupported() const override;
    EGLint getSwapBehavior() const override;

    egl::Error checkForResize() override;
    glx::Drawable getDrawable() const override;

  private:
    bool getWindowDimensions(Window window, unsigned int *width, unsigned int *height) const;

    Window mParent;
    unsigned int mParentWidth, mParentHeight;
    Window mWindow;
    Display *mDisplay;

    const FunctionsGLX &mGLX;
    DisplayGLX *mGLXDisplay;

    glx::FBConfig mFBConfig;
    glx::Window mGLXWindow;

    SwapControlData mSwapControl;
};

}  // namespace rx

#endif  // LIBANGLE_RENDERER_GL_GLX_WINDOWSURFACEGLX_H_
