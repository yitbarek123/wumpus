This project is to create an agent which can servive on the wumpus world. Semantic tabulex is the main component of
the project.
                        
                        
                        pit do not exist
    ( (game[i][j+1]) != (b or (b and s)) or (game[i+1][j])!=(b or (b and s)) ) => (game[i+1][j+1]!=pit)
                         wumpus exist
    ( (game[i][j+1]) == (s or (b and s)) or (game[i+1][j])==(s or (b and s)) ) => (game[i+1][j+1]==wumpus)

 
