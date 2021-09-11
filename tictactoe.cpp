#include <iostream>
#include <stdlib.h>//for random choose random character;
#include <ctime> //for time 
using namespace std;
char current_marker;
int current_player;
char board[3][3]={
    {'1','2','3'},
    {'4','5','6'},
    {'7','8','9'},
    };
void drawBoard(){
    cout<<board[0][0]<<" | "<<board[0][1]<<" | "<<board[0][2]<<endl;
    cout<<"----------\n";
    cout<<board[1][0]<<" | "<<board[1][1]<<" | "<<board[1][2]<<endl;
    cout<<"----------\n";
    cout<<board[2][0]<<" | "<<board[2][1]<<" | "<<board[2][2]<<endl;
}
bool placedmarker(int slot){
    int row;
    int col;
    if(slot%3==0){
        row=(slot/3)-1;
        col=2;
    }
    else{
        row=slot/3;
        col=slot%3-1;
    } 
    if(board[row][col]!='X' && board[row][col]!='O'){
        return true;
        board[row][col]=current_marker;
    }
    return false;
}
void swap_player_and_marker(){
    if(current_marker=='X') current_marker='O';
    else{
        current_marker ='X';
    }
    if(current_player==1) current_player=0;
    else{
        current_player =1;
    }
}
int winner(){
    for(int i=0;i<3;i++){
        if(board[i][0]==board[i][1] && board[i][1]==board[i][2])return current_player;
        if(board[0][i]==board[1][1] && board[1][i]==board[2][i]) return current_player;
    }
    if(board[0][0]==board[1][1]&& board[1][1]==board[2][2])return current_player;
    if(board[0][2]==board[1][1]&& board[1][1]==board[2][0])return current_player;

    return 0;
}
void game(){
    cout<<"player One, choose your marker: ";
    char marker_p1;
    cin>>marker_p1;
    current_player=1;
    current_marker=marker_p1;
    drawBoard();
    int player_won;
    for(int i=0;i<9;i++){
        cout<<"it's player "<<current_player <<"'s turn. enter your slot ";
        int slot;
        cin>>slot;
        if(slot<1 || slot>9){
            cout<<"this is not a valid slot try another slot";
            i--;
            continue;
        }
        if(!placedmarker(slot)){cout<<"that slot occupied try another slot ";i--;continue;};
        drawBoard();
        player_won=winner();
        if(player_won==1){
            cout<<"player one won! congratulations"<<endl;
            break;
        }
        if(player_won==2){
            cout<<"player two won! congratulations"<<endl;
            break;
        }
        swap_player_and_marker();
    }
    if(player_won==0) cout<<"this is a  tie game!"<<endl;
    

}
int main(){
    srand(time(NULL));
    // cout<<rand();
    
    // (l,u)=(rand()%(u-l+1))+l;//formula to generate between the range;l=lower and u = upper;
    // (rand()%(10-1+1))+1;
    cout<<(rand()%(10-1+1))+1;
    // game();
    return 0;
}