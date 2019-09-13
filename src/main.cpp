#include <iostream>
using namespace std;

class wumpus{
    static int game[4][4];
    static int unsafe[4][2];
    static int traversed[16][2];


   public: void build_env(){
        int game[4][4];
        for(int i=0;i<4;i++)
        {for(int j=0;j<4;j++){
                game[i][j]=0;
            }}

        game[2][0]=-2;
        game[3][1]=-1;
        game[0][2]=-1;
        game[2][2]=-1;
        game[3][3]=100;

        for(int i=0;i<4;i++){
            for(int j=0;j<4;j++){
                if(game[i][j]==-2){
                    if((i+1<4)&&(game[i+1][j]!=-1)){
                        game[i+1][j]+=5;
                    }
                    if((j+1<4)&&(game[i][j+1]!=-1)){
                        game[i][j+1]+=5;
                    }
                    if((i-1>0)&&(game[i-1][j]!=-1)){
                        game[i-1][j]+=5;
                    }
                    if((j-1>0)&&(game[i][j-1]!=-1)){
                        game[i][j-1]+=5;
                    }
                }
                if(game[i][j]==-1){
                    if((i+1<4)&&(game[i+1][j]!=-2)&&(game[i+1][j])<6){
                        game[i+1][j]+=6;
                    }
                    if((j+1<4)&&(game[i][j+1]!=-2)&&(game[i][j+1])<6){
                        game[i][j+1]+=6;
                    }
                    if((i-1>0)&&(game[i-1][j]!=-2)&&(game[i-1][j])<6){
                        game[i-1][j]+=6;
                    }
                    if((j-1>0)&&(game[i][j-1]!=-2)&&(game[i][j-1])<6){
                        game[i][j-1]+=6;
                    }
                }
            }
        }
        cout<<"********************************"<<endl<<"|";
        for(int i=0;i<4;i++){
            for(int j=0;j<4;j++){
                if(game[i][j]==0){
                    cout<<"free"<<" "<<" | ";
                }
                if(game[i][j]==-1){
                    cout<<"pit"<<" "<<"  | ";
                }
                if(game[i][j]==-2){
                    cout<<"wumpus"<<""<<"| ";
                }
                if(game[i][j]==5){
                    cout<<"free"<<" "<<" | ";
                }
                if(game[i][j]==6){
                    cout<<"free"<<" "<<" | ";
                }
                if(game[i][j]==11){
                    cout<<"free"<<" "<<" | ";
                }
                if(game[i][j]>50){
                    cout<<"gold"<<" "<<" | ";
                }
            }
            cout<<endl;
            cout<<"********************************"<<endl;
            if(i<3){
                cout<<"|";}
        }
        play(game);

    }
    bool is_breadth(int i ,int j){
        if(game[i][j]==6||game[i][j]==11){
            return true;
        }
        return false;
    }

    bool is_stincky(int i,int j){
        if(game[i][j]==5||game[i][j]==1){
            return true;
        }
        return false;
    }

    bool is_both(int i, int j){
        if(game[i][j]==11){
            return true;
        }
        return false;
    }

    bool is_gold(int i, int j){
        if(game[i][j]>50){
            return true;
        }
        return false;
    }

    bool is_front_free(int i, int j){
        if(j<3){
            true;
        }
        false;
    }

    bool is_back_free(int i,int j){
        if(j>0){
            true;
        }
        false;
    }

    bool is_right_free(int i, int j){
        if((i+1)%4!=0){
            true;
        }
        false;
    }

    bool is_left_free(int i,int j){
        if(i%4!=0){
            true;
        }
        false;
    }

    void play(int game[][4]){
        int m=0;
        int n=0;
       cout<<"current position:"<<m<<n;


    }


};

int main() {
    wumpus obj;
    obj.build_env();
    return 0;
}
