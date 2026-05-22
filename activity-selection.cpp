#include <bits/stdc++.h>
using namespace std;

struct activity{
  char name[10];
  int st;
  int ft;
};
int main(){
  int n;
  cout << "Enter the number of activity: ";
  cin >> n;
  struct activity act[n];

  for(int i=0; i<n; i++){
    cout << "Enter the name of activity - "<< i+1 << ": ";
    cin >> act[i].name;
    cout << "Enter the start time of activity - "<< i+1 << ": ";
    cin >> act[i].st;
    cout << "Enter the finish time of activity - "<< i+1 << ": ";
    cin >> act[i].ft;
  }

  for(int i=0; i<n-1; i++){
    for(int j=i+1; j<n; j++){
      if(act[i].ft > act[j].ft){
        activity temp = act[i];
        act[i] = act[j];
        act[j] = temp;
      }
    }
  }

  vector<string> selectedAct;
  selectedAct.push_back(act[0].name);

  int count = 1;
  int lastFt = act[0].ft;

  for(int i=1; i<n; i++){
    if(act[i].st >= lastFt){
      selectedAct.push_back(act[i].name);
      count++;
      lastFt = act[i].ft;
    }
  }

  cout << "Total number of selected activities : " << count << endl;
  cout << "Selected activities are : ";

  for(int i=0; i<selectedAct.size(); i++){
    cout << selectedAct[i] << " ";
  }
  cout << endl;
}