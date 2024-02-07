#ifndef PLAYER_H
#define PLAYER_H

#include <vector>

class Player {
    public:
        Player () {}
        Player (bool turn, int points) {}
        void Move1(int start, std::vector<std::vector<int>>& Board){}
        void Move2 (int start, std::vector<std::vector<int>>& Board) {}
        void Print1 (const std::vector<std::vector<int>>& Board) {}
        void Print2 (const std::vector<std::vector<int>>& Board) {}
        bool Turn() {}
        bool SwitchTurn() {}

    private:
        bool m_turn;
        int m_points;
};

#endif