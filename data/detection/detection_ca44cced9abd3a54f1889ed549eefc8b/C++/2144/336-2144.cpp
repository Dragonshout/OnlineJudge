#include<iostream>

using namespace std;

int processNum(int num){
	if(num >= 0){
		return num;
	}else{
		return -num;
	}
}

int main(){
	int N = 0;
	int luckyNum = 0;
	int numToCheck[100];
	cin >> N;
	for(int i = 0; i < N ; i++){
		cin >> numToCheck[i];
	}
	int lucky = 0;
	cin >> luckyNum;
	for(int i = 0; i < N; i++){
		if(numToCheck[i] == luckyNum){
			lucky += 10;
		} else {
			int temp = numToCheck[i] - luckyNum;
			if(temp <= 0){
				lucky = lucky + temp;
				
			} else{
				lucky = lucky - temp;
			}
			
			
		}
	}
	cout << lucky << endl;
	if(lucky > 0){
		cout << "Happy" << endl;
	}
	
	return 0;
}