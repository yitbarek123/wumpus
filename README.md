This project is to create an agent which can servive on the wumpus world. Semantic tabulex is the main component of
the project.
                        
                        
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
              
