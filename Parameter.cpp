#include <vector>
using namespace std;

static vector<float> p(5, 0.2f);
static vector<string> world = { "green", "red", "red", "green", "green" };
static vector<string> measurements = { "red", "green" };
static vector<int> motions = { 1, 1 };
static float pHit = 0.6f;
static float pMiss = 0.2f;
static float pExact = 0.8f;
static float pOvershoot = 0.1f;
static float pUndershoot = 0.1f;