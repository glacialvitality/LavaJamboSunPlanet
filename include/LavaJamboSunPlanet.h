#pragma once
#include "Syati.h"

class PartsModel;

/*

@brief This object represents the LavaJamboSunPlanet, a moving planet-like object in the game.
It interacts with the stage switches and follows a correctly configured rail path.



@param PathID: The rail path that the LavaJamboSunPlanet will follow. Required.
@param SW_A: Activates the movement of the LavaJamboSunPlanet when turned ON.
@param SW_B: Resumes the movement of the LavaJamboSunPlanet from a paused state when turned ON.
@param Path_arg0: Determines the speed of the LavaJamboSunPlanet's movement along its rail path
@param Path_arg1: Determines the pause position of the LavaJamboSunPlanet on its rail path, ending SW_A's behavior.

Check the README.md for more details and cutscene information.
*/
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