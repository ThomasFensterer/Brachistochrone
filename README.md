# Brachistochrone

This programming/electornics project was created in 2021 to present at the BergamoScienza science fair. 

## ⚛️ Physical Principle

The Brachistochrone (from the Greek brákhistos "shortest" and khrónos "time") is the curve of fastest descent.
It defines the mathematical path that will carry an object from a starting point $A$ to a lower ending point $B$ in the least amount of time, moving only under the influence of constant gravity and without friction.

This experiment also demonstrates another porperty of this curve which is the Tautochrone: which implies that from any starting point along the curve, the time required to reach the ending point $B$ remains constant.

These properties are verified confronting the times obtained by different metal balls along 3 different tracks (for the brachistochrone) and from different starting points along the cycloid/brachistochrone curve (for the tautochrone).

## 🤖 Automation

To make the demonstration interactive and perfectly repeatable, the whole model was automated through the use of an Arduino Uno board.

- Release Mechanism: The Uno manages the simultaneous release of the spheres across the different tracks (straight line, cycloid, steep descent) using a button-activated servo motor connected to a metal bar holding the spheres in place.

- Timing System: At the finish line, photodiodes are placed below the tracks. These get covered by a balck cardboard flap which signals the arrival of the sphere.

- Experiment Switching: To select the desired experiment to perform an additional button selects the operation mode (Brachistochrone/Tautochrone).

- Result Visualization: The different times are recorded and made visible through an LCD screen placed for the viewers.
