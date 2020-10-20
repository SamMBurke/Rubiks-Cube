#include <iostream>
#include <string>
#include "algorithm.h"

using namespace std;

// The following string arrays represent the faces and squares of a
// standard Rubik's Cube with white on the top and green in the front.
string top[3][3]    = {{"w1","w2","w3"}, {"w4","w5","w6"}, {"w7","w8","w9"}};
string bottom[3][3] = {{"y1","y2","y3"}, {"y4","y5","y6"}, {"y7","y8","y9"}};
string front[3][3]  = {{"g1","g2","g3"}, {"g4","g5","g6"}, {"g7","g8","g9"}};
string back[3][3]   = {{"b1","b2","b3"}, {"b4","b5","b6"}, {"b7","b8","b9"}};
string Left[3][3]   = {{"o1","o2","o3"}, {"o4","o5","o6"}, {"o7","o8","o9"}};
string Right[3][3]  = {{"r1","r2","r3"}, {"r4","r5","r6"}, {"r7","r8","r9"}};

// The following string array is the list of commands the
// user can use to perform a rotation of the Rubik's Cube.
string commands[18] = {"F", "F'", "B", "B'", "L", "L'", "R", "R'", "T",
                       "T'", "b", "b'", "X", "X'", "Y", "Y'", "Z", "Z'"};

// This function is used to print out
// the string arrays that make up the Rubik's Cube.
void print(string array[]) {
    for(int i = 0; i < 15; i++) {
        cout << array[i];
    }
    return;
}

// This function does the same as the function above
// except for the center boxes which hold the faces.
void print_cnt(string array[]) {
    for(int i = 0; i < 12; i++) {
        cout << array[i];
    }
    return;
}

// This function is used to print the available commands to the user.
// This was created to omit the need of a large/long game_loop function.
void print_instr() {
    cout << "Face/Axis    Rotation    Command Name" << endl;
    cout << "Front        CW          F" << endl;
    cout << "Front        CCW         F'" << endl;
    cout << "Back         CW          B" << endl;
    cout << "Back         CCW         B'" << endl;
    cout << "Left         CW          L" << endl;
    cout << "Left         CCW         L'" << endl;
    cout << "Right        CW          R" << endl;
    cout << "Right        CCW         R" << endl;
    cout << "Top          CW          T'" << endl;
    cout << "Top          CCW         T'" << endl;
    cout << "Bottom       CW          b" << endl;
    cout << "Bottom       CCW         b'" << endl;
    cout << "Middle(x)    Left        X" << endl;
    cout << "Middle(x)    Right       X'" << endl;
    cout << "Middle(y)    Up          Y" << endl;
    cout << "Middle(y)    Down        Y'" << endl;
    cout << "Middle(z)    CW          Z" << endl;
    cout << "Middle(z)    CCW         Z'" << endl;

    cout << endl;
}

// This function is used to ensure that the users's
// desired move is valid based on a set list of possible moves.
bool is_valid(string move) {
    for(int i = 0; i < 18; i++) {
        if(commands[i] == move) return true;
    }
    return false;
}

// This is the function that asks the user if they would
// like to use Unicode to draw the cube boxes or not.
bool question() {
    string ans;
    cout << "Type 'Yes' to use Unicode to draw the boxes of the cube and 'No' to use keyboard characters: ";
    cin >> ans;

    while(ans != "Yes" && ans != "No") {
        if(ans != "Yes" && ans != "No") cout << "That answer was no valid. Please type 'Yes' or 'No'" << endl;
        cin >> ans;
    }

    if(ans == "Yes") return true;
    else return false;
}

