// ----------------------------------------------------------------
// From Game Programming in C++ by Sanjay Madhav
// Copyright (C) 2017 Sanjay Madhav. All rights reserved.
// 
// Released under the BSD License
// See LICENSE in root directory for full details.
// ----------------------------------------------------------------

#include "NewAsteroid.h"
#include "SpriteComponent.h"
#include "MoveComponent.h"
#include "Game.h"
#include "Random.h"
#include "CircleComponent.h"
NewAsteroid::NewAsteroid(Game* game)
    : Actor(game)
    , mCircle(nullptr)
    , mHp(3) // Initialisiere Lebenspunkte auf 3
{
    // Initialize to random position/orientation
    Vector2 randPos = Random::GetVector(Vector2::Zero,
        Vector2(1024.0f, 768.0f));
    SetPosition(randPos);

    SetRotation(Random::GetFloatRange(0.0f, Math::TwoPi));

    // Create a sprite component
    SpriteComponent* sc = new SpriteComponent(this);
    sc->SetTexture(game->GetTexture("Assets/NewAsteroid.png"));

    // Create a move component, and set a forward speed
    MoveComponent* mc = new MoveComponent(this);
    mc->SetForwardSpeed(250.0f);

    // Create a circle component (for collision)
    mCircle = new CircleComponent(this);
    mCircle->SetRadius(15.0f);

    // Add to mNewAsteroids in game
    game->AddNewAsteroid(this);
}

NewAsteroid::~NewAsteroid()
{
    GetGame()->RemoveNewAsteroid(this);
}