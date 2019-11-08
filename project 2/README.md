<h1>Distance and Neighbouring Points in c++</h1>
<p> Modern vehicles (cars, industrial trucks, planes, robots, ...) have camera, infrared, laser, radar, ... sensors to continuously scan obstacles in the direction of movement. Their data are needed for distance, collision avoidance, breaking assistance, ... systems. In this task a simplified version of obstacles shall be modeled by points detected by an imaginary sensor system placed in the front and middle of the vehicle as origin of a relative local two dimensional cartesian coordinate system. Arbitrary many of such obstacles/points in front of a vehicle shall be stored in a list. This list shall be sorted by the Euclidian distance from the origin (see picure above and examples below). </p>

<h2>Subtask 1</h2>
<p>To simply identify them each obstacle/point shall store a string ("A", "B", ... in example above), its coordinate (x, y) in the local coordinate system and its distance to the origin. Write a type definition for a structure with these four data as well as a pointer to the next list element as components/variables of the structure.</p>

<h2>Subtask 2</h2>
<p>
Write a function to calculate the Euclidian distance d of two obstacles/points P1 and P2 with coordinates (x1,y1) and (x2,y2) by the formula: 
d = \sqrt{(x_1 - x_2)^2 + (y_1 - y_2)^2}
and return d as function value.</p>

<h2>Subtask 3</h2>
<p>Write a function with a list of obstacles/points as first and one obstacle/point as second parameter calculating the neareast other obstacle/point to it and returning it as pointer. Take care that an obstacle/point does not return itself (distance 0) as well as that at least two obstacles/points need to exist, otherwise a null pointer nullptr shall be returned.</p>

<h2>Subtask 4</h2>
<p>Write a function with a list of obstacles/points sorted by distance from the origin of the coordinate system as first parameter and a pointer to a new obstacle/point as second parameter. In its body insert sorted this new obstacle/point into the list and return a pointer to the (new) head of the list of obstacles/points.</p>

<h2>Subtask 5</h2>
<p>Write a function to output formatted the list of obstacles/points (all numbers with six characters and two digits after decimal point). Beside the identifying string of the obstacle/point, its coordinates and its distance additionally the nearest neighbour obstacle/point to it shall be found and outputted (for each call the function from subtask 3; see example below).</p>

<h2>Subtask 6</h2>
<p>Write a function to delete the whole list of all obstacles/points completely on the heap.</p>

<h2>Subtask 7</h2>
<p>In a loop in function main arbitrary many of such obstacles/points shall be inputted and stored in a list sorted by distance in ascending order - call for each inputted obstacle/point the function from subtask 4. After the end of input output the list by calling the function from subtask 5. Last delete the whole list by calling the function from subtask 6.</p>

<h3>Only use C++ input and output, no calls of scanf or printf function, only new and delete (not malloc, calloc, realloc or free. </h3>