// This function sets up and displays the Rubik's Cube.
void cube_display(bool use_uni) {

    // The display of the box will be dependent on whether or not Unicode
    // page 2500 can be used. By default, if Unicode page 2500 cannot be
    // utilized to display the box, the value can be set to false, in which
    // case basic keyboard characters will represent the cube. Otherwise,
    // the user can decide to use Unicode.

    bool use_U2500 = use_uni;

    string sp =                        " "; // space
    string lh = use_U2500 ? "\u2500" : "-"; // line horizontal
    string lv = use_U2500 ? "\u2502" : "|"; // line vertical
    string tl = use_U2500 ? "\u250c" : "+"; // top left corner
    string tr = use_U2500 ? "\u2510" : "+"; // top right corner
    string bl = use_U2500 ? "\u2514" : "+"; // bottom left corner
    string br = use_U2500 ? "\u2518" : "+"; // bottom right corner
    string jl = use_U2500 ? "\u2524" : "+"; // join from left
    string jr = use_U2500 ? "\u251c" : "+"; // join from right
    string jt = use_U2500 ? "\u2534" : "+"; // join from top
    string jb = use_U2500 ? "\u252c" : "+"; // join from bottom
    string jx = use_U2500 ? "\u253c" : "+"; // join from cross

    // The following strings represents the top, middle and bottom boundaries.
    string topb[] = {sp, sp, tl, lh, lh, lh, jb, lh, lh, lh, jb, lh, lh, lh, tr};
    string midb[] = {sp, sp, jr, lh, lh, lh, jx, lh, lh, lh, jx, lh, lh, lh, jl};
    string botb[] = {sp, sp, bl, lh, lh, lh, jt, lh, lh, lh, jt, lh, lh, lh, br};

    // The following string represents the content rows in the 3x3 grid.
    string cnt[] = {sp, "", lv, sp, "", lv, sp, "", lv, sp, "", lv};

    // The following string represents the non-grid (space-filling) rows.
    string skp[] = {sp, sp, sp, sp, sp, sp, sp, sp, sp, sp, sp, sp, sp, sp, sp};

    cout << endl << flush;
    cout << endl;


    // Displaying the top cube face.
    print(skp); print(topb); cout << endl;
    // Top cube face center lines, top row
    cnt[1] = " ";
    cnt[4] = top[0][0];
    cnt[7] = top[0][1];
    cnt[10] = top[0][2];
    print(skp); print_cnt(cnt); cout << endl;
    print(skp); print(midb); cout << endl;
    // Top cube face center lines, middle row.
    cnt[1] = "T";
    cnt[4] = top[1][0];
    cnt[7] = top[1][1];
    cnt[10] = top[1][2];
    print(skp); print_cnt(cnt); cout << endl;
    print(skp); print(midb); cout << endl;
    // Top cube face center lines, bottom row.
    cnt[1] = " ";
    cnt[4] = top[2][0];
    cnt[7] = top[2][1];
    cnt[10] = top[2][2];
    print(skp); print_cnt(cnt); cout << endl;
    print(skp); print(botb); cout << endl;


    // Display the left, front, right and back cube faces.
    print(topb); print(topb); print(topb); print(topb); cout << endl;
    // Middle cube faces center lines, top row.
    cnt[1] = " ";
    cnt[4] = Left[0][0];
    cnt[7] = Left[0][1];
    cnt[10] = Left[0][2];
    print_cnt(cnt);
    cnt[1] = " ";
    cnt[4] = front[0][0];
    cnt[7] = front[0][1];
    cnt[10] = front[0][2];
    print_cnt(cnt);
    cnt[1] = " ";
    cnt[4] = Right[0][0];
    cnt[7] = Right[0][1];
    cnt[10] = Right[0][2];
    print_cnt(cnt);
    cnt[1] = " ";
    cnt[4] = back[0][0];
    cnt[7] = back[0][1];
    cnt[10] = back[0][2];
    print_cnt(cnt); cout << endl;
    print(midb); print(midb); print(midb); print(midb); cout << endl;
    // Middle cube faces center lines, middle row.
    cnt[1] = "L";
    cnt[4] = Left[1][0];
    cnt[7] = Left[1][1];
    cnt[10] = Left[1][2];
    print_cnt(cnt);
    cnt[1] = "F";
    cnt[4] = front[1][0];
    cnt[7] = front[1][1];
    cnt[10] = front[1][2];
    print_cnt(cnt);
    cnt[1] = "R";
    cnt[4] = Right[1][0];
    cnt[7] = Right[1][1];
    cnt[10] = Right[1][2];
    print_cnt(cnt);
    cnt[1] = "B";
    cnt[4] = back[1][0];
    cnt[7] = back[1][1];
    cnt[10] = back[1][2];
    print_cnt(cnt); cout << endl;
    print(midb); print(midb); print(midb); print(midb); cout << endl;
    // Middle cube faces center lines, bottom row.
    cnt[1] = " ";
    cnt[4] = Left[2][0];
    cnt[7] = Left[2][1];
    cnt[10] = Left[2][2];
    print_cnt(cnt);
    cnt[1] = " ";
    cnt[4] = front[2][0];
    cnt[7] = front[2][1];
    cnt[10] = front[2][2];
    print_cnt(cnt);
    cnt[1] = " ";
    cnt[4] = Right[2][0];
    cnt[7] = Right[2][1];
    cnt[10] = Right[2][2];
    print_cnt(cnt);
    cnt[1] = " ";
    cnt[4] = back[2][0];
    cnt[7] = back[2][1];
    cnt[10] = back[2][2];
    print_cnt(cnt); cout << endl;
    print(botb); print(botb); print(botb); print(botb); cout << endl;


    // Display the bottom cube face.
    print(skp); print(topb); cout << endl;
    // Top cube face center lines, top row.
    cnt[1] = " ";
    cnt[4] = bottom[0][0];
    cnt[7] = bottom[0][1];
    cnt[10] = bottom[0][2];
    print(skp); print_cnt(cnt); cout << endl;
    print(skp); print(midb); cout << endl;
    // Top cube face center lines, middle row.
    cnt[1] = "b";
    cnt[4] = bottom[1][0];
    cnt[7] = bottom[1][1];
    cnt[10] = bottom[1][2];
    print(skp); print_cnt(cnt); cout << endl;
    print(skp); print(midb); cout << endl;
    // Top cube face center lines, bottom row.
    cnt[1] = " ";
    cnt[4] = bottom[2][0];
    cnt[7] = bottom[2][1];
    cnt[10] = bottom[2][2];
    print(skp); print_cnt(cnt); cout << endl;
    print(skp); print(botb); cout << endl;

    cout << endl;
    return;
}

