#pragma once
#include <ECSpp/ECSWorld.h>
#include "Module.h"

class WorldModule : public Module<>
{

public:

	template<class ...MTypes>
	WorldModule(const MDepPack_t<MTypes...> & dependencies) : ModuleBase_t(dependencies) {}

	virtual void startUp() override;

	virtual void update() override;

	virtual void shutdown() override;

public:

	epp::ECSWorld world;

};