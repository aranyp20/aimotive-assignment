# aimotive-assignment

## Compilation

A single CMakeLists is available in the root directory (run binary created by CMake: ./aimotive). No extrernal dependencies needed.

## About the solution

The program follows object oriented design. The main algorithm is a recursive, dynamic programming method. This algorithm enters a field (initially the enter point) passing the current shortest path to the current field (0 if it enters the enter point) + the distance between the two cells. If the given field was not entered before, or the current path to it is shorter than the current shortest path to it, then the shortest path stored in this field is refreshed, and the algorithm enters all of it's neighbors. Obviously the fields behaviour upon being entered is different by field type.

## Exception handling

The program is not prepared for handling invalid input, and will result in unintended behaviour.
 
