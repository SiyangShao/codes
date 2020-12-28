#include <bits/stdc++.h>
using namespace std;
struct point{
    double x , y , z;
};
inline double dis(point a , point b){
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y)+(a.z-b.z)*(a.z-b.z));
}
inline double accos(double A , double B , double C){
    return acos((A*A+B*B-C*C)/(2*A*B));
}
int T;
double r;
inline double sua(double dis){
    return sqrt(dis*dis-r*r);
}
point o , s , t;
int main(){
    cin>>T;
    while(T--){
        cin>>o.x>>o.y>>o.z>>r;
        cin>>s.x>>s.y>>s.z>>t.x>>t.y>>t.z;
        double disa = dis(o,s) , disb = dis(o,t) , disc = dis(s,t);
        double all = accos(disa , disb , disc);
        double left = acos(r/disa) , right = acos(r/disb);
        //cout<<disa<<" "<<disb<<" "<<disc<<" "<<all<<" "<<left<<" "<<right<<"\n";
        if(all<left+right){
            cout<<setiosflags(ios::fixed)<<setprecision(8)<<disc<<"\n";
        }else{
            double angle = all - left - right;
            double length = angle * r;
            cout<<setiosflags(ios::fixed)<<setprecision(8)<<sua(disa)+sua(disb)+length<<"\n";
        }
    }
}