#include <string>
#include <iostream>
#include <unordered_map>
#include <SFML/Graphics.hpp>
#include "Connector.hpp"
#include "ajedrez.h"
#include "cpu_player.h"

using namespace std;
using namespace sf;


int size = 56;
Vector2f offset(28,28);


// Piezas
Sprite f[32];
string position="";

int board[8][8] =
        {-1,-2,-3,-4,-5,-3,-2,-1,
         -6,-6,-6,-6,-6,-6,-6,-6,
         0, 0, 0, 0, 0, 0, 0, 0,
         0, 0, 0, 0, 0, 0, 0, 0,
         0, 0, 0, 0, 0, 0, 0, 0,
         0, 0, 0, 0, 0, 0, 0, 0,
         6, 6, 6, 6, 6, 6, 6, 6,
         1, 2, 3, 4, 5, 3, 2, 1};

string toChessNote(Vector2f p)
{
    string s = "";
    s += char(p.x/size+97);
    s += char(7-p.y/size+49);
    return s;
}
Vector2f toCoord(char a,char b)
{
    int x = int(a) - 97;
    int y = 7-int(b)+49;
    return Vector2f(x*size,y*size);
}
void move(string str)
{
    Vector2f oldPos = toCoord(str[0],str[1]);
    Vector2f newPos = toCoord(str[2],str[3]);

    for(int i=0;i<32;i++)
        if (f[i].getPosition()==newPos) f[i].setPosition(-100,-100);

    for(int i=0;i<32;i++)
        if (f[i].getPosition()==oldPos) f[i].setPosition(newPos);

    //castling       //if the king didn't move
    if (str=="e1g1") if (position.find("e1")==-1) move("h1f1");
    if (str=="e8g8") if (position.find("e8")==-1) move("h8f8");
    if (str=="e1c1") if (position.find("e1")==-1) move("a1d1");
    if (str=="e8c8") if (position.find("e8")==-1) move("a8d8");
}
void loadPosition(){
    int k=0;
    for(int i=0;i<8;i++)
        for(int j=0;j<8;j++){
            int n = board[i][j];
            if (!n){
                continue;
            }
            int x = abs(n)-1;
            int y = n>0?1:0;
            f[k].setTextureRect( IntRect(size*x,size*y,size,size) );
            f[k].setPosition(size*j,size*i);
            k++;
        }

    for(int i=0;i<position.length();i+=5)
        move(position.substr(i,4));
}
template <typename T>
void whatClassIs(T t){
    cout<<__PRETTY_FUNCTION__ <<endl;
}


