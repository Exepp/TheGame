#pragma once
#include <ECSpp/CGroup/CGroup.h>
#include <ECSpp/Utility/ThirdParty/sparsepp/spp.h>
#include "Utilities/Math/MathUtilities.h"

#include "Modules/World/Components/CollisionComponent.h"
#include "Modules/World/Components/ShapeComponent.h"
#include "Modules/World/Components/TransformComponent.h"


class Grid
{
	using RefType = epp::CGroup<CollisionComponent, ShapeComponent, TransformComponent>::Iterator_t;

	using CellsHolder_t = spp::sparse_hash_map<Vec2i, std::vector<RefType>>;

public:

	void setGridSize(float size);
	
	void insert(const RefType& it);

	const std::vector<const std::vector<RefType>*>& queryFor(const Vec2f& pos, const AABB& aabb = AABB());

	void clear();


	float getGridSize() const;

	const CellsHolder_t& getCells() const;

private:

	Vec2i posAsIndices(const Vec2f& pos) const;

private:

	float gridSize = 15.f;

	CellsHolder_t cells;

	std::vector<const std::vector<Grid::RefType>*> queryResult;
};
