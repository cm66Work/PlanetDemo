#pragma once

#include "GameObject.h"

class Planet : public GameObject
{
public:
	Planet();
	virtual ~Planet();

	void Update() override;
};
