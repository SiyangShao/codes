#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){ 
    string s; cin >> s;

    // 1. parse the stuff
    map<ll, ll> polynomial;
    bool isExponent = false, isCoeffNegated = false, isExpNegated = false;
    int currCoeff = 0, currExp = 0;
    for (auto e: s) {
        bool NewTerm = ((e == '+' || e == '-') && !isExponent);
        if (NewTerm) {
            currExp *= (isExpNegated ? -1 : 1);
            currCoeff *= (isCoeffNegated ? -1 : 1);
            polynomial[currExp] += currCoeff; // merge similar terms
            currCoeff = 0, currExp = 0, isExponent = isCoeffNegated = isExpNegated = false;

            isCoeffNegated = 
        } else {

        }
    }
}