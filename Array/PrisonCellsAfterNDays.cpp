/*
 * There are 8 prison cells in a row, and each cell is either ocupied or vacant.
 * Each day, whether the cell is occupied or vacant changes according to the
 * following ruels:
 *  If a cell has two adjacent neighbors that both occupied or both vacant, then
 *  the cell becomes occupied.
 *  Otherwise, it becomes vacant.
 * (Note that because the prison is a row, the first and last cells in the row
 * can't have two adjacent neighbors.)
 *
 * We describe the current state of the prison in the following way: cells[i] ==1
 * if the i-th cell is occupied, else cells[i] == 0.
 *
 * Given the initial state of the prison, return the state of the prison after N
 * days (and N such changes described above.)
 *
 * Date: 05/23/2020
 * Author: Wei Du
 */
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> prisonAfterNDays(vector<int>& cells, int N) {
        if (N>14) N = N%14 + 14;
        //else N = N%14;
        for(int i=0;i<N;i++){

            vector<int>temp=cells;
            for(int j=1;j<7;j++)
            {
                if(cells[j-1]==cells[j+1])temp[j]=1;
                else temp[j]=0;
            }
            temp[0]=0;
            temp[7]=0;

            cells=temp;

        }
        return cells;

    }
};
