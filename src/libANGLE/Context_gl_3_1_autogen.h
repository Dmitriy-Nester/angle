// GENERATED FILE - DO NOT EDIT.
// Generated by generate_entry_points.py using data from gl.xml.
//
// Copyright 2019 The ANGLE Project Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.
//
// Context_gl_3_1_autogen.h: Creates a macro for interfaces in Context.

#ifndef ANGLE_CONTEXT_GL_3_1_AUTOGEN_H_
#define ANGLE_CONTEXT_GL_3_1_AUTOGEN_H_

#define ANGLE_GL_3_1_CONTEXT_API                                                    \
    void getActiveUniformName(GLuint program, GLuint uniformIndex, GLsizei bufSize, \
                              GLsizei *length, GLchar *uniformName);                \
    void primitiveRestartIndex(GLuint index);                                       \
    void texBuffer(GLenum target, GLenum internalformat, GLuint buffer);

#endif  // ANGLE_CONTEXT_API_3_1_AUTOGEN_H_
