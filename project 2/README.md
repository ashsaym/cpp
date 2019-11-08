<h1>Distance and Neighbouring Points in c++</h1>
<p> Modern vehicles (cars, industrial trucks, planes, robots, ...) have camera, infrared, laser, radar, ... sensors to continuously scan obstacles in the direction of movement. Their data are needed for distance, collision avoidance, breaking assistance, ... systems. In this task a simplified version of obstacles shall be modeled by points detected by an imaginary sensor system placed in the front and middle of the vehicle as origin of a relative local two dimensional cartesian coordinate system. Arbitrary many of such obstacles/points in front of a vehicle shall be stored in a list. This list shall be sorted by the Euclidian distance from the origin (see picure above and examples below). </p>

<h2>Subtask 1</h2>
<p>To simply identify them each obstacle/point shall store a string ("A", "B", ... in example above), its coordinate (x, y) in the local coordinate system and its distance to the origin. Write a type definition for a structure with these four data as well as a pointer to the next list element as components/variables of the structure.</p>

<h2>Subtask 2</h2>
<p>
Write a function to calculate the Euclidian distance d of two obstacles/points P1 and P2 with coordinates (x1,y1) and (x2,y2) by the formula: 
<math xmlns="http://www.w3.org/1998/Math/MathML">
  <mi>d</mi>
  <mo>=</mo>
  <msqrt>
    <mo stretchy="false">(</mo>
    <msub>
      <mi>x</mi>
      <mn>1</mn>
    </msub>
    <mo>&#x2212;<!-- − --></mo>
    <msub>
      <mi>x</mi>
      <mn>2</mn>
    </msub>
    <msup>
      <mo stretchy="false">)</mo>
      <mn>2</mn>
    </msup>
    <mo>+</mo>
    <mo stretchy="false">(</mo>
    <msub>
      <mi>y</mi>
      <mn>1</mn>
    </msub>
    <mo>&#x2212;<!-- − --></mo>
    <msub>
      <mi>y</mi>
      <mn>2</mn>
    </msub>
    <msup>
      <mo stretchy="false">)</mo>
      <mn>2</mn>
    </msup>
  </msqrt>
</math>
 and return d as function value.</p>

<h2>Subtask 1</h2>

<h2>Subtask 1</h2>

<h2>Subtask 1</h2>

<h2>Subtask 1</h2>