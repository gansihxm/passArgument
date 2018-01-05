#include <iostream>
#include <vector>
#include "Parameter.cpp"

extern vector<float> p;

using namespace std;

vector<float> sense(vector<float> p, string Z){
	vector<float> q;

	for (size_t i = 0, ilen = p.size(); i < ilen; i++) {
		int hit;
		if (Z == world[i]){
			 hit = 1;
		}
		else{
			 hit = 0; 
		}
        float num_to_push = p[i] * (hit * pHit + (1 - hit) * pMiss);
        q.push_back(num_to_push);
	}
	float sum;
	for (size_t i = 0, ilen = q.size(); i < ilen; i++) {
        sum = 0.0;
        sum = sum + q[i];
   
    }
    
	for (size_t i = 0, ilen = q.size(); i < ilen; i++) {
        q[i] = q[i] / sum;
    }
    
	return q;
}

vector<float> move(vector<float> &p, int U){
    vector<float> q;
    
	for (size_t i = 0, ilen = p.size(); i < ilen; i++) {
        float s = pExact * p[(i - U) - (i - U)/p.size() * p.size()];
		s = s + pOvershoot * p[(i - U -1) - (i - U - 1)/p.size() * p.size()];
		s = s + pUndershoot * p[(i - U + 1) - (i - U + 1)/p.size() * p.size()];
		q.push_back(s);
    }
	
	return q;
}

int main(){
	/*
	vector<float> p(5, 0.2);
	static vector<string> world = { "green", "red", "red", "green", "green"};
	static vector<string> measurements = { "red", "green"};
	static vector<int> motions = {1, 1};
	static float pHit = 0.6;
	static float pMiss = 0.2;
	static float pExact = 0.8;
	static float pOvershoot = 0.1;
	static float pUndershoot = 0.1;
	*/
	
	for (size_t i = 0, ilen = measurements.size(); i < ilen; i++) {
		
		p = sense(p, measurements[i]);
		p = move(p, motions[i]);
	}
	
	for (size_t i = 0, ilen = p.size(); i < ilen; i++) {
		
		cout << p[i] << " ";
	}
	cout << endl;
	system("pause");
	return 0;
}

