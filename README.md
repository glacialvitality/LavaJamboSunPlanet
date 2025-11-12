This works with Super Mario Galaxy 2 (SB4E01). Not sure about other regions.

To set up this object, follow these steps:

A valid Path ID is required for this to work properly; the Path ID refers to the identifier assigned to a movement path in the level editor, and you can obtain or set it by selecting the desired path and noting its assigned ID value. For the sake of this example, it's set to 0.

SW_A -> Controls the initial movement along the path. Movement continues until it reaches a path point where path_arg1 is set to 1 (for example, if you want the movement to stop at the third point, set path_arg1 to 1 at that point). For instance, if your path has nine points and you want SW_A to stop at the third, set path_arg1 = 1 for the third point and 0 for the others.
SW_B -> Secondary movement. This movement follows the assigned path until it reaches the end. For example, if you set SW_B to follow Path ID 0, it will continue moving along that path until the final point is reached.

Speed can be determined via path_arg0.
Whether movement ends (SW_A) can be determined via path_arg1. (-1 means do not stop here)

If you're still not understanding this, and you have a copy of Super Mario Galaxy (2007), look in the HellShellZone in the level editor.

Somebody please add documentation to the SMGCommunity database, for the love of all that is holy...