//
// Created by Sam Burke on 2020-10-14.
//

#include "algorithm.h"
#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;

class algorithm {

    // The following string arrays represent the faces and squares of the cube
    // with white on the top and green in the front
    string top[3][3] = {{"w1","w2","w3"}, {"w4","w5","w6"}, {"w7","w8","w9"}};
    string bottom[3][3] = {{"y1","y2","y3"}, {"y4","y5","y6"}, {"y7","y8","y9"}};
    string front[3][3] = {{"g1","g2","g3"}, {"g4","g5","g6"}, {"g7","g8","g9"}};
    string back[3][3] = {{"b1","b2","b3"}, {"b4","b5","b6"}, {"b7","b8","b9"}};
    string left[3][3] = {{"o1","o2","o3"}, {"o4","o5","o6"}, {"o7","o8","o9"}};
    string right[3][3] = {{"r1","r2","r3"}, {"r4","r5","r6"}, {"r7","r8","r9"}};

    void display_cube() {

        // The display of the box will be dependent on whether or not Unicode
        // page 2500 can be used. By default, the value is set to true however,
        // if Unicode page 2500 cannot be utilized to display the box, the value
        // can be set to false, in which case basic keyboard characters will
        // represent the cube.
        // TODO: In a later iteration, set the main to allow the user to decide
        // TODO: if they would like to use Unicode or not by asking them to change
        // TODO: the value of useU2500 itself.

        bool useU2500 = false;

        string sp =                       " "; // space
        string lh = useU2500 ? "\u2500" : "-"; // line horizontal
        string lv = useU2500 ? "\u2502" : "|"; // line vertical
        string tl = useU2500 ? "\u250c" : "+"; // top left corner
        string tr = useU2500 ? "\u2510" : "+"; // top right corner
        string bl = useU2500 ? "\u2514" : "+"; // bottom left corner
        string br = useU2500 ? "\u2518" : "+"; // bottom right corner
        string jl = useU2500 ? "\u2524" : "+"; // join from left
        string jr = useU2500 ? "\u251c" : "+"; // join from right
        string jt = useU2500 ? "\u2534" : "+"; // join from top
        string jb = useU2500 ? "\u252c" : "+"; // join from bottom
        string jx = useU2500 ? "\u253c" : "+"; // join from cross

        // The following strings represents the top, middle and bottom boundaries.
        string fmt1 = "{0}{0}{1}{4}{4}{4}{2}{4}{4}{4}{2}{4}{4}{4}{3}";
        string topb[] = {sp, sp, tl, lh, lh, lh, jb, lh, lh, lh, jb, lh, lh, lh, tr};
        string midb[] = {sp, sp, jr, lh, lh, lh, jx, lh, lh, lh, jx, lh, lh, lh, jl};
        string botb[] = {sp, sp, bl, lh, lh, lh, jt, lh, lh, lh, jt, lh, lh, lh, br};

        // The following string represents the content rows in the 3x3 grid.
        string cnt[] = {sp, "{0}", lv, sp, "{1,-2}", lv, sp, "{2,-2}", lv, sp, "{3,-2}", lv};

        // The following string represents the non-grid (space-filling) rows.
        string skp[] = {sp, sp, sp, sp, sp, sp, sp, sp, sp, sp, sp, sp, sp, sp, sp};

        cout << flush;
        cout << endl;

        // Displaying the top cube face
        cout << skp << topb << endl;
        //cout << skp << cnt[" ", top[0][0], top[0][1], top[0][2]] << endl;
        cout << skp << midb << endl;
        //cout << skp << cnt["u", top[1][0], top[1][1], top[1][2]] << endl;
        cout << skp << midb << endl;
        //cout << skp << cnt[" ", top[2][0], top[2][1], top[2][2]] << endl;
        cout << skp << botb << endl;

        // Display the left, front, right and back cube faces.
        cout << topb << topb << topb << topb << "" << endl;
        //cout << cnt[" ", left[0][0], left[0][1], left[0][2]] << endl;

        for(int a = 0; a < 3; a++) {
            cout << top[a] << endl;
        }

    }
};
