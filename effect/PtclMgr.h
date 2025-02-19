#pragma once

#include <container/seadPtrArray.h>
#include <container/seadTList.h>
#include <heap/seadDisposer.h>

namespace sead { namespace ptcl {

class PtclSystem;

} } // namespace sead::ptcl

namespace nw { namespace eft {

struct EmitterInstance;

} } // namespace nw::eft

namespace agl {

class TextureSampler;

namespace lyr {

class RenderInfo;

} } // namespace agl::lyr

class LevelEffect;
class PtclLightMgr;

class PtclMgr
{
    SEAD_SINGLETON_DISPOSER(PtclMgr)

public:
    PtclMgr();
    ~PtclMgr();

    void cleanUp();

    sead::ptcl::PtclSystem* getPtclSystem()
    {
        return mpPtclSystem;
    }

    void draw(const agl::lyr::RenderInfo& render_info, u32 type, const sead::PtrArray<nw::eft::EmitterInstance>* p_emitters = nullptr);

    u8 getEmitterSetGroupID(s32 set_id, u32 res_id = 0) const;

    // Address: 0x022ADA08
    void setFrameBufferTexture(const agl::TextureSampler& texture, f32 x_offset = 0.0f, f32 y_offset = 0.0f, f32 x_scale = 1.0f, f32 y_scale = 1.0f);

private:
    static u32 userDataToType_(u16 user_data);

private:
    sead::ptcl::PtclSystem*                             mpPtclSystem;
    void*                                               mpPtclParallelTbl;
    PtclLightMgr*                                       mpLightMgr;
    void*                                               mpUserShaderParamTbl;
    sead::TList<LevelEffect*>                           mEffects;
    sead::FixedPtrArray<nw::eft::EmitterInstance, 256>  mpEmitter1;
    sead::FixedPtrArray<nw::eft::EmitterInstance, 256>  mpEmitter2;
    s32                                                 mPlayerId;
    bool                                                mIsUseDisplayList;
    bool                                                mIsDrawDisable;
    bool                                                mIsUseParallel;
};
static_assert(sizeof(PtclMgr) == 0x84C);