int main(){
    //      Se crea la ventana
    RenderWindow window(VideoMode(504, 504), "Chess");

    //      Motor de ajedrez
    ConnectToEngine("stockfish.exe");

    Texture t1,t2;
    t1.loadFromFile("images/figures.png");
    t2.loadFromFile("images/board.png");

    //      Establecemos las piezas
    for(int i=0;i<32;i++){
        f[i].setTexture(t1);
    }
    //      Asignamos una variable a la imagen del tablero
    Sprite sBoard(t2);

    loadPosition();

    //      Creamos al jugador CPU
    cpu_player cpup(false);


    //      Asociar las piezas con el objeto
    Peon peon1({f[16].getPosition().x,f[16].getPosition().y}, {f[16].getPosition().x,f[16].getPosition().y}, 1, false, f[16]);
    Peon peon2({f[17].getPosition().x,f[17].getPosition().y}, {f[17].getPosition().x,f[17].getPosition().y}, 1, false, f[17]);
    Peon peon3({f[18].getPosition().x,f[18].getPosition().y}, {f[18].getPosition().x,f[18].getPosition().y}, 1, false, f[18]);
    Peon peon4({f[19].getPosition().x,f[19].getPosition().y}, {f[19].getPosition().x,f[19].getPosition().y}, 1, false, f[19]);
    Peon peon5({f[20].getPosition().x,f[20].getPosition().y}, {f[20].getPosition().x,f[20].getPosition().y}, 1, false, f[20]);
    Peon peon6({f[21].getPosition().x,f[21].getPosition().y}, {f[21].getPosition().x,f[21].getPosition().y}, 1, false, f[21]);
    Peon peon7({f[22].getPosition().x,f[22].getPosition().y}, {f[22].getPosition().x,f[22].getPosition().y}, 1, false, f[22]);
    Peon peon8({f[23].getPosition().x,f[23].getPosition().y}, {f[23].getPosition().x,f[23].getPosition().y}, 1, false, f[23]);
    Torre torre1({f[24].getPosition().x,f[24].getPosition().y}, {f[24].getPosition().x,f[24].getPosition().y}, 1, false, f[24]);
    Torre torre2({f[31].getPosition().x,f[31].getPosition().y}, {f[31].getPosition().x,f[31].getPosition().y}, 1, false, f[31]);
    Caballo caballo1({f[25].getPosition().x,f[25].getPosition().y}, {f[25].getPosition().x,f[25].getPosition().y}, 1, false, f[25]);
    Caballo caballo2({f[30].getPosition().x,f[30].getPosition().y}, {f[30].getPosition().x,f[30].getPosition().y}, 1, false, f[30]);
    Alfil alfil1({f[26].getPosition().x,f[26].getPosition().y}, {f[26].getPosition().x,f[26].getPosition().y}, 1, false, f[26]);
    Alfil alfil2({f[29].getPosition().x,f[29].getPosition().y}, {f[29].getPosition().x,f[29].getPosition().y}, 1, false, f[29]);
    Dama dama1({f[28].getPosition().x,f[28].getPosition().y}, {f[28].getPosition().x,f[28].getPosition().y}, 1, false, f[28]);
    Rey rey1({f[27].getPosition().x,f[27].getPosition().y}, {f[27].getPosition().x,f[27].getPosition().y}, 1, false, f[27]);


    Peon peon9({f[8].getPosition().x,f[8].getPosition().y}, {f[8].getPosition().x,f[8].getPosition().y}, 0, false, f[8]);
    Peon peon10({f[9].getPosition().x,f[9].getPosition().y}, {f[9].getPosition().x,f[9].getPosition().y}, 0, false, f[9]);
    Peon peon11({f[10].getPosition().x,f[10].getPosition().y}, {f[10].getPosition().x,f[10].getPosition().y}, 0, false, f[10]);
    Peon peon12({f[11].getPosition().x,f[11].getPosition().y}, {f[11].getPosition().x,f[11].getPosition().y}, 0, false, f[11]);
    Peon peon13({f[12].getPosition().x,f[12].getPosition().y}, {f[12].getPosition().x,f[12].getPosition().y}, 0, false, f[12]);
    Peon peon14({f[13].getPosition().x,f[13].getPosition().y}, {f[13].getPosition().x,f[13].getPosition().y}, 0, false, f[13]);
    Peon peon15({f[14].getPosition().x,f[14].getPosition().y}, {f[14].getPosition().x,f[14].getPosition().y}, 0, false, f[14]);
    Peon peon16({f[15].getPosition().x,f[15].getPosition().y}, {f[15].getPosition().x,f[15].getPosition().y}, 0, false, f[15]);
    Torre torre3({f[0].getPosition().x,f[0].getPosition().y}, {f[0].getPosition().x,f[0].getPosition().y}, 0, false, f[0]);
    Torre torre4({f[7].getPosition().x,f[7].getPosition().y}, {f[7].getPosition().x,f[7].getPosition().y}, 0, false, f[7]);
    Caballo caballo3({f[1].getPosition().x,f[1].getPosition().y}, {f[1].getPosition().x,f[1].getPosition().y}, 0, false, f[1]);
    Caballo caballo4({f[6].getPosition().x,f[6].getPosition().y}, {f[6].getPosition().x,f[6].getPosition().y}, 0, false, f[6]);
    Alfil alfil3({f[2].getPosition().x,f[2].getPosition().y}, {f[2].getPosition().x,f[2].getPosition().y}, 0, false, f[2]);
    Alfil alfil4({f[5].getPosition().x,f[5].getPosition().y}, {f[5].getPosition().x,f[5].getPosition().y}, 0, false, f[5]);
    Dama dama2({f[4].getPosition().x,f[4].getPosition().y}, {f[4].getPosition().x,f[4].getPosition().y}, 0, false, f[4]);
    Rey rey2({f[3].getPosition().x,f[3].getPosition().y}, {f[3].getPosition().x,f[3].getPosition().y}, 0, false, f[3]);


    bool isMove=false;
    float dx=0, dy=0;
    Vector2f oldPos,newPos;
    Vector2f piezaBorrada;
    string str;
    int n=0;

    cout<<"----"<<endl;
    auto dequex = cpup.posibilidadesDeTorre(torre1);
    cout<<"Tamanio: "<<dequex.size()<<endl;
    for (int i = 0; i < dequex.size(); ++i) {
        cout<<dequex[i].first<<" "<<dequex[i].second<<endl;
    }


    while (window.isOpen()){
        Vector2i pos = Mouse::getPosition(window) - Vector2i(offset);


        // Registrar el boton que se esta pulsando
        Event e;
        //De acuerdo al boton presionado se toma desicion
        while (window.pollEvent(e)){
            //      Cerrar ventana con boton "Close"
            if (e.type == Event::Closed)
                window.close();

            /*
            if (e.type == Event::KeyPressed){
                if (e.key.code == Keyboard::BackSpace){
                    if (position.length()>6) position.erase(position.length()-6,5); loadPosition();
                }
             }
             */
            //          Al presionar boton
            if (e.type == Event::MouseButtonPressed){
                //      Definir actividad al pulsar boton izquierdo del mouse
                if (e.key.code == Mouse::Left){
                    for(int i=0;i<32;i++){
                        if (f[i].getGlobalBounds().contains(pos.x,pos.y)){
                            isMove=true;
                            n=i;

                            dx=pos.x - f[i].getPosition().x;
                            dy=pos.y - f[i].getPosition().y;
                            oldPos  =  f[i].getPosition();
                        }
                    }
                }
            }
            //          Al soltar boton
            if (e.type == Event::MouseButtonReleased){
                if (e.key.code == Mouse::Left){
                    isMove=false;
                    Vector2f p = f[n].getPosition() + Vector2f(size/2,size/2);
                    newPos = Vector2f( size*int(p.x/size), size*int(p.y/size) );
                    str = toChessNote(oldPos)+toChessNote(newPos);
                    move(str);

                    switch (n) {
                        case 0:
                            torre3.setXNPos(newPos.x);
                            torre3.setYNPos(newPos.y);
                            if (torre3.MovimientoPermitido(f[32])){

                                f[n].setPosition(newPos);
                            }else{

                                f[n].setPosition(oldPos);
                            }
                            break;
                        case 1:
                            caballo3.setXNPos(newPos.x);
                            caballo3.setYNPos(newPos.y);
                            if (caballo3.MovimientoPermitido(f[32])){

                                f[n].setPosition(newPos);
                            }else{
                                f[n].setPosition(oldPos);
                            }
                            break;
                        case 2:
                            alfil3.setXNPos(newPos.x);
                            alfil3.setYNPos(newPos.y);
                            if (alfil3.MovimientoPermitido(f[32])){

                                f[n].setPosition(newPos);
                            }else{
                                f[n].setPosition(oldPos);
                            }
                            break;
                        case 3:
                            rey2.setXNPos(newPos.x);
                            rey2.setYNPos(newPos.y);
                            if (rey2.MovimientoPermitido(f[32])){

                                f[n].setPosition(newPos);
                            }else{
                                f[n].setPosition(oldPos);
                            }
                            break;
                        case 4:
                            dama2.setXNPos(newPos.x);
                            dama2.setYNPos(newPos.y);
                            if (dama2.MovimientoPermitido(f[32])){

                                f[n].setPosition(newPos);
                            }else{
                                f[n].setPosition(oldPos);
                            }
                            break;
                        case 5:
                            alfil4.setXNPos(newPos.x);
                            alfil4.setYNPos(newPos.y);
                            if (alfil4.MovimientoPermitido(f[32])){

                                f[n].setPosition(newPos);
                            }else{
                                f[n].setPosition(oldPos);
                            }
                            break;
                        case 6:
                            caballo4.setXNPos(newPos.x);
                            caballo4.setYNPos(newPos.y);
                            if (caballo4.MovimientoPermitido(f[32])){

                                f[n].setPosition(newPos);
                            }else{
                                f[n].setPosition(oldPos);
                            }
                            break;
                        case 7:
                            torre4.setXNPos(newPos.x);
                            torre4.setYNPos(newPos.y);
                            if (torre4.MovimientoPermitido(f[32])){

                                f[n].setPosition(newPos);
                            }else{
                                f[n].setPosition(oldPos);
                            }
                            break;
                        case 8:
                            peon9.setXNPos(newPos.x);
                            peon9.setYNPos(newPos.y);
                            if (peon9.MovimientoPermitido(f[32])){

                                f[n].setPosition(newPos);
                            }else{
                                f[n].setPosition(oldPos);
                            }
                            break;
                        case 9:
                            peon10.setXNPos(newPos.x);
                            peon10.setYNPos(newPos.y);
                            if (peon10.MovimientoPermitido(f[32])){

                                f[n].setPosition(newPos);
                            }else{
                                f[n].setPosition(oldPos);
                            }
                            break;
                        case 10:
                            peon11.setXNPos(newPos.x);
                            peon11.setYNPos(newPos.y);
                            if (peon11.MovimientoPermitido(f[32])){

                                f[n].setPosition(newPos);
                            }else{
                                f[n].setPosition(oldPos);
                            }
                            break;
                        case 11:
                            peon12.setXNPos(newPos.x);
                            peon12.setYNPos(newPos.y);
                            if (peon12.MovimientoPermitido(f[32])){

                                f[n].setPosition(newPos);
                            }else{
                                f[n].setPosition(oldPos);
                            }
                            break;
                        case 12:
                            peon13.setXNPos(newPos.x);
                            peon13.setYNPos(newPos.y);
                            if (peon13.MovimientoPermitido(f[32])){

                                f[n].setPosition(newPos);
                            }else{
                                f[n].setPosition(oldPos);
                            }
                            break;
                        case 13:
                            peon14.setXNPos(newPos.x);
                            peon14.setYNPos(newPos.y);
                            if (peon14.MovimientoPermitido(f[32])){
                                f[n].setPosition(newPos);
                            }else{
                                f[n].setPosition(oldPos);
                            }
                            break;
                        case 14:
                            peon15.setXNPos(newPos.x);
                            peon15.setYNPos(newPos.y);
                            if (peon15.MovimientoPermitido(f[32])){

                                f[n].setPosition(newPos);
                            }else{
                                f[n].setPosition(oldPos);
                            }
                            break;
                        case 15:
                            peon16.setXNPos(newPos.x);
                            peon16.setYNPos(newPos.y);
                            if (torre2.MovimientoPermitido(f[32])){

                                f[n].setPosition(newPos);
                            }else{
                                f[n].setPosition(oldPos);
                            }
                            break;


                        case 16:
                            peon1.setXNPos(newPos.x);
                            peon1.setYNPos(newPos.y);
                            if (peon1.MovimientoPermitido(f[32])){

                                f[n].setPosition(newPos);
                            }else{

                                f[n].setPosition(oldPos);
                            }
                            break;
                        case 17:
                            peon2.setXNPos(newPos.x);
                            peon2.setYNPos(newPos.y);
                            if (peon2.MovimientoPermitido(f[32])){

                                f[n].setPosition(newPos);
                            }else{
                                f[n].setPosition(oldPos);
                            }
                            break;
                        case 18:
                            peon3.setXNPos(newPos.x);
                            peon3.setYNPos(newPos.y);
                            if (peon3.MovimientoPermitido(f[32])){

                                f[n].setPosition(newPos);
                            }else{
                                f[n].setPosition(oldPos);
                            }
                            break;
                        case 19:
                            peon4.setXNPos(newPos.x);
                            peon4.setYNPos(newPos.y);
                            if (peon4.MovimientoPermitido(f[32])){

                                f[n].setPosition(newPos);
                            }else{
                                f[n].setPosition(oldPos);
                            }
                            break;
                        case 20:
                            peon5.setXNPos(newPos.x);
                            peon5.setYNPos(newPos.y);
                            if (peon5.MovimientoPermitido(f[32])){

                                f[n].setPosition(newPos);
                            }else{
                                f[n].setPosition(oldPos);
                            }
                            break;
                        case 21:
                            peon6.setXNPos(newPos.x);
                            peon6.setYNPos(newPos.y);
                            if (peon6.MovimientoPermitido(f[32])){

                                f[n].setPosition(newPos);
                            }else{
                                f[n].setPosition(oldPos);
                            }
                            break;
                        case 22:
                            peon7.setXNPos(newPos.x);
                            peon7.setYNPos(newPos.y);
                            if (peon7.MovimientoPermitido(f[32])){

                                f[n].setPosition(newPos);
                            }else{
                                f[n].setPosition(oldPos);
                            }
                            break;
                        case 23:
                            peon8.setXNPos(newPos.x);
                            peon8.setYNPos(newPos.y);
                            if (peon8.MovimientoPermitido(f[32])){

                                f[n].setPosition(newPos);
                            }else{
                                f[n].setPosition(oldPos);
                            }
                            break;
                        case 24:
                            torre1.setXNPos(newPos.x);
                            torre1.setYNPos(newPos.y);
                            if (torre1.MovimientoPermitido(f[32])){

                                f[n].setPosition(newPos);
                            }else{
                                f[n].setPosition(oldPos);
                            }
                            break;
                        case 25:
                            caballo1.setXNPos(newPos.x);
                            caballo1.setYNPos(newPos.y);
                            if (caballo1.MovimientoPermitido(f[32])){

                                f[n].setPosition(newPos);
                            }else{
                                f[n].setPosition(oldPos);
                            }
                            break;
                        case 26:
                            alfil1.setXNPos(newPos.x);
                            alfil1.setYNPos(newPos.y);
                            if (alfil1.MovimientoPermitido(f[32])){

                                f[n].setPosition(newPos);
                            }else{
                                f[n].setPosition(oldPos);
                            }
                            break;
                        case 27:
                            rey1.setXNPos(newPos.x);
                            rey1.setYNPos(newPos.y);
                            if (rey1.MovimientoPermitido(f[32])){

                                f[n].setPosition(newPos);
                            }else{
                                f[n].setPosition(oldPos);
                            }
                            break;
                        case 28:
                            dama1.setXNPos(newPos.x);
                            dama1.setYNPos(newPos.y);
                            if (dama1.MovimientoPermitido(f[32])){

                                f[n].setPosition(newPos);
                            }else{
                                f[n].setPosition(oldPos);
                            }
                            break;
                        case 29:
                            alfil2.setXNPos(newPos.x);
                            alfil2.setYNPos(newPos.y);
                            if (alfil2.MovimientoPermitido(f[32])){

                                f[n].setPosition(newPos);
                            }else{
                                f[n].setPosition(oldPos);
                            }
                            break;
                        case 30:
                            caballo2.setXNPos(newPos.x);
                            caballo2.setYNPos(newPos.y);
                            if (caballo2.MovimientoPermitido(f[32])){

                                f[n].setPosition(newPos);
                            }else{
                                f[n].setPosition(oldPos);
                            }
                            break;
                        case 31:
                            torre2.setXNPos(newPos.x);
                            torre2.setYNPos(newPos.y);
                            if (torre2.MovimientoPermitido(f[32])){

                                f[n].setPosition(newPos);
                            }else{
                                f[n].setPosition(oldPos);
                            }
                            break;

                        default:
                            f[n].setPosition(newPos);
                            break;
                    }

                }
            }
        }

        //comp move
        if (Keyboard::isKeyPressed(Keyboard::Space)){
            str =  getNextMove(position);

            oldPos = toCoord(str[0],str[1]);
            newPos = toCoord(str[2],str[3]);

            for(int i=0;i<32;i++) if (f[i].getPosition()==oldPos) n=i;

            //      Animacion
            for(int k=0;k<50;k++)
            {
                Vector2f p = newPos - oldPos;
                f[n].move(p.x/50, p.y/50);
                window.draw(sBoard);
                for(int i=0;i<32;i++) f[i].move(offset);
                for(int i=0;i<32;i++) window.draw(f[i]); window.draw(f[n]);
                for(int i=0;i<32;i++) f[i].move(-offset);
                window.display();
            }

            move(str);  position+=str+" ";
            f[n].setPosition(newPos);
        }

        //      Animacion de arastrar
        if (isMove){
            f[n].setPosition(pos.x-dx,pos.y-dy);
        }
        //      Borrar rastro
        window.clear();

        //      Pintar tablero
        window.draw(sBoard);


        //      Pintar piezas
        for(int i=0;i<32;i++){
            f[i].move(offset);
        }
        for(int i=0;i<32;i++){
            window.draw(f[i]);
            window.draw(f[n]);
        }
        for(int i=0;i<32;i++){
            f[i].move(-offset);
        }

        //peon1.setWasMove(false);


        //      Efectuar cambios
        window.display();
    }

    CloseConnection();


    return 0;
}

