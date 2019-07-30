// XXX: https://github.com/BlakeBrown/HackerRank-Solutions/blob/master/Algorithms/Strings/Common%20Child%20(largest%20subsequence).cpp
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
// Question asks us to find the largest common subsequence between two strings (note: different than largest substring!)
// Great explanation of a DP (dynamic programming) algorithm: https://www.youtube.com/watch?v=NnD96abizww
#define maxxx(a,b) (a>b?a:b)
int main() {
    string s1, s2;
    cin>>s1;
    cin>>s2;
    // We need to use a staticly allocated array or we will run out of stack space (results in a segmentation fault)
    static int array[5001][5001];
    // Initialize array
    for(int i = 0; i <= s1.length(); i++) {
        for(int j = 0; j <= s2.length(); j++) {
            array[i][j] = 0;
        }
    }
    // Use dynamic programming to determine the size of the largest subsequence
    // We can break the problem down into parts by considering each string, character by character
    // If the two strings have the same char at the same index, then the largest subsequence at that point
    // is simply the largest subsequence before that char was added to either string + 1
    // If the two strings DON'T have the same char at the same index, then the largest subsequence at that point
    // is the larger of either a) string1 without that char or b) string2 without that char
    for(int i = 0; i < s1.length(); i++) {
        for(int j = 0; j < s2.length(); j++) {
            int dpt=array[i+1][j];
            if(s1[i] != s2[j]) {
                dpt=maxxx(array[i][j+1], dpt);
            } else {
                dpt = array[i][j] + 1;
            }
            array[i+1][j+1]=dpt;
        }
    }
    cout<<array[s1.length()][s2.length()];
    return 0;
}
