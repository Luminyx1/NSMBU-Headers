#pragma once

#include <common/aglShaderProgramArchive.h>
#include <heap/seadHeap.h>

class MosaicFilter
{
public:
    static void initializeShader(agl::ShaderProgramArchive* p_archive, sead::Heap* heap);
};
