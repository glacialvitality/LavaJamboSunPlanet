This works with Super Mario Galaxy 2 (SB4E01). Not sure about other regions. Nintendo Switch port is not supported nor planned.

### Setup
You must add the following entries to your `ProductMapObjDataTable.bcsv`:
*LavaJamboSunPlanet* (ModelName, ClassName)

### Object Arguments
*Note that the current list of arguments may be subject to any corrections, if needed*

> **Path ID**<br>
A valid one is required for this to work properly; the Path ID refers to the identifier assigned to a movement path in the level editor, and you can obtain or set it by selecting the desired path and noting its assigned ID value. For the sake of this example, it's set to 0.<br><br>
 **SW_A**<br>
Controls the initial movement along the path. Movement continues until it reaches a path point where path_arg1 is set to 1 (for example, if you want the movement to stop at the third point, set path_arg1 to 1 at that point). For instance, if your path has nine points and you want SW_A to stop at the third, set path_arg1 = 1 for the third point and 0 for the others.<br><br>
**SW_B**<br>
Secondary movement. This movement follows the assigned path until it reaches the end. For example, if you set SW_B to follow Path ID 0, it will continue moving along that path until the final point is reached.<br><br>
**Path_arg0**<br>
Determines Speed of the planet's movement<br><br>
**Path_arg1**<br>
Determines whether movement initiated by SW_A ends. (Default -1)<br><br>
**Cutscene ID / Cast ID**<br>
Whether this object can take part in a cutscene. ActionType 5 activates its SW_A, and ActionType 6 activates its SW_B. <br>
<small>[You can read more about the different ActionTypes on the Luma's Workshop website.](https://www.lumasworkshop.com/wiki/Cutscenes#SMG2)</small>

If you're still not understanding how to set this object up correctly, and you have a copy of Super Mario Galaxy (2007), look in the `HellShellZone` in the level editor.

*Somebody please add documentation to the SMGCommunity database, for the love of all that is holy...*