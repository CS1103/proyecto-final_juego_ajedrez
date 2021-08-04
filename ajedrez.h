
#ifndef CHESS_AJEDREZ_H
#define CHESS_AJEDREZ_H
#include <string>
#include <iostream>
#include <unordered_map>
#include <SFML/Graphics.hpp>
#include "Connector.hpp"

using namespace std;
using namespace sf;

class Pieza{
protected:
    pair<int, int> position;
    pair<int, int> next_position;
    bool pieceColor;
    bool wasMove = false;
    bool alive = true;
    Sprite pieza;
public:

    Pieza(pair<int, int> position, pair<int, int> next_position, bool pieceColor,bool wasMove, Sprite pieza) : position(position), next_position(next_position), pieceColor(pieceColor),wasMove(wasMove), pieza(pieza){}
    ~Pieza() {};

    void setSprite(Sprite _peon){
        pieza = _peon;
    }
    void setX(int _x){
        position.first = _x;
    }
    void setY(int _y){
        position.second = _y;
    }
    void setXNPos(int _x){
        next_position.first = _x;

    }
    void setYNPos(int _y){
        next_position.second = _y;

    }
    void setWasMove(bool _wasMove){
        wasMove = _wasMove;
    }
    void setAlive(bool _alive){
        alive = _alive;
    }

    int getX(){
        return position.first;
    }
    int getY(){
        return position.second;
    }
    bool getWasMove(){
        return wasMove;
    }
    bool getAlive(){
        return alive;
    }

    virtual bool MovimientoPermitido(Sprite todasPiezas) = 0;

};


class Peon : public Pieza{
    bool firstMove = true;
public:

    Peon(pair<int, int> position, pair<int, int> next_position, bool pieceColor, bool wasMove, Sprite pieza) : Pieza(position, next_position, pieceColor,wasMove, pieza) {};
    ~Peon() {};
    //cout<<"OColumn: "<<(oldPos.x/56)<< "  :  "<<"OFill: "<<7-(oldPos.y/56)<<endl;
    //cout<<"DColumn: "<<(newPos.x/56)<< "  :  "<<"DFill: "<<7-(newPos.y/56)<<endl;
    bool MovimientoPermitido(Sprite todasPiezas){

        int column_o =  position.first/56;
        int fill_o = 7-(position.second/56);
        int column_d =  next_position.first/56;
        int fill_d = 7-(next_position.second/56);

        //cout<<"OColumn: "<<(position.first/56)<< "  :  "<<"OFill: "<<7-(position.second/56)<<endl;
        //cout<<"DColumn: "<<(next_position.first/56)<< "  :  "<<"DFill: "<<7-(next_position.second/56)<<endl;

        if (pieceColor == true){

            if (firstMove){
                if ((fill_o + 1 == fill_d or fill_o + 2 == fill_d) and column_d == column_o ){
                    firstMove = false;
                    position.first = next_position.first;
                    position.second = next_position.second;
                    return true;
                }else{
                    return false;
                }
            }else{
                if ((fill_o + 1 == fill_d) and column_d == column_o ){
                    position.first = next_position.first;
                    position.second = next_position.second;
                    return true;
                }else{
                    return false;
                }
            }

        }else{
            if (firstMove){
                if ((fill_o - 1 == fill_d or fill_o - 2 == fill_d) and column_d == column_o ){
                    firstMove = false;
                    position.first = next_position.first;
                    position.second = next_position.second;
                    return true;
                }else{
                    return false;
                }
            }else{
                if ((fill_o - 1 == fill_d) and column_d == column_o ){
                    position.first = next_position.first;
                    position.second = next_position.second;
                    return true;
                }else{
                    return false;
                }
            }
        }
    }
    bool casillaValida(int anaX, int anaY){
        int column_o =  position.first/56;
        int fill_o = 7-(position.second/56);
        int column_d =  anaX/56;
        int fill_d = 7-(anaY/56);

        if (pieceColor == true){

            if (firstMove){
                if ((fill_o + 1 == fill_d or fill_o + 2 == fill_d) and column_d == column_o ){
                    firstMove = false;

                    return true;
                }else{
                    return false;
                }
            }else{
                if ((fill_o + 1 == fill_d) and column_d == column_o ){

                    return true;
                }else{
                    return false;
                }
            }

        }else{
            if (firstMove){
                if ((fill_o - 1 == fill_d or fill_o - 2 == fill_d) and column_d == column_o ){
                    firstMove = false;
                    position.first = next_position.first;
                    position.second = next_position.second;
                    return true;
                }else{
                    return false;
                }
            }else{
                if ((fill_o - 1 == fill_d) and column_d == column_o ){

                    return true;
                }else{
                    return false;
                }
            }
        }
    }

};// Parcial (Comer en diagonal)
class Caballo : public Pieza{

public:
    Caballo(pair<int, int> position, pair<int, int> next_position, bool pieceColor, bool wasMove, Sprite pieza) : Pieza(position, next_position, pieceColor,wasMove, pieza) {};
    ~Caballo() {};

