# Description

This project is to create an agent which can servive on the wumpus world. Semantic tabulex is the main component of
the project.

# Background

The Wumpus world is a simple world example to illustrate the worth of a knowledge-based agent and to represent knowledge representation.
It was inspired by a video game Hunt the Wumpus by Gregory Yob in 1973.

The Wumpus world is a cave which has 4/4 rooms connected with passageways. So there are total 16 rooms which are connected with each other.
We have a knowledge-based agent who will go forward in this world. The cave has a room with a beast which is called Wumpus, who eats anyone
who enters the room. The Wumpus can be shot by the agent, but the agent has a single arrow. In the Wumpus world, there are some Pits rooms
which are bottomless, and if agent falls in Pits, then he will be stuck there forever. The exciting thing with this cave is that in one
room there is a possibility of finding a heap of gold. So the agent goal is to find the gold and climb out the cave without fallen into
Pits or eaten by Wumpus. The agent will get a reward if he comes out with gold, and he will get a penalty if eaten by Wumpus or falls in the pit.

# Installation

In order to use or make changes to this repository, you need to meet and follow the following requirements
* pre-requests
    * g++ compiler
    * git
    * An editor of your choice
* Once the above requirements are fulfilled, do the following
    * Clone the repository
    ```bash
        git clone https://github.com/yitbarek123/wumpus.git
    ```
    * Navigate to the directory
    ```bash
        cd wumpus
    ```


                        
                        pit do not exist
    ( (game[i][j+1]) != (b or (b and s)) or (game[i+1][j])!=(b or (b and s)) ) => (game[i+1][j+1]!=pit)
                         wumpus exist
    ( (game[i][j+1]) == (s or (b and s)) or (game[i+1][j])==(s or (b and s)) ) => (game[i+1][j+1]==wumpus)

 
                        semantix taublex
          let z= no pit at i+1, j+1
              y= no stinky at i,j+1
              x= no stincky at i+1,j
          x or y => z
              |
              |
              z=f which means stincky?((i+1,j)and(i+1,j+2)and(i+2,j+1)and(i,j+1))=T
              |
              x=t
              |
              nostincky?(i+1,j)=t and nostincky?(i,j+1)=t
 Therefore, there is a contradiction for both x=t and z=f exist
              