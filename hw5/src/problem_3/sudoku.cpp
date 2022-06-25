#include <set>
#include "sudoku.h"

Sudoku::~Sudoku() {
    delete[] challenge;
}

bool Sudoku::solve() {
    /*
     * TODO: homework
     */
    return solve(0,0);
}

bool Sudoku::solve(size_t row, size_t col) {
    /*
     * TODO: homework
     * This helper function is OPTIONAL.
     * Use this or change it to your like.
     * If you do, remember to change the same in the .h file.
     */
    /*
   /*
     * TODO: homework
     * This helper function is OPTIONAL.
     * Use this or change it to your like.
     * If you do, remember to change the same in the .h file.
     */
    if(row == 8 && col == 9){
        return true;
    }

    if(col == 9){
        col = 0;
        row++;
    }

    if(*challenge_board(row,col) == 0){
        std::set<int> set;
        for(int i = 1; i <= SUDOKU_BOARD_SIZE; i++){
            set.insert(i);
        }

        size_t square_row = (row/3)*3;
        size_t square_col = (col/3)*3;
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                int val = *challenge_board(square_row + i, square_col + j);

                if(val != 0){
                    set.erase(val);
                }
            }
        }

        for(int i = 0; i < SUDOKU_BOARD_SIZE; i++){
            int val = *challenge_board(row, i);

            if(val != 0){
                set.erase(val);
            }

            val = *challenge_board(i, col);

            if(val != 0){
                set.erase(val);
            }
        }


        for (auto i: set) {
            *challenge_board(row, col) = i;
            int v = *challenge_board(row, col);
            std::cout << v << std::endl;
            bool valid = solve(row,col + 1);
            if(valid){
                return true;
            }
            *challenge_board(row,col) = 0;
        }
        return false;

    } else {
        return solve(row, col + 1);
    }
}