    bool MovimientoPermitido(Sprite todasPiezas){
        int column_o =  position.first/56;
        int fill_o = 7-(position.second/56);
        int column_d =  next_position.first/56;
        int fill_d = 7-(next_position.second/56);

        cout<<"OColumn: "<<(position.first/56)<< "  :  "<<"OFill: "<<7-(position.second/56)<<endl;
        cout<<"DColumn: "<<(next_position.first/56)<< "  :  "<<"DFill: "<<7-(next_position.second/56)<<endl;

        if (column_o + 2 == column_d and (fill_o + 1 == fill_d or fill_o == fill_d - 1)){
            position.first = next_position.first;
            position.second = next_position.second;
            return true;
        } else if (fill_o + 2 == fill_d and (column_o + 1 == column_d or column_o - 1== column_d)){
            position.first = next_position.first;
            position.second = next_position.second;
            return true;
        }else if((column_o-2==column_d or column_d-2==column_o)and(fill_o-1==fill_d)){
            position.first = next_position.first;
            position.second = next_position.second;
            return true;
        }else if (column_o-2==column_d and fill_d-1==fill_o){
            position.first = next_position.first;
            position.second = next_position.second;
            return true;
        }else if (fill_o-2==fill_d and (column_d-1==column_o or column_o-1 == column_d)){
            position.first = next_position.first;
            position.second = next_position.second;
            return true;
        }else{
            return false;
        }
    }

    bool casillaValida(int anaX, int anaY){
        int column_o =  position.first/56;
        int fill_o = 7-(position.second/56);
        int column_d =  anaX/56;
        int fill_d = 7-(anaY/56);


        if (column_o + 2 == column_d and (fill_o + 1 == fill_d or fill_o == fill_d - 1)){

            return true;
        } else if (fill_o + 2 == fill_d and (column_o + 1 == column_d or column_o - 1== column_d)){

            return true;
        }else if((column_o-2==column_d or column_d-2==column_o)and(fill_o-1==fill_d)){

            return true;
        }else if (column_o-2==column_d and fill_d-1==fill_o){

            return true;
        }else if (fill_o-2==fill_d and (column_d-1==column_o or column_o-1 == column_d)){

            return true;
        }else{
            return false;
        }
    }

}; // Completo
class Alfil : public Pieza{

public:

    Alfil(pair<int, int> position, pair<int, int> next_position, bool pieceColor, bool wasMove, Sprite pieza) : Pieza(position, next_position, pieceColor,wasMove, pieza) {};
    ~Alfil() {};

    bool MovimientoPermitido(Sprite todasPiezas){
        int column_o =  position.first/56;
        int fill_o = 7-(position.second/56);
        int column_d =  next_position.first/56;
        int fill_d = 7-(next_position.second/56);

        cout<<"OColumn: "<<(position.first/56)<< "  :  "<<"OFill: "<<7-(position.second/56)<<endl;
        cout<<"DColumn: "<<(next_position.first/56)<< "  :  "<<"DFill: "<<7-(next_position.second/56)<<endl;

        if(abs(column_d-column_o)==abs(fill_d-fill_o)){
            position.first = next_position.first;
            position.second = next_position.second;
            return true;
        }else{
            return false;
        }
    }

    bool casillaValida(int anaX, int anaY){
        int column_o =  position.first/56;
        int fill_o = 7-(position.second/56);
        int column_d =  anaX/56;
        int fill_d = 7-(anaY/56);


        if(abs(column_d-column_o)==abs(fill_d-fill_o)){

            return true;
        }else{
            return false;
        }
    }

}; // Completo
class Torre : public Pieza{

public:

    Torre(pair<int, int> position, pair<int, int> next_position, bool pieceColor, bool wasMove, Sprite pieza) : Pieza(position, next_position, pieceColor,wasMove, pieza) {};
    ~Torre() {};

