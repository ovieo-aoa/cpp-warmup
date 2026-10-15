// =====================================================================
//  C++ WARM-UP  ·  African Olympiad Academy
//
//  The question descriptions are in README.md. Read them there.
//  This file holds the data, one worked example, and your answers.
//
//  BUILD AND RUN:   g++ -std=c++17 -Wall -o run warmup.cpp && ./run
//            or:    ./run.sh
//
//  Work on ONE question at a time. Write it, run it, check the output
//  against the README, commit it, move on.
// =====================================================================

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

/**
 * THE RECORD
 * One delivery: who brought it, how much, and what grade it was given.
 */
struct Delivery {
    string farmer;
    double kg;
    char   grade;
};


/**
 * THE DATA
 * Do not change these. Every expected answer in the README comes from exactly this data.
 */

// Q1 — one morning's weights, in the order they were weighed
vector<double> morningWeights = {
    45.5, 80.0, 12.0, -3.0, 66.5, 20.0, 31.0, 95.0, 50.0, 18.5, 0.0, 72.0
};

// Q2, Q3, Q4, Q7, Q8 — the day's logbook
vector<Delivery> logbook = {
    {"Keza",    45.5, 'A'},
    {"Bonu",    80.0, 'B'},
    {"Isanda",  20.0, 'A'},
    {"Keza",    12.0, 'C'},
    {"Onyinye", 66.5, 'B'},
    {"Karimi",  31.0, 'A'},
    {"Karimi",  31.0, 'A'},
    {"Keza",    18.5, 'B'},
    {"Bonu",    50.0, 'C'},
    {"Isanda",  20.0, 'A'},
    {"Onyinye", 72.0, 'A'}
};   // yes, one of these rows is in here twice. Q8 is about that.

// Q5 — records as the volunteers typed them, before any checking. Several of these are wrong. That is the point.
struct RawRecord {
    string id;
    string kg;        // text, because a volunteer can type anything
    char   grade;
};

vector<RawRecord> rawRecords = {
    {"F012", "45.5",  'A'},
    {"F7",   "20",    'A'},
    {"F033", "heavy", 'B'},
    {"F021", "0",     'C'},
    {"F044", "80",    'b'},
    {"F055", "",      'A'},
    {"F066", "31.5",  'D'},
    {"F077", "92",    'B'}
};

// Q6 — an Igisoro board. 16 pits, in sowing order.
//      Position 0 is unused so that board[1] really is pit 1.
vector<int> board = {0, 0, 0, 1, 0, 0, 4, 1, 0, 0, 2, 2, 0, 1, 5, 0, 0};


// ---------------------------------------------------------------------
//  A HELPER YOU MAY FIND USEFUL
// ---------------------------------------------------------------------
void printBoard(const vector<int> &b) {
    for (int i = 1; i <= 16; i++) cout << b[i] << " ";
    cout << "\n";
}


