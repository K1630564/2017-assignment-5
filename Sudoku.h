#ifndef SUDOKU_H
#define SUDOKU_H

#include "Searchable.h"
#include <algorithm>
#include <iostream>
#include <sstream>
#include <vector>
#include <set>
#include <cmath>

using std::set;
using std::cout;
using std::endl;
using std::ostringstream;
using std::vector;
using std::iterator;
using std::sqrt;
using std::floor;
using std::unique_ptr;


class Sudoku : public Searchable{

private:

    int size;
    vector<vector<set<int>>> board;



public:

    Sudoku(int inSize): size(inSize){





        for (int i = 0; i < size; i++) {
            vector<set<int>> temp;
            for(int x = 0; x < inSize; x++){

                set<int> square;
                for (int z = 1; z <= size; z++) {
                    square.insert(z);
                }
                temp.push_back(square);
            }
            board.push_back(temp);
        }
    }

    int getSquare(int row, int col){

        if(board[row][col].size() == 1){
            return *board[row][col].begin();
        }

        return  -1;
    }

    bool setSquareRun(){
        int check = false;
        for (int i = 0; i < size; i++) {
            for (int z = 0; z < size; z++) {

                if (board[i][z].size() == 1) {
                    int toRemove = *board[i][z].begin();

                    //check row
                    for (int q = 0; q < size; q++) {

                        if (board[q][z].find(toRemove) != board[q][z].end() && q != i ) {
                            check = true;
                            board[q][z].erase(toRemove);
                            if (board[q][z].empty() == true) {
                                return false;
                            }
                        }

                    }
                    //check column
                    for (int x = 0; x < size; x++) {

                        if (board[i][x].find(toRemove) != board[i][x].end() && x != z) {
                            check = true;
                            board[i][x].erase(toRemove);
                            if (board[i][x].empty() == true) {
                                return false;
                            }
                        }
                    }


                    /*
                    int boxSize = sqrt(size);
                    int topLeftRow = floor(topLeftRow/boxSize) * boxSize;
                    int topLeftCol = floor(topLeftCol/boxSize) * boxSize;

                    cout << topLeftRow << topLeftCol << endl;

  */


                    // HOLDS FOR MAX 36X36 BOARDS
                    int boxSize = sqrt(size);
                    int topLeftRow;
                    int topLeftCol;

                    if(i < boxSize) {
                        topLeftRow = 0;
                        if (z < boxSize) {
                            topLeftCol = 0;

                        } else if (z >= boxSize && z < (boxSize * 2)) {
                            topLeftCol = boxSize;

                        } else if (z >= boxSize*2 && z < (boxSize *3)) {
                            topLeftCol = boxSize*2;

                        }
                        else if(z >= boxSize*3 && z < (boxSize *4)){
                            topLeftCol = boxSize*3;
                        }
                        else if(z >= boxSize*4 && z < (boxSize *5)){
                            topLeftCol = boxSize*4;
                        }
                        else if(z >= boxSize*5 && z < (boxSize *6)){
                            topLeftCol = boxSize*5;

                        }



                    }

                    else if(i >= boxSize && i < (boxSize*2)){

                        topLeftRow = boxSize;
                        if(z < boxSize){
                            topLeftCol = 0;

                        }

                        else if( z >= boxSize && z < (boxSize*2)){
                            topLeftCol = boxSize;

                        }

                        else if (z >= boxSize*2 && z < (boxSize *3)){
                            topLeftCol = boxSize*2;

                        }
                        else if(z >= boxSize*3 && z < (boxSize *4)){
                            topLeftCol = boxSize*3;
                        }
                        else if(z >= boxSize*4 && z < (boxSize *5)){
                            topLeftCol = boxSize*4;
                        }
                        else if(z >= boxSize*5 && z < (boxSize *6)){
                            topLeftCol = boxSize*5;

                        }
                    }

                    else if( i >= boxSize*2 && i < (boxSize *3)){
                        topLeftRow = boxSize*2;

                        if(z < boxSize){
                            topLeftCol = 0;

                        }

                        else if( z >= boxSize && z < (boxSize*2)){
                            topLeftCol = boxSize;

                        }

                        else if (z >= boxSize*2 && z < (boxSize *3)){
                            topLeftCol = boxSize*2;

                        }
                        else if(z >= boxSize*3 && z < (boxSize *4)){
                            topLeftCol = boxSize*3;
                        }
                        else if(z >= boxSize*4 && z < (boxSize *5)){
                            topLeftCol = boxSize*4;
                        }
                        else if(z >= boxSize*5 && z < (boxSize *6)){
                            topLeftCol = boxSize*5;

                        }

                    }

                    else if( i >= boxSize*3 && i < (boxSize*4)){
                        topLeftRow = boxSize*3;

                        if(z < boxSize){
                            topLeftCol = 0;

                        }

                        else if( z >= boxSize && z < (boxSize*2)){
                            topLeftCol = boxSize;

                        }

                        else if (z >= boxSize*2 && z < (boxSize *3)){
                            topLeftCol = boxSize*2;

                        }
                        else if(z >= boxSize*3 && z < (boxSize *4)){
                            topLeftCol = boxSize*3;
                        }
                        else if(z >= boxSize*4 && z < (boxSize *5)){
                            topLeftCol = boxSize*4;
                        }
                        else if(z >= boxSize*5 && z < (boxSize *6)){
                            topLeftCol = boxSize*5;

                        }
                    }
                    else if(i >= boxSize*4 && i < (boxSize *5)){

                        topLeftRow = boxSize*4;

                        if(z < boxSize){
                            topLeftCol = 0;

                        }

                        else if( z >= boxSize && z < (boxSize*2)){
                            topLeftCol = boxSize;

                        }

                        else if (z >= boxSize*2 && z < (boxSize *3)){
                            topLeftCol = boxSize*2;

                        }
                        else if(z >= boxSize*3 && z < (boxSize *4)){
                            topLeftCol = boxSize*3;
                        }
                        else if(z >= boxSize*4 && z < (boxSize *5)){
                            topLeftCol = boxSize*4;
                        }
                        else if(z >= boxSize*5 && z < (boxSize *6)){
                            topLeftCol = boxSize*5;

                        }
                    }
                    else if(i >= boxSize*5 && i < (boxSize *6)){
                        topLeftRow = boxSize*5;

                        if(z < boxSize){
                            topLeftCol = 0;

                        }

                        else if( z >= boxSize && z < (boxSize*2)){
                            topLeftCol = boxSize;

                        }

                        else if (z >= boxSize*2 && z < (boxSize *3)){
                            topLeftCol = boxSize*2;

                        }
                        else if(z >= boxSize*3 && z < (boxSize *4)){
                            topLeftCol = boxSize*3;
                        }
                        else if(z >= boxSize*4 && z < (boxSize *5)){
                            topLeftCol = boxSize*4;
                        }
                        else if(z >= boxSize*5 && z < (boxSize *6)){
                            topLeftCol = boxSize*5;

                        }


                    }








                    for (int a = topLeftRow; a < topLeftRow+boxSize; a++) {
                        for (int b = topLeftCol; b < topLeftCol+boxSize; b++) {
                            if(a != i && b != z) {
                                if (board[a][b].find(toRemove) != board[a][b].end()) {
                                    check = true;
                                    board[a][b].erase(toRemove);
                                    if (board[a][b].empty() == true) {
                                        return false;
                                    }
                                }
                            }


                        }

                    }


                }

            }

        }
        if(check){
            return this->setSquareRun();
        }
        return true;
    }