    bool MovimientoPermitido(Sprite todasPiezas){
        int column_o =  position.first/56;
        int fill_o = 7-(position.second/56);
        int column_d =  next_position.first/56;
        int fill_d = 7-(next_position.second/56);

        cout<<"OColumn: "<<(position.first/56)<< "  :  "<<"OFill: "<<7-(position.second/56)<<endl;
        cout<<"DColumn: "<<(next_position.first/56)<< "  :  "<<"DFill: "<<7-(next_position.second/56)<<endl;
        if (column_o == column_d or fill_d == fill_o){
            position.first = next_position.first;
            position.second = next_position.second;
            return true;
        }else{
            return false;
        }
    }

    bool casillaValida(int anaX, int anaY){
        int column_o =  position.first/56;
        int fill_o = 7-(position.second/56);
        int column_d =  anaX/56;
        int fill_d = 7-(anaY/56);


        if (column_o == column_d or fill_d == fill_o){

            return true;
        }else{
            return false;
        }
    }

};// Completo
class Dama : public Pieza{

public:

    Dama(pair<int, int> position, pair<int, int> next_position, bool pieceColor, bool wasMove, Sprite pieza) : Pieza(position, next_position, pieceColor,wasMove, pieza) {};
    ~Dama() {};

    bool MovimientoPermitido(Sprite todasPiezas) {
        int column_o = position.first / 56;
        int fill_o = 7 - (position.second / 56);
        int column_d = next_position.first / 56;
        int fill_d = 7 - (next_position.second / 56);

        cout << "OColumn: " << (position.first / 56) << "  :  " << "OFill: " << 7 - (position.second / 56) << endl;
        cout << "DColumn: " << (next_position.first / 56) << "  :  " << "DFill: " << 7 - (next_position.second / 56)
             << endl;
        if (abs(column_d - column_o) == abs(fill_d - fill_o)) {
            position.first = next_position.first;
            position.second = next_position.second;
            return true;
        } else if (column_o == column_d or fill_d == fill_o){
            position.first = next_position.first;
            position.second = next_position.second;
            return true;
        } else if ((column_o == column_d or column_d + 1 == column_o or column_o + 1 == column_d) and
                   (fill_o == fill_d or fill_d + 1 == fill_o or fill_o + 1 == fill_d)) {
            position.first = next_position.first;
            position.second = next_position.second;
            return true;
        } else {
            return false;
        }
    }

    bool casillaValida(int anaX, int anaY){
        int column_o = position.first / 56;
        int fill_o = 7 - (position.second / 56);
        int column_d =  anaX/56;
        int fill_d = 7-(anaY/56);

        if (abs(column_d - column_o) == abs(fill_d - fill_o)) {

            return true;
        } else if (column_o == column_d or fill_d == fill_o){

            return true;
        } else if ((column_o == column_d or column_d + 1 == column_o or column_o + 1 == column_d) and
                   (fill_o == fill_d or fill_d + 1 == fill_o or fill_o + 1 == fill_d)) {

            return true;
        } else {
            return false;
        }
    }
}; // Completo
class Rey : public Pieza{

public:

    Rey(pair<int, int> position, pair<int, int> next_position, bool pieceColor, bool wasMove, Sprite pieza) : Pieza(position, next_position, pieceColor,wasMove, pieza) {};
    ~Rey() {};

    bool MovimientoPermitido(Sprite todasPiezas){
        int column_o =  position.first/56;
        int fill_o = 7-(position.second/56);
        int column_d =  next_position.first/56;
        int fill_d = 7-(next_position.second/56);

        cout<<"OColumn: "<<(position.first/56)<< "  :  "<<"OFill: "<<7-(position.second/56)<<endl;
        cout<<"DColumn: "<<(next_position.first/56)<< "  :  "<<"DFill: "<<7-(next_position.second/56)<<endl;
        if((column_o==column_d or column_d + 1 == column_o or column_o+1==column_d)and(fill_o ==fill_d or fill_d+1==fill_o or fill_o+1==fill_d)){
            position.first = next_position.first;
            position.second = next_position.second;
            return true;
        }else{
            return false;
        }
    }
    bool casillaValida(int anaX, int anaY){
        int column_o =  position.first/56;
        int fill_o = 7-(position.second/56);
        int column_d =  anaX/56;
        int fill_d = 7-(anaY/56);


        if((column_o==column_d or column_d + 1 == column_o or column_o+1==column_d)and(fill_o ==fill_d or fill_d+1==fill_o or fill_o+1==fill_d)){

            return true;
        }else{
            return false;
        }
    }
}; // Completo



#endif //CHESS_AJEDREZ_H