int main() {

    // =================================================================
    //  WORKED EXAMPLE  ·  not a question
    //
    //  This is the house style: walk the data once, keep what you need
    //  as you go, print at the end. Read it before you start Q1.
    //
    //  It answers: how many deliveries were grade A, and what was the
    //  heaviest single delivery in the whole logbook?
    // =================================================================

    int gradeACount = 0;
    Delivery heaviest = logbook[0];        // start from a REAL entry,
                                           // never from a made-up 0
    for (Delivery d : logbook) {
        if (d.grade == 'A') {
            gradeACount++;
        }
        if (d.kg > heaviest.kg) {
            heaviest = d;                  // keep the WHOLE record,
        }                                  // not just the number
    }

    cout << "=== Worked example ===\n";
    cout << "Grade A deliveries: " << gradeACount << "\n";
    cout << "Heaviest: " << heaviest.farmer << " with "
         << heaviest.kg << " kg\n\n";


    // =================================================================
    //  Q1  ·  THE WEIGHING SESSION          (see README)
    //  Uses: morningWeights
    // =================================================================

    cout << "=== Q1 ===\n";
    int count,streak,pos,size;
    double sum, larg,maxx;
    count = 0;
    larg = 0.0;
    pos = 0;
    streak = 0;
    vector <int> streaks;
    for (double num : morningWeights){
        sum += num;
        if(0 < num and num <= 80){
            count += 1;
            streak +=1;
        }
        else{
            streaks.push_back(streak);
            streak = 0;
        }
    }
    maxx = 0;
    for(int i = 0 ; i < 12 ; i++){
        if(morningWeights[i] > larg){
            larg = morningWeights[i];
            pos = i +1;
        }
    }
    size = streaks.size();
    for (int i = 0 ; i < size ; i++){
        if(streaks[i] > maxx ){
            maxx = streaks[i];
        }
    }
    cout << "Total: " << sum << " kg" << "\n";
    cout << "Valid: " << count << " of 12" << "\n";
    cout << "Heaviest: " << larg << " kg at position " << pos << "\n";
    cout << "Longest valid run: " << maxx;






    cout << "\n";


    // =================================================================
    //  Q2  ·  GRADE SUMMARY                 (see README)
    //  Uses: logbook
    // =================================================================

    cout << "=== Q2 ===\n";
    double An,Bn,Cn,Aa,Ba,Ca;
    int Ac,Bc,Cc;
    An = 0.0;
    Bn = 0.0;
    Cn = 0.0;
    Ac = 0;
    Bc = 0;
    Cc = 0;
    for (Delivery record : logbook){
        if(record.grade == 'A'){
            Ac +=1;
            An += record.kg;
        }
        else if(record.grade == 'B'){
            Bc += 1;
            Bn += record.kg;
        }
        else if(record.grade == 'C'){
            Cc += 1;
            Cn += record.kg;
        }
    }
    Aa = An/Ac;
    Ba = Bn/Bc;
    Ca = Cn/Cc;
    
    cout << "Grade A: " << Ac << " deliveries, " << An << " kg total, " << (An/Ac) << " kg average \n";
    cout << "Grade B: " << Bc << " deliveries, " << Bn << " kg total, " << (Bn/Bc) << " kg average \n";
    cout << "Grade C: " << Cc << " deliveries, " << Cn << " kg total, " << (Cn/Cc) << " kg average \n";
    if(max({Aa,Ba,Ca}) == Aa){
        cout << "Best average: Grade A";
    }
    else if(max({Aa,Ba,Ca}) == Ba){
        cout << "Best average: Grade B";
    }
    else if(max({Aa,Ba,Ca}) == Ca){
        cout << "Best average: Grade C";
    }








    cout << "\n";


    // =================================================================
    //  Q3  ·  WHO IS WHO                    (see README)
    //  Uses: logbook, and the findFarmer function you write below main
    // =================================================================

    cout << "=== Q3 ===\n";





    cout << "\n";


    // =================================================================
    //  Q4  ·  PAYMENT RUN WITH A DAILY CAP  (see README)
    //  Uses: logbook, and the payment function you write below main
    // =================================================================

    cout << "=== Q4 ===\n";





    cout << "\n";


    // =================================================================
    //  Q5  ·  THE VALIDATION REPORT         (see README)
    //  Uses: rawRecords
    // =================================================================

    cout << "=== Q5 ===\n";





    cout << "\n";

    // =================================================================
    //  Q6  ·  IGISORO: A FULL TURN          (see README)
    //  Uses: board
    // =================================================================

    cout << "=== Q6 ===\n";



    
    // =================================================================
    //  STRETCH  ·  optional
    // =================================================================

    // =================================================================
    //  Q7  ·  SORT THE LOGBOOK              (see README)
    //  Uses: logbook
    // =================================================================

    // cout << "=== Q7 ===\n";





    // =================================================================
    //  Q8  ·  SPOTTING DOUBLE-ENTRIES       (see README)
    //  Uses: logbook
    // =================================================================

    // cout << "=== Q8 ===\n";





    return 0;
}


// =====================================================================
//  FUNCTIONS YOU WRITE
//
//  C++ reads a file top to bottom, so a function must be DECLARED above
//  the place that calls it. These two are declared here at the bottom,
//  which main() cannot see — so move them ABOVE main(), or leave a
//  one-line declaration up there. Working that out is part of Q3.
// =====================================================================

// Q3:  return the position of the first delivery by this farmer,
//      or -1 if the farmer is not in the log at all.
//
// int findFarmer(const vector<Delivery> &log, string name) {
//
// }


// Q4:  what one delivery earns, before any cap is applied.
//      Grade A pays 10% above the rate, B pays the rate,
//      anything else pays 20% below it. The rate is 450.
//
// double payment(double kg, char grade) {
//
// }
