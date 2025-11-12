#pragma once
#include "Syati.h"

class PartsModel;

class LavaJamboSunPlanet : public LiveActor {
public:
    LavaJamboSunPlanet(const char*);

    virtual ~LavaJamboSunPlanet();
    virtual void init(const JMapInfoIter &);
    virtual void initAfterPlacement();
    virtual void control();

    void exeWait();
    void exeMove();

    ModelObj* mBloomModel; //was PartsModel*
    LodCtrl* mLodCtrl;
    f32 _94;
    TVec3f _98;
};