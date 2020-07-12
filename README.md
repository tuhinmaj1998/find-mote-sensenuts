# Find SENSEnuts motes using trilteration

Run the codes to implement a testbed of localisation.
The idea is first two sensors are used to measure the relation between distance and link quality.
Next 3 sensors are placed with known coordinates and verify the 4th one's position.

You needs:
Hardware: Minimum 4 SENSEnuts motes and a computer
Software: SENSEnuts GUI and Matlab

5 codes are there.

Among which 4 codes are for sensenuts and remaining one code is for matlab.
1. bcast_coord -> Coordinators when measuring relation between distance and lq.
2. bcast_panCoord -> Pan-Coordinators when measuring relation between distance and lq.
3. mbr_coord -> 3 Coordinators in trilateration
4. mbr_panCoord -> 4th unknown motes.
5. Matlab_code.
