// ----------------------------------------------------------------
// From Game Programming in C++ by Sanjay Madhav
// Copyright (C) 2017 Sanjay Madhav. All rights reserved.
// 
// Released under the BSD License
// See LICENSE in root directory for full details.
// ----------------------------------------------------------------

#pragma once
#include "Actor.h"
#include "CircleComponent.h"
class NewAsteroid : public Actor
{
public:
    NewAsteroid(Game* game);
    ~NewAsteroid();
    CircleComponent* GetCircle() { return mCircle; }

private:
    CircleComponent* mCircle;
	int mHp;  // hp
    friend class Laser;
};