    bool setSquare(int row, int col, int value) {


        board[row][col].clear();
        board[row][col].insert(value);
        write(cout);
        return this->setSquareRun();

    }

    bool isSolution() const override {
            for (int i = 0; i < size; i++) {
                for (int z = 0; z < size; z++) {

                    if(board[i][z].size() > 1){
                        return false;
                    }
                }
            }
            return true;
    }

    vector<unique_ptr<Searchable> > successors() const override {
        vector<unique_ptr<Searchable> > toReturn;
        int row;
        int col;
        bool found = false;
        int temp;

        for (int i = 0; i < size; i++) {
            for (int z = 0; z < size; z++) {
                if(board[i][z].size() > 1){
                    temp = board[i][z].size();
                    col = z;
                    row = i;
                    found = true;
                    i = size;
                    z = size;
                    break;
                }
            }

        }

        if(found){
            for(int i = 0; i < temp; i++){

                unique_ptr<Sudoku> copy;
                copy.reset(new Sudoku(*this));
                vector<vector<set<int>>> tempBoard = copy.get()->board;
                set<int> another = tempBoard[row][col];
                auto valueIt = std::next(another.begin(), i);
                int value = *valueIt;
                if(copy.get()->setSquare(row, col, value)){
                    toReturn.push_back(std::move(copy));
                }



            }
        }
        return toReturn;
    }

    void write(ostream & o) const override{


        for (int i = 0; i < size; i++) {
            for (int z = 0; z < size; z++) {

                if(board[i][z].size() == 1){
                    o << *board[i][z].begin();

                }
                else{
                    o << " ";
                }
            }
            o << endl;
        }


    }



};



#endif
