#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<int> robotsLostX;
vector<int> robotsLostY;

int acotadoX;
int acotadoY;

char orientacionRobot;
string instrucciones;

bool lost=false;

int posicionX;
int posicionY;

void changeDir(char a){
    switch(a){
        case 'R':{
            if(orientacionRobot == 'N') orientacionRobot = 'E';
            else if(orientacionRobot == 'S') orientacionRobot = 'W';
            else if(orientacionRobot == 'E') orientacionRobot = 'S';
            else if(orientacionRobot == 'W') orientacionRobot = 'N';
            break;
        }
        case 'L':{
            if(orientacionRobot == 'N') orientacionRobot = 'W';
            else if(orientacionRobot == 'S') orientacionRobot = 'E';
            else if(orientacionRobot == 'E') orientacionRobot = 'N';
            else if(orientacionRobot == 'W') orientacionRobot = 'S';
            break;
        }
    }
}

bool canMove(int x,int y){
    if( orientacionRobot == 'N'){
        if ((y+1)>acotadoY) return false;
    }
    else if( orientacionRobot == 'W') {
        if ((x-1)<0) return false;
    }
    else if( orientacionRobot == 'S') {
        if((y-1)<0) return false;
    }
    else if( orientacionRobot == 'E') {
        if((x+1)>acotadoX) return false;
    }
    return true;
}

bool zonaAroma(int x, int y){
    for (int i = 0; i < robotsLostX.size(); ++i) {
        if(x == robotsLostX[i] && y == robotsLostY[i]){
            return true;
        }
    }
    return false;
}

void move(){
    if(canMove(posicionX,posicionY)){
        if (orientacionRobot == 'N') posicionY++;
        else if (orientacionRobot == 'S') posicionY--;
        else if (orientacionRobot == 'E') posicionX++;
        else if (orientacionRobot == 'W') posicionX--;
    }
    else if(!zonaAroma(posicionX, posicionY)) {
        lost = true;
        robotsLostX.push_back(posicionX);
        robotsLostY.push_back(posicionY);
    }
}

int main() {
    cin>>acotadoX>>acotadoY;
    while(cin>>posicionX>>posicionY>>orientacionRobot){
        cin>>instrucciones;
        for(int i = 0; i < instrucciones.length(); ++i) {

            if (instrucciones[i] == 'L') changeDir('L');
            else if(instrucciones[i] == 'R') changeDir('R');
            else if (instrucciones[i] == 'F') move();

            if(lost) break;

        }
        if(lost) cout<<posicionX<<" "<<posicionY<<" "<<orientacionRobot<<" LOST"<<endl;

        else cout<<posicionX<<" "<<posicionY<<" "<<orientacionRobot<<endl;

        lost = false;

    }
    return 0;
}