// This function rotates a cube face counter-clockwise once.
void rotate_ccw(string a[3][3]) {
    // First, rotate corners 90 degrees counter-clockwise.
    string ctemp = a[0][0];
    a[0][0] = a[0][2];
    a[0][2] = a[2][2];
    a[2][2] = a[2][0];
    a[2][0] = ctemp;

    // Second, rotate middle edges 90 degrees counter-clockwise.
    string etemp = a[0][1];
    a[0][1] = a[1][2];
    a[1][2] = a[2][1];
    a[2][1] = a[1][0];
    a[1][0] = etemp;

    return;
}

// This function rotates a cube face clockwise once.
void rotate_cw(string a[3][3]) {
    // First, rotate corners 90 degrees clockwise.
    string ctemp = a[0][0];
    a[0][0] = a[2][0];
    a[2][0] = a[2][2];
    a[2][2] = a[0][2];
    a[0][2] = ctemp;

    // Second, rotate middle edges 90 degrees clockwise.
    string etemp = a[0][1];
    a[0][1] = a[1][0];
    a[1][0] = a[2][1];
    a[2][1] = a[1][2];
    a[1][2] = etemp;

    return;
}

// This function intakes a command and changes the cube cell variables
// accordingly to simulate the rotation of an actual Rubik's Cube.
void make_move(string command) {
    // Converting the command into a number for the switch-case statement.
    int num;
    for(int i = 0; i < 18; i++) {
        if(commands[i] == command) {
            num = i;
        }
    }

    string temp1, temp2, temp3;
    switch(num) {
        // Front face rotation CW.
        case 0:
            temp1 = bottom[0][0];
            temp2 = bottom[0][1];
            temp3 = bottom[0][2];
            bottom[0][0] = Right[2][0];
            bottom[0][1] = Right[1][0];
            bottom[0][2] = Right[0][0];
            Right[2][0] = top[2][2];
            Right[1][0] = top[2][1];
            Right[0][0] = top[2][0];
            top[2][2] = Left[0][2];
            top[2][1] = Left[1][2];
            top[2][0] = Left[2][2];
            Left[0][2] = temp1;
            Left[1][2] = temp2;
            Left[2][2] = temp3;
            rotate_cw(front);
            break;

        // Front face rotation CCW.
        case 1:
            temp1 = bottom[0][0];
            temp2 = bottom[0][1];
            temp3 = bottom[0][2];
            bottom[0][0] = Left[0][2];
            bottom[0][1] = Left[1][2];
            bottom[0][2] = Left[2][2];
            Left[0][2] = top[2][2];
            Left[1][2] = top[2][1];
            Left[2][2] = top[2][0];
            top[2][2] = Right[2][0];
            top[2][1] = Right[1][0];
            top[2][0] = Right[0][0];
            Right[2][0] = temp1;
            Right[1][0] = temp2;
            Right[0][0] = temp3;
            rotate_ccw(front);
            break;

        // Back face rotation CW.
        case 2:
            temp1 = bottom[2][0];
            temp2 = bottom[2][1];
            temp3 = bottom[2][2];
            bottom[2][0] = Left[0][0];
            bottom[2][1] = Left[1][0];
            bottom[2][2] = Left[2][0];
            Left[0][0] = top[0][2];
            Left[1][0] = top[0][1];
            Left[2][0] = top[0][0];
            top[0][2] = Right[2][2];
            top[0][1] = Right[1][2];
            top[0][0] = Right[0][2];
            Right[2][2] = temp1;
            Right[1][2] = temp2;
            Right[0][2] = temp3;
            rotate_cw(back);
            break;

        // Back face rotation CCW.
        case 3:
            temp1 = bottom[2][0];
            temp2 = bottom[2][1];
            temp3 = bottom[2][2];
            bottom[2][0] = Right[2][2];
            bottom[2][1] = Right[1][2];
            bottom[2][2] = Right[0][2];
            Right[2][2] = top[0][2];
            Right[1][2] = top[0][1];
            Right[0][2] = top[0][0];
            top[0][2] = Left[0][0];
            top[0][1] = Left[1][0];
            top[0][0] = Left[2][0];
            Left[0][0] = temp1;
            Left[1][0] = temp2;
            Left[2][0] = temp3;
            rotate_ccw(back);
            break;

        // Left face rotation CW.
        case 4:
            temp1 = front[0][0];
            temp2 = front[1][0];
            temp3 = front[2][0];
            front[0][0] = top[0][0];
            front[1][0] = top[1][0];
            front[2][0] = top[2][0];
            top[0][0] = back[2][2];
            top[1][0] = back[1][2];
            top[2][0] = back[0][2];
            back[2][2] = bottom[0][0];
            back[1][2] = bottom[1][0];
            back[0][2] = bottom[2][0];
            bottom[0][0] = temp1;
            bottom[1][0] = temp2;
            bottom[2][0] = temp3;
            rotate_cw(Left);
            break;

        // Left face rotation CCW.
        case 5:
            temp1 = front[0][0];
            temp2 = front[1][0];
            temp3 = front[2][0];
            front[0][0] = bottom[0][0];
            front[1][0] = bottom[1][0];
            front[2][0] = bottom[2][0];
            bottom[0][0] = back[2][2];
            bottom[1][0] = back[1][2];
            bottom[2][0] = back[0][2];
            back[2][2] = top[0][0];
            back[1][2] = top[1][0];
            back[0][2] = top[2][0];
            top[0][0] = temp1;
            top[1][0] = temp2;
            top[2][0] = temp3;
            rotate_ccw(Left);
            break;

        // Right face rotation CW.
        case 6:
            temp1 = front[0][2];
            temp2 = front[1][2];
            temp3 = front[2][2];
            front[0][2] = bottom[0][2];
            front[1][2] = bottom[1][2];
            front[2][2] = bottom[2][2];
            bottom[0][2] = back[2][0];
            bottom[1][2] = back[1][0];
            bottom[2][2] = back[0][0];
            back[2][0] = top[0][2];
            back[1][0] = top[1][2];
            back[0][0] = top[2][2];
            top[0][2] = temp1;
            top[1][2] = temp2;
            top[2][2] = temp3;
            rotate_cw(Right);
            break;

        // Right face rotation CCW.
        case 7:
            temp1 = front[0][2];
            temp2 = front[1][2];
            temp3 = front[2][2];
            front[0][2] = top[0][2];
            front[1][2] = top[1][2];
            front[2][2] = top[2][2];
            top[0][2] = back[2][0];
            top[1][2] = back[1][0];
            top[2][2] = back[0][0];
            back[2][0] = bottom[0][2];
            back[1][0] = bottom[1][2];
            back[0][0] = bottom[2][2];
            bottom[0][2] = temp1;
            bottom[1][2] = temp2;
            bottom[2][2] = temp3;
            rotate_ccw(Right);
            break;

        // Top face rotation CW.
        case 8:
            temp1 = front[0][0];
            temp2 = front[0][1];
            temp3 = front[0][2];
            front[0][0] = Right[0][0];
            front[0][1] = Right[0][1];
            front[0][2] = Right[0][2];
            Right[0][0] = back[0][0];
            Right[0][1] = back[0][1];
            Right[0][2] = back[0][2];
            back[0][0] = Left[0][0];
            back[0][1] = Left[0][1];
            back[0][2] = Left[0][2];
            Left[0][0] = temp1;
            Left[0][1] = temp2;
            Left[0][2] = temp3;
            rotate_cw(top);
            break;

        // Top face rotation CCW.
        case 9:
            temp1 = front[0][0];
            temp2 = front[0][1];
            temp3 = front[0][2];
            front[0][0] = Left[0][0];
            front[0][1] = Left[0][1];
            front[0][2] = Left[0][2];
            Left[0][0] = back[0][0];
            Left[0][1] = back[0][1];
            Left[0][2] = back[0][2];
            back[0][0] = Right[0][0];
            back[0][1] = Right[0][1];
            back[0][2] = Right[0][2];
            Right[0][0] = temp1;
            Right[0][1] = temp2;
            Right[0][2] = temp3;
            rotate_ccw(top);
            break;

        // Bottom face rotation CW.
        case 10:
            temp1 = front[2][0];
            temp2 = front[2][1];
            temp1 = front[2][2];
            front[2][0] = Left[2][0];
            front[2][1] = Left[2][1];
            front[2][2] = Left[2][2];
            Left[2][0] = back[2][0];
            Left[2][1] = back[2][1];
            Left[2][2] = back[2][2];
            back[2][0] = Right[2][0];
            back[2][1] = Right[2][1];
            back[2][2] = Right[2][2];
            Right[2][0] = temp1;
            Right[2][1] = temp2;
            Right[2][2] = temp3;
            rotate_cw(bottom);
            break;

        // Bottom face rotation CCW.
        case 11:
            temp1 = front[2][0];
            temp2 = front[2][1];
            temp1 = front[2][2];
            front[2][0] = Right[2][0];
            front[2][1] = Right[2][1];
            front[2][2] = Right[2][2];
            Right[2][0] = back[2][0];
            Right[2][1] = back[2][1];
            Right[2][2] = back[2][2];
            back[2][0] = Left[2][0];
            back[2][1] = Left[2][1];
            back[2][2] = Left[2][2];
            Left[2][0] = temp1;
            Left[2][1] = temp2;
            Left[2][2] = temp3;
            rotate_ccw(bottom);
            break;

        // Middle(x) face rotation CW (Left).
        case 12:
            temp1 = front[1][0];
            temp2 = front[1][1];
            temp3 = front[1][2];
            front[1][0] = Right[1][0];
            front[1][1] = Right[1][1];
            front[1][2] = Right[1][2];
            Right[1][0] = back[1][0];
            Right[1][1] = back[1][1];
            Right[1][2] = back[1][2];
            back[1][0] = Left[1][0];
            back[1][1] = Left[1][1];
            back[1][2] = Left[1][2];
            Left[1][0] = temp1;
            Left[1][1] = temp2;
            Left[1][2] = temp3;
            break;

        // Middle(x) face rotation CCW (Right).
        case 13:
            temp1 = front[1][0];
            temp2 = front[1][1];
            temp3 = front[1][2];
            front[1][0] = Left[1][0];
            front[1][1] = Left[1][1];
            front[1][2] = Left[1][2];
            Left[1][0] = back[1][0];
            Left[1][1] = back[1][1];
            Left[1][2] = back[1][2];
            back[1][0] = Right[1][0];
            back[1][1] = Right[1][1];
            back[1][2] = Right[1][2];
            Right[1][0] = temp1;
            Right[1][1] = temp2;
            Right[1][2] = temp3;
            break;

        // Middle(y) face rotation CW (Up).
        case 14:
            temp1 = front[0][1];
            temp2 = front[1][1];
            temp3 = front[2][1];
            front[0][1] = bottom[0][1];
            front[1][1] = bottom[1][1];
            front[2][1] = bottom[2][1];
            bottom[0][1] = back[2][1];
            bottom[1][1] = back[1][1];
            bottom[2][1] = back[0][1];
            back[2][1] = top[0][1];
            back[1][1] = top[1][1];
            back[0][1] = top[2][1];
            top[0][1] = temp1;
            top[1][1] = temp2;
            top[2][1] = temp3;
            break;

        // Middle(y) face rotation CCW (Down).
        case 15:
            temp1 = front[0][1];
            temp2 = front[1][1];
            temp3 = front[2][1];
            front[0][1] = top[0][1];
            front[1][1] = top[1][1];
            front[2][1] = top[2][1];
            top[0][1] = back[2][1];
            top[1][1] = back[1][1];
            top[2][1] = back[0][1];
            back[2][1] = bottom[0][1];
            back[1][1] = bottom[1][1];
            back[0][1] = bottom[2][1];
            bottom[0][1] = temp1;
            bottom[1][1] = temp2;
            bottom[2][1] = temp3;
            break;

        // Middle(z) face rotation CW.
        case 16:
            temp1 = top[1][0];
            temp2 = top[1][1];
            temp3 = top[1][2];
            top[1][0] = Left[2][1];
            top[1][1] = Left[1][1];
            top[1][2] = Left[0][1];
            Left[2][1] = bottom[1][2];
            Left[1][1] = bottom[1][1];
            Left[0][1] = bottom[1][0];
            bottom[1][2] = Right[0][1];
            bottom[1][1] = Right[1][1];
            bottom[1][0] = Right[2][1];
            Right[0][1] = temp1;
            Right[1][1] = temp2;
            Right[2][1] = temp3;
            break;

        // Middle(z) face rotation CCW.
        case 17:
            temp1 = top[1][0];
            temp2 = top[1][1];
            temp3 = top[1][2];
            top[1][0] = Right[0][1];
            top[1][1] = Right[1][1];
            top[1][2] = Right[2][1];
            Right[0][1] = bottom[1][2];
            Right[1][1] = bottom[1][1];
            Right[2][1] = bottom[1][0];
            bottom[1][2] = Left[2][1];
            bottom[1][1] = Left[1][1];
            bottom[1][0] = Left[0][1];
            Left[2][1] = temp1;
            Left[1][1] = temp2;
            Left[0][1] = temp3;
            break;
    }
    return;
}

