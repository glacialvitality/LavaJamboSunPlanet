#include "LavaJamboSunPlanet.h"

//Documentation: either refer to LavaJamboSunPlanet.h or the README.md in the module's root folder.
namespace NrvLavaJamboSunPlanet {
    FULL_NERVE(HostTypeWait, LavaJamboSunPlanet, Wait);
    FULL_NERVE(HostTypePause, LavaJamboSunPlanet, Wait);
    FULL_NERVE(HostTypeMove, LavaJamboSunPlanet, Move);
};

LavaJamboSunPlanet::LavaJamboSunPlanet(const char* pName) : LiveActor(pName) {
    mBloomModel = nullptr;
    mLodCtrl = nullptr;
    _94 = 0.0f;
    _98.setAll(0.0f);
}

void LavaJamboSunPlanet::init(const JMapInfoIter& rIter) {
    MR::initDefaultPos(this, rIter);
    /* 
    MR::processInitFunction("LavaJamboSunPlanet", nullptr, nullptr, false); 
    This function is supposed to be used, but thorws errors so falling back to the old one for now.
    If anyone can figure this out, open a pull request.
    */
    initModelManagerWithAnm("LavaJamboSunPlanet", nullptr, nullptr, false); 
    initHitSensor(1);
    HitSensor* bodySensor = MR::addBodyMessageSensorMapObj(this);
    MR::initCollisionParts(this, "LavaJamboSunPlanet", bodySensor, nullptr);
    initNerve(&NrvLavaJamboSunPlanet::HostTypeWait::sInstance, 0);
    initRailRider(rIter);
    MR::initAndSetRailClipping(&_98, this, 100.0f, 500.0f);
    MR::needStageSwitchReadA(this, rIter);
    MR::needStageSwitchReadB(this, rIter);
    MR::connectToScenePlanet(this);
    mBloomModel = MR::createBloomModel(this, getBaseMtx());
    initSound(4, false, false, false);
    MR::setClippingTypeSphereContainsModelBoundingBox(this, 100.0f);
    MR::setClippingFarMax(this);
    MR::startBtk(this, "LavaJamboSunPlanet");
    mLodCtrl = MR::createLodCtrlPlanet(this, rIter, -1.0f, -1);
    MR::tryRegisterDemoCast(this, rIter);
    makeActorAppeared();
}

void LavaJamboSunPlanet::initAfterPlacement() {
    MR::moveCoordAndTransToRailPoint(this, 0);
}

void LavaJamboSunPlanet::control() {
    mLodCtrl->update();
}

void LavaJamboSunPlanet::exeWait() {
    if (isNerve(&NrvLavaJamboSunPlanet::HostTypeWait::sInstance) && MR::isOnSwitchA(this)) {
        setNerve(&NrvLavaJamboSunPlanet::HostTypeMove::sInstance);
        return;
    }
    if ( isNerve(&NrvLavaJamboSunPlanet::HostTypePause::sInstance) && MR::isOnSwitchB(this)) {
        setNerve(&NrvLavaJamboSunPlanet::HostTypeMove::sInstance);
    }
}

void LavaJamboSunPlanet::exeMove() {
    MR::getMapPartsArgMoveSpeed(&_94, this);
    _94 *= 0.1f;
    MR::moveCoordAndFollowTrans(this, _94);
    MR::startLevelSound(this, "SE_AT_LV_JUMBO_SUN_MOVE", -1, -1, -1);
    s32 v3 = -1;
    MR::getCurrentRailPointArg1NoInit(this, &v3);
    if (v3 == 1) {
        setNerve(&NrvLavaJamboSunPlanet::HostTypePause::sInstance);
    } else if  (MR::isRailReachedGoal(this)) {
        setNerve(&NrvLavaJamboSunPlanet::HostTypeWait::sInstance);
    }
}

LavaJamboSunPlanet::~LavaJamboSunPlanet() {
}