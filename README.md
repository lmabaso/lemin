
<img width="592" alt="screen shot 2018-09-12 at 10 35 58" src="https://user-images.githubusercontent.com/36439765/45412666-8b588d80-b677-11e8-8bfa-273747258fd9.png">

Summary: This project is meant to make you code an ant farm manager.

**EDIT:** The instructions for this project have since been changed meaning that my implementation would no longer pass. I used a overcomplicated method of storing the information which made the processing speed slow and it used only one path for all ants rather than using multiple paths to get to the end point faster. 

Lem-in was descibed in the brief as being a Hex-sym. A simulation of the movement of ants but was essentially a path finding task
as all the ants started in one room and needed to get to the end room without traffic jams meaning that there could only be one ant per
room at any given time and each ant could only move once per turn. I don't think ive ever heard of a real ant that waits its turn, that 
is irrelevant. 

<img width="326" alt="screen shot 2018-09-12 at 10 44 22" src="https://user-images.githubusercontent.com/36439765/45413129-b4c5e900-b678-11e8-9500-5a3233fb55ce.png">

Above is an example of a valid map.
A big part of this project was the error management. So checking for invalid maps, inputs, number of ants and other intricacies took 
some time. Once all the error checking was done we could move the ants. 
Below shows the output by lem-in first giving back the map, comments and commands then showing how the ants got across the map.
The colour was a bonus that I had built in if the ##colour or ##color commands were present.

<img width="467" alt="screen shot 2018-09-12 at 10 37 47" src="https://user-images.githubusercontent.com/36439765/45412761-c6f35780-b677-11e8-8bbf-3115846733bc.png">
