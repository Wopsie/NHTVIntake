#include <sstream>
#include <string>
#include "DrawableObj.h"
#include <iostream>

using namespace std;

DrawableObj::DrawableObj(){
	stringstream ss;
	ss << this;
	cout << ss.str() << endl;
}

void DrawableObj::Update() {
	cout << "Overwritten" << endl;
}
void DrawableObj::Move(){
	cout << "Move DrawableObj" << endl;
}

void DrawableObj::Draw(RenderWindow &win){
	win.draw(GetShape());
	cout << GetShape().getPosition().x << endl;
}