// TODO: This will be the function which scrambles and shuffles the cube, randomizing it for the user
void shuffle() {
    return;
}

// TODO: This will be the function which sets the win condition and checks it after each move
bool is_game_done() {
    /*
     * Check the status of each face to ensure that each edge and corner piece matches with the center piece
     * If so, return true, else return false
     */
    return false;
}

// This function will run the game loop called by the main function.
void game_loop() {
    bool use_uni;
    use_uni = question();

    bool game_done;

    while(!game_done) {
        string ans;
        bool valid;

        cube_display(use_uni);

        // Check to see if the cube has been solved.
        if(is_game_done()) break;

        cout << "Rubik's Cube Game" << endl;
        cout << "Type one of the following command names to rotates the cube cells or 'Quit' to quit" << endl;
        cout << "Alternatively, you can type 'Shuffle' to shuffle the cube" << endl;
        cout << endl;

        print_instr();

        while(!valid) {
            cout << "Type a command: ";
            cin >> ans;

            if(ans == "Quit") break;
            if(ans == "Shuffle") break;

            if(is_valid(ans)) valid = true;
            else cout << "This is not a valid command name. Please try again." << endl;
        }
        valid = false;
        // Check to see if the user has requested to quit or shuffle. Otherwise, a command has been made.
        if(ans == "Quit") break;
        if(ans == "Shuffle") shuffle();
        else make_move(ans);
    }
}

int main() {
    game_loop();

    cout << endl;
    cout << "Thank you for playing" << endl;
}