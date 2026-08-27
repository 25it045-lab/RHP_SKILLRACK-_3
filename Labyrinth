#include <iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
const int diff[5]={0,-1,0,1,0};
string dir="LURD";
string getPath(int R,int C,int prow,int pcol,vector<string>& g){
    string ans="";
    while(g[prow][pcol]!='A'){
        char ch=g[prow][pcol];
        ans+=ch;
        if(ch=='L') pcol++;
        else if(ch=='R') pcol--;
        else if(ch=='U') prow++;
        else if(ch=='D') prow--;
    }
    reverse(ans.begin(),ans.end());
    return ans;
}
int main() {
    int R,C; 
    cin>>R>>C;
    vector<string> g(R);
    for(int r=0;r<R;r++){
        cin>>g[r];
    }
    queue<pair<int,int>> q;
    
    for(int row=0;row<R;row++){
        for(int col=0;col<C;col++){
            if(g[row][col]=='A'){
                q.push(make_pair(row,col));
                row=R;
                break;
            }
        }
    }
    int brow=-1,bcol=-1;
    bool found =false;
    while (!q.empty() && !found) {
        int row=q.front().first;
        int col=q.front().second;
        q.pop();

        for (int i=0;i<4;i++) {
            int ar=row+diff[i];
            int ac=col+diff[i+1];
            if (ar>=0 && ar<R && ac>=0 && ac<C) {
                if (g[ar][ac]=='B') {
                    g[ar][ac]=dir[i];
                    brow=ar;
                    bcol=ac;
                    found=true;
                    break;
                }
   else if (g[ar][ac]=='.'){
                    g[ar][ac]=dir[i];
                    q.push(make_pair(ar,ac));
                }
            }
        }}

    if(!found){
        cout<<"NO"<<endl;
    }
    else{
        string path= getPath(R,C,brow,bcol,g);
        cout<<"YES"<<endl;
        cout<<path.length()<<"\n";
        cout<<path<<"\n";
    }
    return 0;
}
